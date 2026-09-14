---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-16 07:55::14 AM
tags:
  - MariaDB
  - Database
---
## Password Expiry
Besides automatic password expiry, as determined by [default_password_lifetime](https://mariadb.com/docs/server/server-management/variables-and-modes/server-system-variables#default_password_lifetime), password expiry times can be set on an individual user basis, overriding the global setting, for example:

example:
```sql
CREATE USER 'monty'@'localhost' PASSWORD EXPIRE INTERVAL 120 DAY;
```

