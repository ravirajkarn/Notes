---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-13 09:48::12 AM
tags:
  - Set
  - python
---
# set
more detailed explanation in https://www.w3schools.com/python/python_sets.asp
- Set items are unordered, unchangeable, and do not allow duplicate values.
- A set is a collection which is _unordered_, _unchangeable*_, and _unindexed_.
- From Python's perspective, sets are defined as objects with the data type 'set':
```
<class 'set'>
```
## method
- To determine how many items a set has, use the `len()` function.
- Set items can be of any data type
- It is also possible to use the set() constructor to make a set.
- You cannot access items in a set by referring to an index or a key
	- But you can loop through the set items using a `for` loop, or ask if a specified value is present in a set, by using the `in` keyword.
- To add one item to a set use the `add()` method.
- To add items from another set into the current set, use the `update()` method.
- The object in the `update()` method does not have to be a set, it can be any iterable object (tuples, lists, dictionaries etc.).
- The `union()` and `update()` methods joins all items from both sets.
- You can use the `|` operator instead of the `union()`
> [!warning]
>  The  `|` operator only allows you to join sets with sets, and not with other data types like you can with the  `union()` method.
- The `intersection()` method keeps ONLY the duplicates.
> [!tip]
> You can use the `&` operator instead of the `intersection()`

> [!info]
> The `&` operator only allows you to join sets with sets, and not with other data types like you can with the `intersection()` method.
- The `intersection_update()` method will also keep ONLY the duplicates, but it will change the original set instead of returning a new set.
- The `difference()` method keeps the items from the first set that are not in the other set(s).

> [!info] 
> The `-` operator only allows you to join sets with sets, and not with other data types like you can with the `difference()` method.
- The `symmetric_difference()` method keeps all items EXCEPT the duplicates.
> [!info] 
> The `^` operator only allows you to join sets with sets, and not with other data types like you can with the `symmetric_difference()` method.
- The `symmetric_difference_update()` method will also keep all but the duplicates, but it will change the original set instead of returning a new set.

## remove
- To remove an item in a set, use the `remove()`, or the `discard()` method.

> [!warning] 
> If the item to remove does not exist, `remove()` will raise an error. 

> [!tip]
> If the item to remove does not exist, `discard()` will **NOT** raise an error.

- You can also use the `pop()` method to remove an item, but this method will remove a random item, so you cannot be sure what item that gets removed.
- The `clear()` method empties the set
- The `del` keyword will delete the set completely:

| Method                                                                                                    | Shortcut | Description                                                                    |
| --------------------------------------------------------------------------------------------------------- | -------- | ------------------------------------------------------------------------------ |
| [add()](https://www.w3schools.com/python/ref_set_add.asp)                                                 |          | Adds an element to the set                                                     |
| [clear()](https://www.w3schools.com/python/ref_set_clear.asp)                                             |          | Removes all the elements from the set                                          |
| [copy()](https://www.w3schools.com/python/ref_set_copy.asp)                                               |          | Returns a copy of the set                                                      |
| [difference()](https://www.w3schools.com/python/ref_set_difference.asp)                                   | `-`      | Returns a set containing the difference between two or more sets               |
| [difference_update()](https://www.w3schools.com/python/ref_set_difference_update.asp)                     | `-=`     | Removes the items in this set that are also included in another, specified set |
| [discard()](https://www.w3schools.com/python/ref_set_discard.asp)                                         |          | Remove the specified item                                                      |
| [intersection()](https://www.w3schools.com/python/ref_set_intersection.asp)                               | `&`      | Returns a set, that is the intersection of two other sets                      |
| [intersection_update()](https://www.w3schools.com/python/ref_set_intersection_update.asp)                 | `&=`     | Removes the items in this set that are not present in other, specified set(s)  |
| [isdisjoint()](https://www.w3schools.com/python/ref_set_isdisjoint.asp)                                   |          | Returns True if NO items of this set is present in another set                 |
| [issubset()](https://www.w3schools.com/python/ref_set_issubset.asp)                                       | `<=`     | Returns True if all items of this set is present in another set                |
|                                                                                                           | `<`      | Returns True if all items of this set is present in another, _larger_ set      |
| [issuperset()](https://www.w3schools.com/python/ref_set_issuperset.asp)                                   | `>=`     | Returns True if all items of another set is present in this set                |
|                                                                                                           | `>`      | Returns True if all items of another, _smaller_ set is present in this set     |
| [pop()](https://www.w3schools.com/python/ref_set_pop.asp)                                                 |          | Removes an element from the set                                                |
| [remove()](https://www.w3schools.com/python/ref_set_remove.asp)                                           |          | Removes the specified element                                                  |
| [symmetric_difference()](https://www.w3schools.com/python/ref_set_symmetric_difference.asp)               | `^`      | Returns a set with the symmetric differences of two sets                       |
| [symmetric_difference_update()](https://www.w3schools.com/python/ref_set_symmetric_difference_update.asp) | `^=`     | Inserts the symmetric differences from this set and another                    |
| [union()](https://www.w3schools.com/python/ref_set_union.asp)                                             | `\|`     | Return a set containing the union of sets                                      |
| [update()](https://www.w3schools.com/python/ref_set_update.asp)                                           | `\|=`    | Update the set with the union of this set and others                           |
## Python frozenset
`frozenset` is an immutable version of a set.
Like sets, it contains unique, unordered, unchangeable elements.
Unlike sets, elements cannot be added or removed from a frozenset.
- Use the `frozenset()` constructor to create a frozenset from any iterable.

| Method                 | Shortcut   | Description                                                      |
| ---------------------- | ---------- | ---------------------------------------------------------------- |
| copy()                 |            | Returns a shallow copy                                           |
| difference()           | `-`        | Returns a new frozenset with the difference                      |
| intersection()         | `&`        | Returns a new frozenset with the intersection                    |
| isdisjoint()           |            | Returns True if there is NO intersection between two frozensets  |
| issubset()             | `<=` / `<` | Returns True if this frozenset is a (proper) subset of another   |
| issuperset()           | `>=` / `>` | Returns True if this frozenset is a (proper) superset of another |
| symmetric_difference() | `^`        | Returns a new frozenset with the symmetric differences           |
| union()                | `\|`       | Returns a new frozenset containing the union                     |
