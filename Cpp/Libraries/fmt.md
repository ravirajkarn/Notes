---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - Cpp
  - fmt
  - Library
---
# \#include\<fmt>

## Description:  

{fmt} is an open-source formatting library providing a fast and safe alternative to C stdio and C++ iostreams. 

Library Link: [https://github.com/fmtlib/fmt.git](https://github.com/fmtlib/fmt.git)

## CMakeLists.txt
```Cmake
cmake_minimum_required(VERSION 3.10) 
project(Demo1 VERSION 0.0) 

# creating executable file. 
add_executable(Demo1 Demo1.cpp) 

# linking fmt libraries. 
find_package(fmt) 
target_link_libraries(Demo1 PRIVATE fmt::fmt)
```

## Reference
Very good explanation of member function is available in [{fmt} Formatting & Printing C++ Library | hacking C++ (hackingcpp.com)](https://hackingcpp.com/cpp/libs/fmt.html)

The `fmt` library (libfmt) is a C++ formatting library, primarily designed for **output** (like `printf` or C++ iostreams). It focuses on efficiently formatting data into strings or directly to output streams. 

## log with fmt
**`fmt` itself does not have direct mechanisms for "flushing input."** The concept of "flushing input" usually applies to the standard input stream (`std::cin` in C++ or `stdin` in C). This is because input streams are often buffered by the operating system or the C++ standard library. When you read input, it's often read in blocks, and if you read less than a full line or have leftover characters (like the newline character after pressing Enter), those characters remain in the input buffer, potentially affecting subsequent input operations. 

**If you're using `fmt` for output and you want to ensure that the output is immediately written to the console (or file), you'll need to flush the underlying output stream.** 

Here's how you can do it: 

1.  **When using `fmt::print` to `stdout` or `stderr`:** 

    `fmt::print` by default writes to `stdout` (or `stderr` if you specify it as the first argument). These are C-style file streams. To flush them, you'd use the C standard library function `fflush`. 
```Cpp
#include <fmt/core.h> // For fmt::print 
#include <cstdio>     // For fflush 

int main() { 
	fmt::print("This message might be buffered."); 
	fflush(stdout); // Explicitly flush stdout 
	fmt::print("This message will also be flushed immediately.\n"); // Newline often flushes too 
	fflush(stdout);  
	return 0; 
} 
```

* `fflush(stdout);`: Flushes the standard output buffer. 
* `fflush(stderr);`: Flushes the standard error buffer. Error streams are often unbuffered or line-buffered by default, meaning they might flush more frequently anyway. 

2.  **When using `fmt::format` and then printing to `std::cout`:** 
    If you're using `fmt::format` to create a string, and then printing that string using `std::cout`, you'll use `std::flush` or `std::endl` (which also flushes) with `std::cout`. 

```Cpp
#include <fmt/core.h>    // For fmt::format 
#include <iostream>      // For std::cout, std::flush, std::endl 
#include <string> 

int main() { 
	std::string formatted_message = fmt::format("The answer is {}.", 42); 
	std::cout << formatted_message << std::flush; // Flush immediately 
	std::cout << fmt::format("Another message and a newline with flush.\n") << std::endl; // Newline and flush 
	return 0; 
} 
```

* `std::cout << ... << std::flush;`: Flushes the `std::cout` stream. 
* `std::cout << ... << std::endl;`: Inserts a newline character and then flushes the `std::cout` stream. 

3.  **Turning off buffering for `stdout` (less common but possible):** 
    You can completely turn off buffering for `stdout` using `setvbuf` (or `setbuf`). This means every character written to `stdout` will be written immediately without being buffered. 
```Cpp
#include <fmt/core.h> 
#include <cstdio> // For setvbuf, _IONBF 

int main() { 
	// Turn off buffering for stdout 
	setvbuf(stdout, nullptr, _IONBF, 0); 
	 
	fmt::print("This will print immediately because stdout is unbuffered.\n"); 
	fmt::print("And so will this, without explicit fflush.\n"); 
	return 0; 
} 
```
   * `setvbuf(stdout, nullptr, _IONBF, 0);`: Sets `stdout` to be unbuffered. `_IONBF` stands for "input/output no buffer". 

**In summary, `fmt` is an output formatting library. To "flush input," you're actually dealing with the underlying input stream (`std::cin` or `stdin`). To flush `fmt`'s *output*, you flush the stream it's writing to (typically `stdout` or `std::cout`) using `fflush` or `std::flush`/`std::endl`.**