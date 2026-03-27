---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 08-09-2025 17:53::49 PM
tags:
  - Cpp
---

### Function Pointer to a Callback

To create a [function pointer](https://www.geeksforgeeks.org/cpp/function-pointer-in-cpp/) to any particular [callback](https://www.geeksforgeeks.org/c/callbacks-in-c/) function, we first need to refer to the signature of the function. Consider the function foo()

> int foo(char c) {  
> .......  
> }

Now the function pointer for the following function can be declared as:

> int (*func_ptr)(char) = &foo;

This function pointer allows you to call the function foo() indirectly using func_ptr. We can also pass this function pointer to any other function as an argument allowing the feature of callbacks in C++.

Example:
```Cpp
// C++ program to illustrate how to use the callback 
// function 
#include <iostream> 
using namespace std; 

// callback function 
int foo(char c) { return (int)c; } 

// another function that is taking callback 
void printASCIIcode(char c, int(*func_ptr)(char)) 
{ 
    int ascii = func_ptr(c); 
    cout << "ASCII code of " << c << " is: " << ascii; 
} 

// driver code 
int main() 
{ 

    printASCIIcode('a', &foo); 
    return 0; 
}
```