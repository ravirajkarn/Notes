---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-20 08:14::41 AM
tags:
  - Database
  - postgreSQL
---
# Manage Database
## CREATE DATABASE
---
To create a new database, you use the `CREATE DATABASE` statement.

> [!example]
> ```zsh
> CREATE DATABASE database_name
> WITH 
> 	[OWNER = role_name] 
> 	[TEMPLATE = template] 
> 	[ENCODING = encoding] 
> 	[LC_COLLATE = collate] 
> 	[LC_CTYPE = ctype] 
> 	[TABLESPACE = tablespace_name] 
> 	[ALLOW_CONNECTIONS = true | false] 
> 	[CONNECTION LIMIT = max_concurrent_connection] 
> 	[IS_TEMPLATE = true | false ];
> ```

- you can retrieve the database names from the `pg_database` view
```postgreSQL
SELECT datname FROM pg_database;
```


## ALTER DATABASE
---
### 1) Changing attributes of a database
To change the attributes of a database, you use the following form of the `ALTER DATABASE` statement:
```postgreSQL
ALTER DATABASE name WITH option;
```

The option can be:
- `IS_TEMPLATE`
- `CONNECTION LIMIT`
- `ALLOW_CONNECTIONS`
### 2) Rename the database
The following `ALTER DATABASE RENAME TO` statement renames a database:
```postgreSQL
ALTER DATABASE database_nameRENAME TO new_name;
```

- It is not possible to rename the current database. So, you need to connect to another database and rename it from that database.
- Only superusers and database owners with `CREATEDB` privilege can rename the database.

### 3) Change the owner of the database
The following `ALTER DATABASE` statement changes the owner of a database to the new one:
```postgreSQL
ALTER DATABASE database_name
OWNER TO new_owner | current_user | session_user;
```

The following users can change the owner of the database:
- The database owner with `CREATEDB` privilege and is a direct or indirect member of the new owning role.
- The superusers


## GRANT
---
The following shows the simple form of the `GRANT` statement that grants one or more privileges on a table to a role:

```postgreSQL
GRANT privilege_list | ALL
ON  table_name
TO  role_name;
```

In this syntax:
- First, specify the `privilege_list` that can be [`SELECT`](https://neon.com/postgresql/postgresql-tutorial/postgresql-select), [`INSERT`](https://neon.com/postgresql/postgresql-tutorial/postgresql-insert),[`UPDATE`](https://neon.com/postgresql/postgresql-tutorial/postgresql-update), [`DELETE`](https://neon.com/postgresql/postgresql-tutorial/postgresql-delete),[`TRUNCATE`](https://neon.com/postgresql/postgresql-tutorial/postgresql-truncate-table), etc. Use the `ALL` option to grant all privileges on a table to the role.
- Second, provide the name of the table after the `ON` keyword.
- Third, indicate the name of the role to which you want to grant privileges.

**Table 5.1. ACL Privilege Abbreviations**

| Privilege      | Description                                                                | Abbreviation   | Applicable Object Types                                                                      |
| -------------- | -------------------------------------------------------------------------- | -------------- | -------------------------------------------------------------------------------------------- |
| `SELECT`       | Allows reading data from a table or specific columns.                      | `r` (“read”)   | `LARGE OBJECT`, `SEQUENCE`, `TABLE` (and table-like objects), table column                   |
| `INSERT`       | Allows adding new rows to a table or specific columns.                     | `a` (“append”) | `TABLE`, table column                                                                        |
| `UPDATE`       | Allows modifying existing rows or specific columns.                        | `w` (“write”)  | `LARGE OBJECT`, `SEQUENCE`, `TABLE`, table column                                            |
| `DELETE`       | Allows deleting rows from a table.                                         | `d`            | `TABLE`                                                                                      |
| `TRUNCATE`     | Allows emptying a table completely and quickly.                            | `D`            | `TABLE`                                                                                      |
| `REFERENCES`   | Allows creating foreign keys that reference the table.                     | `x`            | `TABLE`, table column                                                                        |
| `TRIGGER`      | Allows creating triggers on the table.                                     | `t`            | `TABLE`                                                                                      |
| `CREATE`       | Allows creating new objects (like tables or views) within the schema.      | `C`            | `DATABASE`, `SCHEMA`, `TABLESPACE`                                                           |
| `USAGE`        | Allows looking up objects contained within the schema.                     | `U`            | `DOMAIN`, `FOREIGN DATA WRAPPER`, `FOREIGN SERVER`, `LANGUAGE`, `SCHEMA`, `SEQUENCE`, `TYPE` |
| `CONNECT`      | Allows the user to establish a connection to the database.                 | `c`            | `DATABASE`                                                                                   |
| `TEMPORARY`    | Allows creating temporary tables while connected.                          | `T`            | `DATABASE`                                                                                   |
| `EXECUTE`      | Allows executing functions or stored procedures.                           | `X`            | `FUNCTION`, `PROCEDURE`                                                                      |
| `SET`          | Allows altering configuration parameters for a specific role or session.   | `s`            | `PARAMETER`                                                                                  |
| `ALTER SYSTEM` | Allows modifying global configuration files via SQL.                       | `A`            | `PARAMETER`                                                                                  |
| `MAINTAIN`     | Allows running routine maintenance operations like `VACUUM` and `ANALYZE`. | `m`            | `TABLE`                                                                                      |
