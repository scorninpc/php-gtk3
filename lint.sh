#!/usr/bin/env bash
set -euo pipefail

CLANG_TIDY=${CLANG_TIDY:-clang-tidy-17}
CLANG_FORMAT=${CLANG_FORMAT:-clang-format-17}
JOBS=${JOBS:-$(nproc)}

# Checks are defined in .clang-tidy at the repo root
EXTRA_ARGS="-std=c++17"

FIX=0
NO_FORMAT=0
NO_TIDY=0
for arg in "$@"; do
    case "$arg" in
        --fix)       FIX=1 ;;
        --no-format) NO_FORMAT=1 ;;
        --no-tidy)   NO_TIDY=1 ;;
    esac
done

# Build include flags from pkg-config
INCLUDE_FLAGS=()
while IFS= read -r flag; do
    INCLUDE_FLAGS+=("--extra-arg=$flag")
done < <(
    {
        pkg-config --cflags glib-2.0 gtk+-3.0 gtksourceview-3.0 2>/dev/null
        pkg-config --cflags webkit2gtk-4.1 2>/dev/null || pkg-config --cflags webkit2gtk-4.0 2>/dev/null || true
    } | tr ' ' '\n' | grep -v '^$'
)

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Collect .cpp files for clang-tidy (headers are checked transitively)
mapfile -t CPP_FILES < <(
    {
        find "$SCRIPT_DIR/src" -type f -name "*.cpp"
        find "$SCRIPT_DIR" -maxdepth 1 -type f \( -name "main.cpp" -o -name "php-gtk.cpp" \)
    } | grep -v '/vendor/' | sort
)

# Collect all source files for clang-format (includes headers)
mapfile -t FILES < <(
    {
        find "$SCRIPT_DIR/src" -type f \( -name "*.cpp" -o -name "*.h" \)
        find "$SCRIPT_DIR" -maxdepth 1 -type f \( -name "main.cpp" -o -name "php-gtk.cpp" \)
    } | grep -v '/vendor/' | sort
)

ERR_DIR=$(mktemp -d)
trap 'rm -rf "$ERR_DIR"' EXIT

if [[ $FIX -eq 1 ]]; then
    ACTION="fixing"
else
    ACTION="checking"
fi

if [[ $NO_TIDY -eq 1 ]]; then
    echo "=== clang-tidy skipped (--no-tidy) ==="
else
    echo "=== clang-tidy (${JOBS} jobs) ==="
    active=0
    for f in "${CPP_FILES[@]}"; do
        (
            echo "  $ACTION: ${f#"$SCRIPT_DIR"/}"
            TIDY_ARGS=(--extra-arg="$EXTRA_ARGS" "${INCLUDE_FLAGS[@]}")
            if [[ $FIX -eq 1 ]]; then
                TIDY_ARGS+=(--fix --fix-errors)
            fi
            if ! "$CLANG_TIDY" "$f" "${TIDY_ARGS[@]}" -- 2>&1; then
                touch "$ERR_DIR/$(basename "$f").tidy"
            fi
        ) &
        active=$((active + 1))
        if [[ $active -ge $JOBS ]]; then
            wait -n 2>/dev/null || wait
            active=$((active - 1))
        fi
    done
    wait
fi

if [[ $NO_FORMAT -eq 1 ]]; then
    echo "=== clang-format skipped (--no-format) ==="
else
    echo "=== clang-format (${JOBS} jobs) ==="
    active=0
    for f in "${FILES[@]}"; do
        (
            echo "  $ACTION: ${f#"$SCRIPT_DIR"/}"
            if [[ $FIX -eq 1 ]]; then
                "$CLANG_FORMAT" -i "$f"
            else
                if ! "$CLANG_FORMAT" --dry-run --Werror "$f" 2>&1; then
                    touch "$ERR_DIR/$(basename "$f").fmt"
                fi
            fi
        ) &
        active=$((active + 1))
        if [[ $active -ge $JOBS ]]; then
            wait -n 2>/dev/null || wait
            active=$((active - 1))
        fi
    done
    wait
fi

TIDY_ERRORS=$(find "$ERR_DIR" -name "*.tidy" | wc -l)
FORMAT_ERRORS=$(find "$ERR_DIR" -name "*.fmt" | wc -l)

echo ""
echo "=== Summary ==="
if [[ $FIX -eq 1 ]]; then
    echo "  Auto-fix applied. Run without --fix to verify."
    exit 0
fi

echo "  clang-tidy   errors: $TIDY_ERRORS"
echo "  clang-format errors: $FORMAT_ERRORS"

if [[ $TIDY_ERRORS -gt 0 || $FORMAT_ERRORS -gt 0 ]]; then
    exit 1
fi

echo "All checks passed."
