---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-06 13:43::57 PM
tags:
  - Linux
  - command
---
# Network Manager 
network manager in application run on Linux to manage network in Linux.
We can use it to manage wifi connection.


## Commands
- `nmcli device status`: Displays the current state of all network interface.
- `nmcli connection show`: List all configured connection profile
- `nmcli connection up <name>`: connects to a specific network profile.
- `nmcli connection down <name>`: Disconnects the specified network profile.
- `nmcli device wifi list`: Scans and lists available Wi-Fi access points.
- `nmcli devicce wifi connect <SSID> password <password>`: connects to a specific Wi-Fi network.
- `nmcli connection modify <name> ipv4.addresses <IP/mask> ipv4.gateway <gateway>`: update specific parameters, such as setting a static IP address.
- `nmtui`: A TUI that provides a simple menu-drive way to manage connection and host names.