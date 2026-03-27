---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-11 20:01::34 PM
tags:
  - Linux
  - usb
---
**Format the Drive**: Use the `mkfs` (make filesystem) command. The exact command depends on the file system you want.

- **For exFAT (Recommended for compatibility)**:
```bash
sudo mkfs.exfat -n "MyUSB" /dev/sdb1
```
(Replace `"MyUSB"` with your desired volume label and `/dev/sdb1` with the correct partition identifier from `lsblk`).

- **For FAT32**:
```bash 
sudo mkfs.vfat -n "MyUSB" /dev/sdb1
```

- **For NTFS**:
```bash
sudo mkfs.ntfs -L "MyUSB" /dev/sdb1
```

- **For Ext4 (Linux only)**:    
```bash
sudo mkfs.ext4 -L "MyUSB" /dev/sdb1
```