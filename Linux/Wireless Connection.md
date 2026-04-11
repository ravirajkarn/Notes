---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-01-21T17:09:00
tags:
  - Linux
  - wifi
---
note: wifi should be properly shutdown previous os if not there if bit complication. 

To Connect to a network 

we will use tool like wpa_supplicant and iwconfig. 

step 1 : need to know your wifi driver name. tools can be use: iwconfig, nmcli. 
```Bash 
lo              no wireless extensions. 

eth0            no wireless extensions. 

wlan0           IEEE 802.11  ESSID:"Redmi 9i"   
				Mode:Managed  Frequency:2.427 GHz  Access Point:F6:F6:86:41:A5:AF
				Bit Rate=1 Mb/s   Tx-Power=16 dBm    
				Retry short limit:7   RTS thr:off   Fragment thr:off 
				Power Management:off 
				Link Quality=70/70  Signal level=-29 dBm   
				Rx invalid nwid:0  Rx invalid crypt:0  Rx invalid frag:0 
				Tx excessive retries:0  Invalid misc:18   Missed beacon:0 
```
with wpa_supplicant : it support all network like open/wpa/wpa2/wpa3 security connecton  

step 2: need to create a configuration fille. 

```Bash
vim /etc/wpa_supplicant/wpa_supplicant.conf // and write on wpa_supplicant.conf
```

```vim
ctrl_interface=/run/wpa_supplicant 
update_config=1 
```
note with update_config=1 you will allow wpa_suppplicant to overwrite the configuration file. 

step 3: start wpa_supplicant with: 

	sudo wpa_supplicant -B -i interface -c /etc/wpa_supplicant/wpa/supplicant.conf 

step 4: run  

```Bash
sudo wpa_cli 
> scan 
OK 
<3>CTRL-EVENT-SCAN-RESULTS 
> scan_results 
bssid / frequency / signal level / flags / ssid 
00:00:00:00:00:00 2462 -49 [WPA2-PSK-CCMP][ESS] Redmi 9i 
11:11:11:11:11:11 2437 -64 [WPA2-PSK-CCMP][ESS] ANOTHERSSID 
```

step 5: to associate with Redmi 9i 
```Bash
> add_network 
0 
> set_network 0 ssid "Redmi 9i" 
> set_network 0 psk "passphrase" 
> enable_network 0 
<2>CTRL-EVENT-CONNECTED - Connection to 00:00:00:00:00:00 completed (reauth) [id=0 id_str=] 
```
      Note: if "Redmi 9i" don't have passkey then replacing the command "set_network 0 psk "passphrase"" with "set_network 0 key_mgmt NONE". 

step 6: to save the the configuration file 
```Bash
> save_config 
OK 
> quit 
```
To connecting with wpa_passphrase 

step 2: to generate a file with your known network name and passpherse  

	`wpa_passphrase "Redmi 9i" "suumit kumar" > /home/kali/Documents/wpa.conf`

your file will look somthing like this: 

```Bash
cat /home/kali/Documents/wpa.conf                          
network={ 
        ssid="Redmi 9i" 
        #psk="sumit kumar" 
        psk=5e01e0a1213a7d5feded0c2c2e9b07794cf8949676b893bf4944a1cab63a20c9 
} 
```
Step 3: run `wpa_supplicant -B -i interface -c <(wpa_passphrase MYSSID passphrase)`
	`sudo wpa_supplicant -B -i wlan0 -c < /home/kali/Documents/wpa.conf`
