---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-25 16:07::18 PM
tags:
  - hacking
  - wireless
  - wifi
---
# Hacking Exposed wireless
## Introduction
This is my thoughts and impotent points in this chapter.  
## 8.11 in a Nutshell
 1. Wi-Fi is a subset of the 802.11 standard, which is managed by the Wi-Fi Alliance.
 2. The 802.11 standard divides all packets into three different categories: **data, management, and control.**
 3. **Data Packet** are used to carry higher-level data(such as IP packets).
 4. **Management Packets** control the management of the network.
 5. **Control Packets** also known as *media access control*. They are used for mediating access to the shared medium.
### Packets
most 802.11 Packets have three addresses: **a source address *(transmitter address)*, a destination address *(receiver address)*, and a *Basic Service Set ID (BSSID)* .** 
**BSSID:** often same MAC address as the wireless interface on the AP.
### 802.11 Security Primer
Primary **encryption techniques** used to protect 802.11 networks:
1. **Wired Equivalency Protocol (WEP)**
2. **Wi-Fi Protected Access (WPA)**
#### **Wired Equivalency Protocol (WEP)**
 - **WEP** networks (usually) rely on static 40-bit or 104-bit key that is known on each client. This key is used to initialise a **stream cipher (RC4)** 
 - **WPA** can be configured in tow very different modes: **Pre-shared key *(or passphrase)* .** and **enterprise mode**.
 
##### **WPA Pre-Shared Key (WPA-PSK)**
 - Work similar way to WEP, as it requires the connecting party to provide a key in order to access the wireless network.
 - **WPA-PSK** authentication process is also known as **four-way handshake**.
![](4-way-handshake.png)
- **PMK:** Pairwise Master Key
- **PTK:** Pairwise Transient Key
- **MIC:** Message Integrity Code
- **GTK:** Group Temporal Key
##### WPA Enterprise
- **PMK** is created dynamically every time a user connects.
- _This means that even if you recover a PMK, you could impersonate a single user for a specific connection._
- The AP and the authentication server speak over a protocol called RADIUS.
- Server ultimately makes the decision to accept or reject the user.
- Successful, the client and the authentication server both derive the same PMK.
![](WPA-Enterprise.png)
- **EPA:** Extensible Authentication Protocol