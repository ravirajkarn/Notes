---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-10 18:11::13 PM
tags:
  - python
---
## Dictionary
Have very good documentation:
https://www.w3schools.com/python/python_dictionaries.asp

- Dictionaries are used to store data values in key:value pairs.
- Dictionary items are ordered, changeable, and do not allow duplicates.
- Dictionaries are changeable, meaning that we can change, add or remove items after the dictionary has been created.
- Dictionaries cannot have two items with the same key
- To determine how many items a dictionary has, use the `len()` function
- The values in dictionary items can be of any data type.
> [!example] 
> ```python
> thisdict = {  
> 	"brand": "Ford",  
> 	"model": "Mustang",  
> 	"year": 1964  
> }  
> print(thisdict)
> ```

- From Python's perspective, dictionaries are defined as objects with the data type 'dict':
```
<class 'dict'>
```
## Actions or Functions:
- It is also possible to use the `dict()` constructor to make a dictionary.
- the items of a dictionary by referring to its key name, inside square brackets:
	- There is also a method called `get()` that will give you the same result:
- The `keys()` method will return a list of all the keys in the dictionary.
- The `values()` method will return a list of all the values in the dictionary.
- The `items()` method will return each item in a dictionary, as tuples in a list.
- To determine if a specified key is present in a dictionary use the `in` keyword:

> [!example]
> ```python
> thisdict = {  
> 	"brand": "Ford",  
> 	"model": "Mustang",  
> 	"year": 1964  
> }  
> 
> if "model" in thisdict:  
> 	print("Yes, 'model' is one of the keys in the thisdict dictionary")
> ```
- Make a copy of a dictionary with the `copy()` method
- Make a copy of a dictionary with the `dict()` function
### Changing or Modify:
- You can change the value of a specific item by referring to its key name

> [!example]
> ```python
> thisdict = {  
> 	"brand": "Ford",  
> 	"model": "Mustang",  
> 	"year": 1964  
> }  
> thisdict["year"] = 2018
> ```

- The `update()` method will update the dictionary with the items from the given argument.
- The `pop()` method removes the item with the specified key name
- The `del` keyword removes the item with the specified key name

> [!warning]
> - The `del` keyword can also delete the dictionary completely
> ```python
> thisdict = {  
> 	"brand": "Ford",  
> 	"model": "Mustang",  
> 	"year": 1964  
> }  
> del thisdict  
> print(thisdict) #this will cause an error because "thisdict" no longer exists.
> ```
- The `clear()` method empties the dictionary

## Nested Dictionaries
1. ```python 
child1 = {  
  "name" : "Emil",  
  "year" : 2004  
}  
child2 = {  
  "name" : "Tobias",  
  "year" : 2007  
}  
child3 = {  
  "name" : "Linus",  
  "year" : 2011  
}  
  
myfamily = {  
  "child1" : child1,  
  "child2" : child2,  
  "child3" : child3  
}
```

2. ```python
   myfamily = {  
  "child1" : {  
    "name" : "Emil",  
    "year" : 2004  
  },  
  "child2" : {  
    "name" : "Tobias",  
    "year" : 2007  
  },  
  "child3" : {  
    "name" : "Linus",  
    "year" : 2011  
  }  
}
   ```


| Method                                                                         | Description                                                                                                 |
| ------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------- |
| [clear()](https://www.w3schools.com/python/ref_dictionary_clear.asp)           | Removes all the elements from the dictionary                                                                |
| [copy()](https://www.w3schools.com/python/ref_dictionary_copy.asp)             | Returns a copy of the dictionary                                                                            |
| [fromkeys()](https://www.w3schools.com/python/ref_dictionary_fromkeys.asp)     | Returns a dictionary with the specified keys and value                                                      |
| [get()](https://www.w3schools.com/python/ref_dictionary_get.asp)               | Returns the value of the specified key                                                                      |
| [items()](https://www.w3schools.com/python/ref_dictionary_items.asp)           | Returns a list containing a tuple for each key value pair                                                   |
| [keys()](https://www.w3schools.com/python/ref_dictionary_keys.asp)             | Returns a list containing the dictionary's keys                                                             |
| [pop()](https://www.w3schools.com/python/ref_dictionary_pop.asp)               | Removes the element with the specified key                                                                  |
| [popitem()](https://www.w3schools.com/python/ref_dictionary_popitem.asp)       | Removes the last inserted key-value pair                                                                    |
| [setdefault()](https://www.w3schools.com/python/ref_dictionary_setdefault.asp) | Returns the value of the specified key. If the key does not exist: insert the key, with the specified value |
| [update()](https://www.w3schools.com/python/ref_dictionary_update.asp)         | Updates the dictionary with the specified key-value pairs                                                   |
| [values()](https://www.w3schools.com/python/ref_dictionary_values.asp)         | Returns a list of all the values in the dictionary                                                          |