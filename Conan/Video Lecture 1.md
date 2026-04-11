---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-08-22T01:57:00
tags:
  - Conan
---
<iframe width="560" height="315" src="https://www.youtube.com/embed/xBLjXdyh3zs?si=gdrcpS13l1kD_8El" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# Introduction
- Conan is a package manager. 
- Conan file is save as "conanfile.txt" & "conanfile.by". 
- Conanfile.py is new version. 
- Conanfile.txt is old version.

# Installation
## Windows
### Terminal
```Powershell
winget install -e --id JFrog.Conan
```
### Executable file
Download the conan executable file and run it as administrator.
https://conan.io/downloads

## Linux
### Debian
```Bash
sudo apt-get install conan
```
# Prerequisites to run conan  
- You need to setup a conan profile once for every system. 
```Bash
conan profile detect --force
```

- To install the dependency in your current project.  
	```Bash
	conan install . --output-folder=build --build=missing
	```
	- --output-folder=build : This will redirect all the files created and required by the project in build folder in your current project. 
	- --build=missing : This is required to build missing files or dependency for your project. 

- See Dependency Graph 
    ```Bash
    conan info ..
	```

- To integrate it with CMake you need to do this 
![Cmake Conan integration](Cmake%20Conan%20integration.png)

# conanfile.txt 

- Conanfile.txt is similar to .ini file windows. 
```
[requires] 
zlib/1.2.11 

[generators] 
CMakeDeps 
CMakeToolchain
```
- [requires] section is where we declare the libraries we want to use in the project, in this case, zlib/1.2.11. 
- [generators] section tells Conan to generate the files that the compilers or build systems will use to find the dependencies and build the project. In this case, as our project is based in CMake, we will use [CMakeDeps](https://docs.conan.io/2/reference/tools/cmake/cmakedeps.html#conan-tools-cmakedeps) to generate information about where the Zlib library files are installed and [CMakeToolchain](https://docs.conan.io/2/reference/tools/cmake/cmaketoolchain.html#conan-tools-cmaketoolchain) to pass build information to CMake using a CMake toolchain file.


# conanfile.py
![conanfile.py](Conanfile.png)
- to creating this as a recipe you need to export it in your local cache.     
```Bash
conan export path 
```

- To search conan recipe. 
```Bash
conan search 
```

- To build the program 
	```Bash
	conan install path 
	```
	- This build the program from the recipe if the binaries are available. 
	- If you don't have the binaries you need to build the binaries. 
```Bash
 conan install path --build=missing  
````

- To remove all the package from the from the path $ 
```Bash
conan remove "*" -f
```