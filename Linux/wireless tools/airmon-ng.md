---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-21 10:35::15 AM
tags:
  - command
  - Linux
  - hacking
  - wireless
  - wifi
  - network
---

# airmon-ng 
## Description:
It is tool comes with aircrack-ng. It is use to replace many command in Linux to switch into monitor mode. It free us to remember many linux command to switch to monitor mode. 

## Command
```bash
sudo iw wlan0 interface add mon0 type monitor // Or
sudo iwconfig wlan0 mode monitor // and other metord with one.
sudo airmon-ng start wlan0 1
sudo airmon-ng check kill
```