---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - Cpp
---
Functor (it is not a function) 
Functor is an object with overloaded(). 

Eg.
```Cpp
#include <iostream>

class Name{
private:
	std::string nam;
public:
	Name(std::string initial_nam = ""): nam(initial_nam){};
	void get(std::string nn): nam(nn){};
	void operator()() const {
		std::cout << nam;
	}
}
```


