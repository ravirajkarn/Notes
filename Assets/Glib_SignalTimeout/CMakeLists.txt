cmake_minimum_required(VERSION 3.31)
project(builder LANGUAGES CXX)

# Use C++17 standard (Good practice for modern apps)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the PkgConfig tool (helper to find libraries)
find_package(PkgConfig REQUIRED)

# Use PkgConfig to find GTK4 (Equivalent to 'pkg-config --libs gtk4')
pkg_check_modules(Gtkmm REQUIRED IMPORTED_TARGET gtkmm-4.0)

# Create the executable named "lyrics" from "main.cpp"
add_executable(timer main.cc timerexample.cc)

# Link the GTK4 libraries and include headers
target_link_libraries(timer PRIVATE PkgConfig::Gtkmm)