---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-28 21:21::35 PM
tags:
  - Linux
  - command
  - wireless
  - wifi
  - hacking
---
# aircrack-ng
## Detail 
This software help us to crack WEP and WPA/WPA2 keys from handshake is captured packets.

## Commands
- Crack key from the capture file using \[W]ordlist:
```bash
sudo aircrack-ng -w path/to/wordlist.txt path/to/capture.cap
```

- Crack key using multiple CPU threads for capture file using wordlist:
```bash
sudo aircrack-ng -w number -w part/to/wordlist.txt path/to/capture.cap
```

- Crack key from capture file using wordlists and the access point's essid
```bash
sudo aircrack-ng -w path/to/wordlist.txt -e essid path/to/capture.cap
```

- Crack key from capture file using [w]ordlist and the access point's MAC address:

```bash
sudo aircrack-ng -w path/to/wordlist.txt --bssid mac path/to/capture.cap
```