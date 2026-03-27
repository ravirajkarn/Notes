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
