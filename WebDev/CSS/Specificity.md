---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-09-05 08:49::59 AM
tags:
  - CSS
  - webdev
---
# Specificity

Specificity is the process that CSS uses to determine which styles overwrite other styles. The best way to think of specificity is as an array of four numbers per selector. These four numbers represent the four ways that CSS determines specificity.

![[Specificity.png]]

### !important

The first number in this array is the `!important` keyword. The `!important` keyword is used to override all styles no matter their specificity or position in the stylesheet. This is why `!important` is the first number in the array and the first thing CSS checks for specificity.
```CSS
h1 {
  color: blue !important;
}

h1 {
  color: green;
}
```

### #id

If the specificity of the `!important` keyword is the same between two selectors (either they both are `!important` or neither is `!important`) then CSS looks at the count of the id selectors to determine the specificity of an element. This is simply done by adding up the number of ids in a selector and using that as the number for the second position in the specificity array. For example the below selector would have an id specificity of two.

```
#id1 #id2 {
  ...;
}
```
![[0200.png]]

This selector would only have an id count of one, though.

```
#id1 {
  ...;
}
```
![[0100.png]]
If a selector has more ids in the selector then it will be more specific and override the less specific selectors with less ids.

### .class

If the selectors being compared have the same `!important` specificity and they both have the same number of id selectors then the class selector specificity is used. This class specificity includes the count of all class, attribute, and pseudo-class’s in the selector and fills the third number in the array. For example the following selector would have a class specificity of three.

```
.class1 .class2:hover {
  ...;
}
```
![[0030.png]]

This selector would have a class specificity of two and an id specificity of one.

```
#form .textbox[type="text"] {
  ...;
}
```
![[0120.png]]
### element

If after checking `!important`, ids, and classes, the specificity is still the same then the count of all element selectors is used. This count includes all HTML element selectors as well as all pseudo selectors such as `::before`. The count of all these elements goes into the fourth and final number in the array. For example the following selector would have an element specificity of one.

```
h1 {
  ...;
}
```
![[0001.png]]

This selector would have an id count of two, a class count of one, and an element count of three.

```
#page1 header#main-header h1.title::before {
  ...;
}
```
![[0213.png]]
## Inline Styles

Inline styles are a bit of a special case when it comes to specificity since there is no selector for inline styles. This means that inline styles act somewhat like another number in the array that goes between `!important` and id count. This is because inline selectors will always be more specific then any selector in a stylesheet no matter the number of ids, classes, or elements in the selector unless `!important` is used. This means that the only way to override an inline style is by using `!important`.