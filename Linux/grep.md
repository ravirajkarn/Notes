---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-31T05:38:00
tags:
  - Linux
---
# grep

**`grep [OPTION]... PATTERNS [FILE]...`** --- use to search text within different file
- **`-r`** : Search recursively in all files of a directory
- `-i` : Case insensitive search
- `-c` : Displaying the Count Matches Using grep
- `-l` : Display the Matching Filenames Using grep
- `"os$"` : `$`Match Lines Ending with a String using grep
- `grep -r "abc" . --include="*test*" --exclude="*.log"`
	**Explanation:**
	- **`grep -r "abc" .`**: This recursively searches for the string "abc" starting from the current directory (`.`). By default, `grep -r` will descend into hidden directories (like `.git/` or `.vscode/`) and search hidden files within them, as long as they are not explicitly excluded.
	- **`--include="*test*"`**: This ensures that only files with "test" anywhere in their name (e.g., `mytestfile.txt`, `.config/test_data.json`) are searched. This pattern _will_ match hidden files if their name contains "test".
	- **`--exclude="*.log"`**: This specifically tells `grep` to skip any files that end with `.log` (e.g., `error.log`, `test.log`), regardless of whether they are hidden or not.
- **`--exclude-dir={node_modules,build,temp}`** Exclude multiple directories (using brace expansion)
- **`--exclude-dir="*cache*"`** Exclude directories matching a pattern
- **`grep -E "abc|$"`** : This will find the abc highlighted preserving all the output.
