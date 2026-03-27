---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - Cpp
---
# Casting Operators in C++

## type of Casting:
They are used to convert one data type to another. 
C++ supports four type of casts: 
1. Static_cast 
2. Dynamic_cast 
3. Const_cast 
4. Reinterpret_cast

# Type Casting  
Casting is a technique by which one data type is converted to another data type. The operator used for this purpose is known as the cast operator. 

It is a unary operator which force one data type to be converted in to another data type. 

**Syntax: **
```Cpp
(cast type) expression; 

       Or, 

Cast type(expression);
```
# 1. Static_cast
It performs compile-time type conversion and is mainly used for explicit conversions that are considered safe by the compiler . 

Syntax: 
```Cpp
Static_cast <new_type> (expression); 
```
Parameters: 
	Expression: Data to be converted. 
	New_type: Desired type of expression. 

Example 
```Cpp
int num = 10; 
float number = static_cast<float>(num);
```

# 2. Dynamic Cast: 
A cast is an operator that converts data from one type to another type in C++. Dynamic casting is mainly use for safe down casting at run time, to work on dynamic_cast there must be one virtual function in the base class. A dynamic_cast there must be one virtual function in the base class. A dynamic_cast work only polymorphic base class because it use this information to decide safe down casting. 

Syntax: 
```Cpp
dynamic_cast <new_type> (expression);
```