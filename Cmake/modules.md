---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-05-03 17:52::27 PM
tags:
  - CMake
---
# FILE_SET
# [[Compiler/Module|Modules]] in cmake
CMake>3.23
> [!quote] CXX_SCAN_FOR_MODULES
> Ii scan whole modules/units and decide which will compile first.
> CXX_SCAN_FOR_MODULES ON
> CXX_SCAN_FOR_MODULES OFF

```CMake
add_library(Eigen INTERFACE)
  
target_sources(Eigen INTERFACE
	FILE_SET HEADER
	BASE_DIRS src
	FILE src/eigen.h src/vector.h src/matrix.h
)

Install(TARGET Eigen EXPORT Eigen EXPORT
	FILE_SET HEADERS DESTINATION include/Eigen
)
install(EXPORT Eigen EXPORT NAMESPACE Upstream::
	DESTINATION lib/cmake/Eigen
)

add_executable(exe1 exe1.cpp)
target_link_libraries(exe1 Eigen)
```