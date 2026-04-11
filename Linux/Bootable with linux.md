---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T06:12:00
tags:
  - boot
  - Linux
  - usb
---
# Create bootable usb from linux

In Linux, you can create a bootable USB drive using either a graphical tool or the command line

. The `dd` command is a powerful, universal terminal-based method, while tools like BalenaEtcher and Ventoy offer a user-friendly graphical interface. 

Regardless of the method, you will need two things to start:

- A USB drive with at least 4GB of storage.
- A Linux `.iso` file, which you can download from the official website of your chosen distribution. 

**Method 1: Use the `dd` command (Terminal)**

This is a universal method that works on any Linux distribution, but it requires careful attention to avoid overwriting the wrong disk. 

1. **Find your USB device name.** Plug in your USB drive and run the `lsblk` command to list all storage devices. Identify your USB based on its size and look for the device name (e.g., `/dev/sdb`, `/dev/sdc`), not the partition (e.g., `/dev/sdb1`).   
```sh
lsblk
```    
2. **Unmount the USB drive.** If your system automatically mounted the drive, you must unmount it before writing the image. Replace `/dev/sdX` with your device's name.
```sh
sudo umount /dev/sdX*
```
3. **Write the ISO to the USB.** Execute the following command, replacing the input file path and the output device name with your own:
```sh
sudo dd if=/path/to/your.iso of=/dev/sdX bs=4M status=progress oflag=sync
```
 - `if`: Input file, the path to your `.iso` file.
- `of`: Output file, your USB device name.
- `bs=4M`: Sets the block size for faster copying.   
- `status=progress`: Shows the write progress.
- `oflag=sync`: Ensures all data is written completely before the command finishes.

4. **Eject the drive.** Safely remove the drive once the command completes.    
```sh
sudo eject /dev/sdX
```

