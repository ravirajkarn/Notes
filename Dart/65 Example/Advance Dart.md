---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-26T21:49:00
tags:
  - Dart
  - 65-Example
---
## 1. Arrow Functions(Lambdas) 

We can use: 
`=> xxx`
Instead of  
`{return 0;}` 

Example Code 
```Dart
num divideNonLambda(num arg1, num arg2) { 
	return arg1 / arg2; 
} 

num divideLambda(num arg1, num arg2) => arg1 / arg2; 

void main() { 
	print('non-lambda ${divideNonLambda(6, 2)}'); 
	print('non-lambda ${divideNonLambda(9, 2)}'); 
	print('non-lambda ${divideNonLambda(9, 2.5)}'); 
	print('lambda ${divideLambda(6, 2)}'); 
	print('lambda ${divideLambda(9, 2)}'); 
	print('lambda ${divideLambda(9, 2.5)}'); 
} 
```
Output 
```Bash
non-lambda 3 
non-lambda 4.5 
non-lambda 3.6 
lambda 3 
lambda 4.5 
lambda 3.6 
```

## 2. Operator Overloading
It same concept as C++ where we redefine the preexisting operator.

> [!example]
> ```Dart
> class Car{
> Strig _make;
> String _model;
> String _imgaeSrc;
>
> Car(this._make, this._model, this._imageSrc);
>
> operator ==(other) => (other is Car) && (_make == Other._make) && (_model == other._model);
> 
> int get hasCode => _make.hashCode ^ _model.hashCode ^ _imageSrc.hashCode;
> }
> ```

> [!warning] Warning - hashCode 
> Note that when you override the '\==', you need to override the 'hashCode' method as well. if you don't do that then Flutter will give you a warning.
> 

### Equatable
In Flutter, manually writing hashCode is tedious and error-prone. In flutter we can always use a package called `equatable`.

instead of writing the math Our-self,

> [!example]
> ```Dart
> class User extends Equatable{
> 	final String id;
> 	User(this.id);
> 	
> 	@override
> 	List<Object> get props => [id];
> }
> ```

## 3. Collections
this classed are contained in the 'dart"collection' library.
To use this library in your code:
`import 'dart:collection';`
### Lists
list are like vector in c++

> [!example] 
> ```Dart
> Class Person{
> 	String _firstName;
> 	String _phone;
> 	Person(this._firstName, this._lastName, this._phone);
> 	
> 	to Strign(){
> 	return "${_firstName} ${_lastName} ${_phoen}";
> 	}
>  }
> 
> void main()
> List<Person> list = [
> 	Person("Mark", "Clow", "40431244462"),
> 	Person("Brant", "Sandermine", "4243124462"),
> 	Person("Phillip", "Perry", "4243124444")
>  ];
> print("Not sorted: ${list}");
> 
> list.sort((a,b) => a._firstName.compareTo(b._lastName));
> print("Sorted by first name: ${list}");
> 
> list.sort((a,b) => a.._listName.compareTo(b._lastName));
> print("Sorted by last name: ${list}");
> ```

### Maps
maps are just like maps in c++. 

> [!NOTE] Title
> ```Dart
> void main() {
> 	Map<String, String> stateNamesByStateCode =
> 	{"AL": "Alamaba",
> 	"AK": "Alaska",
> 	"AR": "Arkansas",
> 	"AZ": "Arizona"
>  };
>  stateNamesByStateCode["GA"] = "Georgia";
>  for (String key in stateNamesByStateCode.keys){
> 	print(stateNamesByStateCode[key]);  
>  }
>  
>  print("\nGet just one: ${stateNamesByStateCode["AK"]}");
> }
> ```

## 4. Defensive Programming 
When you are developing code, you will frequently come across bugs, where things aren’t going as expected. For example, you have a variable with a value that you never expected. 

This is where assertions come in. An assertion is a statement that something is expected to be always true at that point in the code. If not, the assertion will throw an exception. 

This is a form of Defensive Programming. 

Example Code 
```Dart
void main() { 
	// .. some good code that calculates age 
	int age1 = 50; 
	checkAge(age1); 
	// .. some good code that calculates age 
	// .. some bad code that calculates age incorrectly 
	int age2 = 150; 
	checkAge(age2); 
	// .. some bad code that calculates age incorrectly 
} 

void checkAge(int age) { 
	assert(age < 112, "bad age ${age}"); 
} 
```
Output 
```Bash
Uncaught exception: 
Assertion failed: "bad age 150" 
```

## 5. Error & Exception Handling 
Dart also provides a finally block that will always be executed no matter if any exception is thrown or not. 
```Dart
void main() { 
	try { 
		// do something here \
	} catch (e) { 
		// print exception 
		print(e); 
	} finally { 
		// always executed 
		print('I will always be executed!'); 
	} 
} 
```
If you know you want to catch a specific Exception then you can use an **‘on’ instead of a ‘catch’**. Consider leaving a ‘catch’ at the bottom to catch other Exceptions.

## 6. Asynchronicity
Asynchronicity is the ability to do multiple things at the same time.
