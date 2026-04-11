---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-30 22:06::44 PM
tags:
  - CMake
  - Cpp
  - Conan
---

# Generator

I am currently using ninja

## Single-Config Generator
**Single-Config Generator** (like "Ninja" or "Unix Makefiles")

file structure
```
Music Player/
├── CMakeLists.txt
├── conanfile.py
├── src/
│
├── build/                       <-- Created by You/VS Code
│   │
│   ├── Debug/                   <-- The "Sandbox" for Debug mode
│   │   ├── generators/          <-- Created by CONAN
│   │   │   ├── conan_toolchain.cmake
│   │   │   ├── SQLiteCppConfig.cmake
│   │   │   └── ... other .cmake files
│   │   │
│   │   ├── CMakeCache.txt       <-- Created by CMAKE
│   │   ├── build.ninja (or Makefile)
│   │   └── music_player (The Executable)
│   │
│   └── Release/                 <-- The "Sandbox" for Release mode
│       ├── generators/          <-- Created by CONAN
│       │   ├── conan_toolchain.cmake
│       │   └── ... (Release versions of libs)
│       │
│       ├── CMakeCache.txt       <-- Created by CMAKE
│       ├── build.ninja
│       └── music_player (The Optimized Executable)
│
└── CMakeUserPresets.json        <-- Created by CONAN (at root)
```

**Conan**
```python
def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self, generator="Ninja") # or "Unix Makefiles"
        tc.generate()
```

**CMake for VSCode Setting**

**`.vscode/settings.json`**: Force VS Code to respect the `build/Type` pattern.
```JSON
{
    "cmake.generator": "Ninja",
    "cmake.buildDirectory": "${workspaceFolder}/build/${buildType}"
}
```

## Ninja Multi-Config

**The Golden Rule of Multi-Config:** You do **NOT** have separate `build/Debug` and `build/Release` folders for configuration. You have **ONE** `build` folder that contains the configuration for **BOTH**.

file structure
```
Music Player/
├── build/                       <-- ONE folder for everything
│   ├── generators/              <-- Conan puts BOTH Debug and Release info here
│   │   ├── conan_toolchain.cmake
│   │   ├── SQLiteCppConfig.cmake
│   │   └── ...
│   │
│   ├── CMakeCache.txt           <-- Shared Cache
│   ├── build.ninja              <-- The Master Ninja file
│   │
│   ├── Debug/                   <-- Binaries go here automatically
│   │   └── music_player.exe
│   │
│   └── Release/                 <-- Binaries go here automatically
│       └── music_player.exe
```

**Conan**
```python
def generate(self):
        deps = CMakeDeps(self)
        # Multi-config needs specific configuration setup per build type
        deps.configuration = str(self.settings.build_type) 
        deps.generate()
        
        # Explicitly set the generator
        tc = CMakeToolchain(self, generator="Ninja Multi-Config")
        tc.generate()
```

**CMake for VSCode Setting**

**`.vscode/settings.json`**: Force VS Code to respect the `build/Type` pattern.
```JSON
{
    "cmake.generator": "Ninja Multi-Config",
    "cmake.buildDirectory": "${workspaceFolder}/build"
}
```
