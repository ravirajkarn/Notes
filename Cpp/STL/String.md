---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T13:45:00
tags:
  - Cpp
  - STL
  - Header
  - String
---
# [string](https://en.cppreference.com/w/cpp/string/basic_string.html)
## Introduction
String store data in a sequence. Like char[10], it store 10 character from one after another. But, string can store data much more then 10 character. It assign memory automatically if we add new data. 

In the C++ standard library, a character is an object which, when treated sequentially, can represent text. 

The term means not only objects of [character types](https://en.cppreference.com/w/cpp/language/type), but also any value that can be represented by a type that provides the definitions specified in the strings library and following libraries: 
- [localization library](https://en.cppreference.com/w/cpp/locale) 
- [input/output library](https://en.cppreference.com/w/cpp/io)

# Type of string
| **Type of String** | **Definition**              |
| ------------------ | --------------------------- |
| Std::string        | Std::basic_string\<char>    |
| Std::wstring       | Std::basic_string\<wchar>   |
| Std::u8string      | Std::basic_string<char8_t>  |
| Std::u16string     | Std::basic_string<char16_t> |
| Std::u32string     | Std::basic_string<char32_t> |

## Member Function 
| [(constructor)](https://en.cppreference.com/w/cpp/string/basic_string/basic_string)            | constructs a basic_string <br>(public member function)                                  |
| ---------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| [(destructor)](https://en.cppreference.com/w/cpp/string/basic_string/%7Ebasic_string)          | destroys the string, deallocating internal storage if used <br>(public member function) |
| [operator=](https://en.cppreference.com/w/cpp/string/basic_string/operator%3D)                 | assigns values to the string <br>(public member function)                               |
| [assign](https://en.cppreference.com/w/cpp/string/basic_string/assign)                         | assign characters to a string <br>(public member function)                              |
| [assign_range](https://en.cppreference.com/w/cpp/string/basic_string/assign_range) <br>(C++23) | assign a range of characters to a string <br>(public member function)                   |
| [get_allocator](https://en.cppreference.com/w/cpp/string/basic_string/get_allocator)           | returns the associated allocator <br>(public member function)                           |

## Elements access 
| [at](https://en.cppreference.com/w/cpp/string/basic_string/at)                                                             | accesses the specified character with bounds checking <br>(public member function)                     |
| -------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------ |
| [operator[]](https://en.cppreference.com/w/cpp/string/basic_string/operator_at)                                            | accesses the specified character <br>(public member function)                                          |
| [front](https://en.cppreference.com/w/cpp/string/basic_string/front) <br>(DR*)                                             | accesses the first character <br>(public member function)                                              |
| [back](https://en.cppreference.com/w/cpp/string/basic_string/back) <br>(DR*)                                               | accesses the last character <br>(public member function)                                               |
| [data](https://en.cppreference.com/w/cpp/string/basic_string/data)                                                         | returns a pointer to the first character of a string <br>(public member function)                      |
| [c_str](https://en.cppreference.com/w/cpp/string/basic_string/c_str)                                                       | returns a non-modifiable standard C character array version of the string <br>(public member function) |
| [operator basic_string_view](https://en.cppreference.com/w/cpp/string/basic_string/operator_basic_string_view) <br>(C++17) | returns a non-modifiable string_view into the entire string <br>(public member function)               |

## Iterators 
| [begin](https://en.cppreference.com/w/cpp/string/basic_string/begin) <br>cbegin (C++11)    | returns an iterator to the beginning <br>(public member function)        |
| ------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------ |
| [end](https://en.cppreference.com/w/cpp/string/basic_string/end) <br>cend (C++11)          | returns an iterator to the end <br>(public member function)              |
| [rbegin](https://en.cppreference.com/w/cpp/string/basic_string/rbegin) <br>crbegin (C++11) | returns a reverse iterator to the beginning <br>(public member function) |
| [rend](https://en.cppreference.com/w/cpp/string/basic_string/rend) <br>crend (C++11)       | returns a reverse iterator to the end <br>(public member function)       |

## Capacity 
| [empty](https://en.cppreference.com/w/cpp/string/basic_string/empty)                          | checks whether the string is empty <br>(public member function)                                               |
| --------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| [size](https://en.cppreference.com/w/cpp/string/basic_string/size)   length                   | returns the number of characters <br>(public member function)                                                 |
| [max_size](https://en.cppreference.com/w/cpp/string/basic_string/max_size)                    | returns the maximum number of characters <br>(public member function)                                         |
| [reserve](https://en.cppreference.com/w/cpp/string/basic_string/reserve)                      | reserves storage <br>(public member function)                                                                 |
| [capacity](https://en.cppreference.com/w/cpp/string/basic_string/capacity)                    | returns the number of characters that can be held in currently allocated storage <br>(public member function) |
| [shrink_to_fit](https://en.cppreference.com/w/cpp/string/basic_string/shrink_to_fit)<br>(DR*) | reduces memory usage by freeing unused memory <br>(public member function)                                    |

## Modifier 
| [clear](https://en.cppreference.com/w/cpp/string/basic_string/clear)                                          | clears the contents <br>(public member function)                                                                                                |
| ------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| [insert](https://en.cppreference.com/w/cpp/string/basic_string/insert)                                        | inserts characters <br>(public member function)                                                                                                 |
| [insert_range](https://en.cppreference.com/w/cpp/string/basic_string/insert_range) <br>(C++23)                | inserts a range of characters <br>(public member function)                                                                                      |
| [erase](https://en.cppreference.com/w/cpp/string/basic_string/erase)                                          | removes characters <br>(public member function)                                                                                                 |
| [push_back](https://en.cppreference.com/w/cpp/string/basic_string/push_back)                                  | appends a character to the end <br>(public member function)                                                                                     |
| [pop_back](https://en.cppreference.com/w/cpp/string/basic_string/pop_back) <br>(DR*)                          | removes the last character <br>(public member function)                                                                                         |
| [append](https://en.cppreference.com/w/cpp/string/basic_string/append)                                        | appends characters to the end <br>(public member function)                                                                                      |
| [append_range](https://en.cppreference.com/w/cpp/string/basic_string/append_range) <br>(C++23)                | appends a range of characters to the end <br>(public member function)                                                                           |
| [operator+=](https://en.cppreference.com/w/cpp/string/basic_string/operator%2B%3D)                            | appends characters to the end <br>(public member function)                                                                                      |
| [replace](https://en.cppreference.com/w/cpp/string/basic_string/replace)                                      | replaces specified portion of a string <br>(public member function)                                                                             |
| [replace_with_range](https://en.cppreference.com/w/cpp/string/basic_string/replace_with_range) <br>(C++23)    | replaces specified portion of a string with a range of characters <br>(public member function)                                                  |
| [copy](https://en.cppreference.com/w/cpp/string/basic_string/copy)                                            | copies characters <br>(public member function)                                                                                                  |
| [resize](https://en.cppreference.com/w/cpp/string/basic_string/resize)                                        | changes the number of characters stored <br>(public member function)                                                                            |
| [resize_and_overwrite](https://en.cppreference.com/w/cpp/string/basic_string/resize_and_overwrite)<br>(C++23) | changes the number of characters stored and possibly overwrites indeterminate contents via user-provided operation <br>(public member function) |
| [swap](https://en.cppreference.com/w/cpp/string/basic_string/swap)                                            | swaps the contents <br>(public member function)                                                                                                 |

## Operations 
| [compare](https://en.cppreference.com/w/cpp/string/basic_string/compare)                     | compares two strings <br>(public member function)                                           |
| -------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| [starts_with](https://en.cppreference.com/w/cpp/string/basic_string/starts_with) <br>(C++20) | checks if the string starts with the given prefix <br>(public member function)              |
| [ends_with](https://en.cppreference.com/w/cpp/string/basic_string/ends_with) <br>(C++20)     | checks if the string ends with the given suffix <br>(public member function)                |
| [contains](https://en.cppreference.com/w/cpp/string/basic_string/contains) <br>(C++23)       | checks if the string contains the given substring or character <br>(public member function) |
| [substr](https://en.cppreference.com/w/cpp/string/basic_string/substr)                       | returns a substring <br>(public member function)                                            |

## Search 
| [find](https://en.cppreference.com/w/cpp/string/basic_string/find)                           | finds the first occurrence of the given substring <br>(public member function) |
| -------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| [rfind](https://en.cppreference.com/w/cpp/string/basic_string/rfind)                         | find the last occurrence of a substring <br>(public member function)           |
| [find_first_of](https://en.cppreference.com/w/cpp/string/basic_string/find_first_of)         | find first occurrence of characters <br>(public member function)               |
| [find_first_not_of](https://en.cppreference.com/w/cpp/string/basic_string/find_first_not_of) | find first absence of characters <br>(public member function)                  |
| [find_last_of](https://en.cppreference.com/w/cpp/string/basic_string/find_last_of)           | find last occurrence of characters <br>(public member function)                |
| [find_last_not_of](https://en.cppreference.com/w/cpp/string/basic_string/find_last_not_of)   | find last absence of characters <br>(public member function)                   |

## Constants 
| [npos](https://en.cppreference.com/w/cpp/string/basic_string/npos) <br>[static] | special value. The exact meaning depends on the context <br>(public static member constant) |
| ------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |

##  [Numeric Conversions](stoi.md)

| [stoi](https://en.cppreference.com/w/cpp/string/basic_string/stol) <br>(C++11) <br>[stol](https://en.cppreference.com/w/cpp/string/basic_string/stol) <br>(C++11) <br>[stoll](https://en.cppreference.com/w/cpp/string/basic_string/stol) <br>(C++11) | converts a string to a signed integer <br>(function)                   |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| [stoul](https://en.cppreference.com/w/cpp/string/basic_string/stoul) <br>(C++11) <br>[stoull](https://en.cppreference.com/w/cpp/string/basic_string/stoul) <br>(C++11)                                                                                | converts a string to an unsigned integer <br>(function)                |
| [stof](https://en.cppreference.com/w/cpp/string/basic_string/stof) <br>(C++11) <br>[stod](https://en.cppreference.com/w/cpp/string/basic_string/stof) <br>(C++11) <br>[stold](https://en.cppreference.com/w/cpp/string/basic_string/stof) <br>(C++11) | converts a string to a floating point value <br>(function)             |
| [to_string](https://en.cppreference.com/w/cpp/string/basic_string/to_string) <br>(C++11)                                                                                                                                                              | converts an integral or floating-point value to string <br>(function)  |
| [to_wstring](https://en.cppreference.com/w/cpp/string/basic_string/to_wstring) <br>(C++11)                                                                                                                                                            | converts an integral or floating-point value to wstring <br>(function) |

## Example
```Cpp
#include <iostream> 
#include <string> 

Int main(){  
	using namespace std::literals; 
	
	// Creating a string from const char* 
	std::string str1 = "hello";  
	
	 // Creating a string using string literal 
	Auto str2 = "world"s; 
	
	// Concatenating strings 
	std::string str3 =str1 +" "+str2;  
	
	// Print out the result 
	std::cout<<str3 <<'\n';  
	
	std::string::size_typepos =str3.find(" "); 
	str1 =str3.substr(pos +1); // the part after the space 
	str2 =str3.substr(0, pos);// the part till the space  
	
	std::cout<<str1 <<' '<<str2 <<'\n'; 
	
	// Accessing an element using subscript operator[] 
	std::cout<<str1[0]<<'\n'; 
	str1[0]='W'; 
	std::cout<<str1 <<'\n'; 
}
```

