---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-02-22 02:36::07 AM
tags:
  - Library
  - include
  - Cpp
  - STL
---
# [\#include\<print>](https://en.cppreference.com/w/cpp/io/print.html)
|                                                                                                                                                                                                                                                |                                                                                                                                                                                                                                                                                                                 |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Functions                                                                                                                                                                                                                                      |                                                                                                                                                                                                                                                                                                                 |
| [print](https://en.cppreference.com/w/cpp/io/print.html "cpp/io/print")<br><br>(C++23)                                                                                                                                                         | prints to [stdout](https://en.cppreference.com/w/cpp/io/c/std_streams.html "cpp/io/c/std streams") or a file stream using [formatted](https://en.cppreference.com/w/cpp/utility/format.html "cpp/utility/format") representation of the arguments  <br>(function template)                                      |
| [println](https://en.cppreference.com/w/cpp/io/println.html "cpp/io/println")<br><br>(C++23)                                                                                                                                                   | same as std::print except that each print is terminated by additional new line  <br>(function template)                                                                                                                                                                                                         |
| [vprint_unicode](https://en.cppreference.com/w/cpp/io/vprint_unicode.html "cpp/io/vprint unicode")<br>[vprint_unicode_buffered](https://en.cppreference.com/w/cpp/io/vprint_unicode.html "cpp/io/vprint unicode")<br>(C++23)                   | prints to Unicode capable [stdout](https://en.cppreference.com/w/cpp/io/c/std_streams.html "cpp/io/c/std streams") or a file stream using [type-erased](https://en.cppreference.com/w/cpp/utility/format/basic_format_args.html "cpp/utility/format/basic format args") argument representation  <br>(function) |
| [vprint_nonunicode](https://en.cppreference.com/w/cpp/io/vprint_nonunicode.html "cpp/io/vprint nonunicode")<br>[vprint_nonunicode_buffered](https://en.cppreference.com/w/cpp/io/vprint_nonunicode.html "cpp/io/vprint nonunicode")<br>(C++23) | prints to [stdout](https://en.cppreference.com/w/cpp/io/c/std_streams.html "cpp/io/c/std streams") or a file stream using [type-erased](https://en.cppreference.com/w/cpp/utility/format/basic_format_args.html "cpp/utility/format/basic format args") argument representation  <br>(function)                 |

---
## std::print
```cpp
template< class... Args >  
void print( std::format_string<Args...> fmt, Args&&... args );
```

```cpp
template< class... Args >  
void print( std::FILE* stream,  
            std::format_string<Args...> fmt, Args&&... args );
```

> [!example] 
> ```cpp
> #include <cstdio>
> #include <filesystem>
> #include <print> 
> int main()
> {
> 	std::print("{2} {1}{0}!\n", 23, "C++", "Hello");  // overload (1)
> 	
> 	const auto tmp{std::filesystem::temp_directory_path() / "test.txt"};
> 	if (std::FILE* stream{std::fopen(tmp.c_str(), "w")})
> 	{
> 		std::print(stream, "File: {}", tmp.string()); // overload (2)
> 		std::fclose(stream);
> 	}
> }
> ```

