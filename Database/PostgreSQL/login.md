---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-20 07:56::14 AM
tags:
  - Database
  - postgreSQL
---
# Login 
You need to first need the access of the database to work on it. If you freshly installed it then administrative rights to login.

by default:
postgres have default user **postgres** 

## Method of login:
in linux you usually install database in it's separate user.
### Method 1:
Switch to the Linux **`postgres`** user
```bash
sudo -i -u postgres psql
```

### Method 2:
Force password authentication via TCP/IP
```zsh
psql -U postgres -h localhost
```

