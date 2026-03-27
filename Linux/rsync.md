---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-02-28 07:53::55 AM
tags:
  - Linux
  - command
---

# rsync

- copy
```zsh
rsync source/folder destination/folder
```
- copy folder
```zsh
rsync -r source/folder/ destination/folder
```
> [!info]
> this will give all the folder new time stamp means. It create all the folder new.

- copy with archive
```zsh
rsync -a source/folder/ destination/folder
```
> [!info]
> this will preserve the all the metadata like timestamp

- -h : human readable
- --progress : show progress 
- --partial : if file get cancel in middle. if we run this again this will take less time.
- --delete : destination will same as source if any other will be delete.
- --remove-source-file: it will remove all the file on source directory.
- copy on ssh
```zsh
rsync -ahP source/file sshIP/destination
```
- -z : help in compression. it also reduce file by compressing it.