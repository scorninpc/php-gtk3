#!/bin/bash
set -e

# Re-run with sudo if not root
if [ "$EUID" -ne 0 ]; then
    exec sudo PHPCPP_BASE="$PHPCPP_BASE" "$0" "$@"
fi

# Base directory containing per-version libphpcpp folders (e.g. php7.4/, php8.4/)
# Override by setting PHPCPP_BASE before running, e.g.:
#   PHPCPP_BASE=/custom/path ./build-all.sh
PHPCPP_BASE="${PHPCPP_BASE:-/mnt/share/dev/code/PHP-CPP/dist}"

# FORMAT: "version:php_config_path:ini_dir:so_dest:with_webkit:enabled"
# so_dest: system extension dir where php8.x binary loads extensions from
# enabled: 1=build by default, 0=skip by default
BUILDS=(
    "7.4:/opt/php/php-7.4.33/bin/php-config:/etc/php/7.4/mods-available:/usr/lib/php/20190902:1:1"
   # "8.2:/opt/php/php-8.2.29/bin/php-config:/etc/php/8.2/mods-available:/usr/lib/php/20220829:1:0"
   # "8.3:/opt/php/php8.3/bin/php-config:/etc/php/8.3/mods-available:/usr/lib/php/20230831:1:0"
    "8.4:/opt/php/php-8.4.14/bin/php-config:/etc/php/8.4/mods-available:/usr/lib/php/20240924:0:1"
)

# Kill any running php processes, but don't fail if none exist
for BUILD in "${BUILDS[@]}"; do
    VERSION=$(echo "$BUILD" | cut -d: -f1)
    ENABLED=$(echo "$BUILD" | cut -d: -f6)
    [ "$ENABLED" -eq 1 ] && pkill -f "/usr/bin/php${VERSION}" 2>/dev/null || true
done

#php -vgit pull

for BUILD in "${BUILDS[@]}"; do
    VERSION=$(echo     "$BUILD" | cut -d: -f1)
    PHP_CONFIG=$(echo  "$BUILD" | cut -d: -f2)
    INI_DIR=$(echo     "$BUILD" | cut -d: -f3)
    SO_DEST=$(echo     "$BUILD" | cut -d: -f4)
    WITH_WEBKIT=$(echo "$BUILD" | cut -d: -f5)
    ENABLED=$(echo     "$BUILD" | cut -d: -f6)

    if [ "$ENABLED" -ne 1 ]; then
        echo "=== Skipping PHP ${VERSION} (disabled) ==="
        continue
    fi

    PHPCPP_DIR="${PHPCPP_BASE}/php${VERSION}"
    PHPCPP_STATIC=$(find "${PHPCPP_DIR}" -maxdepth 1 -name "libphpcpp.a.*" | head -1)

    if [ -z "$PHPCPP_STATIC" ]; then
        echo "ERROR: No static libphpcpp found in ${PHPCPP_DIR}" >&2
        exit 1
    fi

    echo "=== Building for PHP ${VERSION} (libphpcpp: ${PHPCPP_STATIC}) ==="
    make clean
    make PHP_CONFIG="${PHP_CONFIG}" INI_DIR="${INI_DIR}/" WITH_WEBKIT="${WITH_WEBKIT}" PHPCPP_STATIC="${PHPCPP_STATIC}" -j12
    cp php-gtk3.so "${SO_DEST}"
done

echo "=== All versions built successfully ==="
