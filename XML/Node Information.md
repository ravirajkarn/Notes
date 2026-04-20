---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-14 08:40::26 AM
tags:
  - xml
---
# Node Properties
- `nodeName`
- `nodeValue`
- `nodeType`

## The `nodeName` Property
The `nodeName` property specifies the name of a node.
- `nodeName` is read-only
- `nodeName` of an element node is the same as the tag name
- `nodeName` of an attribute node is the attribute name
- `nodeName` of a text node is always `#text`
- `nodeName` of the document node is always `#document`

## The `nodeValue` Property
The `nodeValue` property specifies the value of a node.
- `nodeValue` for element nodes is undefined
- `nodeValue` for text nodes is the text itself
- `nodeValue` for attribute nodes is the attribute value

## The `nodeType` Property
The `nodeType` property specifies the type of node.
- `nodeType` is read only.

The most important node types are:

|Node type|NodeType|
|---|---|
|Element|1|
|Attribute|2|
|Text|3|
|Comment|8|
|Document|9|
