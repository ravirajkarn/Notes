---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-18 13:49::37 PM
tags:
  - bluetooth
  - hacking
  - tools
  - wireless
  - command
---

# bluepot
A piece of software designed to accept and store any malware sent to it and interact with common Bluetooth attacks such as “BlueBugging?” and “BlueSnarfing?

## Requirements
You must install:

- libbluetooth-dev on Ubuntu
- bluez-libs-devel on Fedora
- bluez-devel on openSUSE

## run bluepot
⚠️ Running a honeypot as root is a bit risky (but necessary for this software)

```
wget https://github.com/andrewmichaelsmith/bluepot/raw/master/bin/bluepot-0.2.tar.gz
tar xfz bluepot-0.2.tar.gz
cd bluepot/
sudo java -jar bluepot.jar
```