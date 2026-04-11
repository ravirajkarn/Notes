---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T13:45:00
tags:
  - STL
  - String
---
#### Note:- String must start with number or (+ & - ) sign. 

| Std::stoi()  | String to integer     |
| ------------ | --------------------- |
| Std::stol()  | String to long        |
| Std::stoll() | String to long long   |
| Std::stold() | String to long double |

#### Parameters of stoi(), stol(), stoll() & stod(). 
Stoi(const std::string & str, std::size_t* pos = nullptr, int base = 10); 
#### Parameters 
1. Str:- the string to be convert. 
2. Pos:- address of an integer to store the number of characters processed.     
3. Base:- the number base. 
#### Return value 
Integer value corresponding to the content of str. 
#### Exceptions 
| Std::invalid_argument | If no conversion could be performed                                              |
| --------------------- | -------------------------------------------------------------------------------- |
| Std::out_of_range     | If the conversion value would fall out of the range of the result type variable. |