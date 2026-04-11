---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-01-28 12:38::29 PM
tags:
  - Conan
---
# Remove Packages 
To remove single package
```bash
conan remove pkg/0.00.1
```

To remove all the installed version of pkg
```shell
conan remove pkg/*
```

To remove all the package 
```shell
conan remove "*" --confirm
```

To remove cache
```bash
conan cache clean "*"
```

