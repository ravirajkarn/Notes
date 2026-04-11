---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
---
# Lambda Function 
## Introduction
lambda functions are a convenient way to define anonymous functions directly in your code. Here's a brief overview of how to use them: 

### Basic Syntax 
The basic syntax of a lambda function in C++ is as follows: 
```Cpp
[ capture_list ] ( parameters ) -> return_type {
	// function body 
}
```
- **Capture List:** Specifies which variables from the surrounding scope are accessible inside the lambda. 
- **Parameters:** The input parameters for the lambda function. 
- **Return Type:** (Optional) Specifies the return type of the lambda function. 
- **Function Body:** The code that gets executed when the lambda is called. 

A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope. 

**Example 1: Simple Lambda**
Here's a simple example of a lambda function that adds two numbers: 
```Cpp
#include<iostream> 

int main() {
	auto add = [](int a, int b) -> int{         
		return a + b;     
	}; 

	std::cout << "Sum: "<< add(3, 4) << std::endl; // Output: Sum: 7 
	return 0;
}
```

**Example 2: Lambda with Capture List** 
In this example, the lambda captures a variable from the surrounding scope: 
```Cpp
#include<iostream> 

int main() {     
	int factor = 2;     
	auto multiply = [factor](int a) -> int{         
		return a * factor;     
	}; 
	std::cout << "Product: "<< multiply(5) << std::endl; // Output: Product: 10 
	return 0;
}
```

**Example 3: Lambda in Standard Algorithms** 
Lambdas are often used with standard algorithms like std::for_each: 
```Cpp
#include<iostream> 
#include<vector> 
#include<algorithm> 

int main() {     
	std::vector<int> numbers = {1, 2, 3, 4, 5}; 
	
	std::for_each(numbers.begin(), numbers.end(), [](int n {         
	std::cout << n * n << " ";     
	});     
	// Output: 1 4 9 16 25 
	return 0; 
}
```
Key Points 
- **Capture by Value:** [=] captures all variables by value. 
- **Capture by Reference:** [&] captures all variables by reference. 
- **Mixed Capture:** [=, &var] captures all variables by value, but var by reference. 
Lambda functions in C++ are powerful tools that can make your code more concise and expressive. Feel free to experiment with them to see how they can simplify your coding tasks!