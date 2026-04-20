---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-13 18:42::53 PM
tags:
  - xml
---
# Accessing Nodes 
You can access a node in three ways:
1. By using the `getElementsByTagName()` method
2. By looping through (traversing) the nodes tree
3. by navigating the node tree, using the node relationships


## The `getElementsByTagName()` Method
`getElementsByTagName()` returns all elements with a specified tag name.


> [!SYNTAX]
> ```js
> node.getElementsByTagName("tagname");
> ```

## Node Type
- The **documentElement** property of the XML document is the root node.
- The **nodeName** property of a node is the name of the node.
- The **nodeType** property of a node is the type of the node.