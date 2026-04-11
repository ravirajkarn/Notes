---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-08-21T04:41:00
tags:
  - CMake
  - Generators
---
# Generators: single-configurations and multi-configurations.

There are two types of generators: single-configurations and multi-configurations. 

yes, you can. Just define [CMAKE_CONFIGURATION_TYPES](http://www.cmake.org/cmake/help/latest/variable/CMAKE_CONFIGURATION_TYPES.html): 
```CMake
# Somewhere in CMakeLists.txt 
message("Generated with config types: ${CMAKE_CONFIGURATION_TYPES}")
```

Default output: 
```Shell
-- Detecting CXX compiler ABI info - done 
Generated with config types: Debug;Release;MinSizeRel;RelWithDebInfo -
-- Configuring done
```

Rewrite it: 
```Shell
cmake -H. -B_builds -DCMAKE_CONFIGURATION_TYPES="Debug;Release" "-GVisual Studio 12 2013 Win64" 
-- Detecting CXX compiler ABI info - done Generated with config types: Debug;Release 
-- Configuring done
```

You can even define your own configuration type: 
```Shell
cmake -H. -B_builds -DCMAKE_CONFIGURATION_TYPES="Debug;MyRelease" -DCMAKE_CXX_FLAGS_MYRELEASE="/My-Rel-flag" -DCMAKE_EXE_LINKER_FLAGS_MYRELEASE="/My-Linker-flags" "-GVisual Studio 12 2013 Win64"
```

And build: 
```Shell
cmake --build _builds --config MyRelease
```