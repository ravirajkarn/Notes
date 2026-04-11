---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-08-22T01:57:00
tags:
  - Conan
---
<iframe width="560" height="315" src="https://www.youtube.com/embed/JsijdbjVlXw?si=j2L1qdtEviHp-QZz" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

- To create a new package recipe. 
    ```Bash
    $ conan new recipe/name
	```
	- To create test package use parameter: -t 
- We can change the setting of the build any time 
```Bash
conan package/name -s arch=X86 -s sos=linux -s compiler="visual studio"
```

- Instead of giving too much setting to the package we can create a profile for the specific project. 
```Bash
conan profile list
```
- This is profile is just a simple text file. 
```Bash
conan package/name -pr profile/name
```