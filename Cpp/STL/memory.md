---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-02-28 01:58::40 AM
tags:
  - Cpp
  - STL
  - Library
  - include
---

# [\#include \<memory>](https://en.cppreference.com/w/cpp/header/memory) 

## Smart Pointers
In modern C++, you should rarely (if ever) use raw pointers (`new` and `delete`) for memory management. Instead, C++11 introduced **smart pointers**, which automatically manage memory using a concept called RAII (Resource Acquisition Is Initialization). When a smart pointer goes out of scope, it automatically cleans up the memory it owns, preventing memory leaks.
### std::unique_ptr

Imagine you have a rare physical book.

- **The Rule:** Only **one** person can hold this book at a time. It is exclusively yours.
- **No Copying:** You cannot magically duplicate the book to give a copy to your friend.
- **Transferring (Moving):** If your friend wants to read it, you have to physically hand it to them (`std::move`). Now _they_ own it, and your hands are empty. You can't read it anymore.
- **Destruction:** When the current owner finishes the book and leaves the room (goes out of scope), the book spontaneously combusts and cleans itself up.

**Real-World Scenario:** You are writing a game and you have a `BossMonster`. There is only one Boss Monster in the room. The room owns it. You don't need five different parts of your code claiming ownership of the Boss Monster. If the room is destroyed, the Boss Monster is destroyed. You use a `unique_ptr`.

A `unique_ptr` enforces **strict, exclusive ownership**. This means that exactly one `unique_ptr` can point to a specific object in memory at any given time.

Because it represents exclusive ownership, a `unique_ptr` **cannot be copied**. If you try to copy it, the compiler will throw an error. However, you can _transfer_ ownership to another `unique_ptr` using `std::move`.

`std::unique_ptr` is a smart pointer that owns (is responsible for) and manages another object via a pointer and subsequently disposes of that object when the `unique_ptr` goes out of scope.

The object is disposed of, using the associated deleter, when either of the following happens:

