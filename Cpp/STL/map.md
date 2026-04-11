---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - map
  - STL
  - Header
  - Cpp
---
# [\#include \<map>](https://en.cppreference.com/w/cpp/header/map)

## Introduction
- is container which store data using Red-Black Tree, which maintains key in shored order based on a comparison function.  
- By Default  the data is stored in ascending to descending. 
- Time complexity O(log n). 
- It is bit slower then unordered_map 

## Member classes 
| [value_compare](https://en.cppreference.com/w/cpp/container/map/value_compare) | compares objects of type value_type <br>(class) |
| ------------------------------------------------------------------------------ | ----------------------------------------------- |

## Member functions 
| [(constructor)](https://en.cppreference.com/w/cpp/container/map/map)                                 | constructs the map <br>(public member function)                                                             |
| ---------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- |
| [(destructor)](https://en.cppreference.com/w/cpp/container/map/%7Emap)                               | destructs the map <br>(public member function)                                                              |
| [operator=](https://en.cppreference.com/w/cpp/container/map/operator%3D)                             | assigns values to the container <br>(public member function)                                                |
| [get_allocator](https://en.cppreference.com/w/cpp/container/map/get_allocator)                       | returns the associated allocator <br>(public member function)                                               |
| Element access                                                                                       |                                                                                                             |
| [at](https://en.cppreference.com/w/cpp/container/map/at)                                             | access specified element with bounds checking <br>(public member function)                                  |
| [operator[]](https://en.cppreference.com/w/cpp/container/map/operator_at)                            | access or insert specified element <br>(public member function)                                             |
| Iterators                                                                                            |                                                                                                             |
| [begincbegin](https://en.cppreference.com/w/cpp/container/map/begin) <br>(C++11)                     | returns an iterator to the beginning <br>(public member function)                                           |
| [endcend](https://en.cppreference.com/w/cpp/container/map/end) <br>(C++11)                           | returns an iterator to the end <br>(public member function)                                                 |
| [rbegincrbegin](https://en.cppreference.com/w/cpp/container/map/rbegin) <br>(C++11)                  | returns a reverse iterator to the beginning <br>(public member function)                                    |
| [rendcrend](https://en.cppreference.com/w/cpp/container/map/rend) <br><br>(C++11)                    | returns a reverse iterator to the end <br>(public member function)                                          |
| Capacity                                                                                             |                                                                                                             |
| [empty](https://en.cppreference.com/w/cpp/container/map/empty)                                       | checks whether the container is empty <br>(public member function)                                          |
| [size](https://en.cppreference.com/w/cpp/container/map/size)                                         | returns the number of elements <br>(public member function)                                                 |
| [max_size](https://en.cppreference.com/w/cpp/container/map/max_size)                                 | returns the maximum possible number of elements <br>(public member function)                                |
| Modifiers                                                                                            |                                                                                                             |
| [clear](https://en.cppreference.com/w/cpp/container/map/clear)                                       | clears the contents <br>(public member function)                                                            |
| [insert](https://en.cppreference.com/w/cpp/container/map/insert)                                     | inserts elements or nodes(since C++17) <br>(public member function)                                         |
| [insert_range](https://en.cppreference.com/w/cpp/container/map/insert_range) <br>(C++23)             | inserts a range of elements <br>(public member function)                                                    |
| [insert_or_assign](https://en.cppreference.com/w/cpp/container/map/insert_or_assign) <br><br>(C++17) | inserts an element or assigns to the current element if the key already exists <br>(public member function) |
| [emplace](https://en.cppreference.com/w/cpp/container/map/emplace) <br>(C++11)                       | constructs element in-place <br>(public member function)                                                    |
| [emplace_hint](https://en.cppreference.com/w/cpp/container/map/emplace_hint) <br>(C++11)             | constructs elements in-place using a hint <br>(public member function)                                      |
| [try_emplace](https://en.cppreference.com/w/cpp/container/map/try_emplace) <br><br>(C++17)           | inserts in-place if the key does not exist, does nothing if the key exists <br>(public member function)     |
| [erase](https://en.cppreference.com/w/cpp/container/map/erase)                                       | erases elements <br>(public member function)                                                                |
| [swap](https://en.cppreference.com/w/cpp/container/map/swap)                                         | swaps the contents <br>(public member function)                                                             |
| [extract](https://en.cppreference.com/w/cpp/container/map/extract) <br>(C++17)                       | extracts nodes from the container <br>(public member function)                                              |
| [merge](https://en.cppreference.com/w/cpp/container/map/merge) <br>(C++17)                           | splices nodes from another container <br>(public member function)                                           |
| Lookup                                                                                               |                                                                                                             |
| [count](https://en.cppreference.com/w/cpp/container/map/count)                                       | returns the number of elements matching specific key <br>(public member function)                           |
| [find](https://en.cppreference.com/w/cpp/container/map/find)                                         | finds element with specific key <br>(public member function)                                                |
| [contains](https://en.cppreference.com/w/cpp/container/map/contains) <br><br>(C++20)                 | checks if the container contains element with specific key <br>(public member function)                     |
| [equal_range](https://en.cppreference.com/w/cpp/container/map/equal_range)                           | returns range of elements matching a specific key <br>(public member function)                              |
| [lower_bound](https://en.cppreference.com/w/cpp/container/map/lower_bound)                           | returns an iterator to the first element not less than the given key <br>(public member function)           |
| [upper_bound](https://en.cppreference.com/w/cpp/container/map/upper_bound)                           | returns an iterator to the first element greater than the given key <br>(public member function)            |
| Observers                                                                                            |                                                                                                             |
| [key_comp](https://en.cppreference.com/w/cpp/container/map/key_comp)                                 | returns the function that compares keys <br>(public member function)                                        |
| [value_comp](https://en.cppreference.com/w/cpp/container/map/value_comp)                             | returns the function that compares keys in objects of type value_type <br>(public member function)          |

## Non-member functions 
| [operator\==](https://en.cppreference.com/w/cpp/container/map/operator_cmp) <br>[operator<=>](https://en.cppreference.com/w/cpp/container/map/operator_cmp)(C++20) | lexicographically compares the values of two maps <br>(function template)                                       |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------- |
| [std::swap(std::map)](https://en.cppreference.com/w/cpp/container/map/swap2)                                                                                       | specializes the [std::swap](https://en.cppreference.com/w/cpp/algorithm/swap) algorithm <br>(function template) |
| [erase_if(std::map)](https://en.cppreference.com/w/cpp/container/map/erase_if) <br>(C++20)                                                                         | erases all elements satisfying specific criteria <br>(function template)                                        |

| [Deduction guides](https://en.cppreference.com/w/cpp/container/map/deduction_guides) | (since C++17) |
| ------------------------------------------------------------------------------------ | ------------- |

## Notes 
| [Feature-test](https://en.cppreference.com/w/cpp/utility/feature_test) macro                            | Value                                                                                              | Std     | Feature                                          |
| ------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------- | ------- | ------------------------------------------------ |
| [__cpp_lib_containers_ranges](https://en.cppreference.com/w/cpp/feature_test#cpp_lib_containers_ranges) | [202202L](https://en.cppreference.com/w/cpp/compiler_support/23#cpp_lib_containers_ranges_202202L) | (C++23) | Ranges construction and insertion for containers |
| [__cpp_lib_constexpr_map](https://en.cppreference.com/w/cpp/feature_test#cpp_lib_constexpr_map)         | [202502L](https://en.cppreference.com/w/cpp/compiler_support/26#cpp_lib_constexpr_map_202502L)     | (C++26) | constexpr std::map                               |
