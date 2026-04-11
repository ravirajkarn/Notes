---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-08-13T01:01:00
tags:
  - Library
  - Cpp
  - ftxui
---
# [FTXUI](https://github.com/ArthurSonzogni/FTXUI.git)

_Functional Terminal (X) User interface_
A simple cross-platform C++ library for terminal based user interfaces!

## Installation

```python
from conan import ConanFile
from conan.tools.cmake import cmake_layout


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("ftxui/6.0.2")

    def layout(self):
        cmake_layout(self)
```

```CMake
find_package(ftxui REQUIRED)
 
add_executable(main main.cpp)
target_link_libraries(main
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
```

## Optional CMake Flags

FTXUI supports the following CMake options:

|Option|Description|Default|
|---|---|---|
|FTXUI_BUILD_EXAMPLES|Build bundled examples|OFF|
|FTXUI_BUILD_DOCS|Build the documentation|OFF|
|FTXUI_BUILD_TESTS|Enable tests|OFF|
|FTXUI_ENABLE_INSTALL|Generate install targets|ON|
|FTXUI_MICROSOFT_TERMINAL_FALLBACK|Improve Windows compatibility|ON/OFF|

## Modules
![|300](fxtui%20module.jpg)
FTXUI is organised into three modules, each building upon the previous:
1. [ftxui/screen](#ftxui/screen) - Low-level rendering
2. [ftxui/dom](#ftxui/dom) - Layout and composition
3. [ftxui/component](#ftxui/component) - User interaction

## ftxui/screen
### Example
The [ftxui::Screen](https://arthursonzogni.github.io/FTXUI/group__screen.html#classftxui_1_1Screen) class represents a 2D grid of styled characters that can be rendered to a terminal. It provides methods to create a screen, access pixels, and render elements.

- You can access the individual cells ([ftxui::Pixel](https://arthursonzogni.github.io/FTXUI/group__screen.html#structftxui_1_1Pixel)) of the screen using the [ftxui::Screen::PixelAt](https://arthursonzogni.github.io/FTXUI/group__screen.html#a483f8ee1967e200cfc9e277b3ce00174) method, which returns a reference to the pixel at the specified coordinates.
```Cpp
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
 
void main() {
    auto screen = ftxui::Screen::Create(
        ftxui::Dimension::Full(),   // Use full terminal width
        ftxui::Dimension::Fixed(10) // Fixed height of 10 rows
    );
 
    // Access a specific pixel at (10, 5)
    auto& pixel = screen.PixelAt(10, 5);
 
    // Set properties of the pixel.
    pixel.character = U'X';
    pixel.foreground_color = ftxui::Color::Red;
    pixel.background_color = ftxui::Color::RGB(0, 255, 0);
    pixel.bold = true; // Set bold style
    screen.Print(); // Print the screen to the terminal
}
```

```
Note
If the coordinates are out of bounds, a dummy pixel is returned.
```

The screen can be printed to the terminal using [ftxui::Screen::Print()](https://arthursonzogni.github.io/FTXUI/group__screen.html#ad93edbe885499a712129356f1ffd506b) or converted to a std::string with [ftxui::Screen::ToString()](https://arthursonzogni.github.io/FTXUI/group__screen.html#a19c380b03cea21d7ac7325136a131ff0).
```
Note: that you can reset the cursor position to the top-left corner of the screen after printing by calling ftxui::Screen::ResetCursorPosition().
```

### ftxui::Dimension

The [ftxui::Dimension](https://arthursonzogni.github.io/FTXUI/namespaceftxui_1_1Dimension.html) utility controls screen sizing:
- `Dimension::Full()` — use full terminal width or height
- `Dimension::Fit(element)` — size to fit the rendered [ftxui::Element](https://arthursonzogni.github.io/FTXUI/namespaceftxui.html#a2bc31f2d685189e5c61d2293a1f51b4f)
- `Dimension::Fixed(n)` — use exactly `n` columns or rows

These values are to be passed to `[ftxui::Screen::Create()](https://arthursonzogni.github.io/FTXUI/group__screen.html#a32b98be0603ace46d6dc9d05b330a9fd "Create a screen with the given dimension.")`.

[ftxui::Screen::Create()](https://arthursonzogni.github.io/FTXUI/group__screen.html#a32b98be0603ace46d6dc9d05b330a9fd) provides two overloads:

- `Screen::Create(Dimension)` sets both width and height to the same kind of dimension
- `Screen::Create(Dimension width, Dimension height)` allows distinct control per axis
```Cpp
auto screen = ftxui::Screen::Create(
  ftxui::Dimension::Full(),      // width
  ftxui::Dimension::Fixed(10)    // height
);
```

Once created, render an element and display the result:
```Cpp
ftxui::Render(screen, element);
screen.Print();
```

### ftxui::Pixel

Each cell in the screen grid is a [ftxui::Pixel](https://arthursonzogni.github.io/FTXUI/group__screen.html#structftxui_1_1Pixel), which holds:

- Unicode codepoint.
    - `character`
- ftxui::Color:
    - `foreground_color`
    - `background_color`
- Booleans:
    - `blink`
    - `bold`
    - `dim`
    - `italic`
    - `inverted` (swap foreground and background colors)
    - `underlined`
    - `underlined_double`
    - `strikethrough`

```Cpp
auto screen = ftxui::Screen::Create(
  ftxui::Dimension::Fixed(5),
  ftxui::Dimension::Fixed(5),
);
 
auto& pixel = screen.PixelAt(3, 3);
pixel.character = U'X';
pixel.bold = true;
pixel.foreground_color = ftxui::Color::Red;
pixel.background_color = ftxui::Color::RGB(0, 255, 0);
 
screen.Print();
```

```
Note
PixelAt(x, y) performs bounds checking and returns a reference to the pixel at the specified coordinate. If out-of-bounds, a dummy pixel reference is returned.
```
Each cell in the screen is a [ftxui::Pixel](https://arthursonzogni.github.io/FTXUI/group__screen.html#structftxui_1_1Pixel). You can modify them using:

```Cpp
auto& pixel = screen.PixelAt(x, y);
pixel.character = U'X';
pixel.bold = true;
pixel.foreground_color = Color::Red;
```

### ftxui::Color

The [ftxui::Color](https://arthursonzogni.github.io/FTXUI/group__screen.html#classftxui_1_1Color) class is used to define foreground and background colors for each [ftxui::Pixel](https://arthursonzogni.github.io/FTXUI/group__screen.html#structftxui_1_1Pixel).

It supports various color spaces and predefined palettes. FTXUI will dynamically fallback to the closest available color in the terminal if the requested color is not supported by the terminal.

**Color Spaces**

- **Default**: `ftxui::Color::Default` (terminal's default color)
- **16-color palette** [Demo](https://arthursonzogni.github.io/FTXUI/examples/?file=dom/color_gallery):
    - `ftxui::Color::Black`,
    - `ftxui::Color::Red`,
    - ...
- **256-color palette** [Demo](https://arthursonzogni.github.io/FTXUI/examples/?file=dom/color_palette256):
    - `ftxui::Color::Chartreuse1`,
    - `ftxui::Color::DarkViolet`,
    - ...
- **True color** (24bit) [Demo]([https://arthursonzogni.github.io/FTXUI/examples/?file=dom/color_truecolor_HSV:](https://arthursonzogni.github.io/FTXUI/examples/?file=dom/color_truecolor_HSV:)
    - `ftxui::Color::RGB(uint8_t red, uint8_t green, uint8_t blue)`
    - `[ftxui::Color::HSV(uint8_t h, uint8_t s, uint8_t v)`

```
Note
You can query the terminal capability using ftxui::Terminal::ColorSupport();
This can manually be set using ftxui::Terminal::SetColorSupport()
```

## ftxui/dom


## ftxui/component
