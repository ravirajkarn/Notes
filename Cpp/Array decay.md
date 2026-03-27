---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 27-07-2025 06:12 PM
tags:
  - Array
  - Cpp
---
# What is Array Decay?  
The loss of type and dimensions of an array is known as decay of an array. This generally occurs when we pass the array into function by value or pointer. What it does is, it sends first address to the array which is a pointer, hence the size of array is not the original one, but the one occupied by the pointer in the memory. 

## How to prevent Array Decay?  
- A typical solution to handle decay is to pass size of array also as a parameter and not use sizeof on array parameters (See [this](https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters/) for details) 
- Another way to prevent array decay is to send the array into functions by reference. This prevents conversion of array into a pointer, hence prevents the decay.  
- We can also preserve the size of the array by passing it as a pointer to the array which have one more dimension as compared to our array 
## In summary, the best approaches to prevent array decay, especially in C++, are: 
- Passing by reference using template parameters. This is type-safe and preserves the exact array size. 
- Using std::array. This provides a safer and more convenient way to work with fixed-size arrays without decay