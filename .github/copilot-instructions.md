# Copilot Coding Agent Instructions for `scorninpc/php-gtk3`

These instructions are for an automated coding agent seeing this repository for the first time. They are **about understanding and maintaining the source code**, not about building or installing the extension. **Do not spend time trying to compile, package, or install** unless a task explicitly demands that and the user provides the necessary environment information.

If something here appears incomplete or inconsistent with the current tree, you may perform targeted searches, but treat this file as your primary map of the project’s structure and design.

---

## 1. High-level Purpose and Scope

- This repository implements **PHP-GTK3**, a **PHP extension written in C++** that exposes GTK+ 3 and related libraries to PHP.
- It is built on top of the [PHP-CPP](https://github.com/CopernicaMarketingSoftware/PHP-CPP) library.
- The extension allows developers to create **desktop GUI applications in PHP** with GTK widgets, windows, events, dialogs, and related features.
- Major external C/C++ libraries wrapped here:
  - `gtk+-3.0` (core GUI, **GTK 3**)
  - `gladeui-2.0` (Glade integration)
  - `gtksourceview-3.0` (code editing widgets)
  - `pango` (text layout)

**Target platforms:**

- **Linux and Windows only.** Ignore macOS-specific concepts; they are not relevant for future development.

**GTK reference version:**

- The implementation should be conceptually aligned with **GTK 3.24.x**, specifically the APIs available around  
  [GTK 3.24.48](https://github.com/GNOME/gtk/releases/tag/3.24.48).  
  When in doubt about behavior or signatures, consult the GTK 3.24 C API in that repository or its associated documentation.

**PHP compatibility goal:**  
Code should remain compatible with **PHP 7.4 and all newer PHP versions** that PHP-CPP supports. When you make changes:

- Avoid relying on PHP API features that are version-specific unless guarded appropriately.
- Keep the extension’s behavior consistent across PHP 7.4 and newer PHP 8.x releases.

---

## 2. Repository Layout and Architectural Overview

### 2.1. Top-level structure

Important files and directories in the repo root:

- `README.md` – Overview of PHP-GTK3, example PHP usage, links to external resources.
- `LICENSE` – Project licensing.
- `php-gtk.cpp`, `php-gtk.h` – Core binding/extension implementation code.
- `main.cpp`, `main.h` – Central glue for wiring GTK and PHP-CPP together (extension entry, registration, etc.).
- `php-gtk3.ini` – Extension ini configuration template.
- `src/` – Core C++ implementation of the bindings, organized by GTK and related namespaces.
- `docs/` – Additional documentation (you do not need to follow its build instructions).
- `docker/` – Docker and AppImage assets (environment and packaging, not source logic).
- `gen/` – Additional tooling/definitions related to bindings (usually not necessary to touch unless explicitly asked).
- `.github/ISSUE_TEMPLATE/` – Issue templates for this project (no workflows here).

### 2.2. Core architecture and responsibilities

At a high level:

1. **PHP-CPP integration layer** (`main.cpp`, `php-gtk.cpp`, `php-gtk.h`):

   - Uses PHP-CPP constructs (`Php::Extension`, `Php::Class`, etc.) to register extension classes and functions with PHP.
   - Acts as the entry point for the PHP runtime to load and initialize the GTK bindings.
   - Defines which C++ classes (wrapping GTK types) become visible as PHP classes.

2. **GTK and related wrapper layer** (`src/` tree):

   - Each GTK / GDK / Pango / etc. type is represented as one or more C++ classes that:
     - Wrap the underlying C structs/functions from the **GTK 3** C API.
     - Expose methods and properties to PHP via PHP-CPP.
   - Directories map roughly to upstream namespaces from GTK and its stack:
     - `src/G/` – G\* foundation types, generic GLib/GObject-related wrappers.
     - `src/Gdk/` – GDK (lower-level display, input, drawing) types.
     - `src/Gtk/` – GTK widgets and containers (e.g. windows, buttons, tree views), aligned with GTK 3.24 APIs.
     - `src/Glade/` – Glade UI builder integration.
     - `src/GtkSourceView/` – GtkSourceView components.
     - `src/Pango/` – Pango text layout types.

   The wrappers typically:

   - Hold a pointer/reference to the underlying C object (e.g. `GtkWidget*`).
   - Provide constructors and methods that call into the GTK C API.
   - Map C types to PHP-CPP types in function arguments and return values.

You should treat the **GTK 3.24 C API** in the upstream GTK repository as the ground truth for object names, method signatures, and semantics.

---

## 3. Working with the Source Code

### 3.1. Adding or modifying bindings

When implementing new functionality or fixing bugs in existing bindings:

1. **Determine the GTK (or related) namespace and target:**

   - Core GTK widget? → `src/Gtk/`
   - Lower-level windowing / drawing (GDK)? → `src/Gdk/`
   - Pango text layout / fonts? → `src/Pango/`
   - Glade integration features? → `src/Glade/`
   - GtkSourceView widget? → `src/GtkSourceView/`
   - GLib/GObject-style infrastructure or basic types? → `src/G/`

2. **Use GTK 3.24 as the behavioral and signature reference:**

   - Consult the upstream GTK C headers and documentation around the **GTK 3.24.48** release:
     - [GTK repository – 3.24.48 tag](https://github.com/GNOME/gtk/releases/tag/3.24.48).
   - Ensure that:
     - The C++ wrapper’s methods correspond to real GTK 3 APIs.
     - Parameter types and semantics match the underlying C API (e.g., ownership, constness, nullable pointers).
     - You are not using GTK 4 or later APIs.

3. **Locate an existing, similar wrapper as a reference:**

   - For a new widget or function, first search for a comparable GTK type in the same directory.
   - Match patterns such as:
     - Class naming (C++ class and file names mirror GTK type names).
     - Method naming (close to the GTK C function names, but PHP-idiomatic where appropriate).
     - Use of PHP-CPP types (`Php::Value`, `Php::Parameters`, `Php::Object`, etc.).

4. **Maintain PHP-CPP conventions:**

   - Use `Php::Class<T>` and the same method registration patterns used by sibling classes.
   - Ensure argument and return type conversions are consistent:
     - Map GTK integers/enums/flags to PHP integers.
     - Map strings and text data to `Php::Value`/`Php::String`.
     - For complex objects (widgets, layouts, etc.), return PHP objects wrapping the appropriate C++ wrapper type.
   - Handle memory and ownership correctly:
     - Respect GTK reference counting (`g_object_ref`, `g_object_unref`, etc.) when needed.
     - Ensure that PHP object lifetimes do not lead to leaks or premature frees of GTK objects.

5. **Compatibility with PHP 7.4 and newer:**
   - Use APIs and patterns supported by PHP-CPP across both PHP 7.4 and newer PHP 8.x versions.
   - Avoid relying on PHP-internal behavior that changed between PHP 7 and PHP 8.
   - When behavior differences are unavoidable, strive for **consistent observable behavior in PHP**.

### 3.2. Cross-cutting concerns

When modifying cross-cutting areas (changes that affect many widgets or multiple namespaces):

- Start from `main.cpp`, `php-gtk.cpp`, and `php-gtk.h` to understand:
  - How classes are registered and exposed to PHP.
  - How module initialization/shutdown is wired.
- Track how common helper utilities in `src/` (not under a sub-namespace directory) are used:
  - These may provide shared conversion routines, error-handling helpers, or ownership utilities.
- Keep such changes minimal, well-documented, and consistent with **GTK 3.24 behavior** to avoid subtle breakage.

---

## 4. External Reference for Semantics

Instead of relying on in-repo documentation for low-level behavior, **use the official GTK 3 sources and docs as your reference**:

- Upstream GTK repository:
  - [GTK on GitHub – 3.24.48 release](https://github.com/GNOME/gtk/releases/tag/3.24.48)
- Use this for:
  - Confirming object names, method signatures, and enum/flag values.
  - Understanding how a widget or function is meant to behave.
  - Checking edge cases, ownership conventions, and deprecations in GTK 3.

When you need to reason about how a wrapper _should_ behave, first:

1. Identify the GTK type or function (`GtkWidget`, `GtkWindow`, `GtkTreeView`, etc.).
2. Look up its definition and documentation in the GTK 3.24 sources or associated reference manual.
3. Mirror the behavior in the C++ wrapper and PHP exposure, rather than inventing new semantics.

---

## 5. How to Approach Tasks in this Repo

When receiving a task related to this repository:

1. **Assume a working build/CI environment exists outside your control.**  
   Do **not** spend time trying to:

   - Discover or modify compiler flags.
   - Adjust or create new build scripts or Makefile targets.
   - Write instructions on how to install the extension.

2. **Focus on source-level changes and GTK 3 semantics:**

   - Implement or adjust C++ bindings in the appropriate `src/` subdirectory.
   - Modify `main.cpp`/`php-gtk.cpp`/`php-gtk.h` only when you need to update registration or extension metadata.
   - Use **GTK 3.24.48** in the upstream GTK repository as your authoritative behavioral reference.

3. **Preserve compatibility with PHP 7.4 and all newer PHP versions:**

   - Keep PHP-facing APIs stable and predictable.
   - Avoid introducing behaviors that rely on undefined or version-specific differences in PHP internals.
   - When in doubt, follow existing patterns in this codebase.

4. **Only search further when necessary:**
   - Start from the directories and files listed here.
   - Use code search (e.g., for a GTK type name or method) to find the existing wrapper to mimic.
   - Expand your search scope only when this file and the directly-related code are insufficient.

By following this guidance, you will maximize your effectiveness on tasks involving this repository while minimizing time spent on non-essential build or environment details.
