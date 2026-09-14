---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-06 17:58::49 PM
tags:
  - python
---
# @ symbol, it's name is decorator

They can definitely seem like magic when you first encounter them, but at its core, a **decorator** is just a function that takes another function, adds some new functionality to it, and then returns it.

It is a way to "wrap" a function to extend its behavior without permanently modifying its original source code.

### The "Gift Wrap" Analogy

Imagine you have a plain cardboard box containing a gift (this is your original function). A decorator is like wrapping paper and a bow. When you apply the decorator to the box, you don't change the box itself or the gift inside it, but you _do_ change how it behaves and is presented to the outside world.

### How it Actually Works

In Python, functions are "first-class citizens." This means they can be passed around as arguments to other functions just like standard variables (strings, integers, lists).

A decorator relies on three specific steps:

1. **Taking a function as an argument:** The decorator function receives the target function it is supposed to modify.
2. **Creating a wrapper:** Inside the decorator, a nested function (usually called `wrapper`) is defined. This wrapper executes the extra code (like starting a timer, printing "Before", or opening a log file) and then calls the original function.
3. **Returning the wrapper:** The decorator returns this new `wrapper` function to replace the original one.

### The Syntactic Sugar (`@`)

When you place `@timer` or `@before_after` above a function (like in the code images you shared earlier), Python is automatically taking the function directly below it and passing it into your decorator.

Writing this:
``` Python
@timer
def run():
    time.sleep(2)
```

Is the exact same thing as writing this under the hood:

``` python 
def run():
    time.sleep(2)

# Overwriting 'run' with the wrapped version
run = timer(run) 
```

> [!example] Example 1
> 
> ```python
> import time
> 
> def before_after(func):
>     def wrapper(*args):
>         print("Before")
>         func(*args)
>         print("After")
>     
>     return wrapper
> 
> class Test:
>     @before_after
>     def decorated_method(self):
>         print("run")
> 
> t = Test()
> 	t.decorated_method()
> ```

> [!Example] Example 2
> ``` python
> import time
> 
> def timer(func):
>     def wrapper():
>         before = time.time()
>         func()
>         print("Function took:", time.time() - before, "seconds")
>         
>     return wrapper
> 
> @timer
> def run():
>     time.sleep(2)
> 
> run()
> ```

> [!example] Example 3
> ```Python
> import datetime
> 
> def logger(func):
>     def wrapper(*args, **kwargs):
>         with open("logs.txt", "a") as f:
>             f.write("Called function with " + " ".join([str(arg) for arg in args]) + " at " + str(datetime.datetime.now()) + "\n")
>         val = func(*args, **kwargs)
>         return val
>         
>     return wrapper
> 
> @logger
> def fn(a, b, c=9):
>     print(a + b + c)
> 
> fn(1, 2, c=9)
> ```