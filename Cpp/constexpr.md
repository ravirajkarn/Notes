---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-31T01:00:00
tags:
  - Cpp
  - Keyword
  - Variable
---
# constexpr

It is use to evaluate the value in compile time.
## Explanation :

```Cpp
constexpr int i = 10+12;
const int n = 10+12;
```

in this code, `constexpr int i = 10+12;` The compiler will evaluate the code and assigned the value 10+12 = 22 in the compile time to the variable `i`. So, the `i` = 22. Now, the compiler will compile the code with the value of `i = 22`  into machine code or executable code. This will the the run time process of evaluating the value.

But, in `const int n = 10+22;` the compiler will convert the code into machine code or executable code the evaluate the code at runtime which is 22. This means every time when the program will run, the line will evaluate very time. increasing the time taking of the process.