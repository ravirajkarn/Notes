---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-11 18:40::54 PM
tags:
  - Cpp
---

 To get user input 
 ```cpp
 #include <iostream>

int main(int argc, char* argv[]) {
    // argv[0] is always the name of the program
    std::cout << "Program name: " << argv[0] << std::endl;
    std::cout << "Number of arguments: " << argc << std::endl;
    if (argc > 1) {
        std::cout << "Arguments passed:" << std::endl;
        for (int i = 1; i < argc; ++i) {
            std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
        }
    } else {
        std::cout << "No additional arguments provided." << std::endl;
    }
    return 0;
}
 ```