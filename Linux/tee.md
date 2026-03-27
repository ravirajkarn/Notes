---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-03-26 00:11::17 AM
tags:
  - Linux
  - command
---
# tee
Acts like a "T-junction" for data. It takes the text from the pipe (`|`) and writes it into a file while also showing it on your screen.

  Copy `stdin` to each file, and also to `stdout`:
```bash
echo "example" | tee path/to/file
```
  Append to the given files, do not overwrite:
```bash
echo "example" | tee [-a|--append] path/to/file
```
  Print `stdin` to the terminal, and also pipe it into another program for further processing:
```bash
echo "example" | tee /dev/tty | xargs printf "[%s]"
```
  Create a directory called "example", count the number of characters in "example", and write "example" to the terminal:
```bash
echo "example" | tee >(xargs mkdir) >(wc [-c|--bytes])
```