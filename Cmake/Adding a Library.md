---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2034-06-16T00:25:00
tags:
  - CMake
  - Library
---

We can configure our library separately with CMakeList.txt in the directory. 

We can create variable with option().
- The first step is to add an option to MathFunctions/CMakeLists.txt. This option will be displayed in the [cmake-gui](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui\(1\)) and [ccmake](https://cmake.org/cmake/help/latest/manual/ccmake.1.html#manual:ccmake\(1\)) with a default value of ON that can be changed by the user. 
	TODO 7: MathFunctions/CMakeLists.txt 
`option(USE_MYMATH "Use tutorial provided math implementation" ON)`

- Next, make building and linking our library with mysqrt function conditional using this new option. 

	- Create an [if()](https://cmake.org/cmake/help/latest/command/if.html#command:if) statement which checks the value of USE_MYMATH. 
	- Inside the [if()](https://cmake.org/cmake/help/latest/command/if.html#command:if) block, put 
	- the [target_compile_definitions()](https://cmake.org/cmake/help/latest/command/target_compile_definitions.html#command:target_compile_definitions) command with the compile definition USE_MYMATH. 

TODO 8: MathFunctions/CMakeLists.txt 
```CMake
if(USE_MYMATH)   
	target_compile_definitions(MathFunctions 
						PRIVATE
						"USE_MYMATH"
	) 
endif() 
```

When USE_MYMATH is ON, the compile definition USE_MYMATH will be set. We can then use this compile definition to enable or disable sections of our source code. 

The corresponding changes to the source code are fairly straightforward. In MathFunctions.cxx, we make USE_MYMATH control which square root function is used: 

TODO 9: MathFunctions/MathFunctions.cxx 
```CPP
#ifdef USE_MYMATH   
	return detail::mysqrt(x); 
#else   
	return std::sqrt(x); 
#endif
```

Now let's update the value of USE_MYMATH to OFF. The easiest way is to use the [cmake-gui](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui\(1\)) or [ccmake](https://cmake.org/cmake/help/latest/manual/ccmake.1.html#manual:ccmake\(1\)) if you're in the terminal. Or, alternatively, if you want to change the option from the command-line, try: 
`cmake ../Step2 -DUSE_MYMATH=OFF`

## Library's CMakeList.txt

1. Add a library to the project using the specified source files. 
	`add_library(<name> [<type>] [EXCLUDE_FROM_ALL] <sources>...)`
	Eg.- 
		`add_library(MathFunctions MathFunctions.cxx)`

2. Provide a boolean option that the user can optionally select. 
	`option(<variable> "<help_text>" [value])`
	Eg.-  
	`option(USE_MYMATH "Use tutorial provided math implementation" ON)`

3. Conditionally execute a group of commands. 
```CMake
if(<condition>) 

<commands> 

elseif(<condition>) # optional block, can be repeated 

<commands> 

else() # optional block 

<commands> 

endif() 
```
Eg.- 
```
if(USE_MYMATHS) 

    target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")     

endif() 
```

4. Add compile definitions to a target. 
    
```
target_compile_definitions(<target> 
 <INTERFACE|PUBLIC|PRIVATE> [items1...] 
 [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...]) 
```
Eg.- 
	`target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")`

5. Specify libraries or flags to use when linking a given target and/or     its dependent. 
	`target_link_libraries(<target> ... <item>... ...)`
	Eg.- 
		`target_link_libraries(MathFunctions PRIVATE SqrtLibrary)`

## CMakeFile.txt 

1. Add a subdirectory to the build. 
	`add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL] [SYSTEM])`
	Eg.- 
		`add_subdirectory(MathFunctions)`

2. Specify libraries or flags to use when linking a given target and/or its dependents. 
	`target_link_libraries(<target> ... <item>... ...)`
	Eg.- 
		`target_link_libraries(MathFunctions PRIVATE SqrtLibrary)`