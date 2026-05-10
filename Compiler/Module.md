---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-05-03 17:37::28 PM
tags:
  - Compiler
---
# What is module?
Modules are line import in python.
> [!success]  C++
> ```cpp
> export module B;
> export void b(){}
> ```

> [!example] Sample module 1:
> ```b.cpp
> export module B;
> export void b(){}
> ```
> ```a.cpp
> export module A;
> export void a(){b();}
> ```
> ```bash
> cl -std:c++20 -interface -c a.cpp
> a.cpp:
> a.cpp(2): error C2230: could not find nodule 'B'
> a.cpp(3): error C3861 'b' identifier not found
> ```

> [!example] Sample module 2:
> ```b.cpp
> export module B;
> export void b(){}
> ```
> ```a.cpp
> export module A;
> export void a(){b();}
> ```
> ```bash
> cl -std:c++20 -interface -c b.cpp
> b.cpp:
> 
> cl -std:c++20 -interface -c a.cpp 
> a.cpp
> 
> ls
> a.cpp a.ifc a.obj b.cpp b.ifc b.obj
> ```

> [!important]  Sample Conclusion: Order matter
