---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 05-09-2025 11:28::51 AM
tags:
  - Cpp
  - Cpp17
---
# std::optional

Any instance of `optional` at any given point in time either _contains a value_ or _does not contain a value_.

If an `optional` contains a value, the value is guaranteed to be [nested within](https://en.cppreference.com/w/cpp/language/objects.html#Address "cpp/language/object") the `optional` object. Thus, an `optional` object models an object, not a pointer, even though [operator*()](https://en.cppreference.com/w/cpp/utility/optional/operator%252A.html "cpp/utility/optional/operator*") and [operator->()](https://en.cppreference.com/w/cpp/utility/optional/operator%252A.html "cpp/utility/optional/operator*") are defined.

When an object of type `optional<T>` is [contextually converted to bool](https://en.cppreference.com/w/cpp/language/implicit_cast.html#Contextual_conversions "cpp/language/implicit conversion"), the conversion returns true if the object contains a value and false if it does not contain a value.

The `optional` object contains a value in the following conditions:

- The object is initialized with/assigned from a value of type `T` or another `optional` that contains a value.

The object does not contain a value in the following conditions:

- The object is default-initialized.
- The object is initialized with/assigned from a value of type [std::nullopt_t](https://en.cppreference.com/w/cpp/utility/optional/nullopt_t.html "cpp/utility/optional/nullopt t") or an `optional` object that does not contain a value.
- The member function [reset()](https://en.cppreference.com/w/cpp/utility/optional/reset.html "cpp/utility/optional/reset") is called.


#### example
```Cpp
#include <iostream>
#include <optionsl>
#include <string>

using namespace std;

std::optional<string> getSomeString(bool a){
	if (a) {
	return "CppNuts";
	}
	return {}
}

int main(){

	if(auto mystr = getSomeString(true)){
		cout << *mystr << endl;
	}else{
		cout << "No value" << endl;
	}
	
	return 0;
}
```