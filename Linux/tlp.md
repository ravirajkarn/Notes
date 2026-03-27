---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-06T08:21:00
tags:
  - Linux
  - command
  - power-manager
  - Introduction
---
# Introduction 

TLP is a feature-rich command line utility for Linux, saving laptop battery power without the need to delve deeper into technical details. 

TLP’s default settings are already optimized for battery life, so you may install it and just sit back and relax. Nevertheless, TLP is completely customizable to get even more power savings or meet your exact requirements.

# Commands
- **`sudo tlp start`** : After installation TLP will start automatically on boot. To avoid having to restart the system the first time, you can start it manually by using the command 
- `sudo tlp-stat -s` : show the tlp short status. 
- `tlp –version`  : show tlp version 
- `sudo tlp bat`  : Apply battery profile and enter manual mode 
- `sudo tlp ac`  : Apply AC profile and enter manual mode 
- `sudo tlp usb` : Apply autosuspend mode for all attached USB devices except those excluded by default or via configuration 
- `sudo tlp bayoff` : Power off optical drive in MediaBay/Ultrabay. 
- `sudo tlp-stat –b` : the main battery will be BAT0, the secondary battery BAT1. When in doubt, check the output of tlp-stat -b, which lists all batteries. 
## Change battery charge thresholds temporarily
`sudo tlp setcharge [<start threshold> <stop threshold>] [<battery>]`

Changes the charge thresholds for the battery to the given values. 
Configured thresholds will be restored at the next boot or by using tlp setcharge again but without the threshold arguments. 

Example: 
`sudo tlp setcharge 70 90 BAT0`

Applies thresholds of 70/90% to battery BAT0. 
## Charge battery to full capacity 
`sudo tlp fullcharge [<battery>]` 

This is done by applying vendor presets to the charge thresholds temporarily. Configured thresholds will be restored at the next boot or by using tlp setcharge without the threshold arguments. 

Hint: after setting the thresholds the command terminates; it does not wait for the charge to complete. 

Example: 
`sudo tlp fullcharge BAT1`

Charges battery BAT1 to full capacity. 
## Force a complete/partial discharge of the battery while on AC power 
Version 1.8 and newer 
`sudo tlp discharge [<battery>] [<level>]`

Version 1.7 and older 
`sudo tlp discharge [<battery>]`

Discharge stops at the specified charge level (in %). If none is specified the battery is fully discharged. The command continuously shows remaining capacity and estimated discharge time. Discharging may be stopped at any time with Control-C. 

