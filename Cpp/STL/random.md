---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T13:45:00
tags:
  - Random
  - Cpp
  - Library
  - Header
  - STL
---
# include\<random> 

This is standard header file available in C++. 
It is use to generate random number.  

Techniques used in generating random number are: - 

- [x] **linear_congruential_engine**
 Xi=((Xi−1⋅a)+c) mod m 
```Cpp
#include <iostream> 
#include <random> 

int main() { 
    // Parameters for LCG 
    const unsigned int a = 48271; 
    const unsigned int c = 0; 
    const unsigned int m = 2147483647; 
    const unsigned int seed = 12345;
    
    // Create the LCG engine 
    std::linear_congruential_engine<unsigned int, a, c, m> lcg(seed); 

    // Generate and print random numbers 
    for (int i = 0; i < 10; ++i) { 
        std::cout << lcg() << " "; 
    } 
    return 0; 
}
```

- [x] **mersenne_twister_engine**

```Cpp
#include <iostream> 
#include <random> 

int main() { 
    std::mt19937 mt; // Instantiate a 32-bit Mersenne Twister
    
    // Print a bunch of random numbers 
    for (int count = 1; count <= 40; ++count) { 
        std::cout << mt() << '\t'; // Generate a random number

        // If we've printed 5 numbers, start a new row 
        if (count % 5 == 0) 
            std::cout << '\n'; 
    } 
    
    return 0; 
}
```

```Cpp
#include <iostream> 
#include <random> 

int main() { 
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, 100); 
    int random_number = distrib(gen); 
    std::cout << "Random Number: " << random_number << std::endl; 
    return 0; 
}
```

- [ ] subtract_with_carry_engine 
```Cpp
#include <iostream> 
#include <random> 

int main() { 
    std::subtract_with_carry_engine<unsigned, 32, 16, 31> engine; 

    // Generate and print random numbers 
    for (int count = 1; count <= 10; ++count) { 
        std::cout << engine() << ' '; 
    } 

    return 0; 
}
```

- [ ] Std::random_device 
```Cpp
#include <iostream> 
#include <map> 
#include <random> 

int main() { 
    std::random_device rd; 
    std::map<int, int> hist; 

    for (int n = 0; n < 20000; ++n) 
        ++hist[rd() % 10]; 

    for (const auto& p : hist) 
        std::cout << p.first << ": " << std::string(p.second / 100, '*') << '\n'; 
}
```

```Cpp
#include <iostream> 
#include <map> 
#include <random> 

int main() { 
    std::random_device rd; 
    std::map<int, int> hist; 

    for (int n = 0; n < 20000; ++n) 
        ++hist[rd() % 10]; 

    for (const auto& p : hist) 
        std::cout << p.first << ": " << std::string(p.second / 100, '*') << '\n'; 
}
```

```Cpp
#include <iostream> 
#include <random> 

int main() { 
    // Create a random device to seed the Mersenne Twister 
    std::random_device rd; 
    std::mt19937 eng(rd()); // Instantiate a 32-bit Mersenne Twister 

    // Generate random numbers 
    for (int count = 1; count <= 10; ++count) { 
        std::cout << eng() << '\t'; // Generate a random number 
        if (count % 5 == 0) 
            std::cout << '\n'; // Start a new row after 5 numbers
    } 

    return 0; 
}
```