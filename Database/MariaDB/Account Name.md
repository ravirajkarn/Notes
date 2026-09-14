---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-16 07:37::16 AM 
tags:
---
# Account Names
Account names have both a user name component and a host name component, and are specified as `'user_name'@'host_name'`.

The user name and host name may be unquoted, quoted as strings using double quotes (`"`) or single quotes (`'`), or quoted as identifiers using backticks (\`\`\`). You must use quotes when using special characters (such as a hyphen) or wildcard characters. If you quote, you must quote the user name and host name separately (for example `'user_name'@'host_name'`).
## Host Name Component

If the host name is not provided, it is assumed to be `'%'`.

example:
```sql
CREATE USER 'joffrey'@'192.168.0.3';
CREATE USER 'joffrey'@'%';
GRANT SELECT ON test.t1 TO 'joffrey'@'192.168.0.3';
GRANT INSERT ON test.t1 TO 'joffrey'@'%';
```

## Anonymous Accounts
Anonymous accounts are accounts where the user name portion of the account name is empty. These accounts act as special catch-all accounts. If a user attempts to log into the system from a host, and an anonymous account exists with a host name portion that matches the user's host, then the user will log in as the anonymous account if there is no more specific account match for the user name that the user entered.

example:
```sql
CREATE USER ''@'localhost';
CREATE USER ''@'192.168.0.3';
```