Hints: 
- The command needs the charger plugged in 
- As soon as the battery is empty, charging begins and the command terminates; it does not wait for the charge to complete 
- Normal use of the laptop is possible during the discharge process; it does not suddenly switch off when the battery is empty 
- ThinkPads with two batteries: the battery controller can only handle one battery at a time; while discharging one battery with this command the other battery can neither be charged nor discharged 
- When encountering problems, see the FAQ: [Battery Care](https://linrunner.de/tlp/faq/battery.html) 
## Perform a battery re calibration while on AC power 
`sudo tlp recalibrate [<battery>]`

This command works as follows: 
- The command needs the charger plugged in 
- Applies vendor presets to the charge thresholds 
- Discharges the selected battery completely; 
- As soon as the battery is empty, charging begins and the command terminates; it does not wait for the charge to complete 
- Normal use of the laptop is possible during the discharge process; it does not suddenly switch off when the battery is empty 
- Important: to complete the recalibration process, let the battery charge to 100 % subsequently; you may power off but not remove the charger 
- ThinkPads with two batteries: the battery controller can only handle one battery at a time; while discharging one battery with this command the other battery can neither be charged nor discharged 
- When encountering problems, see the FAQ: [Battery Care](https://linrunner.de/tlp/faq/battery.html) 
    
Example: 
`sudo tlp recalibrate BAT0`

Recalibrates battery BAT0. 
Hints: 
- Configured thresholds will be restored at the next boot or by using tlp setcharge without the threshold arguments 
- ThinkPads with two batteries: the battery controller can only handle one battery at a time; while discharging one battery with this command the other battery can neither be charged nor discharged 
- Recalibration forces the battery pack to update the energy_full or charge_full information shown by tlp-stat -b     
- Recalibration does not repair defective or worn out batteries 

- Enable, disable or check automatic event based actions on radio devices (aka [Radio Device Wizard](https://linrunner.de/tlp/settings/rdw.html)): 
	`tlp-rdw [ enable | disable ]`

## tlp-stat 
Purpose 
View TLP’s configuration, system information, kernel power saving tunables and battery data. 
Invocation without options shows all information categories 
`sudo tlp-stat`

View battery data 
```Bash
sudo tlp-stat -b 
sudo tlp-stat --battery
```

Add -v to see battery voltages (if available). 
View active configuration 
```Bash
tlp-stat -c 
tlp-stat --config  
```

View the difference between defaults and user configuration 
```Bash
tlp-stat --cdiff
```

View disk device information 
```Bash
sudo tlp-stat -d 
sudo tlp-stat --disk
```

View PCIe device information 
```Bash
sudo tlp-stat -e 
sudo tlp-stat --pcie  
```

Add -v to see device runtime status. 
View graphics card information 
```Bash
sudo tlp-stat -g 
sudo tlp-stat --graphics  
```

View current power mode 
Version 1.7 
```Bash
tlp-stat -m 
tlp-stat --mode  
```

View processor information 
```Bash
sudo tlp-stat -p 
sudo tlp-stat --processor  
```

For clarity the standard output shows only cpu0, add -v to see all. 

Version 1.7 
Omit version header and show less information in the processor category. 
```Bash
tlp-stat -q 
tlp-stat --quiet  
```

View radio device states 
```Bash
tlp-stat -r 
tlp-stat --rfkill  
```

View system information and TLP status 
```Bash
tlp-stat -s 
tlp-stat --system  
```

View temperatures and fan speed 
```Bash
tlp-stat -t 
tlp-stat --temp  
```

View USB device information 
```Bash
tlp-stat -u 
tlp-stat --usb  
```

Add -v to see device runtime status. 

Show more information in battery, PCIe, processor and USB categories. 
```Bash
tlp-stat -v 
tlp-stat --verbose  
```

View version 
Version 1.7 
```Bash
tlp-stat --version  
```

Diagnostics and debugging 
Monitor power supply udev events: 
```Bash
sudo tlp-stat -P 
sudo tlp-stat --pev  
```

View power supply diagnostics: 
```Bash
tlp-stat --psup  
```

View trace output: 
```Bash
sudo tlp-stat -T 
sudo tlp-stat --trace  
```

Check if udev rules for power source changes and connecting USB devices are active: 
```Bash
tlp-stat --udev  
```

View warnings about SATA disks: 
```Bash
tlp-stat -w 
tlp-stat --warn
```

## Configuration
If you just want to make a quick change to the configuration, read this section and then read the rest later. 
Open TLP’s main config file with a text editor: 
```Bash
sudo nano /etc/tlp.conf  
```
Change the desired line(s). Before: 
```vim
#CPU_ENERGY_PERF_POLICY_ON_AC=balance_performance 
#CPU_ENERGY_PERF_POLICY_ON_BAT=balance_power  
```

After – remember to remove the leading #: 
```Bash
CPU_ENERGY_PERF_POLICY_ON_AC=balance_performance 
CPU_ENERGY_PERF_POLICY_ON_BAT=power  
```

Note 
In contrast to below, the two preceding code blocks are not shell commands but excerpts from the configuration file. 
Save and quit the editor. Then activate your changes using the shell command 
`sudo tlp start`

## Profiles 

TLP uses two settings profiles that are automatically applied depending on the power source: 
- Parameters ending in _AC are effective when AC is connected     
- Parameters ending in _BAT are effective when running on battery 

Parameters ending neither in _AC nor in _BAT apply to both profiles. 

| Important <br><br>Parameters without intrinsic default (see [below](https://linrunner.de/tlp/settings/introduction.html#set-param-defaults)) must always be specified for both _AC and _BAT. Omitting one of the two makes the set value effective for both power sources, since a change only occurs when different values are defined. |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |

## Config Files 

Settings are read from the following files in the specified order: 
- Intrinsic defaults 
- /etc/tlp.d/*.conf: Drop-in customization snippets, read in lexical (alphabetical) order 
- /etc/tlp.conf: User configuration 

Hints: 
- In case of identical parameters in several but also within the same file, the last occurrence has precedence 
- This also means, parameters in /etc/tlp.conf will override anything else because it is read last 
- All parameters in /etc/tlp.conf are disabled, remove the leading # to activate your change 
- Config files in the /etc/tlp.d/ directory are created by the user: 
    - Filenames must end in .conf, otherwise the file will be ignored 
    - 00-template.conf is provided as an example 
- If in doubt, put your configuration changes in /etc/tlp.d/01-mytlp.conf 
- [Transfer settings when upgrading](https://linrunner.de/tlp/faq/settings.html#faq-set-mig-from-13) describes how to migrate your configuration from versions before 1.3

| Note <br><br>TLP versions 1.2.2 and older stored all settings in a single config file named /etc/default/tlp. |
| ------------------------------------------------------------------------------------------------------------- |

## Parameter Defaults 

Two kinds of parameters exist: 
- Parameters with intrinsic default: 
    - Marked with “Default when unconfigured:” in this documentation 
    - Preceded by “Default:” in /etc/tlp.conf 
- Parameters without intrinsic default 

| Note <br><br>Parameter values given in this documentation and in the config files may be suggestions rather than intrinsic defaults. |
| ------------------------------------------------------------------------------------------------------------------------------------ |

## Parameter Syntax 
[Config Files](https://linrunner.de/tlp/settings/introduction.html#set-config-files) consist of parameter and comment lines. 

#### Parameter lines 
`PARAMETER=value`

Parameter values containing blanks must be enclosed in double quotes: 
`USB_DENYLIST="1111:2222 3333:4444"`  

#### Comment lines 
The content of lines beginning with a # in the first column is ignored completely: 
`#What is written here does not matter.`  

Empty lines are ignored as well. 
Until version 1.5 comments after parameters are not allowed, the whole line will be silently ignored: 
`EXAMPLE="do not use like this" # Parameter in front is ignored - until version 1.5!`

As of version 1.6 the above line is valid and taken into account. 

#### Disabling features 
Parameters without intrinsic default may be disabled by commenting them out with a leading #: 
`#STOP_CHARGE_THRESH_BAT1=80`

Parameters with intrinsic default may be disabled by entering an empty string: 
`RUNTIME_PM_DRIVER_DENYLIST=""`

#### Concatenation with += 
A nifty feature to add something to an intrinsic default (Example 1): 
```Bash
Intrinsic default DISK_DEVICES=”nvme0n1 sda”
plus /etc/tlp.d/01-mytlp.conf: 
DISK_DEVICES+="sdb"  

Results in: DISK_DEVICES=”nvme0n1 sda sdb” 
```
Or add values in a subsequent config file (Example 2): 
```Shell
/etc/tlp.d/01-mytlp.conf: 
USB_DENYLIST="1111:2222 3333:4444"  

plus /etc/tlp.d/02-hw-specific.conf: 
USB_DENYLIST+="5555:6666"  

Results in: USB_DENYLIST=”1111:2222 3333:4444 5555:6666” 
```

#### Making Changes 
A config file can be changed with any text editor (root privilege is needed). For example: 
```Shell
sudo nano /etc/tlp.conf  

sudo nano /etc/tlp.d/01-mytlp.conf  
```
All changes must be activated by removing the leading # and, after saving the file, will take effect only 
- after a reboot, 
- plugging or unplugging AC 
- or by the shell command 
    `sudo tlp start`