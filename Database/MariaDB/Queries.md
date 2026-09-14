---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-12 15:09::12 PM
tags:
  - sqlite
  - Database
---

# Queries
- A query is a set of instruction given to the RDBMS (written is SQL) that tell the RDBMS what information you want it to retrieve for you
	- TONS of data is a DB
	- Often hidden in a complex schema 
	- Goal is to only get the data you need

```SQL
SELECT employee.name, employee.age
FROM employee
WHERE employee.salary > 30000;
```
