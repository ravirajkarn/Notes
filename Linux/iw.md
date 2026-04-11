---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-28 11:55::43 AM
tags:
  - command
  - Linux
  - wireless
---

# iw
## Introduction
iw is a new [nl80211](https://wireless.docs.kernel.org/en/latest/en/developers/documentation/nl80211.html) based CLI configuration utility for wireless devices. It supports all new drivers that have been added to the kernel recently. The old tool iwconfig, which uses Wireless Extensions interface, is deprecated and it’s strongly recommended to switch to iw and nl80211.

## Commands
- `iw dev <devname> del` : delete the virtual interface.
```bash
iw dev wlan0 del
```
_note : if above command delete the virtual interface completely, then you need to create a virtual interface from the physical interface._
- `iw phy <phyname> interface add <name> type <mode>` : IT will create a virtual interface from the physical interface named \<name> of the given mode.
```bash
iw phy phy0 interface add wlan0 type managed
```
_what is mode? This mode dictates how the network card behaves and what tasks it can perform._

| MODE                             | details                                                                                                                                                                                                                                                                                                                                                                                                           |
| -------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| managed or station 📡            | - **Function:** This is the **standard client mode**. The interface operates as a normal Wi-Fi device connecting to a central Access Point (AP), like your home router.<br>    <br>- **Purpose:** Connecting to a Wi-Fi network for general internet and network use.<br>    <br>- **Command:** `sudo iw phy phy0 interface add wlan0 type managed`                                                               |
| Access Point (`ap` or `__ap`) 🏠 | - **Function:** This mode turns your device into an **Access Point**, creating its own Wi-Fi network that other devices can connect to.<br>    <br>- **Purpose:** Setting up a wireless hotspot or bridging a connection (often used with software like **Hostapd**).<br>    <br>- **Command:** `sudo iw phy phy0 interface add wlan0 type ap`                                                                    |
| Monitor (`monitor`) 👀           | - **Function:** This mode allows the interface to **passively capture** all raw wireless traffic (802.11 frames) in its range, even packets not addressed to it.<br>    <br>- **Purpose:** Network troubleshooting, packet sniffing, security auditing, and analysis (often used with tools like **Wireshark** or **Aircrack-ng**).<br>    <br>- **Command:** `sudo iw phy phy0 interface add wlan0 type monitor` |
| Ad-Hoc (`ibss`) 🤝               | - **Function:** This mode creates an **Independent Basic Service Set (IBSS)**, allowing devices to connect directly to each other without a central Access Point.<br>    <br>- **Purpose:** Creating a simple peer-to-peer network between two or more devices where no router is present or necessary.<br>    <br>- **Command:** `sudo iw phy phy0 interface add wlan0 type ibss`                                |
- Perform and Active scan:
``` bash
  iwlist wlan0 scan  # using old iwlist command
  iw dev wlan0 scan  # using new iw command
```
- Enabling monitor mode on an existing interface
```bash
iwconfig wlan0 mode monitor # old
iw dev wlan0 set monitor none
```
- Manually set the channel
```bash
iwconfig wlan0 channel 1
iw dev wlan0 set channel 1
```
- Manually enable 802.11n 40-MHz mode:
```bash
iw dev wlan0 set channel 6 HT40+ # or iw dev wlan0 set channel 6 HT40-
```
:Note: The +/- designate if the adjacent 20-MHz channel is above or below the specified one.
- Create a monitor mode interface.
```bash
iw dev wlan0 interface add mon0 type monitor
```
- change channel of a interface.
```bash
sudo iwconfig <interface_name> channel <channel_number> # old
sudo iw dev <interface_name> set channel <channel_number> [optional_band]
```
example
```bash
sudo iw dev mon0 set channel 11
sudo iw dev mon0 set channel 40 5GHz
sudo iwconfig mon0 channel 11
```


