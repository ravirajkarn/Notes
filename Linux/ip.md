---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-08 21:53::12 PM
tags:
  - network
  - Linux
  - command
  - wireless
  - wifi
---

# ip
The `ip` command is the **modern, primary utility** in Linux for **managing and configuring network interfaces, routing tables, and network policies**. It is intended to replace older commands li
Here is how to use ￼￼ip￼￼ for common networking tasks:


ke `ifconfig`, `route`, `arp`, and `netstat`.

The general syntax is:

```bash
ip [OPTIONS] OBJECT{COMMAND∣help}
```

## 1. Interface Management (`ip link`)

The `ip link` command is used to display and modify the state of network interfaces (e.g., Ethernet, Wi-Fi, loopback).

| Task                          | Command                                               | Description                                              |
| ----------------------------- | ----------------------------------------------------- | -------------------------------------------------------- |
| **View all interfaces**       | `ip link show`                                        | Lists all network interfaces and their status (UP/DOWN). |
| **View a specific interface** | `ip link show dev eth0`                               | Shows detailed information for the `eth0` interface.     |
| **Bring an interface UP**     | `sudo ip link set dev eth0 up`                        | Activates the network interface.                         |
| **Bring an interface DOWN**   | `sudo ip link set dev eth0 down`                      | Deactivates the network interface.                       |
| **Change MAC Address**        | `sudo ip link set dev eth0 address 00:1A:2B:3C:4D:5E` | Temporarily sets a new hardware address.                 |

## 2. Address Management (`ip addr`)

The `ip addr` (or `ip address`) command is used to display, add, or delete IP addresses and their properties.

|Task|Command|Description|
|---|---|---|
|**View all addresses**|`ip addr show`|Displays all configured IP addresses, their subnets, and scopes.|
|**View address for specific interface**|`ip addr show dev eth0`|Shows the IP address(es) assigned to `eth0`.|
|**Add a new IP address**|`sudo ip addr add 192.168.1.100/24 dev eth0`|Assigns an IP address and subnet mask to `eth0`.|
|**Delete an IP address**|`sudo ip addr del 192.168.1.100/24 dev eth0`|Removes the specified IP address from `eth0`.|

## 3. Routing Table Management (`ip route`)

The `ip route` command is used to display and modify the system's routing table.

|Task|Command|Description|
|---|---|---|
|**View routing table**|`ip route show`|Lists the current routing rules.|
|**Add a default gateway**|`sudo ip route add default via 192.168.1.1`|Sets the default router (gateway) for all traffic.|
|**Add a static route**|`sudo ip route add 10.0.0.0/8 via 192.168.1.254`|Adds a rule to send all traffic for the `10.x.x.x` network through the gateway at `192.168.1.254`.|
|**Delete a route**|`sudo ip route del 10.0.0.0/8`|Removes the specified route.|

## 4. ARP Table Management (`ip neigh`)

The `ip neigh` (or `ip neighbour`) command is used to manage the Address Resolution Protocol (ARP) cache.

|Task|Command|Description|
|---|---|---|
|**View ARP cache**|`ip neigh show`|Shows the mapping of IP addresses to MAC addresses.|
|**Delete an ARP entry**|`sudo ip neigh del 192.168.1.1 dev eth0`|Removes the specific neighbor entry.|

> [!question] How to Combine multiple network to form a single.
> - Combine multiple network to form a single it will increases data speed. 
> 
> **Step 1**: Find your interfaces name and their respective gateway IPs.
> ```bash
> ip route show
> ```
> **Example**
> ```bash
> ──(ravirajkarn㉿sumit)-[~]
> └─$ ip route show
default via 10.163.138.162 dev usb0 proto dhcp src 10.163.138.95 metric 100 
default via 10.227.151.231 dev wlan0 proto dhcp src 10.227.151.106 metric 600 
10.163.138.0/24 dev usb0 proto kernel scope link src 10.163.138.95 metric 100 
10.227.151.0/24 dev wlan0 proto kernel scope link src 10.227.151.106 metric 600 
172.17.0.0/16 dev docker0 proto kernel scope link src 172.17.0.1 linkdown 
> ```
> _Assume usb0 and wlan0_
> 
> **Step 2:** Remove Existing Default Routes.
> Before adding a combined route, you must remove the existing individual default routes to avoid conflicts.
> ```bash
> sudo ip route del default dev usb0
> sudo ip route del default dev wlan0
> ```
> **Step 3:** Add the multi-path route.
> ```bash
> sudo ip route add <interface-name> scope global nexthop via <gateway1> dev <gateway1-name> weight <num> nexthop via <gateway2-name> dev <gateway2-name> weight <num>
> ``` 
> _weight 2 for 100Mbps and weight 1 for 50Mbps._
> 
> **Example**
> ```bash
> sudo ip route add multi scope global nexthop via 10.163.138.162 dev usb0 weight 4 nexthop via 10.227.151.231 dev wlan0 weight 1
> ```
> 

> [!success] revert your networking
> **Option 1:** Service Restart
> ```terminal
> sudo systemctl restart NetworkManger
> ```
> **Option 2:** Manual Way
> **Step 1:**
> ```terminal
> sudo ip route del default
> ```
> **Step 2:**
> ```terminal
> sudo ip route add default via [Gateway_IP_1] dev usb0
> sudo ip route add default via [Gateway_IP_2] dev wlan0
> ```
