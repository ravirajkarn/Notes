---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-11 09:09::12 AM
tags:
  - python
  - List
---
# List
A good documentation on https://www.w3schools.com/python/python_lists.asp

Lists are used to store multiple items in a single variable.
```python
mylist = ["apple", "banana", "cherry"]
```

- List items are ordered, changeable, and allow duplicate values.
- When we say that lists are ordered, it means that the items have a defined order, and that order will not change.
- If you add new items to a list, the new items will be placed at the end of the list.
- To determine how many items a list has, use the `len()` function
- From Python's perspective, lists are defined as objects with the data type 'list':
```
<class 'list'>
```
- It is also possible to use the `list()` constructor when creating a new list.
- list items are indexed and you can access them by referring to the index number
- Negative indexing means start from the end, `-1` refers to the last item, `-2` refers to the second last item etc.
- You can specify a range of indexes by specifying where to start and where to end the range.
	- When specifying a range, the return value will be a new list with the specified items.
```python
thislist[2:5]
```
- To determine if a specified item is present in a list use the `in` keyword
## Modify
- To insert a new list item, without replacing any of the existing values, we can use the `insert()` method.
- To add an item to the end of the list, use the `append()` method
- To insert a list item at a specified index, use the `insert()` method.
```python
thislist.insert(1, "orange")
```
- To append elements from _another list_ to the current list, use the `extend()` method.
- The `remove()` method removes the specified item.
- If there are more than one item with the specified value, the `remove()` method removes the first occurrence
```python 
thislist = ["apple", "banana", "cherry", "banana", "kiwi"]  
thislist.remove("banana")
```
- The `pop()` method removes the specified index.
- The `del` keyword also removes the specified index
- The `del` keyword can also delete the list completely
- The `clear()` method empties the list.
- You can use the built-in List method `copy()` to copy a list
- Another way to make a copy is to use the built-in method `list()`
- You can also make a copy of a list by using the `:` (slice) operator.
- One of the easiest ways are by using the `+` operator.
```python
list1 = ["a", "b" , "c"]  
list2 = [1, 2, 3]  
  
for x in list2:  
  list1.append(x)  

list3 = list1 + list2
list1.extend(list2)

print(list1)
```

## Loop
- You can loop through the list items by using a `for` loop
- Use the `range()` and `len()` functions to create a suitable iterable.
```python
thislist = ["apple", "banana", "cherry"]  
for i in range(len(thislist)):  
  print(thislist[i])
```
- You can loop through the list items by using a `while` loop.
- List objects have a `sort()` method that will sort the list alphanumerically, ascending.
- By default the `sort()` method is case sensitive, resulting in all capital letters being sorted before lower case letters
- To sort descending, use the keyword argument `reverse = True`
- You can also customize your own function by using the keyword argument `key = function`
```python
def myfunc(n):  
  return abs(n - 50)  
  
thislist = [100, 50, 65, 82, 23]  
thislist.sort(key = myfunc)  
print(thislist)
```
- The `reverse()` method reverses the current sorting order of the elements


| Method                                                             | Description                                                                  |
| ------------------------------------------------------------------ | ---------------------------------------------------------------------------- |
| [append()](https://www.w3schools.com/python/ref_list_append.asp)   | Adds an element at the end of the list                                       |
| [clear()](https://www.w3schools.com/python/ref_list_clear.asp)     | Removes all the elements from the list                                       |
| [copy()](https://www.w3schools.com/python/ref_list_copy.asp)       | Returns a copy of the list                                                   |
| [count()](https://www.w3schools.com/python/ref_list_count.asp)     | Returns the number of elements with the specified value                      |
| [extend()](https://www.w3schools.com/python/ref_list_extend.asp)   | Add the elements of a list (or any iterable), to the end of the current list |
| [index()](https://www.w3schools.com/python/ref_list_index.asp)     | Returns the index of the first element with the specified value              |
| [insert()](https://www.w3schools.com/python/ref_list_insert.asp)   | Adds an element at the specified position                                    |
| [pop()](https://www.w3schools.com/python/ref_list_pop.asp)         | Removes the element at the specified position                                |
| [remove()](https://www.w3schools.com/python/ref_list_remove.asp)   | Removes the item with the specified value                                    |
| [reverse()](https://www.w3schools.com/python/ref_list_reverse.asp) | Reverses the order of the list                                               |
| [sort()](https://www.w3schools.com/python/ref_list_sort.asp)       | Sorts the list                                                               |