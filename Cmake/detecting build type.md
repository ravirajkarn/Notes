---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-24 20:37::03 PM
tags:
  - CMake
  - Cpp
---
# Detecting build type
CMake variable:- CMAKE_BUILD_TYPE

```Cmake
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building in Debug mode")
    # Add debug-specific compiler flags, definitions, or link libraries
    target_compile_definitions(my_target PRIVATE DEBUG_BUILD)
    # ...
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Building in Release mode")
    # Add release-specific compiler flags, definitions, or link libraries
    target_compile_definitions(my_target PRIVATE NDEBUG)
    # ...
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    message(STATUS "Building in Release with Debug Info mode")
    # Add flags for optimized release builds with debug information
    # ...
elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    message(STATUS "Building in Minimum Size Release mode")
    # Add flags for optimized release builds with smallest possible size
    # ...
else()
    message(STATUS "CMAKE_BUILD_TYPE is not set or unknown, defaulting to Debug.")
    # Handle cases where CMAKE_BUILD_TYPE might not be set explicitly
    set(CMAKE_BUILD_TYPE Debug)
    # ...
endif()
```