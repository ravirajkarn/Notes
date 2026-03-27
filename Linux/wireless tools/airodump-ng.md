---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-29 10:54::58 AM
tags:
  - wireless
  - hacking
  - monitor
  - wifi
  - Linux
  - tools
---
# airodump-ng
## Description

Airodump-ng is used for packet capture, capturing raw 802.11 frames. It is particularly suitable for collecting WEP [IVs](http://en.wikipedia.org/wiki/Initialization_vector "http://en.wikipedia.org/wiki/Initialization_vector") (Initialization Vector) or [WPA handshakes](https://www.aircrack-ng.org/doku.php?id=wpa_capture "wpa_capture") for the intent of using them with [aircrack-ng](https://www.aircrack-ng.org/doku.php?id=aircrack-ng "aircrack-ng"). If you have a GPS receiver connected to the computer, airodump-ng is capable of logging the coordinates of the found access points.

## Commands

- Capture packets and display information about wireless network(s) on the 2.4GHz band:
``` bash
sudo airodump-ng interface
```

- Capture packets and display information about wireless network(s) on the 5GHz band:
``` bash
sudo airodump-ng interface --band a
```

- Capture packets and display information about wireless network(s) on both 2.4GHz and 5GHz bands:
```bash
sudo airodump-ng interface --band abg
```
  
- Capture packets and display information about a wireless network given the MAC address and channel, and save the output to a file:
```bash
sudo airodump-ng --channel channel --write path/to/file --bssid mac interface
```

- Capture packets and display information about wireless network including GPS details.
```bash
sudo airodump-ng --gpsd --write file_name interface
```
example:
```bash
sudo airodump-ng --gpsd --write file_name mon0
```

- `--write` flag:  
`--write` flag create all it's report in `.cap`, `.gps`, `.kismet.netxml`, `.csv` `.kismet.csv` and `.log.csv`.
this files that are compatible with Kismet’s older .netxml and
.csv format. 
[GISKismet](giskismet.md) works by importing the .csv or .netxml files output by Kismet (and airodump-ng) into a SQLite database. Then you can run queries against your wardriving results with all of the flexibility of a SQL interface