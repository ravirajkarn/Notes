---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-12-05 00:33::56 AM
tags:
  - Cpp
  - class
---
# [Resource Acquisition is Initialization (RAII)](https://stackoverflow.com/questions/2321511/what-is-meant-by-resource-acquisition-is-initialization-raii)
It's a really terrible name for an incredibly powerful concept, and perhaps one of the number 1 things that C++ developers miss when they switch to other languages. There has been a bit of a movement to try to rename this concept as **Scope-Bound Resource Management**, though it doesn't seem to have caught on just yet.

When we say 'Resource' we don't just mean memory - it could be file handles, network sockets, database handles, GDI objects... In short, things that we have a finite supply of and so we need to be able to control their usage. The 'Scope-bound' aspect means that the lifetime of the object is bound to the scope of a variable, so when the variable goes out of scope then the destructor will release the resource. A very useful property of this is that it makes for greater exception-safety. For instance, compare this:

```cpp
RawResourceHandle* handle=createNewResource(); 
handle->performInvalidOperation();  // Oops, throws exception 
... 
deleteResource(handle); // oh dear, never gets called so the resource leaks`
```

With the RAII one
```cpp
class ManagedResourceHandle { 
public:    
	ManagedResourceHandle(RawResourceHandle* rawHandle_) : rawHandle(rawHandle_) {};    
	~ManagedResourceHandle() {delete rawHandle; }    
	... // omitted operator*, etc 
private:    
	RawResourceHandle* rawHandle; 
};  

ManagedResourceHandle handle(createNewResource()); 
handle->performInvalidOperation();`
```
In this latter case, when the exception is thrown and the stack is unwound, the local variables are destroyed which ensures that our resource is cleaned up and doesn't leak.


RAII: Modern technique in which a certain code run even if exception occur(in any condition) 