- the managing `unique_ptr` object is destroyed.
- the managing `unique_ptr` object is assigned another pointer via [operator=](https://en.cppreference.com/w/cpp/memory/unique_ptr/operator=.html "cpp/memory/unique ptr/operator=") or [reset()](https://en.cppreference.com/w/cpp/memory/unique_ptr/reset.html "cpp/memory/unique ptr/reset").

#### Member functions

|   |   |
|---|---|
|[(constructor)](https://en.cppreference.com/w/cpp/memory/unique_ptr/unique_ptr.html "cpp/memory/unique ptr/unique ptr")|constructs a new `unique_ptr`  <br>(public member function)|
|[(destructor)](https://en.cppreference.com/w/cpp/memory/unique_ptr/~unique_ptr.html "cpp/memory/unique ptr/~unique ptr")|destructs the managed object if such is present  <br>(public member function)|
|[operator=](https://en.cppreference.com/w/cpp/memory/unique_ptr/operator=.html "cpp/memory/unique ptr/operator=")|assigns the `unique_ptr`  <br>(public member function)|
|##### Modifiers|   |
|[release](https://en.cppreference.com/w/cpp/memory/unique_ptr/release.html "cpp/memory/unique ptr/release")|returns a pointer to the managed object and releases the ownership  <br>(public member function)|
|[reset](https://en.cppreference.com/w/cpp/memory/unique_ptr/reset.html "cpp/memory/unique ptr/reset")|replaces the managed object  <br>(public member function)|
|[swap](https://en.cppreference.com/w/cpp/memory/unique_ptr/swap.html "cpp/memory/unique ptr/swap")|swaps the managed objects  <br>(public member function)|
|##### Observers|   |
|[get](https://en.cppreference.com/w/cpp/memory/unique_ptr/get.html "cpp/memory/unique ptr/get")|returns a pointer to the managed object  <br>(public member function)|
|[get_deleter](https://en.cppreference.com/w/cpp/memory/unique_ptr/get_deleter.html "cpp/memory/unique ptr/get deleter")|returns the deleter that is used for destruction of the managed object  <br>(public member function)|
|[operator bool](https://en.cppreference.com/w/cpp/memory/unique_ptr/operator_bool.html "cpp/memory/unique ptr/operator bool")|checks if there is an associated managed object  <br>(public member function)|
|##### Single-object version, `unique_ptr<T>`|   |
|[operator*operator->](https://en.cppreference.com/w/cpp/memory/unique_ptr/operator%252A.html "cpp/memory/unique ptr/operator*")|dereferences pointer to the managed object  <br>(public member function)|
|##### Array version, `unique_ptr<T[]>`|   |
|[operator[]](https://en.cppreference.com/w/cpp/memory/unique_ptr/operator_at.html "cpp/memory/unique ptr/operator at")|provides indexed access to the managed array  <br>(public member function)|
### std::shared_ptr

Imagine a television in an apartment shared by several roommates.

- **The Rule:** Multiple people can watch the TV (own the resource) at the same time.
- **The Tally Mark (Reference Counting):** Next to the TV is a chalkboard. Every time a roommate walks into the room to watch TV, they add a tally mark. Every time a roommate leaves the room, they erase their tally mark.
- **Sharing:** It’s totally fine for three people to be watching it at once (the chalkboard says "3").
- **Destruction:** When the _very last_ roommate leaves the room and erases the final tally mark (the chalkboard hits "0"), that last person turns off the TV and unplugs it.

**Real-World Scenario:** You are building a music player app. You have a `Song` object currently playing. The "Now Playing" screen needs access to the song to show the lyrics. The "Audio Engine" needs access to the song to play the sound. The "Download Manager" needs access to save it for offline listening. They all share ownership of the `Song`. When all three screens/systems are closed or move on to the next track, the original song is finally cleared from memory. You use a `shared_ptr`.

A `shared_ptr` allows **multiple pointers to own the same resource**. 

`std::shared_ptr` is a smart pointer that retains shared ownership of an object through a pointer. Several `shared_ptr` objects may own the same object. The object is destroyed and its memory deallocated when either of the following happens:

- the last remaining `shared_ptr` owning the object is destroyed;
- the last remaining `shared_ptr` owning the object is assigned another pointer via [operator=](https://en.cppreference.com/w/cpp/memory/shared_ptr/operator=.html "cpp/memory/shared ptr/operator=") or [reset()](https://en.cppreference.com/w/cpp/memory/shared_ptr/reset.html "cpp/memory/shared ptr/reset").
#### Member functions

|                                                                                                                                                                                                                                              |                                                                                                                    |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------ |
| [(constructor)](https://en.cppreference.com/w/cpp/memory/shared_ptr/shared_ptr.html "cpp/memory/shared ptr/shared ptr")                                                                                                                      | constructs new `shared_ptr`  <br>(public member function)                                                          |
| [(destructor)](https://en.cppreference.com/w/cpp/memory/shared_ptr/~shared_ptr.html "cpp/memory/shared ptr/~shared ptr")                                                                                                                     | destructs the owned object if no more `shared_ptr`s link to it  <br>(public member function)                       |
| [operator=](https://en.cppreference.com/w/cpp/memory/shared_ptr/operator=.html "cpp/memory/shared ptr/operator=")                                                                                                                            | assigns the `shared_ptr`  <br>(public member function)                                                             |
| ##### Modifiers                                                                                                                                                                                                                              |                                                                                                                    |
| [reset](https://en.cppreference.com/w/cpp/memory/shared_ptr/reset.html "cpp/memory/shared ptr/reset")                                                                                                                                        | replaces the managed object  <br>(public member function)                                                          |
| [swap](https://en.cppreference.com/w/cpp/memory/shared_ptr/swap.html "cpp/memory/shared ptr/swap")                                                                                                                                           | swaps the managed objects  <br>(public member function)                                                            |
| ##### Observers                                                                                                                                                                                                                              |                                                                                                                    |
| [get](https://en.cppreference.com/w/cpp/memory/shared_ptr/get.html "cpp/memory/shared ptr/get")                                                                                                                                              | returns the stored pointer  <br>(public member function)                                                           |
| [operator*](https://en.cppreference.com/w/cpp/memory/shared_ptr/operator%251A.html "cpp/memory/shared ptr/operator*") [operator->](https://en.cppreference.com/w/cpp/memory/shared_ptr/operator%251A.html "cpp/memory/shared ptr/operator*") | dereferences the stored pointer  <br>(public member function)                                                      |
| [operator[]](https://en.cppreference.com/w/cpp/memory/shared_ptr/operator_at.html "cpp/memory/shared ptr/operator at")<br><br>(C++17)                                                                                                        | provides indexed access to the stored array  <br>(public member function)                                          |
| [use_count](https://en.cppreference.com/w/cpp/memory/shared_ptr/use_count.html "cpp/memory/shared ptr/use count")                                                                                                                            | returns the number of `shared_ptr` objects referring to the same managed object  <br>(public member function)      |
| [unique](https://en.cppreference.com/w/cpp/memory/shared_ptr/unique.html "cpp/memory/shared ptr/unique")<br><br>(until C++20)                                                                                                                | checks whether the managed object is managed only by the current `shared_ptr` object  <br>(public member function) |
| [operator bool](https://en.cppreference.com/w/cpp/memory/shared_ptr/operator_bool.html "cpp/memory/shared ptr/operator bool")                                                                                                                | checks if the stored pointer is not null  <br>(public member function)                                             |
| [owner_before](https://en.cppreference.com/w/cpp/memory/shared_ptr/owner_before.html "cpp/memory/shared ptr/owner before")                                                                                                                   | provides owner-based ordering of shared pointers  <br>(public member function)                                     |
| [owner_hash](https://en.cppreference.com/w/cpp/memory/shared_ptr/owner_hash.html "cpp/memory/shared ptr/owner hash")<br><br>(C++26)                                                                                                          | provides owner-based hashing of shared pointers  <br>(public member function)                                      |
| [owner_equal](https://en.cppreference.com/w/cpp/memory/shared_ptr/owner_equal.html "cpp/memory/shared ptr/owner equal")<br><br>(C++26)                                                                                                       | provides owner-based equal comparison of shared pointers  <br>(public member function)                             |

#### Helper classes

|                                                                                                                                             |                                                                           |
| ------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------- |
| [std::atomic<std::shared_ptr>](https://en.cppreference.com/w/cpp/memory/shared_ptr/atomic2.html "cpp/memory/shared ptr/atomic2")<br>(C++20) | atomic shared pointer  <br>(class template specialization)                |
| [std::hash<std::shared_ptr>](https://en.cppreference.com/w/cpp/memory/shared_ptr/hash.html "cpp/memory/shared ptr/hash")<br>(C++11)         | hash support for **std::shared_ptr**  <br>(class template specialization) |
