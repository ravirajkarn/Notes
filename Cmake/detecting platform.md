---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-21 20:18::25 PM
tags:
  - CMake
  - Cpp
  - Linux
  - windows
---
```cmake
if(WIN32)
    message(STATUS "System is Windows")
    # Add Windows-specific sources or definitions
    add_definitions(-DTARGET_OS_WINDOWS)

elseif(UNIX AND NOT APPLE)
    message(STATUS "System is Linux (or Unix-like, excluding macOS)")
    # Add Linux-specific sources
    add_definitions(-DTARGET_OS_LINUX)

elseif(APPLE)
    message(STATUS "System is macOS")

else()
    message(WARNING "System is unknown")
endif()
```

