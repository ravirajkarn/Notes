---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-02-21 09:14::29 AM
tags:
  - Cpp
  - Library
  - Header
---
# [libsigc++](https://libsigcplusplus.github.io/libsigcplusplus/reference/html/index.html) 
It the library used by [[gtkmm]] for managing the signals, like button clicked or other.

## Adaptors
----
### Modules
#### 1. `bind(), bind_return()`
As the name it **"bind in" extra arguments** to a  function when you connect it to a signal.
##### `bind()`
> [!question] The Problem it Solves
> Imagine we have three different buttons, and we want them all to trigger the same function when clicked. But how does the function know which button was clicked?
> 
> The `signal_clicked()` event in GTK doesn't send any arguments. it just say "I was clicked."
> 
> ```cpp
> void on_button_clicked(int button_id){
> 	std::cout << "Button " << button_id << " was clicked!";
> }
> ```
>  
> we cannot just connect it normally, because GTK will try to call `on_button_clicked()` with zero arguments, causing a compiler error.

> [!success] Solution
> we can use `sigc::bind()` to attach this missing `button_it` argument at the exact moment you connect the signal.
> ```cpp
> button1.signal_clicked().connect(
> 	sigc::bind(sigc::mem_fun(*this, &MyWindow::on_button_clicked), 1)
> );
> 
> button1.signal_clicked().connect(
> 	sigc::bind(sigc::mem_fun(*this, &MyWindow::on_button_clicked), 2)
> );
> ```

> [!success] Modern C++ Alternative: Lambdas
> While `sigc::bind()` is the traditional gtkmm way of doing things, Modern C++ introduces lambdas.
> 
> ```cpp
> int id = 1;
> button1.signal_clicked().connect([this, id](){on_button_clicked(id);
> });
> ```
##### `bind_return()`
same as `bind()`, But it forces a return a specific value, regardless of what that function actually returns(or even if it returns nothing at all).


> [!warning] The Problem
> Suppose we write a function which return number or any thing even void. 
> if we try to connect this void function to a signal that expects a bool, the C++ compiler will throw a massive error.

> [!success] Solution
> Instead of rewriting the entire function to return a `boolen` value. we can wrap it in `sigc::bind_return()`. This tells `libsigc++`: "Run this function, ignore what it actually returns, and just return this specific value instead"
> ```cpp
> // Run update_clock_ui, and when it finishes, automatically return 'true'
> Glib::signal_timeout().connect(
> 	sigc::bind_return(sigc::mem_fun(*this, &MyWindow::update_clock_ui), true), 
> 	1000 // 1000ms (1 second)
> );
> ```

> [!success] Modern C++ Alternative: Lambdas
> Just like `sigc::bind()`. Modern C++ introduces lambdas.
> 
> ```cpp
> Glib::signal_timeout().connect(
> 	[this]() -> bool {
> 	update_clock_ui();
> 	return true;
> 	},
> 	1000
> );
> ```
