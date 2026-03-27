---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-01-21T17:09:00
tags:
  - Linux
  - command
---
We are going to use apt(Advanced Package Management) 

we should not edit directly /etc/apt/sources.list. Four each new package repository we should create a new file with new name under /etc/apt/sources.list.d/  

This directory hold the data from where  our packages are gone to download or install. 
```Bash 
apt-get [option] <url / package_name / "./local/directory"> 

[options]                      Description
Install        ---     use to install the package. 
upgrade        ---     use to upgrade a install package. 
auto-remove    ---     use to remove a installed package.
auto-repair    ---     use to repair broken installation 
update         ---     use to update package
```

### installing multiple program simultaneously
1. Using `dpkg`:

This method is suitable for installing multiple `.deb` packages at once, but it does not automatically resolve dependencies. Navigate to the directory.

Code

```
  cd /path/to/the/directory/containing/debs
```

Replace `/path/to/the/directory/containing/debs` with the actual path. install all packages.

Code

```
  sudo dpkg -i *.deb
```

This command will attempt to install all `.deb` files in the current directory.

- **Resolve dependencies (if needed):** If `dpkg` reports missing dependencies, run:

Code

```
  sudo apt-get install -f
```

This command will attempt to download and install the necessary dependencies.

2. Using `dpkg -R` for recursive installation:

This command allows for recursive installation of `.deb` files within a directory and its sub directories. Install recursively.

Code

```
  sudo dpkg -R /path/to/the/directory/containing/debs
```

Replace `/path/to/the/directory/containing/debs` with the actual path.

### Installation of pre-compiled binaries.
#### Option 1: The System-Wide Way
place all the  contain of `bin` & `lib` inside `/usr/local/`

**Step 1**
```bash
sudo cp -r bin/* /usr/local/bin
sudo cp -r lib/* /usr/local/lib
```

> [!NOTE] 
> If lib contain may item.
> ```bash
> sudo cp -r bin/* /usr/local/bin
> sudo cp -r lib/* /usr/local/lib/myapp
> ```
> 
> 
> Tell the system where to find the `.so` files
> ```bash
> echo "/usr/local/lib/myapp" | sudo tree /etc/ld.so.conf.d/myapp.conf
> ```

**Step 2**
update the library cache:
```bash 
sudo ldconfig
```

#### Option 2: Self-Contained Way
If software is large, complex package
**Step 1**
```bash
sudo mv my_extracted_folder /opt/my_app
```

**Step 2**
Create a symbolic link:
```bash
sudo ln -s /opt/my_app/bin/app_name /usr/local/bin/app_name
```

#### Option 3: Local User Way
`sudo` privileges not required
- Move `bin` file to: `~/.local/bin`
- Move `lib` file to: `~/.local/lib`
- add `~/.local/bin` to your system's PATH variable