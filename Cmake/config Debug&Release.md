---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-30 20:02::38 PM
tags:
  - CMake
  - CMakeList
  - Cpp
---
# Debug & Release 

To choose Debug or Release type in cmake you can either define it in `CMakeLists.txt` file or during build time.

- `${CMAKE_BUILD_DIR}` is wrong.
- `${CMAKE_BINARY_DIR}` is your build directory. ie `/to/you/build`

```sh
# Only set a default build type if it hasn't been specified on the command line
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
  
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithPostInfo")
endif()
```

```sh 
cmake -DCMAKE_BUILD_TYPE=Debug
```