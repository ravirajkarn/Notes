---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-17 22:05::26 PM
tags:
  - Database
  - MariaDB
---

# Managing Table
## Create Table
```sql
CREATE TABLE student (
    id INT AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (id)
);
```

## Display a Table
```sql
DESCRIBE student;
```

## Delete a Table
```SQL
DROP TABLE student;
```

## Add a new Column in the Table
```sql
ALTER TABLE student ADD gpa DECIMAL(3,2);
```

## Delete a Column on a Table
```sql
ALTER TABLE student DROP COLUMN gpa;
```
