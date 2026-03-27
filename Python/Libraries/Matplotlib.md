---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-12-11 15:16::20 PM
tags:
  - python
  - Library
---

# Matplotlib
It is library to create graphs in python.

we usually use pyplot in our projects.

## Various function
- `pyplot.subplot()`: It help in organising the graphs in different graphs. such as using graph paper. If you want to make to graphs you will use two graph paper.
> [!example] Example
> `graph0= pyplot.subplot() `

- `pyplot.plot(x_Intersection, zeroArr, color='red', marker='o')`: This is responsible for plotting the value in graph.
> [!example] Example
> `graph0.plot(x_Intersection, zeroArr, color='red', marker='o')`

- `pyplot.grid(True)`: Responsible for creating grid in graph you can configure it how the grid will look.
> [!example] Example
> `graph0.grid(True, linestyle='--')`

- `pyplot.axhline(0, color='Black')`: creating horizontal line in 0
- `pyplot.axvline(0, color='Black')`: creating vertical line in 0
- `pyplot.show()`: responsible to creating showing graph in a window.

- `sympy.lambdify() ` **Converting Symbolic Expression into normal Expression**. It output a function.
> [!example] Example
> ```python
> # 2. Create a "normal" Python/NumPy function from the symbolic expression
> # The first argument is the variable(s) the function takes
> # The second argument is the expression to use
> # The third argument specifies which library to use for numerical calculation (NumPy is best for arrays)
> normal_py_func = sympy.lambdify(x, symbolic_expression, "numpy")


- `sympify()`: Converting Normal Equation to Symbolic Expression
> [!example] Example
> ``` Python
> # 1. Define the variables we expect to see in the expression
x, y = symbols('x y')
> # 2. Define your expression as a standard Python string (this is your "normal expression" source)
normal_expression_string = " (x - 1)*(x - 2)*(x - 3) "
> # 3. Convert the string into a manipulable symbolic object
symbolic_expr = sympify(normal_expression_string)
