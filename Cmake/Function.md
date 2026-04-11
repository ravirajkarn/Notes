---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-06-18T13:59:00
tags:
  - CMake
  - function
---
Syntax:
```CMake
function(<name> [<arg1> ...])   
	<commands> 
endfunction()
```
NOTES:  
- Function introduce new scope  
- When you outside the function you have global scope  
- Global variable and local variable do not affect each other 
- If you want to make global variable inside function you nee to define PARENT_SCOPE
 
![](6-functions.cmake)
