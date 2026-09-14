---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-20 09:21::20 AM
tags:
  - Database
  - postgreSQL
---
# User Account Management

## Creating User

> [!important] 
> PostgreSQL uses the concept of **roles** to represent user accounts. It doesn’t use the concept of users like other database systems.

Typically, roles that can log in to the PostgreSQL server are called login roles. They are equivalent to user accounts in other database systems.

Here’s the basic syntax of the `CREATE ROLE` statement:

```postgreSQL
CREATE ROLE role_name;
```

For example, the following statement uses the `CREATE ROLE` statement to create a new role called `bob`:

```postgreSQL

CREATE ROLE bob;
```

To retrieve all roles in the current PostgreSQL server, you can query them from the `pg_roles` system catalog as follows:

```postgreSQL

SELECT rolname FROM pg_roles;
```

Output:

```
rolname
----------------------------- 
pg_database_owner 
pg_read_all_data 
pg_write_all_data 
pg_monitor 
pg_read_all_settings 
pg_read_all_stats 
pg_stat_scan_tables 
pg_read_server_files 
pg_write_server_files 
pg_execute_server_program 
pg_signal_backend 
pg_checkpoint 
pg_use_reserved_connections 
pg_create_subscription 
postgres 
bob
(16 rows)
```
Notice that the roles whose names start with `pg_` are system roles. The `postgres` is a [superuser](https://neon.com/postgresql/administration/create-superuser-postgresql) role created by the PostgreSQL installer.

In `psql`, you can use the `\du` command to show all roles that you create including the postgres role in the current PostgreSQL server:

```postgreSQL
\du
```

### Role attributes
The attributes of a role define privileges for that role, including login, [superuser](https://neon.com/postgresql/administration/create-superuser-postgresql) status, database creation, role creation, password management, and so on.

Here’s the syntax for creating a new role with attributes.

```
CREATE ROLE name WITH option;
```

In this syntax, the `WITH` keyword is optional. The `option` can be one or more attributes like `SUPERUSER`, `CREATEDB`, `CREATEROLE`, etc.

```postgreSQL
CREATE ROLE john 
SUPERUSER 
LOGIN 
PASSWORD 'securePass1';
```

To change attributes of a [role](https://neon.com/postgresql/administration/postgresql-roles), you use the following form of `ALTER ROLE` statement.
Here’s the basic syntax of the `ALTER ROLE` statement:

```postgreSQL
ALTER ROLE role_name [WITH] option;
```

The option can be:
- `SUPERUSER` | `NOSUPERUSER` – determine if the role is a `superuser` or not.
- `CREATEDB` | `NOCREATEDB`– allow the role to create new databases.
- `CREATEROLE` | `NOCREATEROLE` – allow the role to create or change roles.
- `INHERIT` | `NOINHERIT` – determine if the role inherits the privileges of roles of which it is a member.
- `LOGIN` | `NOLOGIN` – allow the role to log in.
- `REPLICATION` | `NOREPLICATION` – determine if the role is a replication role.
- `BYPASSRLS` | `NOBYPASSRLS` – determine if the role is to bypass the row-level security (RLS) policy.
- `CONNECTION LIMIT limit` – specify the number of concurrent connections a role can make, -1 means unlimited.
- `PASSWORD 'password' | PASSWORD NULL` – change the role’s password.
- `VALID UNTIL 'timestamp'` – set the date and time after which the role’s password is no longer valid.

## Privilege

### REVOKE
PostgreSQL `REVOKE` statement to remove privileges from a role.

The `REVOKE` statement revokes previously [granted privileges](https://neon.com/postgresql/administration/postgresql-grant) on database objects from a [role](https://neon.com/postgresql/administration/postgresql-roles)

The following shows the syntax of the `REVOKE` statement that revokes privileges on one or more tables from a role:

```postgreSQL
REVOKE privilege | ALLON TABLE table_name |  ALL TABLES IN SCHEMA schema_nameFROM role_name;
```

In this syntax:
- First, specify one or more privileges that you want to revoke or use the `ALL` option to revoke all privileges.
- Second, provide the name of the table after the `ON` keyword or use the `ALL TABLES` to revoke specified privileges from all tables in a schema.
- Third, specify the name of the role from which you want to revoke privileges.
## Change Password

```postgreSQL
ALTER ROLE username 
WITH PASSWORD 'password';
```

Sometimes, you want to set the password to be valid until a date and time. In this case, you use the `VALID UNTIL` clause:

```postgreSQL
ALTER ROLE username
WITH PASSWORD 'new_password'
VALID UNTIL timestamp;
```

The `VALID UNTIL` clause is optional. If you omit it, the password will have no expiration date.

The following statement uses the `ALTER ROLE` statement to set the expiration date for the password of  `super` user to `December 31 2050`:

```postgreSQL
ALTER ROLE bob
VALID UNTIL 'December 31, 2050';
```

To verify the result, you can use the `\du` command in psql to [view the detailed information of the user](https://neon.com/postgresql/administration/postgresql-list-users):

```
\du super
```

Output:
```bash
Role name |                 Attributes
---------------+---------------------------------------------
 super         | Password valid until 2050-12-31 00:00:00+07
``` 

