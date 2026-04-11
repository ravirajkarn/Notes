---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-29 14:30::42 PM
tags:
  - Cpp
  - CMake
  - Conan
  - Git
---

# My own recipe
I need taglib/2.1.1. The time I am writhing, this package is not available in conan-center. So I decided to make my won recipe to build it. 

Here the code.
```python
import os
from conan import ConanFile
from conan.errors import ConanInvalidConfiguration
from conan.tools.build import stdcpp_library, check_min_cppstd
from conan.tools.cmake import CMake, CMakeToolchain, cmake_layout, CMakeDeps
from conan.tools.files import apply_conandata_patches, copy, export_conandata_patches, get, replace_in_file, rm, rmdir
from conan.tools.scm import Version
from conan.tools.microsoft import is_msvc_static_runtime
  
class TagLibRecipe(ConanFile):
	name = "taglib"
	version = "2.1.1"
	
	# Metadata
	license = ("LGPL-2.1-or-later", "MPL-1.1")
	homepage = "https://taglib.org"
	topics = ("audio", "metadata")
	url = "https://github.com/taglib/taglib"
	description = "TagLib is a library for reading and editing the metadata of several popular audio formats."
	
	# Settings: OS, Arch, Compiler (GCC 15), Debug/Release
	package_type = "library"
	settings = "os", "compiler", "build_type", "arch"
	
	# Options: Allow building as Shared (.so/.dll) or Static (.a/.lib)
	options = {
		"shared": [True, False],
		"fPIC": [True, False],
		"bindings": [True, False],
	}
	default_options = {
		"shared": False,
		"fPIC": True,
		"bindings": True,
	}
  
	@property
	def _min_cppstd(self):
		# https://github.com/taglib/taglib/blob/v2.0beta/CMakeLists.txt#L5
		return 17
	
	@property
	def _compilers_minimum_version(self):
		return {
			"Visual Studio": "16",
			"msvc": "192",
			"gcc": "7",
			"clang": "6",
			"apple-clang": "10",
		}
	  
	def config_options(self):
		if self.settings.os == "Windows":
			del self.options.fPIC
	
	def configure(self):
		if self.options.shared:
			self.options.rm_safe("fPIC")
	  
	def requirements(self):
		# TagLib needs ZLib to read compressed frames in ID3 tags
		self.requires("zlib/[>=1.3.1 <2]")
		if Version(self.version) >= 2:
			self.requires("utfcpp/4.0.4")
	
	def validate(self):
		if Version(self.version) >= 2:
			if self.settings.compiler.cppstd:
				check_min_cppstd(self, self._min_cppstd)
			minimum_version = self._compilers_minimum_version.get(str(self.settings.compiler), False)
			if minimum_version and Version(self.settings.compiler.version) < minimum_version:
				raise ConanInvalidConfiguration(
					f"{self.ref} requires C++{self._min_cppstd}, which your compiler does not support."
				)
  
	def layout(self):
		# Standard CMake layout (src, build, etc.)
		cmake_layout(self, src_folder="src")
	  
	def source(self):
		# Download the specific tarball for v2.1.1
		get(self, "https://github.com/taglib/taglib/archive/refs/tags/v2.1.1.tar.gz", strip_root=True)
	
	def generate(self):
		# Generate the toolchain to compile TagLib
		# Explicitly setting generator to Ninja
		tc = CMakeToolchain(self, generator="Ninja")
		tc.variables["BUILD_TESTING"] = False
		tc.variables["ENABLE_CCACHE"] = False
		tc.variables["VISIBILITY_HIDDEN"] = True
		tc.variables["BUILD_EXAMPLES"] = False
		tc.variables["BUILD_BINDINGS"] = self.options.bindings
		tc.variables["ENABLE_STATIC_RUNTIME"] = is_msvc_static_runtime(self)
		tc.generate()
	
		# Generate the config to find ZLib
		deps = CMakeDeps(self)
		deps.generate()
	  
	def build(self):
		cmake = CMake(self)
		cmake.configure()
		cmake.build()
	  
	def package(self):
		cmake = CMake(self)
		cmake.install()
	
	def package_info(self):
		# # Tell consumers (your Music Player) to link against 'tag' library
		# self.cpp_info.libs = ["tag"]
		# # If using the 2.x version, sometimes it requires defining this macro
		# self.cpp_info.defines = ["TAGLIB_STATIC"] if not self.options.shared else []
	
		self.cpp_info.set_property("pkg_config_name", "taglib_full_package") # unofficial, to avoid conflicts in pkg_config generator
		  
		self.cpp_info.components["tag"].set_property("pkg_config_name", "taglib")
		self.cpp_info.components["tag"].includedirs.append(os.path.join("include", "taglib"))
		self.cpp_info.components["tag"].libs = ["tag"]
		self.cpp_info.components["tag"].requires = ["zlib::zlib"]
		if Version(self.version) >= 2:
			self.cpp_info.components["tag"].requires.append("utfcpp::utfcpp")
		if not self.options.shared:
			self.cpp_info.components["tag"].defines.append("TAGLIB_STATIC")
			if self.settings.os in ["Linux", "FreeBSD"]:
				self.cpp_info.components["tag"].system_libs.append("m")
		  
		if self.options.bindings:
			self.cpp_info.components["tag_c"].set_property("pkg_config_name", "taglib_c")
			self.cpp_info.components["tag_c"].libs = ["tag_c"]
			self.cpp_info.components["tag_c"].requires = ["tag"]
			if not self.options.shared:
				libcxx = stdcpp_library(self)
				if libcxx:
					self.cpp_info.components["tag"].system_libs.append(libcxx)
```

After creating the recipe we follow a "Product-Consumer" workflow
1. **Producer:** You "Export" your recipe to your local Conan cache.
2. **Consumer:** Your main project "Requires" it from the cache.

Here are the exact steps:

### Step 1: Export the Recipe (The Producer)
``` bash
conan create . --build=missing
```
### Step 2: Update Main Project (The Consumer)

**1. Update `conanfile.py`:** Change the requirement
```python
def requirements(self):
    self.requires("taglib/2.1.1") 
```

**2. Update `CMakeLists.txt`:** Conan's default behavior, the CMake target name `taglib::taglib` (lowercase package name), not `TagLib::TagLib` (PascalCase, which is used by the system FindTagLib.cmake).
```cmake
# 1. Find the package (Conan generates taglib-config.cmake)
find_package(taglib REQUIRED)

# 2. Link it
target_link_libraries(extraction 
    PRIVATE 
    taglib::taglib  # Note: Lowercase 't' is standard for Conan generated targets
    fmt::fmt
)
```
----
# function: 
- **`get()` vs Git:** The `get()` function extracts archives. If you wanted to clone a repo, you would use `self.run("git clone ...")` or `tools.Git`, but downloading the tarball is faster and cleaner for builds.
- **`strip_root=True`:** GitHub tarballs always wrap the code in a folder (e.g., `faad2-2.11.1/`). This argument peels off that outer folder so your source code ends up right where you expect it.