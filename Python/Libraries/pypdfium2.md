---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-06 22:16::24 PM
tags:
  - Library
  - python
  - pdf
---
# pypdfium2 
It is a wrapper around pdfium main system behind chrome pdf viewer.

- **Importing the library**
`import pypdfium2 as pdfium`

- **Open/Load a file**
```python
	pdf = pdfium.PdfDocument("GEM-2026-B-7508238.pdf")
	
	with pdfium.PdfDocument("GEM-2026-B-7508238.pdf") as pdf:
```

- **load single page**
	`page = pdf[0]`

- **Convert a page into image**
	`image = page.render()`
	-  *return:* 
		- raw bitmap object.
		- to make easy to save or view us `Pillow Library` by the method `to_pil()`. its native raw bitmap format is actually BGRA (Blue-Green-Red-Alpha) rather than the standard RGBA used by Python libraries. If you are working with the raw bytes, this parameter helps flip them. Thankfully, pypdfium2's `.to_pil()` method automatically handles this byte-swapping translation for you behind the scenes!
	- *parameter:*
		- default `scale` = 72 DPI(dots per inch)
		- increase the `scale` with `image = page.render(scale=3).to_pil()`
		- black and white `greyscale=True`
		- custom Backgrounds (Alpha/Transparency): rgba format `fill_colour(0,0,0,0)`
		- crop: `crop(left, bottom, right, top)` coordinate.
		- `rotation()`
		- `no_smoothtext`: Set to `True` to disable text anti-aliasing.
		- `no_smoothimage`: Set to `True` to disable image smoothing.
		- `no_smoothpath`: Set to `True` to disable vector graphic smoothing.
- **Save the image**
	`image.save("first_page.png")`

- **Extracting metadata form pdf**
```python
metadata = pdf.get_metadata_dict()
title = metadata.get('Title'. 'N/A')
Author = metadata.get('Author', 'N/A')

for i, page in enumerate(pdf):
	width, height = page.get_size()
	aspect_ratio = width / height if height > 0 else 0
	
```

- **Extract text**
	- Extract visual text layout
		`textpage = page.get_textpage()`
	- get text from text layout
		`page_text = textpage.get_text_bounded()`
	
```python
with pdf[0] as page:
	textpage = page.get_textpage()
	page_text = textpage.get_text_bounded()
```

- **get the pdf standard version**
`version = pdf.get_version()`

- **get number of pages in the document**
`n_pages = len(pdf)`

## 1. **The Coordinate System**
	he origin `(0,0)` is typically at the **bottom-left** corner of the page.

> [!EXAMPLE]
> ```python 
> import pypdfium2 as pdfium
> 
> # 1. Load the document and access the specific page
> pdf = pdfium.PdfDocument("sample.pdf")
> page = pdf[0] 
> 
> # 2. Initialize the TextPage helper
> textpage = page.get_textpage()
> 
> # 3. Define your bounding box: (left, bottom, right, top)
> # Let's say we want to extract a header located at the top of an 800pt tall page
> bbox = (50, 700, 500, 800)
> 
> # 4. Extract the bounded text
> # We use the * operator to unpack the tuple into the method
> extracted_text = textpage.get_text_bounded(*bbox)
> print("Extracted Area Contains:")
> print(extracted_text)
> ```

## 2. The Rendering Pipeline
When PDFium turns a PDF page into an image (a process called rasterization), it follows a specific sequence. Understanding this helps you optimize performance when using `pypdfium2`.

**1.Parsing:** Reading the raw data.
PDFium reads the underlying PDF file structure (which is essentially a text-based format defining objects and dictionaries) and builds an in-memory representation of the document and its pages.

**2.Page Processing:** Preparing the elements.
When a specific page is requested for rendering, PDFium evaluates the objects on that page, applying necessary transformations (like scaling or rotation) and resolving resource dependencies (like fonts or color spaces).

**3.Rasterization:** Creating the bitmap.
Finally, PDFium uses its graphics engine to draw the parsed page elements onto a memory buffer, resulting in a bitmap image (an array of pixels) that can be displayed on a screen or saved as an image file.
## 3. Rasterization
Here is exactly how PDFium's C++ engine handles the different object types on a page during rasterization.

### 1. Text Blocks

PDFs don't store text as pixels; they store character codes, font dictionaries, and exact positional coordinates.

- **The Process:** When rasterizing, PDFium looks up the mathematical outline (the vector shape) for each character in the embedded font file. It scales this outline to match the page dimensions and your requested resolution, then fills the shape with the specified color.
    
- **Smoothing (Anti-Aliasing):** By default, PDFium applies anti-aliasing to text to make the curved edges look smooth to the human eye.
    
