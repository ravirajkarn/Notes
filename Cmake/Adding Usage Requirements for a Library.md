---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-06-16T08:42:00
tags:
  - CMake
  - Library
---

1. Add expected compiler features to a target. 
```CMake
target_compile_features(<target> <PRIVATE|PUBLIC|INTERFACE> <feature> [...])
```
Eg.- 
```CMake
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11) 
```
2. We can split CMakeLists.txt into different file.cmake and we can link it with
```CMake
include(file.cmake)
```
Note:- If we create a variable then it is global for whole file. Which can make code confusing. 

3. We can split CMakeLists.txt into different CMakeLists.txt and we can link it with
```CMake
Add_subdirectory(path/of/CMakeLists/Directory)
```
Note:- It is batter then include method and we can create variable without compromising make it global variable.