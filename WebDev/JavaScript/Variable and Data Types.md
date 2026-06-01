---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-05-29 22:44::16 PM
tags:
  - Js
  - Variable
---
# Data Types

- Line in Java script should ends with  `;`.  But it is not necessary to end line of code with `;`.  As Java script parser automatically applies it. 

> [!NOTE]  DataType Name  = Value
> ### Modern JavaScript
> - Using `let`
> - Using `const`
> ### Older JavaScript
> - Using `var` (Not Recommended) 
> - Automatically (Not Recommended)

- JavaScript treat `_`  and `$` as character.

## Difference Between var, let and const

|       | Scope | Re-declare | Reassign | Hoisted | Binds this |
| ----- | ----- | ---------- | -------- | ------- | ---------- |
| Var   | no    | yes        | yes      | yes     | yes        |
| let   | yes   | no         | yes      | no      | no         |
| const | yes   | no         | no       | no      | no         |
```javascript
// number => range 2 to power 53
// bigint
// string =>""
// boolean => true/false
// null => standalone value
// undefined =>
// symbol => unique

// object
  
console.log(typeof age); // it is number
console.log(typeof undefined); // It is undefined type
console.log(typeof null); // It is Object type
```

