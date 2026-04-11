---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-14T19:38:00
tags:
  - CMake
  - cross-platform
---
For large project ninja makefile is best and faster. So I will switch to ninja  
```Shell
sudo apt install ninja-build 
```

This will install ninja makefiles. 

## Making windows application from Linux. 
- Compiler needed x86_64-w64-mingw32-gcc, x86_64-w64-mingw32-g++  
- Make toolchain-mingw64.cmake
```sh
# toolchain-mingw64.cmake 
	set(CMAKE_SYSTEM_NAME Windows) 
	set(CMAKE_SYSTEM_PROCESSOR x86_64) 

  
# Specify the cross compiler 
	set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc) 
	set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++) 
# Optionally, of you have resource files(.rc) 
	set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres) 


# Adjust the default behavior of the find commands: 
# Search headers and libraries in the target environment 
	set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY) 
	set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY) 
# Search programs in the build environment (e.g., CMake itself, utilities) 
	set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
```

- `cmake -G "Ninja Multi-Config" -DCMAKE_TOOLCHAIN_FILE=./toolchain-mingw64.cmake -S . -B ./build_windows` 
-  `cmake --build  -S ./build_windows --config Debug`


-CMakeUserPresets.json
```json
{
    "version": 4,
    "vendor": {
        "conan": {}
    },
    "include": [
        "build/Release/generators/CMakePresets.json"
    ],
    "configurePresets": [
        {
            "name": "default-config",
             "generator": "Ninja"
        }
    ]
}
```