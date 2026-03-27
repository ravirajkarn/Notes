---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-02-16 12:39::55 PM
tags:
  - Cpp
  - Library
---

---

# 1. Introduction
----
Gtkmm is wrapper around GTK. 


# 2. Basics
----

> [!info]
> ```cpp
> #include <gtkmm.h> 
> class MyWindow : public Gtk::Window { 
> 	public: 
> 		MyWindow(); 
> }; 
> 
> MyWindow::MyWindow() { 
> 	set_title("Basic application"); 
> 	set_default_size(200, 200); 
> } 
> 
> int main(int argc, char* argv[]) { 
> 	auto app = Gtk::Application::create("org.gtkmm.examples.base"); 
> 	return app->make_window_and_run<MyWindow>(argc, argv); 
> }
> ```

## 2.2 Widgets
It is like widgets inside widgets. 

> [!Example] Example code that adds Gtk::Button
> ```cpp
> m_box.append(m_Button1);
> m_box.append(m_Button2);
> ```
> 
> add Gtk::Box, containing those buttons, to a Gtk::Frame, which has a visible frame and title:
> ```cpp
> m_frame.set_child(m_box);
> ```

## 2.3 Signals
gtkmm or GTK is event-driven. When an event occurs, such as the press of a mouse button, the appropriate signal will be emitted by the widget that was passed.
GTK use libsigc++ library to implement signals.

> [!example]
> ```cpp
> m_button1.signal_clicked().connect( sigc::mem_fun(*this, &HelloWorld::on_button_click));
> ```

----
# 6 Buttons
## 6.1 Button
There are two ways to create a Button. You can specify a label string in the `Gtk::Button` constructor, or set it later with `set_label()`.

To define an accelerator key for keyboard navigation, place an underscore before one of the label's characters and specify `true` for the optional `mnemonic` parameter. For instance:

```cpp
Gtk::Button* pButton = new Gtk::Button("_Something", true);
```

`Gtk::Button` is also a container so you could put any other widget, such as a `Gtk::Image` into it.

The `Gtk::Button` widget has the `clicked` signal which is emitted when the button is pressed and released.

> [!Example]
> 
> ![[buttons.cc]]
> 
> ![[buttons.h]]
> 
> ![[Assets/Gtk_Buttons/CMakeLists.txt]]
> 
> ![[Assets/Gtk_Buttons/CMakePresets.json]]
> 
> ![[Assets/Gtk_Buttons/main.cc]]

# 6.2 ToggleButton
`ToggleButton`s are like normal `Button`s, but when clicked they remain activated, or pressed, until clicked again.

To retrieve the state of the `ToggleButton`, you can use the `get_active()` method. This returns `true` if the button is "down". You can also set the toggle button's state, with `set_active()`. Note that, if you do this, and the state actually changes, it causes the "clicked" signal to be emitted. This is usually what you want.

You can use the `toggled()` method to toggle the button, rather than forcing it to be up or down: This switches the button's state, and causes the `toggled` signal to be emitted.

# 6.3 CheckButton
`Gtk::CheckButton` inherits directly from `Gtk::Widget`. It is similar to `Gtk::ToggleButton`. The only real difference between the two is `Gtk::CheckButton`'s appearance. You can check and set a check button using the same member methods as for `Gtk::ToggleButton`.

> [!Example]
> ![[Assets/Gtk_CheckButton/CMakeLists.txt]]
> 
> ![[Assets/Gtk_CheckButton/CMakePresets.json]]
> 
> ![[Assets/Gtk_CheckButton/examplewindow.cc]]
> 
> ![[Assets/Gtk_CheckButton/examplewindow.h]]
> 
> ![[Assets/Gtk_CheckButton/main.cc]]
> 

## 6.4 Radio Button
There is no separate class for radio buttons. Check buttons and toggle buttons act as radio buttons when they form a group. Only one button in a group can be selected at any one time.
### Groups
You create the buttons, and set up their group afterwards. In the following example, we put 3 radio buttons in a group:

