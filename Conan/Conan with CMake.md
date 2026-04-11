---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-22 13:46::22 PM
tags:
  - Linux
  - CMake
  - Cpp
  - Conan
---

```cmake
cmake_minimum_required(VERSION 3.20)

# -------------------------------------------------------------
# ⚠️ MUST BE DEFINED HERE (Before project())
# -------------------------------------------------------------
if(EXISTS "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
elseif(EXISTS "${CMAKE_SOURCE_DIR}/conan_toolchain.cmake")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/conan_toolchain.cmake")
endif()

# Now initialize the project
project(MyProject CXX)
```
