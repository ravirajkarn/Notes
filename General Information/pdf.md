---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-07 09:04::43 AM
tags:
  - pdf
---

# pdf
- PDFs don't store text as pixels; they store character codes, font dictionaries, and exact positional coordinates.
-  It is binary file.
- It's binary start with `%PDF-` and end with `%%EOF`.
- if `%%EOF` is missing, the PDF parser cannot locate the `startxref` pointer.
- The `startxref` points to the cross-reference table, which is essentially the map of where every object (text, image, font) is located within the file.

- pdf contain **Text Blocks**, **Vector Paths(Graphics and Lines like Bézier curves)** and **Embedded Images**.

**text :**
- Sometimes a draw command is a whole paragraph.
- Sometimes, especially with non-Latin scripts (like Hindi/Devanagari) or heavily formatted text, the software places every single letter or syllable individually to ensure perfect spacing.
- Many of those blank lines are PdfTextObj elements that only contain a space character (" ") or an invisible layout artifact.