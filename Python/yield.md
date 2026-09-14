---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-06 18:23::48 PM
tags:
  - python
---
# yield
`yield` keyword turns a function into a function generator.

the function generator returns an iterator.

the code inside the functions is not executed when they are first called, but are divided into steps, one step for each yield, and each step is only executed when iterator upon.

Unlike the `return` keyword which stops further execution of the function, the `yield` keyword returns the result so far, and continues to the next step.

The return value will be a list of values, one item for each `yield`.

```python
y = 0  
  
def myFunc():  
  global y  
  y = 10  
  yield "Hello"  
  y = 20  
  yield 51  
  y = 30  
  yield "Good Bye"  
  
#The function is called:  
x = myFunc()  
  
#But y is still 0:  
print("At this point, y is still:", y)  
  
#Run the first iteration:  
next(x)  
  
#And y becomes 10:  
print("Now, y is:", y)  
  
#Run another iteration:  
next(x)  
  
#And y becomes 20:  
print("Now, y is:", y)  
  
#Run another iteration:  
next(x)  
  
#And y becomes 30:  
print("Now, y is:", y)
```





