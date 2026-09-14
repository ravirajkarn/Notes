---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-09 13:14::58 PM
tags:
  - pdf
  - python
  - Library
---

# pdfplumber







## Example
----
### Extract text
``` python
import pdfplumber

def something():
	with pdfplumber.open("GEM-2026-B-7508238.pdf") as pdf:
		first_page = pdf.pages[0]
        words = first_page.extract_words()
        print(words)
```

### Visual text debugging
```python 
import pdfplumber

def something():
    with pdfplumber.open("GEM-2026-B-7508238.pdf") as pdf:
        first_page = pdf.pages[0]
        im = first_page.to_image(resolution=150)
		
        words = first_page.extract_words()
        im.draw_rects(words, stroke="red", stroke_width=2)
		
        im.save("debug_text.png")
        print(words)
```

### Visual Table debugging
```python
import pdfplumber

def something():
    with pdfplumber.open("GEM-2026-B-7508238.pdf") as pdf:
        first_page = pdf.pages[0]
        im = first_page.to_image(resolution=150)
		
		im.debug_tablefinder() # draw boundry around table for debugging
		
        im.save("debug_text.png")
```

### Extracting Tables
```python
tables = page.extract_tables()
```

> [!warning] 
> `.extract_tables()` returns multiple tables, the output is structured as a three-dimensional list (a list of tables, containing lists of rows, containing lists of cells).
> 
> To put it into perspective:
> - **Level 1:** `tables[0]` gives you the entire first table.
> - **Level 2:** `tables[0][0]` gives you the first row of the first table.
> - **Level 3:** `tables[0][0][0]` gives you the first cell in that row.

### Extracting Table
```python
table = page.extract_table()
```