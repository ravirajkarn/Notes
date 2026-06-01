---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-05-29 23:45::35 PM
tags:
  - Js
---

```js
let score = "123adf";
  
console.log(typeof score);
console.log(typeof score);
  
let valueInNumber = Number(score);
console.log(typeof valueInNumber);
console.log(valueInNumber); // output is NaN
  
// "33" => 33
// "33abc" => NaN
// true => 1; false => 0
  
let isLoggedIn = 1;
  
let booleanInLoggedIn = Boolean(isLoggedIn);
console.log(booleanInLoggedIn);
  
// 1 => true; 0 => false
// "" => false
// "sumit" => true
  
let someNumber = 33;
  
let stringNumber = String(someNumber);
console.log(stringNumber);
console.log(typeof stringNumber);
  
/********** Operations ***********************/
  
let value = 3;
let negValue = -value;
console.log(negValue);
  
console.log(2 + 2);
console.log(2 - 2);
console.log(2 * 2);
console.log(2 ** 3); // 2 rase to power of 3
console.log(2 / 3);
console.log(2 % 3);2
  
let str1 = "hello";
let str2 = " Sumit Kumar";
  
let str3 = str1 + str2;
console.log(str3);
  
console.log("1" + 2); // 12
console.log(1 + "2"); // 12
console.log("1" + 2 + 2); // 122
console.log(1 + 2 + "2"); // 32 number before string will sum
```