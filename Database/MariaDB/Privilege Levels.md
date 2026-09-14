---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-16 12:25::05 PM
tags:
  - MariaDB
  - Date
---
	# Privilege Levels
Privileges can be set globally, for an entire database, for a table or routine, or for individual columns in a table. Certain privileges can only be set at certain levels.

> [!important] [**List Privilege of a user or role.**](https://mariadb.com/docs/server/reference/sql-statements/administrative-sql-statements/show/show-grants)
> - Syntax:
> ```SQL
> SHOW GRANTS [FOR user|role]
> ```
> - Description:
> The `SHOW GRANTS` statement lists privileges granted to a particular user or role.
> - Example:
> ```sql
> SHOW GRANTS FOR 'root'@'localhost';
> +---------------------------------------------------------------------------------------------------------+
> | Grants for root@localhost                                                                                     |
> +---------------------------------------------------------------------------------------------------------+
> | GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION |
> +---------------------------------------------------------------------------------------------------------+
> ```

## Global Level:
These privileges apply to the entire server and all of its databases. Examples include administrative rights like `CREATE USER`, `SHUTDOWN` and `SUPER`

- **`*.*`** Is used as privilege level identifier to apply the grant globally.
-  **The Privileges are:** 
	- [**ALL PRIVILEGES**](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/grant#the-all-privileges-privilege) 
	- [**BINLOG ADMIN**](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/grant#binlog-admin): Enables administration of the binary log, allowing the user to execute `PURGE BINARY LOGS` and modify binary log-related system variables
	- **BINLOG MONITOR** : Permits running informative `SHOW` commands related to the binary log, such as `SHOW BINLOG STATUS` and `SHOW BINARY LOGS`
	- **BINLOG REPLAY** : Enables replaying the binary log using the `BINLOG` statement and setting related session variables
	- **CONNECTION ADMIN**: Allows administration of connection resource limits, such as ignoring `max_user_connections` or `max_password_errors` limits, allowing one extra connection over `max_connections`, and killing connections or queries owned by other users
	- **CREATE USER**
	- **FEDERATED ADMIN**
	- **FILE**
	- **GRANT OPTION**
	- **PROCESS**
	- **PROXY**
	- **READ_ONLY ADMIN**
	- **RELOAD**
	- **REPLICA MONITOR**
	- **REPLICATION MASTER ADMIN**
	- **REPLICATION SLAVE**
	- **REPLICATION SLAVE ADMIN**
	- **SET USER**
	- **SHOW DATABASES**
	- **SHUTDOWN**
	- **SUPER**
	- **USAGE**

> [!example]
> ```sql
> GRANT ALL PRIVILEGES ON *.* TO 'username'@'hostname';
> ```

## Database Level:
These privileges grant access to manage all objects (tables functions, procedures) within one specific database.

- **`.*`** (eg. **`db_name.*`**) must to select a database on the server.
- **Privileges are:**
	- **CREATE**
	- **CREATE ROUTINE**
	- **CREATE TEMPORARY TABLES**
	- **DROP**
	- **EVENT**
	- **GRANT OPTION**
	- **LOCK TABLES**
	- **SHOW CREATE ROUTINE**

> [!example] 
> ```sql
> GRANT SELECT ON database_name.* TO 'username'@'hostname';
> ```


## Table Level:
These privileges determine what operations a user can perform on specific tables or views, such as `ALTER`, `CREATE`, OR `DELETE`.

- **db_name.tbl_name** is used to select the a table.
- **Privileges are:**
	- **ALTER**
	- **CREATE**
	- **CREATE VIEW**
	- **DELETE**
	- **DELETE HISTORY**
	- **DROP**
	- **GRANT OPTION**
	- **INDEX**
	- **REFERENCES**
	- **SELECT**
	- **SHOW VIEW**
	- **TRIGGER**
	- **UPDATE**

> [!example]
> ```sql
> GRANT ALL PRIVILEGES ON database_name.table_name TO 'username'@'hostname';
> ```

## Column Level:
These provide highly granular control, allow us restricted reading (`SELECT`) or writing (`INSERT`, `UPDATE`) access to specific columns within a table.

> [!example]
> ```sql
> GRANT SELECT (column1), UPDATE (column2) ON table_name TO 'username'@'hostname';
> ```

## Routine Level:
These control access to stored procedure and functions, such as the ability to `EXECUTE` them.

- The keyword `PROCEDURE` or `FUNCTION` followed by the routine name (e.g., **PROCEDURE db_name.routine_name**)

> [!example]
> ```sql
> GRANT EXECUTE ON PROCEDURE procedure_name TO 'username'@'hostname';
> ```

## Proxy User: 
This privilege allows one user account to connect as and impersonate another user.

> [!example]
> ```sql
> GRANT PROXY ON 'owner_user'@'%' TO 'proxy_user'@'%';
> ```
