---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-22 18:49::09 PM
tags:
  - bluetooth
  - wireless
  - Linux
  - command
  - hacking
---
# [gattacker](https://github.com/securing/gattacker.git)
A Node.js package for BLE (Bluetooth Low Energy) security assessment using Man-in-the-Middle and other attacks

## installation 
### Prerequisite 
1. [**noble**](https://github.com/noble/noble.git): A Node.js BLE (Bluetooth Low Energy) central module
	1. `sudo apt-get install bluetooth bluez libbluetooth-dev libudev-dev`
	2. `npm install noble`
2. [**bleno**](https://github.com/noble/bleno.git): A Node.js module for implementing BLE (Bluetooth Low Energy) peripherals
	1. `sudo apt-get install bluetooth bluez libbluetooth-dev libudev-dev`
	2. `npm install bleno`
3. `sudo apt install bluetooth bluez libbluetooth-dev libudev-dev -y`
4. **Before installing make sure these things**
	1. **gattacker** do not support latest python (> 3.11). Downgrade your python version. Method to do so.
		1. Patching the `node-gyp` script : 
			`sed -i "s/'rU'/'r'/g" /home/ravirajkarn/.config/nvm/versions/node/v14.21.3/lib/node_modules/npm/node_modules/node-gyp/gyp/pylib/gyp/input.py`
		2. Using a compatible Python version:
			`sudo apt install python3.10`
	2. **gattacker** support Node.js v8.16.0.
		`nvm install 8.16.0`
		`nvm use 8.16.0`
### installation
```bash 
git clone https://github.com/securing/gattacker.git
cd gattacker
npm install
```