---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-14 14:03::16 PM
tags:
  - xml
  - CMake
  - Cpp
---
# Linking Resource
## 1. Copying the File to the Build Directory(Best for Development)

```CMake
# Copies config.xml from your source directory to the build directory
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/config.xml"
    "${CMAKE_CURRENT_BINARY_DIR}/config.xml"
    COPYONLY
)
```

## 2. Using a Post-Build Event(Best for Assets)
- Assets that change frequently
- This ensures that every time you compile your code, The code is copied to the output folder.
```CMake
add_executable(MyProject main.cpp)

# Copy the file after the build completes
add_custom_command(TARGET MyProject POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_SOURCE_DIR}/config.xml"
        "$<TARGET_FILE_DIR:MyProject>/config.xml"
    COMMENT "Copying XML resource to build directory"
)
```

## 3. Embedding the XML into the Binary (Advanced)
- If you want a single executable file with no external dependencies.

```CMake
file(READ "config.xml" XML_CONTENTS)
# This creates a header file with the XML string inside it
configure_file(config.hpp.in config.hpp)
```

and In `config.hpp.in` template:
```cpp
const char* my_xml_data = R"(@XML_CONTENTS@)";
```

## 4. The Installation Step(For Distribution)
```CMake
install(TARGETS MyProject DESTINATION bin)
install(FILES config.xml DESTINATION bin)
```
