---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-03-27 22:31::48 PM
tags:
  - Linux
  - command
---
# GRUB
It is boot menu appear on the screen on starting of the screen.

> [!important]  Add new theme.
> 1. **Copy the team folder**
> `/boot/grub/themes` or `/usr/share/grub/themes`
> 2. **Edit the Config**.
> `sudo nvim /etc/default/grub`
> 3. **Change  GRUB_THEME**
> `GRUB_THEME="/boot/grub/themes/new_theme/theme/txt`
> 4. **Update GRUB**
> `sudo update-grub`

