---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-05-30 14:35::14 PM
tags:
  - Js
---
# reference
```js
/**
*~ Primitive
*_Definition_:_Call by Value
*
* 7 Type : String, Number, Boolean, null, undefined, Symbol, BingInt
*/
  
const score = 100;
const scoreValue = 100.3;
  
const isLoggedIn = false;
const outsideTemp = null;
let userEmail;
  
const id = Symbol("123");
const anotherId = Symbol("123");
  
console.log(id === anotherId);
  
const bigNumber = 234356754314546576665n;
  
/**
*~ Reference
*_Definition_:_ Call by reference
*
* Array, Objects, Functions
*/
  
const heroes = ["shaktiman", "naagraj", "doga"];
  
let myObj = {
name: "Sumit",
age: 22,
};
  
const myFunction = function () {
console.log("hello world");
};
  
console.log(typeof bigNumber);
console.log(typeof null);
console.log(typeof myFunction);
console.log(typeof heroes);
console.log(typeof id);
  
// ++++++++++++++++++++++++++++++++++++
  
// Stack (Primitive), Heap (Non-Primitive)
  
let YoutubeName = "sumit Mastana";
  
let anotherName = YoutubeName;
anotherName = "Sumit code";
  
console.log(anotherName);
console.log(YoutubeName);
  
// Reference
let userOne = {
email: "user@gmail.com",
upi: "user@ybl",
};
  
let userTwo = userOne;
  
console.log(userOne.email);
console.log(userTwo.email);
  
userTwo.email = "ravirajkarn21@gmail.com";
  
console.log(userOne.email);
console.log(userTwo.email);
```

Reference are defined inside {}. according to my observation