---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
---
# \#include \<mutex\> 

### Classes
| [mutex](https://en.cppreference.com/w/cpp/thread/mutex.html "cpp/thread/mutex")<br>(C++11)                                                     | provides basic mutual exclusion facility  <br>(class)                                                                                                                |
| ---------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [timed_mutex](https://en.cppreference.com/w/cpp/thread/timed_mutex.html "cpp/thread/timed mutex")<br>(C++11)                               | provides mutual exclusion facility which implements locking with a timeout  <br>(class)                                                                              |
| [recursive_mutex](https://en.cppreference.com/w/cpp/thread/recursive_mutex.html "cpp/thread/recursive mutex")<br>(C++11)                   | provides mutual exclusion facility which can be locked recursively by the same thread  <br>(class)                                                                   |
| [recursive_timed_mutex](https://en.cppreference.com/w/cpp/thread/recursive_timed_mutex.html "cpp/thread/recursive timed mutex")<br>(C++11) | provides mutual exclusion facility which can be locked recursively by the same thread and implements locking with a timeout  <br>(class)                             |
| [lock_guard](https://en.cppreference.com/w/cpp/thread/lock_guard.html "cpp/thread/lock guard")<br>(C++11)                                  | implements a strictly scope-based mutex ownership wrapper  <br>(class template)                                                                                      |
| [unique_lock](https://en.cppreference.com/w/cpp/thread/unique_lock.html "cpp/thread/unique lock")<br>(C++11)                                   | implements movable mutex ownership wrapper  <br>(class template)                                                                                                     |
| [scoped_lock](https://en.cppreference.com/w/cpp/thread/scoped_lock.html "cpp/thread/scoped lock")<br>(C++17)                                   | deadlock-avoiding RAII wrapper for multiple mutexes  <br>(class template)                                                                                            |
| [once_flag](https://en.cppreference.com/w/cpp/thread/once_flag.html "cpp/thread/once flag")<br>(C++11)                                     | helper object to ensure that [call_once](https://en.cppreference.com/w/cpp/thread/call_once.html "cpp/thread/call once") invokes the function only once  <br>(class) |

### Functions
| [try_lock](https://en.cppreference.com/w/cpp/thread/try_lock.html "cpp/thread/try lock")<br>(C++11)                                  | attempts to obtain ownership of mutexes via repeated calls to `try_lock`  <br>(function template)                                        |
| ---------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| [lock](https://en.cppreference.com/w/cpp/thread/lock.html "cpp/thread/lock")<br>(C++11)                                                  | locks specified mutexes, blocks if any are unavailable  <br>(function template)                                                          |
| [call_once](https://en.cppreference.com/w/cpp/thread/call_once.html "cpp/thread/call once")<br>(C++11)                               | invokes a function only once even if called from multiple threads  <br>(function template)                                               |
| [std::swap(std::unique_lock)](https://en.cppreference.com/w/cpp/thread/unique_lock/swap2.html "cpp/thread/unique lock/swap2")<br>(C++11) | specializes the [std::swap](https://en.cppreference.com/w/cpp/utility/swap.html "cpp/algorithm/swap") algorithm  <br>(function template) |