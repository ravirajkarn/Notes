---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
---
# [\#include\<thread>](https://en.cppreference.com/w/cpp/header/thread)

### Includes
| [\<compare\>](https://en.cppreference.com/w/cpp/header/compare.html "cpp/header/compare")<br>(C++20) | [Three-way comparison operator](https://en.cppreference.com/w/cpp/language/operator_comparison.html#Three-way_comparison "cpp/language/operator comparison") support |
| ---------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |

### Namespaces
| **`this_thread`**                                                                                                                                                                                                                                              | provide functions that access the current thread of execution                                                                                       |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------- |

### Classes
| [thread](https://en.cppreference.com/w/cpp/thread/thread.html "cpp/thread/thread")<br>(C++11)                          | manages a separate thread  <br>(class)                                                                                                              |
| ---------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------- |
| [jthread](https://en.cppreference.com/w/cpp/thread/jthread.html "cpp/thread/jthread")<br>(C++20)                       | [std::thread](https://en.cppreference.com/w/cpp/thread/thread.html "cpp/thread/thread") with support for auto-joining and cancellation  <br>(class) |
| [std::hash<std::thread::id>](https://en.cppreference.com/w/cpp/thread/thread/id/hash.html "cpp/thread/thread/id/hash") | specializes [std::hash](https://en.cppreference.com/w/cpp/utility/hash.html "cpp/utility/hash")  <br>(class template specialization)                |

### Functions
| [std::swap(std::thread)](https://en.cppreference.com/w/cpp/thread/thread/swap2.html "cpp/thread/thread/swap2")<br>(C++11)                                                                                                                                      | specializes the [std::swap](https://en.cppreference.com/w/cpp/utility/swap.html "cpp/algorithm/swap") algorithm  <br>(function) |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| [operator\==](https://en.cppreference.com/w/cpp/thread/thread/id/operator_cmp.html "cpp/thread/thread/id/operator cmp")<br>[operator<=>](https://en.cppreference.com/w/cpp/thread/thread/id/operator_cmp.html "cpp/thread/thread/id/operator cmp") (C++20)<br> | compares two `thread::id` objects  <br>(function)                                                                               |
| [operator<<](https://en.cppreference.com/w/cpp/thread/thread/id/operator_ltlt.html "cpp/thread/thread/id/operator ltlt") <br>Defined in namespace `std::this_thread`                                                                                           | serializes a `thread::id` object  <br>(function template)                                                                       |
| [yield](https://en.cppreference.com/w/cpp/thread/yield.html "cpp/thread/yield") (C++11)                                                                                                                                                                        | suggests that the implementation reschedule execution of threads  <br>(function)                                                |
| [get_id](https://en.cppreference.com/w/cpp/thread/get_id.html "cpp/thread/get id") (C++11)                                                                                                                                                                     | returns the thread id of the current thread  <br>(function)                                                                     |
| [sleep_for](https://en.cppreference.com/w/cpp/thread/sleep_for.html "cpp/thread/sleep for") (C++11)                                                                                                                                                            | stops the execution of the current thread for a specified time duration  <br>(function)                                         |
| [sleep_until](https://en.cppreference.com/w/cpp/thread/sleep_until.html "cpp/thread/sleep until") (C++11)                                                                                                                                                      | stops the execution of the current thread until a specified time point  <br>(function)                                          |
