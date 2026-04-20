---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-13 17:59::33 PM
tags:
  - Introduction
  - xml
---

# What is DOM?
_"The W3C Document Object Model (DOM) is a platform and language-neutral interface that allows programs and scripts to dynamically access and update the content, structure, and style of a document."_

# The XML DOM
All XML elements can be accessed through the XML DOM.

The XML DOM is:
- A standard object model for XML
- A standard programming interface for XML
- Platform- and language-independent
- A W3C standard

## Get the Value of an XML Element
> [!EXAMPLE] 
> ```js
> txt = xmlDoc.getElementsByTagName("title")[0].childNodes[0].nodeValue;
> ```


## XML DOM Properties
- `x.nodeName` - the name of x
- `x.nodeValue` - the value of x
- `x.parentNode` - the parent node of x
- `x.childNodes` - the child nodes of x
- `x.attributes` - the attributes nodes of x

NOTE: x is a node object.

## XML DOM Methods
- `x.getElementsByTagName(name)` - get all elements with a specified tag name
-  `x.appendChild(node)` - Insert a child node to x
- `x.removeChild(node)` -remove a child node from x