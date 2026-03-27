---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-02-22 03:01::45 AM
tags:
  - include
  - Cpp
  - STL
---
# [\#include\<format\>](https://en.cppreference.com/w/cpp/header/format.html)
### 1. The Core Formatting Functions
These are the primary functions you will use daily to generate formatted text.

- `std::format` (C++20)
	The bread and butter. Takes a format string and arguments, and returns a freshly allocated std::string (or `std::wstring`).
```C++
std::string s = std::format("Hello {}! You have {} messages.", "Alice", 5);
```
- `std::format_to` (C++20)
	Instead of returning a new string, it writes the formatted characters directly into an output iterator (like `std::back_inserter` for a vector, or a raw character array). This is highly efficient because it avoids allocating a new `std::string`.
```C++
std::vector<char> buffer;
std::format_to(std::back_inserter(buffer), "Value: {}", 42);
```

- `std::format_to_n` (C++20)
	Like format_to, but takes a maximum size n. It prevents writing past a certain limit, preventing buffer overflows when formatting into fixed-size C-arrays. Returns a `std::format_to_n_result` struct containing the updated iterator and the truncated size.

- `std::formatted_size` (C++20)
	Calculates exactly how many characters the formatted string will take, without actually allocating or writing the string. Useful if you need to pre-allocate a buffer of the exact correct size before calling format_to.

- `std::vformat` / `std::vformat_to` (C++20)
	The "v" stands for variadic or value-erased. `std::format` is a template function, meaning the compiler generates a new version of it for every combination of arguments you pass. To prevent binary bloat, `std::format` actually delegates its work to vformat. vformat takes type-erased arguments via `std::format_args`.

- `std::runtime_format` (C++26)
	By default, C++20 formatting strings must be compile-time constants (constexpr). This allows the compiler to check your placeholders for errors. If you need to load a format string at runtime (e.g., from a translation .json file), you wrap it in `std::runtime_format`(your_string).

### 2. The Mechanics (Behind the Scenes)
How does `<format>` check your syntax at compile-time and process it at run-time?

- `std::basic_format_string` (C++20)
	When you call `std::format("...", args)`, the string literal is secretly converted into this class. Its constructor is `consteval` (forced at compile-time). It parses the format string while compiling. If you write `std::format("{} {}", 1)`, the compile-time parser notices you have two `{}` but only one argument, and halts the build with a compiler error!

- `std::basic_format_args` & `std::make_format_args` (C++20)
	This class holds a type-erased array of all the arguments you passed. It safely packs integers, strings, floats, etc., into a uniform array so the internal formatting engine doesn't need to be heavily templated.

### 3. State and Context Classes
When a string is being formatted, `<format>` passes these "Context" objects around to keep track of what's going on.

- `std::basic_format_parse_context` (C++20)
	Holds the state during the parsing phase. It keeps track of the format string being read, where the parser currently is, and handles custom format specifiers (the stuff inside the `{...}`).

- `std::basic_format_context` (C++20)
	Holds the state during the formatting phase. It contains the actual values of the arguments and the output iterator where the final characters are being written.

### 4. Custom Formatting (`std::formatter`)
If you create your own custom `struct` or `class`, `<format>` doesn't know how to print it. You have to teach it by specializing `std::formatter`.

A custom formatter requires two functions: `parse` (reads the `{}` brackets) and `format` (writes the text).

```C++
struct Point { int x, y; };

template <>
struct std::formatter<Point> {
    // 1. Parse phase (can just accept empty "{}" for now)
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin(); 
    }
    
    // 2. Format phase
    auto format(const Point& p, std::format_context& ctx) const {
        return std::format_to(ctx.out(), "({}, {})", p.x, p.y);
    }
};

// Now this works perfectly!
std::string s = std::format("The player is at {}", Point{10, 20});
```

### 5. C++23 Additions: Ranges, Tuples, and Enums
C++23 massively expanded `<format>` to automatically handle collections and standard library types.

- `std::formatter<range>` (C++23)
	You can now directly format std::vector, std::array, std::map, etc., without writing loops!
```C++
std::vector<int> v = {1, 2, 3};
std::string s = std::format("{}", v); // Output: "[1, 2, 3]"
```

- `std::formatter<pair-or-tuple>` (C++23)
	Tuples and pairs are also natively printable now.
```C++
std::pair<int, std::string> p = {1, "apple"};
std::string s = std::format("{}", p); // Output: "(1, "apple")"
```

- std::range_formatter (C++23)
	A helper class used if you want to write a custom formatter for your own custom container. It handles the brackets `[]` and commas `,` for you.

- `std::formattable` (Concept) (C++23)
	A C++20 Concept that allows you to constrain templates. If you write a template function that formats a generic type `T`, you can say requires `std::formattable<T, char>` to ensure `T` actually has a formatter written for it.

### 6. Error Handling
- `std::format_error` (C++20)
	An exception thrown at runtime if a formatting error occurs that the compiler couldn't catch. This usually only happens if you are using `std::vformat` or `std::runtime_format` with bad format strings, or if a custom `std::formatter` throws it manually. Inherits from `std::runtime_error`.
