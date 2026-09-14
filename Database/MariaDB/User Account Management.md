---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-15 10:47::13 AM
tags:
  - Database
  - MariaDB
---
# User Account Management
## Role
Manage roles in MariaDB Server and privilege management.

With roles, managing this is easy. For example, there could be a number of users assigned to a journalist role, with identical privileges. Changing the privileges for all the journalists is a matter of simply changing the role's privileges, while the individual user is still linked with any changes that take place.

Roles are created with the [[#1. [CREATE ROLE](https //mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/create-role)|CREATE ROLE]] statement, and dropped with the [[#2. [DROP ROLE](https //mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/drop-role)|DROP ROLE]] statement. Roles are then assigned to a user with an extension to the [[#[GRANT](https //mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/grant roles)|GRANT]] statement, while privileges are assigned to a role in the regular way with [[#[GRANT](https //mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/grant roles)|GRANT]] . Similarly, the [REVOKE](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/revoke) statement can be used to both revoke a role from a user, or revoke a privilege from a role.

### 1. [CREATE ROLE](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/create-role)
![[ROLE.svg|bg-white|]] 

### 2. [Create User](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/create-user)
The `CREATE USER` statement creates new MariaDB accounts.

![[Railroad diagram of CREATE USER.svg|bg-white]]
Railroad diagram of CREATE USER
![[Railroad diagram of user_specification.svg|bg-white]]
Railroad diagram of user_specification
![[Railroad diagram of authentication_option.svg|bg-white]]
Railroad diagram of authentication_option
![[Railroad diagram of authentication_rule.svg|bg-white]]
Railroad diagram of authentication_rule
![[Railroad diagram of tls_option.svg|bg-white]]
Railroad diagram of tls_option
![[Railroad diagram of resource_option.svg|bg-white]]
Railroad diagram of resource_option
![[Railroad diagram of password_option.svg|bg-white]]
Railroad diagram of password_option
![[Railroad diagram of lock_option.svg|bg-white]]
Railroad diagram of lock_option


> [!tip] Basic Syntax:
> ```sql
> CREATE USER [IF NOT EXISTS] 'username'@'host_name' IDENTIFIED BY 'password';
> ```

- first generate the hash by running: `SELECT PASSWORD('hello sumit');`
- **SQL:** `CREATE USER IF NOT EXISTS 'sumit'@'localhost' IDENTIFIED BY PASSWORD '*your_computed_hash_here';`

> [!example] 
> ```sql
> CREATE USER 'new_user'@'localhost' IDENTIFIED BY 'strong_password';
> ``` 

### 3. [DROP ROLE](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/drop-role) 
The `DROP ROLE` statement removes one more MariaDB roles. To use this statement, you must have the global [CREATE USER](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/grant#create-user) privilege or the [DELETE](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/grant#table-privileges) privilege for the mysql database.
```sql
DROP ROLE [IF EXISTS] role_name [,role_name ...]
```

- Example
```sql
DROP ROLE journalist;
ERROR 1396 (HY000): Operation DROP ROLE failed for 'journalist'

DROP ROLE IF EXISTS journalist;
Query OK, 0 rows affected, 1 warning (0.00 sec)

Note (Code 1975): Can't drop role 'journalist'; it doesn't exist
```

### 4. [Drop user](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/drop-user)
The `DROP USER` statement removes one or more MariaDB accounts.


> [!success] Syntax
> ```sql
> The DROP USER statement removes one or more MariaDB accounts.
> ```


> [!example] 
>  ```sql
>  DROP USER bob;
>  ERROR 1396 (HY000): Operation DROP USER failed for 'bob'@'%'
>  
>  DROP USER IF EXISTS bob;
>  Query OK, 0 rows affected, 1 warning (0.00 sec)
>  
>  SHOW WARNINGS;
>  +-------+--------+--------------------------------------------------------+
>  | Level | Code | Message                                                    |
>  +-------+--------+-------------------------------------------------------+
>  | Note  | 1974 | Can't drop user 'bob'@'%'; it doesn't exist |
>  +-------+--------+-------------------------------------------------------+
>  ```

### 5. [GRANT](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/grant#roles)
The `GRANT` statement allows you to grant privileges or [roles](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/grant#roles) to accounts. To use `GRANT`, you must have the `GRANT OPTION` privilege, and you must have the privileges that you are granting.

![[Railroad diagram of GRANT (privileges form).svg|bg-white]]
Railroad diagram of GRANT PROXY
![[Railroad diagram of GRANT PROXY.svg|bg-white]]
Railroad diagram of GRANT PROXY
![[Railroad diagram of GRANT (roles form).svg|bg-white]]
Railroad diagram of GRANT (roles form)

![[Privilege Levels]]


### 6. [Rename User](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/rename-user)

> [!example] 
> ```sql
> RENAME USER 'old_username'@'host' TO 'new_username'@'host';
> ```

> [!example]
> ```sql
> CREATE USER 'donald', 'mickey';
> RENAME USER 'donald' TO 'duck'@'localhost', 'mickey' TO 'mouse'@'localhost';
> ```

### 7. [Revoke](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements/revoke)
Remove privileges or roles. Learn how to withdraw previously granted permissions from users or roles to restrict access and secure the database.

- Generic Syntax:
```sql
REVOKE privilege_type ON privilege_level FROM 'username'@'hostname';
```

> [!example] 
> Example 1:
> ```sql
> REVOKE ALL PRIVILEGES ON database_name.* FROM 'username'@'hostname';
> ```
> Example 2:
> ```sql
>  REVOKE INSERT, DELETE ON database_name.* FROM 'username'@'hostname'; 
> ```
> Example 3:
> ```sql
> REVOKE SELECT, INSERT, UPDATE ON database_name.table_name FROM 'username'@'hostname';
> ```

> [!tip] Role
> ```sql
> REVOKE role  [, role ...]
> 	FROM grantee [, grantee2 ... ]
> REVOKE ADMIN OPTION FOR role FROM grantee [, grantee2]
> ```

### 8. Set Default Role
Define the default role for a user. Learn how to configure which role is automatically active when a user connects to the server.

**Syntax :**
```sql
SET DEFAULT ROLE { role | NONE } [ FOR user@host ]
```

> [!example]
> ```sql
> SET DEFAULT ROLE journalist;
> ``` 
>```sql
>CREATE ROLE journalist;
>CREATE USER taniel;
>
>SET DEFAULT ROLE journalist FOR taniel;
>ERROR 1959 (OP000): Invalid role specification `journalist`
>
>GRANT journalist TO taniel;
>SET DEFAULT ROLE journalist FOR taniel;
>``` 

### 9. Set Password
The `SET PASSWORD` statement assigns a password to an existing MariaDB user account.
**Syntax :**
```sql
SET PASSWORD [FOR user] =
    {
        PASSWORD('some password')
      | OLD_PASSWORD('some password')
      | 'encrypted password'
    }
```
![[set_password.svg|bg-white]]

> [!example] 
>```sql
>SET PASSWORD FOR 'bob'@'%.loc.gov' = PASSWORD('newpass');
>``` 

### 10. Set Session Authorization
How much I am able to understand this is use to grant higher privileges to a user for a session for purpose like testing etc. 

I will go in deep in future If I need his.
### 11. Set Role
The `SET ROLE` statement switches the current role for the session, enabling its associated permissions. To have no current role, set `NONE`
**Syntax:**
```sql
SET ROLE { role | NONE }
```

> [!NOTE] 
> ```sql
> --Setting the staff role, and verifying the switch
> SET ROLE staff;
> SELECT CURRENT_ROLE;
> ```
