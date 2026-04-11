---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-07-05T12:22:00
tags:
  - Set
  - Container
  - Cpp
  - STL
  - Header
---
# [\#include\<set>](https://en.cppreference.com/w/cpp/header/set) 
Defined in \#include \<set\> 
std::set\<char\> variable;

std::set ensures that only unique variables (no repetition allowed) are stored, so duplicates are automatically handled, and data are stored in order i.e. ascending or descending order.

## Member function  
| [(constructor)](https://en.cppreference.com/w/cpp/container/set/set)           | constructs the set <br>(public member function)               |
| ------------------------------------------------------------------------------ | ------------------------------------------------------------- |
| [(destructor)](https://en.cppreference.com/w/cpp/container/set/%7Eset)         | destructs the set <br>(public member function)                |
| [operator=](https://en.cppreference.com/w/cpp/container/set/operator%3D)       | assigns values to the container <br>(public member function)  |
| [get_allocator](https://en.cppreference.com/w/cpp/container/set/get_allocator) | returns the associated allocator <br>(public member function) |

## Iterators 
| [begin](https://en.cppreference.com/w/cpp/container/set/begin) <br>[cbegin](https://en.cppreference.com/w/cpp/container/set/begin) <br>(C++11)     | returns an iterator to the beginning <br>(public member function)        | 1, 2, 3, 4, 5 |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------ | ------------- |
| [end](https://en.cppreference.com/w/cpp/container/set/end) <br>[cend](https://en.cppreference.com/w/cpp/container/set/end) <br>(C++11)             | returns an iterator to the end <br>(public member function)              | 1, 2, 3, 4, 5 |
| [rbegin](https://en.cppreference.com/w/cpp/container/set/rbegin) <br>[crbegin](https://en.cppreference.com/w/cpp/container/set/rbegin) <br>(C++11) | returns a reverse iterator to the beginning <br>(public member function) | 1, 2, 3, 4, 5 |
| [rend](https://en.cppreference.com/w/cpp/container/set/rend) <br>[crend](https://en.cppreference.com/w/cpp/container/set/rend) <br>(C++11)         | returns a reverse iterator to the end <br>(public member function)       | 1, 2, 3, 4, 5 |

## Capacity 
| [empty](https://en.cppreference.com/w/cpp/container/set/empty)       | checks whether the container is empty <br>(public member function)           |
| -------------------------------------------------------------------- | ---------------------------------------------------------------------------- |
| [size](https://en.cppreference.com/w/cpp/container/set/size)         | returns the number of elements <br>(public member function)                  |
| [max_size](https://en.cppreference.com/w/cpp/container/set/max_size) | returns the maximum possible number of elements <br>(public member function) |

## Modifiers 
| [clear](https://en.cppreference.com/w/cpp/container/set/clear)                           | clears the contents <br>(public member function)                       |
| ---------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| [insert](https://en.cppreference.com/w/cpp/container/set/insert)                         | inserts elements or nodes(since C++17) <br>(public member function)    |
| [insert_range](https://en.cppreference.com/w/cpp/container/set/insert_range) <br>(C++23) | inserts a range of elements <br>(public member function)               |
| [emplace](https://en.cppreference.com/w/cpp/container/set/emplace) <br>(C++11)           | constructs element in-place <br>(public member function)               |
| [emplace_hint](https://en.cppreference.com/w/cpp/container/set/emplace_hint) <br>(C++11) | constructs elements in-place using a hint <br>(public member function) |
| [erase](https://en.cppreference.com/w/cpp/container/set/erase)                           | erases elements <br>(public member function)                           |
| [swap](https://en.cppreference.com/w/cpp/container/set/swap)                             | swaps the contents <br>(public member function)                        |
| [extract](https://en.cppreference.com/w/cpp/container/set/extract) <br>(C++17)           | extracts nodes from the container <br>(public member function)         |
| [merge](https://en.cppreference.com/w/cpp/container/set/merge) <br>(C++17)               | splices nodes from another container <br>(public member function)      |

## Lookup 
| [count](https://en.cppreference.com/w/cpp/container/set/count)                   | returns the number of elements matching specific key <br>(public member function)                 |
| -------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- |
| [find](https://en.cppreference.com/w/cpp/container/set/find)                     | finds element with specific key <br>(public member function)                                      |
| [contains](https://en.cppreference.com/w/cpp/container/set/contains) <br>(C++20) | checks if the container contains element with specific key <br>(public member function)           |
| [equal_range](https://en.cppreference.com/w/cpp/container/set/equal_range)       | returns range of elements matching a specific key <br>(public member function)                    |
| [lower_bound](https://en.cppreference.com/w/cpp/container/set/lower_bound)       | returns an iterator to the first element not less than the given key <br>(public member function) |
| [upper_bound](https://en.cppreference.com/w/cpp/container/set/upper_bound)       | returns an iterator to the first element greater than the given key <br>(public member function)  |

## Observers 
| [key_comp](https://en.cppreference.com/w/cpp/container/set/key_comp)     | returns the function that compares keys <br>(public member function)                               |
| ------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------- |
| [value_comp](https://en.cppreference.com/w/cpp/container/set/value_comp) | returns the function that compares keys in objects of type value_type <br>(public member function) |