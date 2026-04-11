---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - unordered_map
  - map
  - STL
  - Hash
  - Header
---
# [\#include<unordered_map>](https://en.cppreference.com/w/cpp/header/unordered_map) 

## Introduction
`unordered_map` is ==a C++ container that stores elements in the form of key-value pairs, similar to a dictionary==. It uses a hash table for storage, providing fast average-case time complexity for insertion, deletion, and lookup operations (O(1)). However, it does not maintain any specific order for the elements. 

### Key characteristics of `unordered_map`:
- **Key-Value Pairs:** Stores data as unique keys associated with corresponding values. 
- **Hashing:** Implements a hash table to organize elements, allowing for efficient access based on keys. 
- **Unordered:** Elements are not stored in any sorted order, unlike `map`.
- **Fast Operations:** Provides average-case constant time complexity for insertion, deletion, and search operations. 
- **Iterators:** Can be accessed and traversed using iterators. 
- **No Order Guarantee:** The order of elements is not predictable and can vary based on the hash function and other factors. 

### When to use `unordered_map`:
- When fast lookups based on unique keys are required.
- When the order of elements is not important.
- In scenarios like caching, database indexing, or counting frequencies.

| Includes                                                                                                                                                                                                            |                                                                                                                              |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| [\<compare\>](https://en.cppreference.com/w/cpp/header/compare) <br>(C++20)                                                                                                                                         | [Three-way comparison operator](https://en.cppreference.com/w/cpp/language/operator_comparison#Three-way_comparison) support |
| [<initializer_list>](https://en.cppreference.com/w/cpp/header/initializer_list) <br>(C++11)                                                                                                                         | [std::initializer_list](https://en.cppreference.com/w/cpp/utility/initializer_list) class template                           |
| Classes                                                                                                                                                                                                             |                                                                                                                              |
| [unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map) <br>(C++11)                                                                                                                              | collection of key-value pairs, hashed by keys, keys are unique <br>(class template)                                          |
| [unordered_multimap](https://en.cppreference.com/w/cpp/container/unordered_multimap) <br>(C++11)                                                                                                                    | collection of key-value pairs, hashed by keys <br>(class template)                                                           |
| Functions                                                                                                                                                                                                           |                                                                                                                              |
| [operator\==](https://en.cppreference.com/w/cpp/container/unordered_map/operator_cmp) (C++11)                                                                                                                       | compares the values in the unordered_map <br>(function template)                                                             |
| [std::swap(std::unordered_map)](https://en.cppreference.com/w/cpp/container/unordered_map/swap2) <br>(C++11)                                                                                                        | specializes the [std::swap](https://en.cppreference.com/w/cpp/algorithm/swap) algorithm <br>(function template)              |
| [erase_if(std::unordered_map)](https://en.cppreference.com/w/cpp/container/unordered_map/erase_if) <br>(C++20)                                                                                                      | erases all elements satisfying specific criteria <br>(function template)                                                     |
| [operator\==](https://en.cppreference.com/w/cpp/container/unordered_multimap/operator_cmp) (C++11) <br>[operator!=](https://en.cppreference.com/w/cpp/container/unordered_multimap/operator_cmp) (removed in C++20) | compares the values in the unordered_multimap <br>(function template)                                                        |
| [std::swap(std::unordered_multimap)](https://en.cppreference.com/w/cpp/container/unordered_multimap/swap2)<br>(C++11)                                                                                               | specializes the [std::swap](https://en.cppreference.com/w/cpp/algorithm/swap) algorithm <br>(function template)              |
| [erase_if(std::unordered_multimap)](https://en.cppreference.com/w/cpp/container/unordered_multimap/erase_if) <br>(C++20)                                                                                            | erases all elements satisfying specific criteria <br>(function template)                                                     |
| Range access                                                                                                                                                                                                        |                                                                                                                              |
| [begin](https://en.cppreference.com/w/cpp/iterator/begin) \(C++11)<br>[cbegin](https://en.cppreference.com/w/cpp/iterator/begin) \(C++14)                                                                           | returns an iterator to the beginning of a container or array <br>(function template)                                         |
| [end](https://en.cppreference.com/w/cpp/iterator/end) \(C++11)<br>[cend](https://en.cppreference.com/w/cpp/iterator/end) \(C++14)                                                                                   | returns an iterator to the end of a container or array <br>(function template)                                               |
| [rbegin](https://en.cppreference.com/w/cpp/iterator/rbegin) <br>[crbegin](https://en.cppreference.com/w/cpp/iterator/rbegin) <br>(C++14)                                                                            | returns a reverse iterator to the beginning of a container or array <br>(function template)                                  |
| [rend](https://en.cppreference.com/w/cpp/iterator/rend) <br>[crend](https://en.cppreference.com/w/cpp/iterator/rend) <br>(C++14)                                                                                    | returns a reverse end iterator for a container or array <br>(function template)                                              |
| [size](https://en.cppreference.com/w/cpp/iterator/size) \(C++17)<br>[ssize](https://en.cppreference.com/w/cpp/iterator/size) \(C++20)                                                                               | returns the size of a container or array <br>(function template)                                                             |
| [empty](https://en.cppreference.com/w/cpp/iterator/empty) <br>(C++17)                                                                                                                                               | checks whether the container is empty <br>(function template)                                                                |
| [data](https://en.cppreference.com/w/cpp/iterator/data) <br>(C++17)                                                                                                                                                 | obtains the pointer to the underlying array <br>(function template)                                                          |

## Member functions 
| [(constructor)](https://en.cppreference.com/w/cpp/container/unordered_map/unordered_map)                   | constructs the unordered_map <br>(public member function)                                                                |
| ---------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| [(destructor)](https://en.cppreference.com/w/cpp/container/unordered_map/%7Eunordered_map)                 | destructs the unordered_map <br>(public member function)                                                                 |
| [operator=](https://en.cppreference.com/w/cpp/container/unordered_map/operator%3D)                         | assigns values to the container <br>(public member function)                                                             |
| [get_allocator](https://en.cppreference.com/w/cpp/container/unordered_map/get_allocator)                   | returns the associated allocator <br>(public member function)                                                            |
| Iterators                                                                                                  |                                                                                                                          |
| [begincbegin](https://en.cppreference.com/w/cpp/container/unordered_map/begin)                             | returns an iterator to the beginning <br>(public member function)                                                        |
| [endcend](https://en.cppreference.com/w/cpp/container/unordered_map/end)                                   | returns an iterator to the end <br>(public member function)                                                              |
| Capacity                                                                                                   |                                                                                                                          |
| [empty](https://en.cppreference.com/w/cpp/container/unordered_map/empty)                                   | checks whether the container is empty <br>(public member function)                                                       |
| [size](https://en.cppreference.com/w/cpp/container/unordered_map/size)                                     | returns the number of elements <br>(public member function)                                                              |
| [max_size](https://en.cppreference.com/w/cpp/container/unordered_map/max_size)                             | returns the maximum possible number of elements <br>(public member function)                                             |
| Modifiers                                                                                                  |                                                                                                                          |
| [clear](https://en.cppreference.com/w/cpp/container/unordered_map/clear)                                   | clears the contents <br>(public member function)                                                                         |
| [insert](https://en.cppreference.com/w/cpp/container/unordered_map/insert)                                 | inserts elements or nodes(since C++17) <br>(public member function)                                                      |
| [insert_range](https://en.cppreference.com/w/cpp/container/unordered_map/insert_range) <br>(C++23)         | inserts a range of elements <br>(public member function)                                                                 |
| [insert_or_assign](https://en.cppreference.com/w/cpp/container/unordered_map/insert_or_assign) <br>(C++17) | inserts an element or assigns to the current element if the key already exists <br>(public member function)              |
| [emplace](https://en.cppreference.com/w/cpp/container/unordered_map/emplace)                               | constructs element in-place <br>(public member function)                                                                 |
| [emplace_hint](https://en.cppreference.com/w/cpp/container/unordered_map/emplace_hint)                     | constructs elements in-place using a hint <br>(public member function)                                                   |
| [try_emplace](https://en.cppreference.com/w/cpp/container/unordered_map/try_emplace) <br>(C++17)           | inserts in-place if the key does not exist, does nothing if the key exists <br>(public member function)                  |
| [erase](https://en.cppreference.com/w/cpp/container/unordered_map/erase)                                   | erases elements <br>(public member function)                                                                             |
| [swap](https://en.cppreference.com/w/cpp/container/unordered_map/swap)                                     | swaps the contents <br>(public member function)                                                                          |
| [extract](https://en.cppreference.com/w/cpp/container/unordered_map/extract) <br>(C++17)                   | extracts nodes from the container <br>(public member function)                                                           |
| [merge](https://en.cppreference.com/w/cpp/container/unordered_map/merge) <br>(C++17)                       | splices nodes from another container <br>(public member function)                                                        |
| Lookup                                                                                                     |                                                                                                                          |
| [at](https://en.cppreference.com/w/cpp/container/unordered_map/at)                                         | access specified element with bounds checking <br>(public member function)                                               |
| [operator[]](https://en.cppreference.com/w/cpp/container/unordered_map/operator_at)                        | access or insert specified element <br>(public member function)                                                          |
| [count](https://en.cppreference.com/w/cpp/container/unordered_map/count)                                   | returns the number of elements matching specific key <br>(public member function)                                        |
| [find](https://en.cppreference.com/w/cpp/container/unordered_map/find)                                     | finds element with specific key <br>(public member function)                                                             |
| [contains](https://en.cppreference.com/w/cpp/container/unordered_map/contains) <br>(C++20)                 | checks if the container contains element with specific key <br>(public member function)                                  |
| [equal_range](https://en.cppreference.com/w/cpp/container/unordered_map/equal_range)                       | returns range of elements matching a specific key <br>(public member function)                                           |
| Bucket interface                                                                                           |                                                                                                                          |
| [begin(size_type)cbegin(size_type)](https://en.cppreference.com/w/cpp/container/unordered_map/begin2)      | returns an iterator to the beginning of the specified bucket <br>(public member function)                                |
| [end(size_type)cend(size_type)](https://en.cppreference.com/w/cpp/container/unordered_map/end2)            | returns an iterator to the end of the specified bucket <br>(public member function)                                      |
| [bucket_count](https://en.cppreference.com/w/cpp/container/unordered_map/bucket_count)                     | returns the number of buckets <br>(public member function)                                                               |
| [max_bucket_count](https://en.cppreference.com/w/cpp/container/unordered_map/max_bucket_count)             | returns the maximum number of buckets <br>(public member function)                                                       |
| [bucket_size](https://en.cppreference.com/w/cpp/container/unordered_map/bucket_size)                       | returns the number of elements in specific bucket <br>(public member function)                                           |
| [bucket](https://en.cppreference.com/w/cpp/container/unordered_map/bucket)                                 | returns the bucket for specific key <br>(public member function)                                                         |
| Hash policy                                                                                                |                                                                                                                          |
| [load_factor](https://en.cppreference.com/w/cpp/container/unordered_map/load_factor)                       | returns average number of elements per bucket <br>(public member function)                                               |
| [max_load_factor](https://en.cppreference.com/w/cpp/container/unordered_map/max_load_factor)               | manages maximum average number of elements per bucket <br>(public member function)                                       |
| [rehash](https://en.cppreference.com/w/cpp/container/unordered_map/rehash)                                 | reserves at least the specified number of buckets and regenerates the hash table <br>(public member function)            |
| [reserve](https://en.cppreference.com/w/cpp/container/unordered_map/reserve)                               | reserves space for at least the specified number of elements and regenerates the hash table <br>(public member function) |
| Observers                                                                                                  |                                                                                                                          |
| [hash_function](https://en.cppreference.com/w/cpp/container/unordered_map/hash_function)                   | returns function used to hash the keys <br>(public member function)                                                      |
| [key_eq](https://en.cppreference.com/w/cpp/container/unordered_map/key_eq)                                 | returns the function used to compare keys for equality <br>(public member function)                                      |

## Non-member functions 
| [operator\==](https://en.cppreference.com/w/cpp/container/unordered_map/operator_cmp) (C++11)                  | compares the values in the unordered_map <br>(function template)                                                |
| -------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- |
| [std::swap(std::unordered_map)](https://en.cppreference.com/w/cpp/container/unordered_map/swap2) <br>(C++11)   | specializes the [std::swap](https://en.cppreference.com/w/cpp/algorithm/swap) algorithm <br>(function template) |
| [erase_if(std::unordered_map)](https://en.cppreference.com/w/cpp/container/unordered_map/erase_if) <br>(C++20) | erases all elements satisfying specific criteria <br>(function template)                                        |

| [Deduction guides](https://en.cppreference.com/w/cpp/container/unordered_map/deduction_guides) | (since C++17) |
| ---------------------------------------------------------------------------------------------- | ------------- |

## Notes 
| [Feature-test](https://en.cppreference.com/w/cpp/utility/feature_test) macro                                        | Value                                                                                                    | Std     | Feature                                          |
| ------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------- | ------- | ------------------------------------------------ |
| [__cpp_lib_containers_ranges](https://en.cppreference.com/w/cpp/feature_test#cpp_lib_containers_ranges)             | [202202L](https://en.cppreference.com/w/cpp/compiler_support/23#cpp_lib_containers_ranges_202202L)       | (C++23) | Ranges construction and insertion for containers |
| [__cpp_lib_constexpr_unordered_map](https://en.cppreference.com/w/cpp/feature_test#cpp_lib_constexpr_unordered_map) | [202502L](https://en.cppreference.com/w/cpp/compiler_support/26#cpp_lib_constexpr_unordered_map_202502L) | (C++26) | constexpr std::unordered_map                     |

## Example

```Cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> student_grades;
	
    // Insert elements
    student_grades["Alice"] = 90;
    student_grades["Bob"] = 85;
    student_grades["Charlie"] = 95;
	
    // Access elements
    std::cout << "Alice's grade: " << student_grades["Alice"] << std::endl;
	
    // Check if an element exists
    if (student_grades.count("David") > 0) {
        std::cout << "David's grade: " << student_grades["David"] << std::endl;
    } else {
        std::cout << "David's grade not found" << std::endl;
    }
	
    // Iterate through the map (order is not guaranteed)
    for (const auto& pair : student_grades) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
	
    return 0;
}
```

