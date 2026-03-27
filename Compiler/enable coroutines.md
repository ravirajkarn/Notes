---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-01-08 07:55::25 AM
tags:
  - clang
  - Cpp
  - gcc
  - cpp20
  - CMake
---

**How to enable coroutines depends on the compiler used.** 

> [!success] **GCC**
> - **In GCC >= 10 it can be enabled by setting `-std=c++20 -fcoroutines`.**
> - **GCC 11 enables coroutines by default when C++20 is enabled.**


> [!success] **Clang**
> C++20 coroutines are available by default when using a modern C++ standard dialect.
> - Use the `-std=c++20` or `-std=c++23` flag when compiling with `clang++`.
> - Ensure you include the standard `<coroutine>` header file.
> 
> ### **Key Concepts**
> A function becomes a coroutine if it uses any of the three coroutine-specific keywords: 
> - `co_await`: Suspends the coroutine until a result is ready.
> - `co_yield`: Pauses the coroutine and returns a value, typically used for generators.
> - `co_return`: Completes the coroutine, optionally returning a final value.
