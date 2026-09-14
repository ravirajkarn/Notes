---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - Cpp
---
# Range-Based Loop

## Syntax:
```Cpp
for(char variable : input string) 

{ ; }
```

This loop interact/assign each character one by one in "variable" from "input string.


## Example:
```Cpp
std::vector<int> v = {0, 1, 2, 3, 4, 5}; 
for (const int& i : v) 
  std::cout << i << ' '; 
std::cout << '\n';
```


## 1. C++20 Init-Statement (Recommended)
Starting with C++20, you can initialize a counter variable **directly inside the loop statement**. This keeps the scope of the counter restricted only to the loop body. 
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> fruits = {"Apple", "Banana", "Cherry"};
	
    // The counter 'i' is initialized before the colon
    for (int i = 0; auto& fruit : fruits) {
        std::cout << "Index " << i << ": " << fruit << "\n";
        i++; // Manually increment the counter
    }
}
```

## 2. External Counter (C++11 / C++14 / C++17)
If you are working with an older C++ standard, you must declare the counter **outside the loop scope**.
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> fruits = {"Apple", "Banana", "Cherry"};
	
    int i = 0; // Declared outside the loop
    for (const auto& fruit : fruits) {
        std::cout << "Index " << i << ": " << fruit << "\n";
        i++; 
    }
    // Note: 'i' is still accessible here
}
```

## 3. Structured Binding with `std::views::enumerate` (C++23)
If you are using C++23, you can use the [ranges library](https://en.cppreference.com/w/cpp/ranges) along with structured binding to get both the index and the element cleanly **without manual incrementing**.
```cpp
#include <iostream>
#include <vector>
#include <ranges> // Required for std::views::enumerate

int main() {
    std::vector<std::string> fruits = {"Apple", "Banana", "Cherry"};
	
    // Automatically unpacks into [index, element] pairs
    for (auto [i, fruit] : std::views::enumerate(fruits)) {
        std::cout << "Index " << i << ": " << fruit << "\n";
    }
}
```

**Summary Comparison**

| Method                      | C++ Version  | Syntax Cleanliness | Scope Safety                |
| --------------------------- | ------------ | ------------------ | --------------------------- |
| **External Counter**        | C++11 and up | Verbose            | ❌ Leaks to outer scope      |
| **Init-Statement**          | C++20 and up | Clean              | Safe scope                  |
| **`std::views::enumerate`** | C++23 and up | Very Clean         | Safe scope, auto-increments |