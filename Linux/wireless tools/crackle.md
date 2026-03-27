---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-19 09:24::16 AM
tags:
  - tools
  - hacking
  - Linux
  - command
  - bluetooth
---

# CrackLE
crackle cracks BLE Encryption (AKA Bluetooth Smart).

crackle exploits a flaw in the BLE pairing process that allows an attacker to guess or very quickly brute force the TK (Temporary Key). With the TK and other data collected from the pairing process, the STK (Short Term Key) and later the LTK (Long Term Key) can be collected.

With the STK and LTK, all communications between the master and the slave can be decrypted.

## Important 
Crackle itself can help determine whether or not there are Link Layer encrypted packets in a given PCAP or PcapNG file. Simply run the tool without any extra options and it will list how many encrypted packets it finds for each connection in the input:

```
$ crackle -i input.pcap
...
Analyzing connection n:
  xx:xx:xx:xx:xx:xx (public) -> yy:yy:yy:yy:yy:yy (public)
  Found 13 encrypted packets
```

If this number is non-zero, then the device is likely using Link Layer encryption.

You can also use Wireshark to look for such packets. Load your capture file and apply the filter "btle.data_header.length > 0". Link Layer encrypted packets will look like an L2CAP fragment of non-zero length with random-looking data as in the following screenshot:![](encrypted_data.png)
