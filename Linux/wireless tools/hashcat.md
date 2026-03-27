---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-29 10:21::32 AM
tags:
  - hacking
  - Linux
  - wifi
  - wireless
  - command
---
## hashcat
## detail
Hashcat is a password recovery and cracking tool.

It a very good password cracking tool. It support different method to crack password.

Few method that hashcat do not support you can find it in the John the Ripper.

## How to use.
I will edit this page as I will learn the way to use it.

### Use for WPA/WEP/WEP2 password cracking.

- hashcat can't read from the libpcap packet capture directly. [hcxpcapngtool](hcxpcapngtool.md) includes support for converting the cap file to the intermediate hccapx format.
```bash
sudo hcxpcapngtool ./redmi13c-01.cap -o redmi13c-01-hashcat.hccapx
```

- once created you are ready to go.
```bash
sudo hashcat -m 22000 redmi13c-01-hashcat.hccapx /usr/share/wordlists/rockyou.txt
```
