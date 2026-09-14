---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-13 22:48::35 PM
tags:
  - Linux
---
# User Management

## 1. List all the user 
```bash
cat /etc/passwd
```

```bash
sumit:x:1000:1000:Sumit Kumar,,,:/home/sumit:/usr/bin/zsh
```

| **Field**          | **Value**        | **What it means**                                                                                                                       |
| ------------------ | ---------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| **Username**       | `sumit`          | The login name you type to access the system.                                                                                           |
| **Password**       | `x`              | A placeholder. It means your actual encrypted password is securely stored in a separate, restricted file called `/etc/shadow`.          |
| **UID**            | `1000`           | **User ID**. The unique number the operating system uses internally to identify you (1000 is typically the first regular user created). |
| **GID**            | `1000`           | **Group ID**. The unique number for your primary user group (usually shares your username).                                             |
| **GECOS**          | `Sumit Kumar,,,` | **User Info**. Your full name and optional details like office number or phone, separated by commas.                                    |
| **Home Directory** | `/home/sumit`    | Your personal folder where all your files, desktop settings, and configurations live.                                                   |
| **Login Shell**    | `/usr/bin/zsh`   | The command-line environment that starts up when you open a terminal (in this case, Zsh).                                               |
## 2. add new user
```bash
sudo useradd shruti
```

**Usually UID assign to new user is above 1000. and less then 1000 are considered as system level account.**

## 3. remove a user
```bash
sudo userdel shruti
```

## 4. password
```bash
sudo passwd shruti
```
**user password are saved in hash format**
```bash
sudo cat /etc/shadow 
```