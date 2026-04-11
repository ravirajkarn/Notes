---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-12-31 11:56::19 AM
tags:
  - Conan
  - python
---

# FAAD2 recipe
```python
import os
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout
from conan.tools.files import get, copy, rmdir

class Faad2Recipe(ConanFile):
    name = "faad2"
    version = "2.11.2"
    
    # Metadata
    license = "GPL-v2.0-or-later"
    url = "https://github.com/knik0/faad2"
    description = "Freeware Advanced Audio (AAC) Decoder including SBR decoding"
    topics = ("audio", "aac", "mp4", "m4a", "decoder")
    
    # Settings
    settings = "os", "compiler", "build_type", "arch"
    package_type = "library"
    
    # Options: Allow building as Shared (.so/.dll) or Static (.a/.lib)
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
    }

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")
        # FAAD2 is a C library, so we don't strictly need to enforce C++ settings,
        # but CMake will use them.

    def layout(self):
        # Standard CMake layout (src, build, etc.)
        cmake_layout(self, src_folder="src")

    def source(self):
        # Download the official release tarball
        get(self, f"https://github.com/knik0/faad2/archive/refs/tags/{self.version}.tar.gz", strip_root=True)

    def generate(self):
        tc = CMakeToolchain(self, generator="Ninja")
        # CRITICAL: We MUST build the app/frontend because that is where mp4ff lives.
        # If we set this to OFF, the mp4ff library will not be compiled.
        tc.variables["FAAD_BUILD_APP"] = "ON" 
        
        # Ensure we build shared/static based on options
        tc.variables["BUILD_SHARED_LIBS"] = self.options.shared
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
        
        # --- THE MP4FF FIX ---
        # Upstream FAAD2 installs 'libfaad' but DOES NOT install 'libmp4ff' 
        # (it considers mp4ff an internal helper).
        # We must manually copy it so you can use it in your C++ bridge.
        
        # 1. Copy mp4ff headers
        frontend_src = os.path.join(self.source_folder, "frontend")
        copy(self, "mp4ff.h", src=frontend_src, dst=os.path.join(self.package_folder, "include"))
        copy(self, "mp4ff_int_types.h", src=frontend_src, dst=os.path.join(self.package_folder, "include"))
        
        # 2. Copy mp4ff library (Location depends on OS/Build)
        # It is usually built in the 'frontend' directory of the build folder
        copy(self, "libmp4ff.a", src=os.path.join(self.build_folder, "frontend"), dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "mp4ff.lib",  src=os.path.join(self.build_folder, "frontend"), dst=os.path.join(self.package_folder, "lib"), keep_path=False)

        # Remove the 'faad' CLI executable from the package to keep it clean (we only want libs)
        rmdir(self, os.path.join(self.package_folder, "bin"))
        rmdir(self, os.path.join(self.package_folder, "share"))

    def package_info(self):
        # Define the libraries to link against.
        # Order matters! mp4ff might depend on libc, but faad is standalone.
        self.cpp_info.libs = ["faad", "mp4ff"]

        if self.settings.os in ["Linux", "FreeBSD"]:
            self.cpp_info.components["tag"].system_libs.append("m")
```
