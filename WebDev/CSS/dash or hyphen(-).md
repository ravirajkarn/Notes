---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-06-05 11:15::39 AM
tags:
  - CSS
---

# dash or hyphen ( - )

## 1. CSS Variables (Custom Properties)
```CSS
:root { 
	--primary-color: #3498db; /* Declaring the variable */ 
}

button { 
	background-color: var(--primary-color); /* Using the variable */ 
}
```

## 2. Math Operations in `calc()`
```CSS
.sidebar { 
	width: calc(100% - 40px); /* Subtracts 40 pixels from 100% width */ 
}
```

## 3. Writing Negatives 
```CSS
.card { 
	margin-top: -20px; /* Pulls the element upward */ 
	transform: rotate(-45deg); /* Rotates counter-clockwise */ 
}
```

## 4. Property and Naming Conventions
- **Standard Properties:** `background-color`, `font-size`, `margin-bottom`
- **Vendor Prefixes:** `-webkit-transition`, `-moz-box-sizing`
- **Class Names (BEM style):** `.card__button--disabled`

### Vendor Prefixes
**CSS vendor prefixes** are extensions added to the front of CSS properties to allow browser makers to test and support new, experimental features before they are fully finalized into web standards
#### [CSS prefixes](https://developer.mozilla.org/en-US/docs/Glossary/Vendor_Prefix#css_prefixes)
The most common browser CSS prefixes you will see in older code bases include:
- `-webkit-` (Chrome, Safari, newer versions of Opera and Edge, almost all iOS browsers including Firefox for iOS; basically, any WebKit or Chromium-based browser)
- `-moz-` (Firefox)
- `-o-` (old pre-WebKit versions of Opera)
- `-ms-` (Internet Explorer and Microsoft Edge, before Chromium)
```CSS
-webkit-transition: all 4s ease;
-moz-transition: all 4s ease;
-ms-transition: all 4s ease;
-o-transition: all 4s ease;
transition: all 4s ease;
```