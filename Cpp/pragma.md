---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - Cpp
---
# \#pragma
## \#pragma Directive 
In C++, the **pragma** directive is a special purpose directive that is used to turn on or off some features. **pragma** also allows us to provide some additional information or instructions to the compiler. It is compiler-specific i.e., the behaviour of pragma directive varies from compiler to compiler. 

## Syntax of **pragma** 
```Cpp
#pragma directive_name
```
## Commonly Used **pragma** Directives in C++ 
Some of the commonly used **pragma** directives are discussed below: 
### 1.  **pragma** startup and **pragma** exit 
These directives help us to specify the functions that are needed to run before the program starts ( before the control passes to the main()) and just before the program exits (just before the control returns from the main()). 
**Syntax**
```Cpp
#pragma startup function_name 
#pragma exit function_name
```

Example 
The below program will not work with GCC compilers. Look at the below program: 
```Cpp
// C program to demonstrate the working of #pragma startup 
// and #pragma exit 

#include <stdio.h> 

void func1(); 
void func2(); 

#pragma startup func1 
#pragma exit func2 

void func1() { printf("Inside func1()\n"); } 
void func2() { printf("Inside func2()\n"); } 

int main() 
{ 
    printf("Inside main()\n"); 
    return 0; 
}
```

Output 
```Bash
inside func1() 
inside main() 
inside func2()
```
The above code will produce the output as given below when run on GCC compilers: 
```Bash
inside main()
```

This happens because GCC does not support **pragma** startup or exit. However, you can use the below code for a similar output on GCC compilers. 
```Cpp
// C program to demonstrate the working of #pragma startup 
// and #pragma exit (without GCC compiler) 

#include <stdio.h> 

void func1(); 
void func2(); 

void __attribute__((constructor)) func1(); 
void __attribute__((destructor)) func2(); 

void func1() { printf("Inside func1()\n"); } 
void func2() { printf("Inside func2()\n"); } 

int main() 
{ 
    printf("Inside main()\n"); 

    return 0; 
}
```

Output 
```Bash
inside func1() 
inside main() 
inside func2()
```

### 2.  **pragma** warn Directive 
This directive is used to hide the warning messages which are displayed during compilation. This may be useful for us hen we have a large program and we want to solve all the errors before looking on warnings then by using it we can focus on errors by hiding all warnings. we can again let the warnings be visible by making slight changes in syntax. 

**Syntax**
```Cpp
#pragma warn +xxx (To show the warning)  
#pragma warn -xxx (To hide the warning)  
#pragma warn .xxx (To toggle between hide and show)
```
We can hide the warnings as shown below: 
- **pragma warn -rvl:** This directive hides those warning which are raised when a function which is supposed to return a value does not return a value. 
- **pragma warn -par:** This directive hides those warning which are raised when a function does not uses the parameters passed to it. 
- **pragma warn -rch:** This directive hides those warning which are raised when a code is unreachable. For example: any code written after the return statement in a function is unreachable.     

Example 

The below example demonstrates the use of above warnings. 
```Cpp
// C program to explain the working of   
// #pragma warn directive  
// This program is compatible with C/C++ compiler   

#include<stdio.h>  

#pragma warn -rvl /* return value */  
#pragma warn -par /* parameter never used */  
#pragma warn -rch /*unreachable code */  

int show(int x)  
{     
    // parameter x is never used in  
    // the function  

    printf("GEEKSFORGEEKS");  

    // function does not have a  
    // return statement  
}  

int main()  
{  
    show(10);  

    return 0;  
}
```

Output 
```
GEEKSFORGEEKS
```

The above program compiles successfully without any warnings to give the output “GEEKSFORGEEKS”. 

### 3. Use **pragma** warning( push ) and **pragma** warning( pop ): 
```Cpp
#pragmawarning( push ) 
#pragmawarning( disable: ThatWarning ) 
//code with ThatWarning here 
#pragmawarning( pop )
```
### 4. The second is to use **pragma** warning( default ): 
```Cpp
#pragmawarning( disable: ThatWarning ) 
//code with ThatWarning here 
#pragmawarning( default: ThatWarning )
```

