---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-05-03 17:22::17 PM
tags:
  - Cpp
  - CMake
  - CMakeList
---

# add_library
## [[Types of libraries#Normal Libraries|Normal Libraries]]
**`add_library(<name> [<type>] [EXCLUDE_FROM_ALL] <sources>...)`**

Add a library target called `<name>` to be built from the source files listed in the command invocation.

The optional `<type>` specifies the type of library to be created:

`STATIC`
	A [Static Library](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#static-libraries): an archive of object files for use when linking other targets.

`SHARED`
	A [Shared Library](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#shared-libraries): a dynamic library that may be linked by other targets and loaded at runtime.

`MODULE`
	A [Module Library](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#module-libraries): a plugin that may not be linked by other targets, but may be dynamically loaded at runtime using dlopen-like functionality.

If no `<type>` is given the default is `STATIC` or `SHARED` based on the value of the [`BUILD_SHARED_LIBS`](https://cmake.org/cmake/help/latest/variable/BUILD_SHARED_LIBS.html#variable:BUILD_SHARED_LIBS "BUILD_SHARED_LIBS") variable.

The options are:
`EXCLUDE_FROM_ALL`
	Set the [`EXCLUDE_FROM_ALL`](https://cmake.org/cmake/help/latest/prop_tgt/EXCLUDE_FROM_ALL.html#prop_tgt:EXCLUDE_FROM_ALL "EXCLUDE_FROM_ALL") target property automatically. See documentation of that target property for details.
## [[Types of libraries#Object Libraries|Object Libraries]]
**`add_library(<name> OBJECT <sources>...)`**
```CMake
add_library(... $<TARGET_OBJECTS:objlib> ...)
add_executable(... $<TARGET_OBJECTS:objlib> ...)
```
## [[Types of libraries#Interface Libraries|Interface Libraries]]

- [`set_property()`](https://cmake.org/cmake/help/latest/command/set_property.html#command:set_property "set_property"),
- [`target_link_libraries(INTERFACE)`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries "target_link_libraries(interface)"),
- [`target_link_options(INTERFACE)`](https://cmake.org/cmake/help/latest/command/target_link_options.html#command:target_link_options "target_link_options(interface)"),
- [`target_include_directories(INTERFACE)`](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories "target_include_directories(interface)"),
- [`target_compile_options(INTERFACE)`](https://cmake.org/cmake/help/latest/command/target_compile_options.html#command:target_compile_options "target_compile_options(interface)"),
- [`target_compile_definitions(INTERFACE)`](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions "target_compile_definitions(interface)"), and
- [`target_sources(INTERFACE)`](https://cmake.org/cmake/help/latest/command/target_sources.html#command:target_sources "target_sources(interface)"),

1. **`add_library(<name> INTERFACE [EXCLUDE_FROM_ALL] <sources>...)`**
2. **`add_library(<name> INTERFACE SYMBOLIC)`**
## [[Types of libraries#Imported Libraries|Imported Libraries]]
**`add_library(<name> <type> IMPORTED [GLOBAL])`**

Add an [IMPORTED library target](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#imported-targets) called `<name>`. The target name may be referenced like any target built within the project, except that by default it is visible only in the directory in which it is created, and below.

The `<type>` must be one of:

`STATIC`, `SHARED`, `MODULE`, `UNKNOWN`
	References a library file located outside the project. The [`IMPORTED_LOCATION`](https://cmake.org/cmake/help/latest/prop_tgt/IMPORTED_LOCATION.html#prop_tgt:IMPORTED_LOCATION "IMPORTED_LOCATION") target property (or its per-configuration variant [`IMPORTED_LOCATION_<CONFIG>`](https://cmake.org/cmake/help/latest/prop_tgt/IMPORTED_LOCATION_CONFIG.html#prop_tgt:IMPORTED_LOCATION_%3CCONFIG%3E "IMPORTED_LOCATION_<CONFIG>")) specifies the location of the main library file on disk:
		- For a `SHARED` library on most non-Windows platforms, the main library file is the `.so` or `.dylib` file used by both linkers and dynamic loaders. If the referenced library file has a `SONAME` (or on macOS, has a `LC_ID_DYLIB` starting in `@rpath/`), the value of that field should be set in the [`IMPORTED_SONAME`](https://cmake.org/cmake/help/latest/prop_tgt/IMPORTED_SONAME.html#prop_tgt:IMPORTED_SONAME "IMPORTED_SONAME") target property. If the referenced library file does not have a `SONAME`, but the platform supports it, then the [`IMPORTED_NO_SONAME`](https://cmake.org/cmake/help/latest/prop_tgt/IMPORTED_NO_SONAME.html#prop_tgt:IMPORTED_NO_SONAME "IMPORTED_NO_SONAME") target property should be set.
		- For a `SHARED` library on Windows, the [`IMPORTED_IMPLIB`](https://cmake.org/cmake/help/latest/prop_tgt/IMPORTED_IMPLIB.html#prop_tgt:IMPORTED_IMPLIB "IMPORTED_IMPLIB") target property (or its per-configuration variant [`IMPORTED_IMPLIB_<CONFIG>`](https://cmake.org/cmake/help/latest/prop_tgt/IMPORTED_IMPLIB_CONFIG.html#prop_tgt:IMPORTED_IMPLIB_%3CCONFIG%3E "IMPORTED_IMPLIB_<CONFIG>")) specifies the location of the DLL import library file (`.lib` or `.dll.a`) on disk, and the `IMPORTED_LOCATION` is the location of the `.dll` runtime library (and is optional, but needed by the [`TARGET_RUNTIME_DLLS`](https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html#genex:TARGET_RUNTIME_DLLS "TARGET_RUNTIME_DLLS") generator expression).
	Additional usage requirements may be specified in `INTERFACE_*` properties.
	An `UNKNOWN` library type is typically only used in the implementation of [Find Modules](https://cmake.org/cmake/help/latest/manual/cmake-developer.7.html#find-modules). It allows the path to an imported library (often found using the [`find_library()`](https://cmake.org/cmake/help/latest/command/find_library.html#command:find_library "find_library") command) to be used without having to know what type of library it is. This is especially useful on Windows where a static library and a DLL's import library both have the same file extension.

`OBJECT`
	References a set of object files located outside the project. The [`IMPORTED_OBJECTS`](https://cmake.org/cmake/help/latest/prop_tgt/IMPORTED_OBJECTS.html#prop_tgt:IMPORTED_OBJECTS "IMPORTED_OBJECTS") target property (or its per-configuration variant [`IMPORTED_OBJECTS_<CONFIG>`](https://cmake.org/cmake/help/latest/prop_tgt/IMPORTED_OBJECTS_CONFIG.html#prop_tgt:IMPORTED_OBJECTS_%3CCONFIG%3E "IMPORTED_OBJECTS_<CONFIG>")) specifies the locations of object files on disk. Additional usage requirements may be specified in `INTERFACE_*` properties.

`INTERFACE`
	Does not reference any library or object files on disk, but may specify usage requirements in `INTERFACE_*` properties.

The options are:
`GLOBAL`
	Make the target name globally visible.