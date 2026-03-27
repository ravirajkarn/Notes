---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-08 22:06::10 PM
tags:
  - Linux
  - command
  - wireless
---

# Change MAC address of pc.
MAC :- Media Access Control

## Linux
- Old method
```bash
sudo ifconfig wlan0 down
sudo ifconfig wlan0 hw ether 00:11:22:33:44:55
sudo ifconfig wlan0 up
```

- new method
```bash
sudo ip link set dev wlan0 down
sudo ip link set dev wlan0 address 00:1A:2B:3C:4D:5E
sudo ip link set dev wlan0 up
```