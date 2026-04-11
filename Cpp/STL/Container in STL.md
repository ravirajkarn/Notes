---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T13:45:00
tags:
  - Container
  - STL
---
# [Containers library - cppreference.com](https://en.cppreference.com/w/cpp/container)
- ## Sequence Containers
Sequence containers implement data structures which can be accessed sequentially. 

| [array](https://en.cppreference.com/w/cpp/container/array)  <br>(C++11)                 | fixed-sized in place contiguous array <br>(class template)                            |
| --------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| [vector](https://en.cppreference.com/w/cpp/container/vector)                            | dynamic contiguous array <br>(class template)                                         |
| [inplace_vector](https://en.cppreference.com/w/cpp/container/inplace_vector)<br>(C++26) | dynamically-resizable, fixed capacity, in place contiguous array <br>(class template) |
| [deque](https://en.cppreference.com/w/cpp/container/deque)                              | double-ended queue <br>(class template)                                               |
| [forward_list](https://en.cppreference.com/w/cpp/container/forward_list) <br>(C++11)    | singly-linked list <br>(class template)                                               |
| [list](https://en.cppreference.com/w/cpp/container/list)                                | doubly-linked list                                                                    |

- ## Associative Containers  
Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity). 

| [set](https://en.cppreference.com/w/cpp/container/set)           | collection of unique keys, sorted by keys <br>(class template)                      |
| ---------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| [map](https://en.cppreference.com/w/cpp/container/map)           | collection of key-value pairs, sorted by keys, keys are unique <br>(class template) |
| [multiset](https://en.cppreference.com/w/cpp/container/multiset) | collection of keys, sorted by keys <br>(class template)                             |
| [multimap](https://en.cppreference.com/w/cpp/container/multimap) | collection of key-value pairs, sorted by keys <br>(class template)                  |

- ## Unordered associative containers (since C++11)
Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) average, O(n) worst-case complexity). 

| [unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set) <br>(C++11)           | collection of unique keys, hashed by keys <br>(class template)                      |
| ------------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------- |
| [unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map) <br>(C++11)           | collection of key-value pairs, hashed by keys, keys are unique <br>(class template) |
| [unordered_multiset](https://en.cppreference.com/w/cpp/container/unordered_multiset) <br>(C++11) | collection of keys, hashed by keys <br>(class template)                             |
| [unordered_multimap](https://en.cppreference.com/w/cpp/container/unordered_multimap)<br>(C++11)  | collection of key-value pairs, hashed by keys <br>(class template)                  |

- ## Container adaptors 
Container adaptors provide a different interface for sequential containers. 

| [stack](https://en.cppreference.com/w/cpp/container/stack)                             | adapts a container to provide stack (LIFO data structure) <br>(class template)                               |
| -------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ |
| [queue](https://en.cppreference.com/w/cpp/container/queue)                             | adapts a container to provide queue (FIFO data structure) <br>(class template)                               |
| [priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)           | adapts a container to provide priority queue <br>(class template)                                            |
| [flat_set](https://en.cppreference.com/w/cpp/container/flat_set) <br>(C++23)           | adapts a container to provide a collection of unique keys, sorted by keys <br>(class template)               |
| [flat_map](https://en.cppreference.com/w/cpp/container/flat_map) <br>(C++23)           | adapts two containers to provide a collection of key-value pairs, sorted by unique keys <br>(class template) |
| [flat_multiset](https://en.cppreference.com/w/cpp/container/flat_multiset) <br>(C++23) | adapts a container to provide a collection of keys, sorted by keys <br>(class template)                      |
| [flat_multimap](https://en.cppreference.com/w/cpp/container/flat_multimap) <br>(C++23) | adapts two containers to provide a collection of key-value pairs, sorted by keys                             |