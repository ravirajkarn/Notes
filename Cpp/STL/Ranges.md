---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-05-10 07:07::41 AM
tags:
  - STL
  - Library
---
# include[\<ranges>](https://en.cppreference.com/w/cpp/header/ranges)
Ranges are are sequence of elements that you can iterate over. It is lazily created series of elements.


### **ranges**
1. **std::ranges::forword_range** :- Iterate through elements move strictly forward.
2. **range_value_t** :-  Its entire job is to look at a range (like a `std::vector`, `std::list`, or a custom view) and tell the compiler: **"What is the underlying raw data type of the elements stored inside this range?"** 
> [!question]  How it works
> When you are writing template code, you often don't know what kind of container the user is going to pass in. You just know it's a "Range". If you need to create a variable or a vector to hold copies of the data inside that range, you need to know the data type.
> 
> Here is what `range_value_t` returns for different types of ranges:
