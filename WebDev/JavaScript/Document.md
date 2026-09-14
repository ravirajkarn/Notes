---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-27 17:22::52 PM
tags:
  - Js
---
# Document
the `Document` interface represents any web-page loaded in thee browser and serves as an entry point into the web page's content, which is the **DOM tree**.

## Constructor
- **Document()**
Creates a new `Document` object.

## Instance properties
- **Document.body**
Returns the [`<body>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Reference/Elements/body) or [`<frameset>`](https://developer.mozilla.org/en-US/docs/Web/HTML/Reference/Elements/frameset) node of the current document.

## Extensions for HTMLDocument
- **Document.title**
Sets or gets the title of the current document.

## Instance methods
- **Document.createElement()**
Creates a new element with the given tag name.

- **Document.getAnimations()**
Returns an array of all [`Animation`](https://developer.mozilla.org/en-US/docs/Web/API/Animation) objects currently in effect, whose target elements are descendants of the `document`.

- **Document.getBoxQuads()**
Returns a list of [`DOMQuad`](https://developer.mozilla.org/en-US/docs/Web/API/DOMQuad) objects representing the CSS fragments of the node.

- **Document.getElementById()**
Returns an object reference to the identified element.

- **Document.getElementsByClassName()**
Returns a list of elements with the given class name.

- **Document.getElementsByTagName()**
Returns a list of elements with the given tag name.

- **Document.getElementsByTagNameNS()**
Returns a list of elements with the given tag name and namespace.

- **Document.getSelection()**
Returns a [`Selection`](https://developer.mozilla.org/en-US/docs/Web/API/Selection) object representing the range of text selected by the user, or the current position of the caret.