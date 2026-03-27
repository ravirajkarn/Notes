---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-05-19T22:57:00
tags:
  - Set
  - unordered_set
  - Cpp
  - Container
  - Header
---
# [\#include\<unordered_set\>](https://en.cppreference.com/w/cpp/header/unordered_set) 

## Introduction 
It is same as [#include\<set\>](set.md) and function. It only store key in any order as the name suggests.

Unordered set is unordered collection of element

An `unordered_set` in C++ Standard Template Library (STL) is an associative container that stores unique elements in no particular order. It is designed for efficient storage and retrieval of unique elements, offering average constant-time complexity (O(1)) for insertions, deletions, and searches.

**Key characteristics of `unordered_set`:**
- **Unique Elements:** It only stores unique values; duplicate elements are not allowed.
- **No Specific Order:** Unlike `std::set`, which stores elements in a sorted order, `std::unordered_set` does not maintain any particular order of elements. The internal arrangement depends on the hash function and the elements' hash values.
- **Hash Table Implementation:** It is implemented using a hash table data structure, where elements are placed into buckets based on their hash values. This hashing mechanism is what enables its average constant-time performance.
- **Average Case O(1) Complexity:** Most operations like insertion, deletion, and searching have an average time complexity of O(1).
- **Worst Case O(N) Complexity:** In the worst-case scenario (e.g., due to hash collisions leading to a poorly distributed hash table), operations can degrade to O(N) complexity, where N is the number of elements.
- **Header File:** To use `unordered_set`, the `<unordered_set>` header file must be included.

## Example
```Cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet;
	
    mySet.insert(10);
    mySet.insert(5);
    mySet.insert(20);
    mySet.insert(5); // This will not be inserted as 5 is already present
	
    std::cout << "Elements in the unordered_set: ";
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
	
    if (mySet.count(10)) {
        std::cout << "10 is in the set." << std::endl;
    }
	
    mySet.erase(5);
    std::cout << "Elements after erasing 5: ";
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
	
    return 0;
}
```
