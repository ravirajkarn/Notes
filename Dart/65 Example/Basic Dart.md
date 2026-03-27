---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-26T21:39:00
tags:
  - Dart
  - 65-Example
---
To create a dart project use  
- `Dart create "project name"`

## Feature of Dart programming: 

- Statically-typed languages & Dynamically-typed languages. 
    - Statically-typed : int, double, bool, String, StringBuffer, RegExp, List, Map, Set, etc 
    - Dynamically typed : var and dynamic          
	    - **var :** Once initialised, the type cannot change.
	    - **dynamic :** We can store string, then change it to int, then list.
        - Type Inference: when the program runs, the runtime figures out what the variable types are based on the values they are set to. 

- Type Matching : is keyword. 
- Run time Object type: runtimeType 
- Interpolation: ${expression}     
- Raw String: escape sequence is allowed. We can prefix the string with an 'r' to indicate to tell Dart to treat the string differently, to ignore escape characters.  

- Object-Orientated Language Features: 
    - Private Class, Variables & Methods 
        - If a class name, instance variable or method starts with an underscore, it's private and cannot be accessed outside the Dart file in which it is declared. 
    - Factory Constructors         
    - Instance Variables/Unspecified Visibility : You don't have to specify the visibility of instance variable and if you don't they are made public. 
    - Constructor and method parameters are very flexible. We can define them anywhere.

- Required Decorator 
    - You can add the ‘@required’ decorator to named parameters to make them required. This is not a part of Dart, but it is part of Flutter. 
    - Example Code 
	    We define a constructor for SelectButton that requires both ‘text’ and ‘onTap’ named parameters. 
		`SelectButton({@required this.text, @required this.onTap});
	    If you declare a named parameter as ‘@required’ and the developer writes code that does not supply that parameter: 
	    `SelectButton(text: "YES"),`  
	    then the following compilation error occurs:     
    **`warning:`** The parameter `onTap` is required. (missing_required_param at [yes_no] lib/main.dart:58) 

- Method Cascades: 
Example Code 
```Dart
class Logger { 
	void log(dynamic v){ 
		print(DateTime.now().toString() + ' ' + v); 
	} 
} 

main(){ 
	// Without method cascades 
	new Logger().log('program started'); 
	new Logger().log('doing something'); 
	new Logger().log('program finished'); 
	
	// With method cascades
	new Logger() 
		..log('program started') 
		..log('going something') 
		..log('program finished'); 
} 
```
Output:
```Shell
2018-12-30 09:28:39.686 program started 
2018-12-30 09:28:39.686 doing something 
2018-12-30 09:28:39.686 program finished 
2018-12-30 09:28:39.686 program started 
2018-12-30 09:28:39.686 going something 
2018-12-30 09:28:39.686 program finished
```