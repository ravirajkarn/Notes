---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-08-03T07:14:00
tags:
  - Cpp
  - Library
  - terminal
---
# \#include\<ncurses>
## Introduction
It is third party library to manipulate terminal. use to make interactive terminal.

## Installation
### conan
```python
def requirements(self):
	self.requires("ncurses/6.5")	
```

### CMake 
```CMake
...
find_package(Curses REQUIRED)
...
target_link_libraries(<target> PRIVET|PUBLIC|INTERFACE
						Curses::Curses
)
```

## Member function
### 1. **`initscr()`**: 
initialises the terminal, putting it into a special "curses mode." This changes the terminal's behaviour, allowing ncurses to take control of the screen.(**`It is the starting of the code. It is absulute nessasary.`**)
### 2. **`cbreak()`** : 
The `cbreak()` function puts the terminal into a mode where input is available to your program as soon as the user presses a key.
**`NOTE :`**
	**Terminal Default Behavior (Cooked Mode):**
	By default, the terminal is in "cooked" or "canonical" mode. In this mode, the terminal itself handles basic editing like backspace, and it only sends a complete line of input to the waiting program when the user presses **Enter**. This is the behavior you're familiar with in a standard shell prompt.
**How `cbreak()` Changes Things:**
When you call `cbreak()`, you are telling the terminal to break from that canonical mode.
- **No Buffering:** Keystrokes are no longer buffered by the terminal. The `getch()` function (or `wgetch()`) will return immediately after a single key is pressed.
- **No Line Editing:** The terminal no longer handles backspace or other line-editing characters. Your program is now responsible for processing these keys if you want to implement that functionality.

### 3. **`noecho()`** (No Echoing) 
The `noecho()` function turns off the automatic echoing of characters to the screen.
**Terminal Default Behavior (Echo Mode):**
By default, the terminal is in "echo" mode. This means that whenever you type a character, the terminal immediately displays that character on the screen.
### 4. **`keypad(stdscr, TRUE);`** 
`keypad(stdscr, TRUE);` is a crucial function call in `ncurses` for handling special keys on the keyboard, such as arrow keys, function keys (F1, F2, etc.), and navigation keys (Home, End, Page Up, Page Down).
This means that instead of getting three separate characters, your `getch()` function will return one of the predefined ncurses constants, such as:
- `KEY_UP` for the Up Arrow key
- `KEY_DOWN` for the Down Arrow key
- `KEY_LEFT` for the Left Arrow key
- `KEY_RIGHT` for the Right Arrow key
- `KEY_HOME` for the Home key
- `KEY_END` for the End key
- `KEY_F(1)` for the F1 function key
- And many more...
 **The `stdscr` Window :**
In `keypad(stdscr, TRUE);`, `stdscr` is the global, default window that represents the entire terminal screen. This is where most programs will enable keypad mode, as it's the main window for user interaction. You can, however, enable keypad mode on any window you create with `newwin()`.

# ! I don't want to learn ncurses