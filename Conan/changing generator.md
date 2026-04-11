---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-24 17:43::44 PM
tags:
  - Conan
  - Cpp
---

# Changing Generator

## Method 1:
make changes in profile

Example:
for Ninja:
```conan 
[conf]
tools.cmake.cmaketoolchain:generator=Ninja
```

for Conan
```conan
[conf]
tools.cmake.cmaketoolchain:generator=Unix Makefiles
```

## Method 2:
make changes in conanfile.py

Example:
```python
from conan import ConanFile
from conan.tools.cmake import CMakeToolchain

class App(ConanFile):
    settings = "os", "compiler", "build_type", "arch"

    def generate(self):
        tc = CMakeToolchain(self, generator="Ninja")
        tc.generate()
```

## Method 3:
changing Environment Variables

```bash
# On Linux/macOS
export CMAKE_GENERATOR=Ninja
conan install .

# On Windows (Command Prompt)
set CMAKE_GENERATOR=Ninja
conan install .
```