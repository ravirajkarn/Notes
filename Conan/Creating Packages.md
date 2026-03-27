---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-03-06 01:28::04 AM
tags:
  - Conan
  - Package-manager
---
# Creating Packages 
- **`source()` :** method to retrieve sources from external repositories and apply patches to those sources.
- **`requirements()` :** Add requirements to your Conan packages inside.
- **`generate()` :** method to prepare the package build, and customize the toolchain.
- Configure settings and options in the **`configure()`** and **`config_options()`** methods and how they affect the packages’ binary compatibility.
- Use the **`build()`** method to customize the build process and launch the tests for the library you are packaging.
- Select which files will be included in the Conan package using the **`package()`** method.
- Define the package information in the **`package_info()`** method so that consumers of this package can use it.
- Use a _test_package_ to test that the Conan package can be consumed correctly.


---
## Handle sources in packages

### Sources from a _zip_ file stored in a remote repository
```python 
def source(self):
    # Please, be aware that using the head of the branch instead of an immutable tag
    # or commit is strongly discouraged, unsupported by Conan and likely to cause issues
    get(self, "https://github.com/conan-io/libhello/archive/refs/heads/main.zip",
              strip_root=True)
```

### Sources from a branch in a _git_ repository
```python 
...
from conan.tools.scm import Git

class helloRecipe(ConanFile):
    name = "hello"
    version = "1.0"
    
    ...
    
    def source(self):
        git = Git(self)
        git.clone(url="https://github.com/conan-io/libhello.git", target=".")
	    git.checkout("<tag> or <commit hash>")
...
```

### Using the conandata.yml file
```yml
sources:
  "1.0":
    url: "https://github.com/conan-io/libhello/archive/refs/heads/main.zip"
    sha256: "7bc71c682895758a996ccf33b70b91611f51252832b01ef3b4675371510ee466"
    strip_root: true
  "1.1":
    url: ...
    sha256: ...
```

```python
def source(self):
    get(self, **self.conan_data["sources"][self.version])
    # Equivalent to:
    # data = self.conan_data["sources"][self.version]
    # get(self, data["url"], sha256=data["sha256"], strip_root=data["strip_root"])
```


----
## Add dependencies to packages
```python
...
from conan.tools.build import check_max_cppstd, check_min_cppstd
...

class helloRecipe(ConanFile):
    name = "hello"
    version = "1.0"
    
    ...
    generators = "CMakeDeps"
    ...
    
    def validate(self):
        check_min_cppstd(self, "11")
        check_max_cppstd(self, "20")
        
    def requirements(self):
        self.requires("fmt/8.1.1")
        
    def source(self):
        git = Git(self)
        git.clone(url="https://github.com/conan-io/libhello.git", target=".")
        # Please, be aware that using the head of the branch instead of an immutable tag
        # or commit is not a good practice in general
        git.checkout("require_fmt")
```

### Headers transitivity

By default, Conan assumes that the required dependency headers are an implementation detail of the current package, to promote good software engineering practices like low coupling and encapsulation. In the example above, `fmt` is purely an implementation detail in the `hello/1.0` package. Consumers of `hello/1.0` will not know anything about `fmt`, or has access to its headers, if a consumer of `hello/1.0` would try to add a `#include <fmt/color.h>`, it will fail, not being able to find that headers.

But if the public headers of the `hello/1.0` package have the `#include` to `fmt` headers, that means that such headers must be propagated down to allow consumers of `hello/1.0` to be compiled successfully. As this is not the default expected behaviour, recipes must declare it as:

```python
class helloRecipe(ConanFile):
    name = "hello"
    version = "1.0"
    
    def requirements(self):
        self.requires("fmt/8.1.1", transitive_headers=True)
```


---
## Preparing the build
You will notice some changes in the conanfile.py file from the previous recipe. Let’s check the relevant parts:

```python
...
from conan.tools.build import check_max_cppstd, check_min_cppstd
...

class helloRecipe(ConanFile):
    name = "hello"
    version = "1.0"
    
    ...
    options = {"shared": [True, False],
               "fPIC": [True, False],
               "with_fmt": [True, False]}
    default_options = {"shared": False,
                       "fPIC": True,
                       "with_fmt": True}    
    ...
    def validate(self):
        if self.options.with_fmt:            
	        check_min_cppstd(self, "11")
            check_max_cppstd(self, "14")
            
    def source(self):
        git = Git(self)
        git.clone(url="https://github.com/conan-io/libhello.git", target=".")
        # Please, be aware that using the head of the branch instead of an immutable tag
        # or commit is not a good practice in general
        git.checkout("optional_fmt")
    def requirements(self):
        if self.options.with_fmt:            
	        self.requires("fmt/8.1.1")
	        
    def generate(self):
        tc = CMakeToolchain(self)
        if self.options.with_fmt:            
	        tc.variables["WITH_FMT"] = True
        tc.generate()
        
    ...
```
As you can see:

- We declare a new `with_fmt` option with the default value set to `True`.
- Based on the value of the `with_fmt` option:
    
     - We conditionally install the `fmt/8.1.1` Conan package.
     - We conditionally require a minimum and a maximum C++ standard as the _fmt_ library requires at least C++11 and it will not compile if we try to use a standard above C++14 (just an example, _fmt_ can actually build with more modern standards).
     - We conditionally inject the `WITH_FMT` variable with the value `True` to the [CMakeToolchain](https://docs.conan.io/2/reference/tools/cmake/cmaketoolchain.html#conan-tools-cmaketoolchain) so that we can use it in the _CMakeLists.txt_ of the **hello** library to add the CMake **fmt::fmt** target.
- We are cloning another branch of the library. The _optional_fmt_ branch contains some changes in the code. Let’s see what changed on the CMake side:

```CMakeList.txt
cmake_minimum_required(VERSION 3.15)
project(hello CXX)

add_library(hello src/hello.cpp)
target_include_directories(hello PUBLIC include)
set_target_properties(hello PROPERTIES PUBLIC_HEADER "include/hello.h")

if (WITH_FMT)
    find_package(fmt)    target_link_libraries(hello fmt::fmt)    target_compile_definitions(hello PRIVATE USING_FMT=1)
endif()
install(TARGETS hello)
```

As you can see, we use the `WITH_FMT` we injected in the CMakeToolchain. Depending on the value we will try to find the fmt library and link our hello library with it. Also, check that we add the `USING_FMT=1` compile definition that we use in the source code depending on whether we choose to add support for `fmt` or not.