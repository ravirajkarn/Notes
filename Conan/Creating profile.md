---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-12-26 21:31::21 PM
tags:
  - Conan
  - Cpp
  - python
---
# Creating profile


> [!abstract] Method 1
> you can create profile by manually typing them.

> [!abstract] Method 2
> This will detect your default compiler for c and c++.
> ```bash
> conan profile detect
> ```

> [!abstract] Method 3
> This will generate your custom profile based on the given CC and CXX with clang name.
> ```bash
> CC=clang CXX=clang++ conan profile detect --name clang
> ```

