---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-29 19:48::59 PM
tags:
  - Linux
  - command
  - hacking
  - wifi
  - wireless
---
# hcxpcapngtool

## Details
used to convert `.pcapng` (and other capture) files into hash formats readable by cracking tools like Hashcat and John the Ripper. The primary use is to extract Wi-Fi PMKID and EAPOL hashes from captured network traffic to test the security of a WPA/WPA2 network.

## Extracting Hashcat 22000 hashes 

This is the most common use case. It extracts PMKID and EAPOL handshakes, providing a single, modern hash format for Hashcat (`-m 22000`). This format allows Hashcat to reuse PBKDF2 calculations, making cracking more efficient. 

**Command:**
```bash 
sudo hcxpcapngtool -o redmi13c-01-hashcat.hccapx ./redmi13c-01.cap
```

## **Advanced use:** Extracting additional information `hcxpcapngtool` can also extract other valuable information from a capture file. 

### Extracting ESSIDs and identities

You can extract a list of all network names (ESSIDs), identities, and usernames found in the capture file to create a custom wordlist. 

**Command:**

```bash
hcxpcapngtool -o myhashes.22000 -E essidlist.txt -I identitylist.txt mycapture.pcapng
```

- `-E essidlist.txt`: Writes a list of all captured ESSIDs (network names) to a text file.
- `-I identitylist.txt`: Writes a list of all captured identities to a text file.

### Extracting EAP hashes

For networks using EAP-based authentication, `hcxpcapngtool` can extract specific hash types. - **EAP MD5 (`-m 4800`):**
```sh
hcxpcapngtool --eapmd5=eapmd5.4800 mycapture.pcapng
```

- **EAP LEAP/MSCHAPv2 (`-m 5500`):**
 
```sh
hcxpcapngtool --eapleap=eapleap.5500 mycapture.pcapng
```
 
Extracting AP information

To gather reconnaissance on the access points captured in the file, you can output information to a CSV file. 

**Command:**

```
hcxpcapngtool --csv=ap_info.csv mycapture.pcapng
```

- `--csv=ap_info.csv`: Outputs detailed AP information like MAC addresses, ESSIDs, encryption types, and channels