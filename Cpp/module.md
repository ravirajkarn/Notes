---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-05-03 18:08::01 PM
tags:
  - Cpp
  - cpp20
---

# Modules (since C++20)
Most C++ projects use multiple translation units, and so they need to share [declarations](https://en.cppreference.com/cpp/language/declarations "cpp/language/declarations") and [definitions](https://en.cppreference.com/cpp/language/definition "cpp/language/definition") across those units. The usage of [headers](https://en.cppreference.com/cpp/standard_library#Headers "cpp/standard library") is prominent for this purpose, an example being the [standard library](https://en.cppreference.com/cpp/standard_library "cpp/standard library") whose declarations can be provided by [including the corresponding header](https://en.cppreference.com/cpp/standard_library#Including_headers "cpp/standard library").
Modules are a language feature to share declarations and definitions across translation units. They are an alternative to some use cases of headers.
Modules are orthogonal to [namespaces](https://en.cppreference.com/cpp/language/namespace "cpp/language/namespace").

```cpp
// helloworld.cpp
export module helloworld; // module declaration

import <iostream>;        // import declaration

export void hello()       // export declaration
{
    std::cout << "Hello world!\n";
}
```

```cpp
// main.cpp
import helloworld; // import declaration

int main()
{
    hello();
}
```
### Syntax
- `export`(optional) `module` module-name module-partition ﻿(optional) attr ﻿(optional) `;`
- `export` declaration
- `export {` declaration-seq ﻿(optional) `}`
- `export`(optional) `import` module-name attr ﻿(optional) `;`
- `export`(optional) `import` module-partition attr ﻿(optional) `;`
- `export`(optional) `import` header-name attr ﻿(optional) `;`
- `module;`
- `module : private;`