```cpp
auto rb1 = Gtk::make_managed<Gtk::CheckButton>("button1");
auto rb2 = Gtk::make_managed<Gtk::CheckButton>("button2");
auto rb3 = Gtk::make_managed<Gtk::CheckButton>("button3");
rb2->set_group(*rb1);
rb3->set_group(*rb1);
```

We told gtkmm to put all three `CheckButton`s in the same group by using `set_group()` to tell the other `CheckButton`s to share group with the first `CheckButton`.
### Methods
`CheckButton`s and `ToggleButton`s are "off" when created; this means that when you first make a group of them, they will all be off. Don't forget to turn one of them on using `set_active()`.

> [!Example]
> ![[Assets/Gtk_RadioButton/CMakeLists.txt]]
> 
> ![[Assets/Gtk_RadioButton/CMakePresets.json]]
> 
> ![[Assets/Gtk_RadioButton/main.cc]]
> 
> ![[radiobuttons.cc]]
> 
> ![[radiobuttons.h]]
> 

----
# 8 [Miscellaneous Widgets](https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/chapter-misc-widgets.html)
## 8.1 Label
Label is the main method of placing non-editable text in windows, for instance to place a title next to an Entry widget.
The width of the label will be adjusted automatically. You can produce multi-line labels by putting line breaks ("\n") in the label string.

The label text can be justified using the `set_justify()` method. The widget is also capable of word-wrapping, which can be activated with `set_wrap()`.

