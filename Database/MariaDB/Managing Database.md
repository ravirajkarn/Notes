---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-13 12:44::51 PM
tags:
  - MariaDB
  - Database
---

# Managing Database

- **Creating new Database**
```SQL
CREATE database fileName;
```

- **Show all the database**
```sql 
SHOW DATABASES;
```

- **Delete database**
```sql
DROP DATABASE IF EXISTS your_database_name;
```
## Default Database in MariaDB
- **`mysql`**: Contains system tables required for data dictionary information, user privileges, time zones, and log structures.
- **`information_schema`**: A virtual database that stores metadata about database objects, column types, and access rights.
- **`performance_schema`**: A tool for monitoring server performance events at a low level.
- **`sys`**: A set of views built on top of `performance_schema` to make performance tuning easier to read.