The problem I see in the second variant is that it discards the original warning level - the warning might have been off before that or its warning level might have been altered. Using default would discard those alterations. 
```Cpp
#ifdefined(__clang__) 
	# pragmaclang diagnostic push 
#endif 

#ifdefined(_MSC_VER) 
	# pragmawarning(push) 
#endif 

#ifdefined(__GNUC__) 
	#pragmaGCC diagnostic error "-Wuninitialized" 
	foo(a);         /* error is given for this one */ 
	#pragmaGCC diagnostic push 
	#pragmaGCC diagnostic ignored "-Wuninitialized" 
	foo(b);         /* no diagnostic for this one */ 
	#pragmaGCC diagnostic pop 
	foo(c);         /* error is given for this one */ 
	#pragmaGCC diagnostic pop  
	foo(d);         /* depends on command line options */ 
#endif 

#ifdefined(YOUR_FAVORITE_COMPILER) 
	# pragmayour compiler push warning 
#endif
```
### 5.  **pragma** GCC poison 
This directive is supported by the GCC compiler and is used to remove an identifier completely from the program. If we want to block an identifier then we can use the **pragma** GCC poison directive. 
**Syntax**
```Cpp
#pragma GCC poison identifier
```

Example 
The below example demonstrates the use of **pragma** GCC poison. 
```C
// C Program to illustrate the 
// **pragma** GCC poison directive 

#include <stdio.h> 

#pragma GCC poison printf 

int main() 
{ 
    int a = 10; 
    if (a == 10) { 
        printf("GEEKSFORGEEKS"); 
    } 
    else 
        printf("bye"); 
    return 0; 
}
```
Output 
```
prog.c: In function 'main': 
prog.c:14:9: error: attempt to use poisoned "printf"                     printf("GEEKSFORGEEKS");          ^ prog.c:17:9: error: attempt to use poisoned "printf"                               printf("bye");          ^
```
The program will give the above error. 

### 6. **pragma** GCC dependency 
The **pragma** GCC dependency allows you to check the relative dates of the current file and another file. If the other file is more recent than the current file, a warning is issued. This is useful if the current file is derived from the other file, and should be regenerated. 

**Syntax**
```Cpp
#pragma GCC dependency "main.c"
```

Example 
In the below program **pragma** GCC dependency “parse.y” is used to indicate that this file depends on the file named “parse.y” 
```C
// C program to demonstrate use of 

#include <stdio.h> 

// Using #pragma GCC dependency to check if "parse.y" file 
// has been modified 

#pragma GCC dependency "solution.c" 

int main() 
{ 
    printf("Hello, Geek!"); 
    return 0; 
}
```
Explanation: At the compile time compiler will check whether the “parse.y” file is more recent than the current source file. If it is, a warning will be issued during compilation. 

### 7.  **pragma** GCC system_header 
The **pragma** GCC system_header directive in GCC is used to tell the compiler that the given file should be treated as if it is a system header file. warnings that will be generated by the compiler for code in that file will be suppressed hence it is extremely useful when the programmer doesn’t want to see warnings or errors. This pragma takes no arguments. It causes the rest of the code in the current file to be treated as if it came from a system header. 

**Syntax**
```Cpp
#pragma GCC system_header
```

Example 

The below example demonstrates the use of **pragma** GCC system_header. 
```Cpp
// external_library.h 
#ifndef EXTERNAL_LIBRARY_H 
#define EXTERNAL_LIBRARY_H 

#pragma GCC system_header 

void externalFunction(); 

#endif
```
The above code is for external library that we want to include in our main code. So to inform the compiler that external_library.h is a system header, and we don’t want to see warnings from it the **pragma** GCC system_header is used. 
```C
// C program to demonstrate #pragma GCC system_header 
#include <stdio.h> 
#include "external_library.h" 

int main() { 
    externalFunction();  // Using a function from the external library 

    printf("Hello, Geek!\n"); 
    return 0; 
}
```
Output 
```
Hello, Geek!
```
**Explanation:** Now inour main program,”external_library.h” header is included and the function declared in it is used. Hello,Geek ! is printed without any warnings. 
### 8.  **pragma** once 
The **pragma** once directive has a very simple concept. The header file containing this directive is included only once even if the programmer includes it multiple times during a compilation. This directive works similar to the #include guard idiom. Use of **pragma** once saves the program from multiple inclusion optimisation. 

**Syntax**
```Cpp
#pragma once
```

Example 
The below example demonstrates the use of **pragma** once. 
```C
// my_header.h 
#pragma once 

void myFunction();
```
Consider the above my_header.h header file in this header file, **pragma** once is used to guard against multiple inclusions. 
```C
// C program to demonstrate the use of pragma once 
#include <stdio.h> 
#include "my_header.h" 

int main() { 
    myFunction();  // Using a function from my_header.h 

    printf("Hello, World!\n"); 
    return 0; 
}
```
Output 
```
Hello, World!
```

