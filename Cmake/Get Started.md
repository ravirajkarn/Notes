---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-06-15T23:33:00
tags:
  - CMake
  - Introduction
---

# Introduction
- CMake is just a build generator. 

- To work with Cmake we need to create CMakeLists.txt. This file will hold all the configuration for our project. 
Note- Order of writing code is important. cmake_minimum_required() must be at first.

- To change default generator in cmake 
	For Cmake 3.15 or later  
		`$Env:CMAKE_GENERATOR = "MinGW Makefiles"`
	For cmake < 3.15 
		`@cmake.exe -G "MinGW Makefiles"%*`


# CMakeLists.txt 

1. set the minimum required version of Cmake to build the program. 
	`cmake_minimum_required(VERSION 3.30)`

2. Create a project name. 
```CMake
project(<PROJECT-NAME> 
 [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]] 
 [DESCRIPTION <project-description-string>] 
 [HOMEPAGE_URL <url-string>] 
 [LANGUAGES <language-name>...])
```
	Eg- 
	`Project("Tutorial" VERSION 1.0)` 

3. Add an executable to the project using the specified source files. 
	`add_executable(<name> <options>... <sources>...)` 
	Eg- 
		`add_executable(Tutorial tutorial.cxx)`

4. We will need to explicitly state in the Cmake code that it should use the correct flags. We can achieve this by set is use tor create variable. 
	In these case two variable are project variable. 
```CMake
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)
```
5. Copy a file to another location and modify its contents. 
	`configure_file(<input> <output>)`
	Eg.- 
	`configure_file(TutorialConfig.h.in TutorialConfig.h)`
```CMake
configure_file(CMAKE_CURRENT_SOURCE_DIR CMAKE_CURRENT_BINARY_DIR)
```
6. We used [target_include_directories()](https://cmake.org/cmake/help/latest/command/target_include_directories.html#command:target_include_directories) to specify where the executable target should look for include files. 
```CMake
target_include_directories(Tutorial  
				PUBLIC                
				"${PROJECT_BINARY_DIR}" 
				 "${PROJECT_SOURCE_DIR}/MathFunctions" 
              )
```
7. set up before the project() line in CMakeLists.txt: 
```CMake
set( CMAKE_CXX_COMPILER "/pathto/g++" ) 
set( CMAKE_C_COMPILER "/pathto/gcc" ) 

project(mytest) ...
```