- **Optimization:** If you are rendering pages just to feed them into a machine learning model or an OCR engine that doesn't care about pretty edges, you can pass `no_smoothtext=True` to the `.render()` method. This disables the smoothing step, significantly speeding up the rasterization process.
    

### 2. Vector Paths (Graphics and Lines)

These are mathematical lines, curves (like Bézier curves), and polygons used to draw charts, borders, or illustrations.

- **The Process:** Similar to text, PDFium calculates the exact geometry of these paths based on the scale matrix. It then applies the defined stroke (outline) width and fill colors, determining exactly which pixels on the output bitmap fall inside or on the line.
    
- **Optimization:** You can manipulate how these are rendered by using the `no_smoothpath=True` argument. Disabling this anti-aliasing saves processing time when rendering thousands of document pages.
    

### 3. Embedded Images

Unlike text and paths, embedded images (like a scanned photo inside the PDF) are _already_ rasters.

- **The Process:** PDFium decodes the embedded image (which might be compressed as JPEG or Flate data) and maps it onto the output pixel grid. If the requested output resolution (controlled by your `scale` parameter) is different from the embedded image's native resolution, PDFium has to interpolate (scale up or down) the image pixels to fit the new dimensions.
    
- **Optimization:** You can disable image interpolation smoothing by passing `no_smoothimage=True`.
    
### The Final Output Matrix

Once all objects are processed, PDFium outputs a raw C-level bitmap. Because PDFium is written in C++, its native raw pixel format is actually BGRA (Blue-Green-Red-Alpha), which is backward compared to standard Python image libraries.

Thankfully, when you call my `.to_pil()` method, I handle the memory management and byte-swapping translation automatically, giving you a clean, standard Pillow image object ready for Python.

## 4. **Extracting raw, embedded images**
A page is just a collection of elements. To extract a photo, you cannot just ask the page for "images." You must iterate through every single object on the page, check its type, and extract the data if it matches an image format.

```python 
import pypdfium2 as pdfium

# 1. Open the document safely using a context manager
with pdfium.PdfDocument("scanned_report.pdf") as pdf:
    
    # 2. Access the target page
    page = pdf[0] 
    
    # 3. Iterate through all the elements (objects) on the page
    for index, obj in enumerate(page.get_objects()):
        
        # 4. Filter out text and paths to isolate the images
        if isinstance(obj, pdfium.PdfImage):
            
            # 5. Extract the raw bitmap pixels and convert to a PIL image
            image = obj.get_bitmap().to_pil()
            
            # 6. Save the image to your disk
            image.save(f"extracted_image_{index}.png")
```



# Examples
----
## Print all the coordinate of objects
```python
import pypdfium2 as pdfium

pdf = pdfium.PdfDocument("pan.pdf")
page = pdf[0]

for obj in page.get_objects():
    print(obj.level, obj.type, obj.get_bounds())
```

## Extract image
```python
import pypdfium2 as pdfium

pdf = pdfium.PdfDocument("pan.pdf")
page = pdf[0]

for obj in page.get_objects():
    if isinstance(obj, pdfium.PdfImage):
	    image_bitmap = obj.get_bitmap()
        pil_image = image_bitmap.to_pil()
        
        pil_image.save("image.png")
```

## Extract text
### method 1: `textpage`
best for regular text extraction if you don't care about structure. or to prepare files for Optical Character Recognition(OCR).
```python
import pypdfium2 as pdfium

pdf = pdfium.PdfDocument("pan.pdf")
page = pdf[0]

textpage = page.get_textpage()
all_page = textpage.get_text_bounded()

print("--- Bulk Text Extracted ---")
print(all_page[:500] + "...\n")
```

### method 2: `pdfTextObj`
best for Analyzing Layouts(Tables, Columns, Sidebars). Extracting Text from a Specific Region. bypassing Hidden or Overlapping Text.

```python
import pypdfium2 as pdfium

pdf = pdfium.PdfDocument("pan.pdf")
page = pdf[0]

textpage = page.get_textpage()

for obj in page.get_objects(textpage=textpage):
    if isinstance(obj, pdfium.PdfTextObj):
        coords = obj.extract()
        print(f"text:\t {coords}\n")
```

> [!warning] Title
> above code might print letter in new line every time. 
> **Why is this happening?**
> In a PDF, a **`PdfTextObj` does not always represent a full word or a sentence.** It represents a single "draw command."
> - Sometimes a draw command is a whole paragraph.
> - Sometimes, especially with non-Latin scripts (like Hindi/Devanagari) or heavily formatted text, the software places **every single letter** or syllable individually to ensure perfect spacing.
> - Many of those blank lines are `PdfTextObj` elements that only contain a space character (`" "`) or an invisible layout artifact.
