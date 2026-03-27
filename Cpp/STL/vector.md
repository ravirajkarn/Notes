---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T13:45:00
tags:
---
# \#include \<vector\>
## introduction
The elements are stored contiguously, which means that elements can be accessed not only through to elements. This means that a pointer to an element of a vector may be passed to any function that expects a pointer to an elements of an array.

## Define in header \<vector\>
```Cpp
template< 
	class T, 
	class Allocator = std::allocator)<T> 
> class vector;
```

```Cpp
namespace pmr {
	template< class T > 
using vector = std::vector<T,std::pmr::polymorphic_allocator<T>>; 
}
```

1) std::vector is a sequence container that encapsulates dynamic size arrays. 
2) std::pmr::vector is an alias template that uses a [polymorphic allocator](https://en.cppreference.com/w/cpp/memory/polymorphic_allocator).

## Details:
The complexity (efficiency) of common operations on vectors is as follows: 
- Random access - constant 𝓞(1). 
- Insertion or removal of elements at the end - amortized constant 𝓞(1). 
- Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n).

## Member functions
| [(constructor)](https://en.cppreference.com/w/cpp/container/vector/vector)                  | constructs the vector <br>(public member function)                      |
| ------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| [(destructor)](https://en.cppreference.com/w/cpp/container/vector/%7Evector)                | destructs the vector <br>(public member function)                       |
| [operator=](https://en.cppreference.com/w/cpp/container/vector/operator%3D)                 | assigns values to the container <br>(public member function)            |
| [assign](https://en.cppreference.com/w/cpp/container/vector/assign)                         | assigns values to the container <br>(public member function)            |
| [assign_range](https://en.cppreference.com/w/cpp/container/vector/assign_range) <br>(C++23) | assigns a range of values to the container <br>(public member function) |
| [get_allocator](https://en.cppreference.com/w/cpp/container/vector/get_allocator)           | returns the associated allocator <br>(public member function)           |

## Element access 
| [at](https://en.cppreference.com/w/cpp/container/vector/at)                  | access specified element with bounds checking <br>(public member function)      |
| ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| [operator[]](https://en.cppreference.com/w/cpp/container/vector/operator_at) | access specified element <br>(public member function)                           |
| [front](https://en.cppreference.com/w/cpp/container/vector/front)            | access the first element <br>(public member function)                           |
| [back](https://en.cppreference.com/w/cpp/container/vector/back)              | access the last element <br>(public member function)                            |
| [data](https://en.cppreference.com/w/cpp/container/vector/data)              | direct access to the underlying contiguous storage <br>(public member function) |

## Iterators 
| [begin](https://en.cppreference.com/w/cpp/container/vector/begin) <br>[cbegin](https://en.cppreference.com/w/cpp/container/vector/begin) <br>(C++11)     | returns an iterator to the beginning <br>(public member function)        |
| -------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| [end](https://en.cppreference.com/w/cpp/container/vector/end) <br>[cend](https://en.cppreference.com/w/cpp/container/vector/end) <br>(C++11)             | returns an iterator to the end <br>(public member function)              |
| [rbegin](https://en.cppreference.com/w/cpp/container/vector/rbegin) <br>[crbegin](https://en.cppreference.com/w/cpp/container/vector/rbegin) <br>(C++11) | returns a reverse iterator to the beginning <br>(public member function) |
| [rend](https://en.cppreference.com/w/cpp/container/vector/rend) <br>[crend](https://en.cppreference.com/w/cpp/container/vector/rend) <br>(C++11)         | returns a reverse iterator to the end <br>(public member function)       |

## Capacity 
| [empty](https://en.cppreference.com/w/cpp/container/vector/empty)                          | checks whether the container is empty <br>(public member function)                                          |
| ------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------- |
| [size](https://en.cppreference.com/w/cpp/container/vector/size)                            | returns the number of elements <br>(public member function)                                                 |
| [max_size](https://en.cppreference.com/w/cpp/container/vector/max_size)                    | returns the maximum possible number of elements <br>(public member function)                                |
| [reserve](https://en.cppreference.com/w/cpp/container/vector/reserve)                      | reserves storage <br>(public member function)                                                               |
| [capacity](https://en.cppreference.com/w/cpp/container/vector/capacity)                    | returns the number of elements that can be held in currently allocated storage <br>(public member function) |
| [shrink_to_fit](https://en.cppreference.com/w/cpp/container/vector/shrink_to_fit)<br>(DR*) | reduces memory usage by freeing unused memory <br>(public member function)                                  |

## Modifiers 
| [clear](https://en.cppreference.com/w/cpp/container/vector/clear)                           | clears the contents <br>(public member function)                       |
| ------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| [insert](https://en.cppreference.com/w/cpp/container/vector/insert)                         | inserts elements <br>(public member function)                          |
| [insert_range](https://en.cppreference.com/w/cpp/container/vector/insert_range) <br>(C++23) | inserts a range of elements <br>(public member function)               |
| [emplace](https://en.cppreference.com/w/cpp/container/vector/emplace) <br>(C++11)           | constructs element in-place <br>(public member function)               |
| [erase](https://en.cppreference.com/w/cpp/container/vector/erase)                           | erases elements <br>(public member function)                           |
| [push_back](https://en.cppreference.com/w/cpp/container/vector/push_back)                   | adds an element to the end <br>(public member function)                |
| [emplace_back](https://en.cppreference.com/w/cpp/container/vector/emplace_back) <br>(C++11) | constructs an element in-place at the end <br>(public member function) |
| [append_range](https://en.cppreference.com/w/cpp/container/vector/append_range) <br>(C++23) | adds a range of elements to the end <br>(public member function)       |
| [pop_back](https://en.cppreference.com/w/cpp/container/vector/pop_back)                     | removes the last element <br>(public member function)                  |
| [resize](https://en.cppreference.com/w/cpp/container/vector/resize)                         | changes the number of elements stored <br>(public member function)     |
| [swap](https://en.cppreference.com/w/cpp/container/vector/swap)                             | swaps the contents <br>(public member function)                        |

## Example 

```Cpp
#include <iostream> 
#include <vector>  
int main(){ 
	// Create a vector containing integers 
	std::vector<int>v ={8, 4, 5, 9};   
	
	// Add two more integers to vector 
	v.push_back(6); 
	v.push_back(9);       
	
	// Overwrite element at position
	v[2]=-1;     
	
	// Print out the vector 
	for(int n :v) 
		std::cout<<n <<' '; 
	std::cout<<'\n';
}
```
Output: 
```Bash
8 4 -1 9 6 9
```
