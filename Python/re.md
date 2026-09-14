---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-10 17:40::43 PM
tags:
  - python
  - Library
---
# re -- Regular expression
## Core Functions
- **`re.search()`**: Scans entire string for first match.
- **`re.match()`**: Checks for match only at string start.
- **`re.findall()`**: Returns all matches as a string list.
- **`re.finditer()`**: Returns matches as iterators yielding match objects.
- **`re.sub()`**: Replaces pattern matches with new text.
- **`re.split()`**: Splits string wherever the pattern occurs.
- **`re.compile()`**: Saves pattern as an object for reuse.
## Basic Syntax Tokens
- **`\d` / `\D`**: Matches any digit / non-digit.
- **`\w` / `\W`**: Matches any alphanumeric character / non-alphanumeric.
- **`\s` / `\S`**: Matches any whitespace / non-whitespace.
- **`.`**: Matches any single character except newline.
- **`^` / `$`**: Marks start / end of string.
## Quantifiers & Groups
- **`*` / `+` / `?`**: Matches 0+, 1+, or 0-1 times.
- **`{n,m}`**: Matches between `n` and `m` times.
- **`[]`**: Matches any character inside the brackets.
- **`()`**: Groups tokens together and captures the match.
## Common Compilation Flags
- **`re.IGNORECASE` (or `re.I`)**: Makes matching case-insensitive.
- **`re.MULTILINE` (or `re.M`)**: Makes `^` and `$` test every line.
- **`re.DOTALL` (or `re.S`)**: Makes dot `.` match newline characters.