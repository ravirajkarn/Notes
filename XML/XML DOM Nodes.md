---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-13 18:24::20 PM
tags:
  - xml
---

# XML DOM Node
According to the XML DOM, everything in an XML document is a node:

- The entire document is a document node
- Every XML element is an element node
- The text in the XML elements are text nodes
- Every attribute is an attribute node
- Comments are comment nodes
---

## Text is Always Stored in Text Nodes
A common error in DOM processing is to expect an element node to contain text.
However, the text of an element node is stored in a text node.
In this example: **<year>2005</year>**, the element node \<year\> holds a text node with the value "2005".
"2005" is **not** the value of the \<year\> element!

## The XML DOM Node Tree
The XML DOM views an XML document as a tree-structure. The tree structure is called a **node-tree.**

All nodes can be accessed through the tree. Their contents can be modified or deleted, and new elements can be created.

The node tree shows the set of nodes, and the connections between them. The tree starts at the root node and branches out to the text nodes at the lowest level of the tree:
![DOM node tree](https://www.w3schools.com/xml/nodetree.gif)

## Node Parents, Children, and Siblings
The nodes in the node tree have a hierarchical relationship to each other.

The terms parent, child, and sibling are used to describe the relationships. Parent nodes have children. Children on the same level are called siblings (brothers or sisters).

- In a node tree, the top node is called the root
- Every node, except the root, has exactly one parent node
- A node can have any number of children
- A leaf is a node with no children
- Siblings are nodes with the same parent

The following image illustrates a part of the node tree and the relationship between the nodes:

![Node tree](https://www.w3schools.com/xml/navigate.gif)
Because the XML data is structured in a tree form, it can be traversed without knowing the exact structure of the tree and without knowing the type of data contained within.

## First Child - Last Child
Look at the following XML fragment:
```xml
<bookstore>  
  <book category="cooking">  
    <title lang="en">Everyday Italian</title>  
    <author>Giada De Laurentiis</author>  
    <year>2005</year>  
    <price>30.00</price>  
  </book>  
</bookstore>
```
In the XML above, the \<title> element is the first child of the \<book> element, and the \<price> element is the last child of the \<book> element.

Furthermore, the \<book> element is the parent node of the \<title>, \<author>, \<year>, and \<price> elements.