Gtk::Label supports some simple formatting, for instance allowing you to make some text bold, colored, or larger. You can do this by providing a string to `set_markup()`, using the [Pango Markup syntax](https://docs.gtk.org/Pango/pango_markup.html). For instance, `<b>bold text</b> and <s>strikethrough text</s>` .

## 8.2 Entry
Entry widgets allow the user to enter text. You can change the contents with the `set_text()` method, and read the current contents with the `get_text()` method.

## 8.3 SpinButton
A `SpinButton` allows the user to select a value from a range of numeric values. It has an `Entry` widget with increment and decrement buttons at the side. Clicking the buttons causes the value to 'spin' up and down across the range of possible values. The `Entry` widget may also be used to enter a value directly.

it also have an feature 'auto-repeat' as wall:holding down the increment or decrement button can optionally cause the value to change more quickly the longer the button is held down.

**SpinButton** use an [[#16 Adjustments|Adjustment]] object to hold information about the range of value. [[#16 Adjustments|Adjustment]] attributes are:
- `value`: value for the Spin Button
- `lower`: lower range value
- `upper`: upper range value
- `step_increment`: value to increment/decrement when pressing mouse button 1
- `page_increment`: value to increment/decrement when pressing mouse button 2
- `page_size`: unused
Additionally, mouse button 3 can be used to jump directly to the `upper` or `lower` values.
### Methods
The number of decimal places can be altered using the `set_digits()` method.

You can set the spinbutton's value using the `set_value()` method, and retrieve it with `get_value()`.

The `spin()` method 'spins' the `SpinButton`, as if its increment or decrement button had been clicked. You need to specify a `Gtk::SpinType` to specify the direction or new position.

To prevent the user from typing non-numeric characters into the entry box, pass `true` to the `set_numeric()` method.

To make the `SpinButton` 'wrap' between its upper and lower bounds, use the `set_wrap()` method.

> [!example]
> ![[Assets/Gtk_SpinButton/CMakeLists.txt]]
> 
> ![[Assets/Gtk_SpinButton/CMakePresets.json]]
> 
> ![[examplewindow.cc]]
> 
> ![[examplewindow.h]]
> 
> ![[Assets/Gtk_SpinButton/main.cc]] 
> 

## 8.4 ProgressBar
Progress bars are used to show the status of an ongoing operation. For instance, a `ProgressBar` can show how much of a task has been completed.

## 8.5 InfoBAr
An `InfoBar` may show small items of information or ask brief questions. Unlike a `Dialog`, it appears at the top of the current window instead of opening a new window. Its API is very similar to the [Gtk::Dialog](https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/chapter-dialogs.html "Chapter 17. Dialogs") API.

## 8.6 Tooltips
Tooltips are the little information windows that pop up when you leave your pointer over a widget for a few seconds. Use `set_tooltip_text()` to set a text string as a tooltip on any `Widget`. `Gtk::Tooltip` is used for more advanced tooltip usage, such as showing an image as well as text.

---
# 16 Adjustments
## 16.1 Creating an Adjustment
The `Gtk::Adjustment` is created by its `create()` method which is as follows:

```cpp
Glib::RefPtr<Gtk::Adjustment> Gtk::Adjustment::create(
  double value,
  double lower,
  double upper,
  double step_increment = 1,
  double page_increment = 10,
  double page_size = 0);
```

## 16.2 Using Adjustments the Easy Way
```cpp
// creates its own adjustments 
Gtk::TextView textview; 
// uses the newly-created adjustment for the scrollbar as well 
Gtk::Scrollbar vscrollbar(textview.get_vadjustment(), Gtk::Orientation::VERTICAL);
```

## 16.3 Adjustment Internals
`Gtk::Adjustment` can emit signals. This is, of course, how updates happen automatically when you share an `Adjustment` object between a `Scrollbar` and another adjustable widget; all adjustable widgets connect signal handlers to their adjustment's `value_changed` signal, as can your program.

if you have a `Scale` widget, and you want to change the rotation of a picture whenever its value changes, you would create a signal handler like this:

```cpp
void cb_rotate_picture(MyPicture* picture)
{
  picture->set_rotation(adj->get_value());
...
```

and connect it to the scale widget's adjustment like this:

```cpp
adj->signal_value_changed().connect(sigc::bind<MyPicture*>(sigc::mem_fun(*this,
    &cb_rotate_picture), picture));
```

What if a widget reconfigures the _`upper`_ or _`lower`_ fields of its `Adjustment`, such as when a user adds more text to a text widget? In this case, it emits the `changed` signal.

`Range` widgets typically connect a handler to this signal, which changes their appearance to reflect the change - for example, the size of the slider in a scrollbar will grow or shrink in inverse proportion to the difference between the _`lower`_ and _`upper`_ values of its `Adjustment`.

You probably won't ever need to attach a handler to this signal, unless you're writing a new type of range widget.

```cpp
adjustment->signal_changed();
```

----
# 18 The DrawingArea Widget

## 18.1 The Cairo Drawing Model

The basic concept of drawing in Cairo involves defining 'invisible' paths and then stroking or filling them to make them visible.

To do any drawing in gtkmm with Cairo, you must first get a `Cairo::Context` object. This class holds all of the graphics state parameters that describe how drawing is to be done. This includes information such as line width, color, the surface to draw to, and many other things. This allows the actual drawing functions to take fewer arguments to simplify the interface. Usually, you use the `Cairo::Context` that you get as input data to the draw function that you set with the call to `set_draw_func()`. It's also possible to create a `Cairo::Context` by calling the `Gdk::Surface::create_cairo_context()` and `Gdk::CairoContext::cairo_create()` functions. Since Cairo contexts are reference-counted objects, `cairo_create()` returns a `Cairo::RefPtr<Cairo::Context>` object. (Note the difference between `Gdk::CairoContext` and `Cairo::Context`.)

The following example shows how to set up a Cairo context with a foreground color of red and a width of 2. Any drawing functions that use this context will use these settings.

```cpp
Gtk::DrawingArea myArea;
auto gdkCairoContext = myArea.get_surface()->create_cairo_context();
auto myContext = gdkCairoContext->cairo_create();
myContext->set_source_rgb(1.0, 0.0, 0.0);
myContext->set_line_width(2.0);
    
```

Each `Cairo::Context` is associated with a particular `Gdk::Surface`, so the first line of the above example creates a `Gtk::DrawingArea` widget and the next two lines use its associated `Gdk::Surface` to create a `Cairo::Context` object. The final two lines change the graphics state of the context.

There are a number of graphics state variables that can be set for a Cairo context. The most common context attributes are color (using `set_source_rgb()` or `set_source_rgba()` for translucent colors), line width (using `set_line_width()`), line dash pattern (using `set_dash()`), line cap style (using `set_line_cap()`), and line join style (using `set_line_join()`), and font styles (using `set_font_size()`, `set_font_face()` and others). There are many other settings as well, such as transformation matrices, fill rules, whether to perform antialiasing, and others. For further information, see the [cairomm](http://www.cairographics.org/cairomm/) API documentation.

The current state of a `Cairo::Context` can be saved to an internal stack of saved states and later be restored to the state it was in when you saved it. To do this, use the `save()` method and the `restore()` method. This can be useful if you need to temporarily change the line width and color (or any other graphics setting) in order to draw something and then return to the previous settings. In this situation, you could call `Cairo::Context::save()`, change the graphics settings, draw the lines, and then call `Cairo::Context::restore()` to restore the original graphics state. Multiple calls to `save()` and `restore()` can be nested; each call to `restore()` restores the state from the matching paired `save()`.

## 18.2 Drawing Straight Lines

----
# 24 Timeouts, I/O and Idle Function

## 24.1 Timeouts
Using the following method we can create a timeout method that will be called every few milliseconds. 
```cpp
sigc::connection Glib::SignalTimeout::connect(const sigc::slot<bool()>& slot, unsigned int interval, int priority = Glib::PRIORITY_DEFAULT);
```

**Method to Disconnect/Destroying**
1. this can be disconnected with `disconnect()` method:
```cpp
my_connection.disconnect()
```
2. We can use signal handler. to destroy the connection. it should of type `sigc::slot<bool()>`. our signal handler has to return a value of the type `bool`. A simple method might look like this:
```cpp
bool MyCallback() { std::cout << "Hello World!\n" << std::endl; return true; }
```
We can **stop timeout method by returning `false`** from your signal handler. if it return **`true` then it called repeatedly**.

> [!Example]
> 
> ![[Assets/Glib_SignalTimeout/main.cc]]
> ![[timerexample.cc]]
> ![[timerexample.h]]
> ![[Assets/Glib_SignalTimeout/CMakeLists.txt]]
> ![[CMakePresets.json]]
> 

## 24.2 [Monitoring I/O](https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/sec-monitoring-io.html)
We can check for data on a file descriptor with Glib. Useful for networking applications.
```cpp
sigc::connection Glib::SignalIO::connect(const sigc::slot<bool(Glib::IOCondition)>& slot, Glib::PollFD::fd_t fd, Glib::IOCondition condition, int priority = Glib::PRIORITY_DEFAULT);
```
The first argument is a slot you wish to have called when the specified event (see argument 3) occurs on the file descriptor you specify using argument two. Argument three may be one or more (using `|`) of:
- Glib::IOCondition::IO_IN - Call your method when there is data ready for reading on your file descriptor.
- Glib::IOCondition::IO_OUT - Call your method when the file descriptor is ready for writing.
- Glib::IOCondition::IO_PRI - Call your method when the file descriptor has urgent data to be read.
- Glib::IOCondition::IO_ERR - Call your method when an error has occurred on the file descriptor.
- Glib::IOCondition::IO_HUP - Call your method when hung up (the connection has been broken usually for pipes and sockets).

## 24.3 Idle Functions
if we want to specify a method that get called when nothing else is happening, use the following:
```cpp
sigc::connection Glib::SignalIdle::connect(const sigc::slot<bool()>& slot, int priority = Glib::PRIORITY_DEFAULT_IDLE);
```
This causes gtkmm to call the specified method whenever nothing else is happening. You can add a priority (lower numbers are higher priorities). There are two ways to remove the signal handler: calling `disconnect()` on the `sigc::connection` object, or returning `false` in the signal handler, which should be declared as follows:
```cpp
bool idleFunc();
```


---
# 25 Memory Management

## 25.1 Widgets
We can control the lifetime of any widget in the same manner as any other C++ object. This allows us to use `new` and `delete` to create and destroy objects dynamically or to use regular class members. 

### Class Scope widgets
The primary disadvantage of using class scope widgets is revealing the class implementation rather than the class interface in the class header.

> [!example]
> ```cpp
> #include <gtkmm/button.h>
> #include <gtkmm/window.h>
> class Foo : public Gtk::Window
> {
> private:
>   Gtk::Button theButton;
>   // will be destroyed when the Foo object is destroyed
> };
> ```

### Function scope widgets
The advantages to function scope over class scope are the increased data hiding and reduced dependencies.

> [!example]
> ```cpp
> {
>   Gtk::Button aButton;
>   aButton.set_visible(true);
>   ...
>   app->run();
> }
> ```

### Dynamic allocation with new and delete
This is not strictly required, as the `new` and `delete` operators may also be used, but modern C++ style discourages those in favor of safer models of memory management, so it is better to create widgets using `Gtk::make_managed()` and let their parent destroy them, than to manually perform dynamic allocation.

> [!example]
> ```cpp
> auto pButton = new Gtk::Button("Test");
> // do something useful with pButton
> delete pButton;
> ```


### Managed Widgets
let a widget's container control when the widget is destroyed. In most cases, you want a widget to last only as long as the container it is in. To delegate the management of a widget's lifetime to its container, create it with `Gtk::make_managed()` and then pack it into its container with `Gtk::Box::append()` or a similar method. Now the widget will be destroyed whenever its container is destroyed.

> [!example]
> ```cpp
> MyContainer::MyContainer() 
> { 
> 	auto pButton = Gtk::make_managed<Gtk::Button>("Test"); 
> 	append(*pButton); //add *pButton to MyContainer 
> }
> ```

## 25.2 Shared resources
Some objects, Such as `Gdk::Pixbuf` and `Pango::Fonts` are obtained from a shared store. Therefor we cannot instantiate your own instances. These classes typically inherit from Glib::Object. Rather than requiring you to reference and un-reference these objects, gtkmm use the `Glib::RefPtr<>` smart-pointer. Cairomm has its own smart-pointer, `Cairo::RefPtr<>`.

----
# 26 Gtk::Builder
We can hard code the UI with C++ code. But, this become tedious and repetitive And requires a recompilation to show changes. The [Cambalache](https://gitlab.gnome.org/jpu/cambalache) application allows us to layout widgets on screen and then save an XML description of the arrangement. Then we can use `Gtk::builder` API to load that XML file at runtime and obtain a pointer.

## 26.1 Loading the .ui file
---

`Gtk::Builder` must be used via a `Glib::RefPtr`. Like all such classes, you need to use a `create()` method to instantiate it. For instance,

> [!example]
> ```cpp
> auto builder = Gtk::Builder::create_from_file("basic.ui");
> ```

This will instantiate the windows defined in the .ui file.

To instantiate just one window, or just one of the child widgets, you can specify the name of a widget as the second parameter. For instance,

> [!example]
> ```cpp
> auto builder = Gtk::Builder::create_from_file("basic.ui", "treeview_products");
> ```

## 26.2 Accessing widgets
----
To access a widget, for instance to show a dialog, use the `get_widget()` method, providing the widget's name. This name should be specified in the `Cambalache Window.` ==if the widget could not be found, or is of the wrong type, then the pointer will be set to `nullptr`.== 

> [!example]
> ```cpp
> auto pDialog = builder->get_widget<Gtk::Window>("DialogBasic");
> ```

==`Gtk::Builder` checks for a null pointer, and checks that the widget is of the expected type, and will show warnings on the command line about these.==

![[Assets/Gtk_Builder/main.cc]]
![[basic.ui]]
![[CMakeLists.txt]]


## 26.3 Using derived widgets
----
https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/sec-builder-using-derived-widgets.html

