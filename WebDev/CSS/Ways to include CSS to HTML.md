---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-01-13 09:20::42 AM
tags:
  - html
  - CSS
---

# There are three ways to add CSS in HTML

## 1. External CSS (Best Way)

> [!example] 
> - `styles.css`
> ```css
> body {
> 	background-color: lightblue;
>  }
>  h1 {
> 	 color: navy;
> 	 margin-left: 20px;
>  }
> ```
>
> - `index.html`
> ```html
> <!DOCTYPE html>
> <html>
> <head>
> 	<title>External CSS Example</title>
> 	<link rel="stylesheet" href="styles.css">
> </head>
> <body>
> 	<h1>This is a heading</h1>
> 	<p>This is a paragraph with a blue background.</p>
> </body>
> </html>
> ```

## 2. Internal CSS

> [!example] 
> - `index.html`
> ```html
> <!DOCTYPE html>
> <html>
> <head>
> 	<title>Internal CSS Example</title>
> 	<style>
> 		body {
> 			background-color: linen;
> 		}
> 		h1 {
> 			color: maroon;
> 			margin-left: 40px;
> 		}
> 	</style>
> </head>
> <body>
> 	<h1>This is a heading</h1>
> 	<p>This paragraph has a maroon heading and linen background.</p>
> </body>
> </html>
> ```

## 3. Inline CSS

> [!example] 
> - `index.html`
> ``` html
> <!DOCTYPE html>
> <html>
> <body>
> 	<h1 style="color:blue;text-align:center;">This is a blue, center-aligned heading</h1>
> 	<p style="color:red;">This is a red paragraph.</p>
> </body>
> </html>
> ```

## Cascading Order (Priority)

If a single HTML element has styles defined by multiple methods, the styles are applied based on a priority order: 

1. **Inline styles** (highest priority)
2. **External and internal style sheets** (the one read last by the browser has higher priority)
3. Browser default styles