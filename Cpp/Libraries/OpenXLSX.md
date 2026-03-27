---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - Cpp
  - Excel
  - Library
---
# \#include \<OpenXLSX>

## Description:  
OpenXLSX is library written in C++ for the purpose of manipulating Excel Data i.e. reading ,writing, formatting and others. 

Library Link: [https://github.com/troldal/OpenXLSX.git](https://github.com/troldal/OpenXLSX.git)

## CMakeLists.txt
```CMake
cmake_minimum_required(VERSION 3.10) 
project(Demo1 VERSION 0.0) 

# creating executable file. 
add_executable(Demo1 Demo1.cpp) 

# linking OpenXLSX libraries. 
find_package(OpenXLSX) 
target_link_libraries(Demo1 PRIVATE OpenXLSX::OpenXLSX)
```

![](html.7z)