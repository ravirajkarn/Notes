---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-08-28T06:12:00
tags:
  - Linux
  - bluetooth
  - dbus
---
## sdptool 
sdptool(1)  provides the interface for performing SDP queries on Bluetooth devices, and administering a local SDP database.

```bash
sdptool browse xx:xx:xx:xx:xx:xx
```
# Managing call 
While there is no user interface for it (yet), it is straightforward to use it from the command line with tools such as `busctl` or `qdbus`. Here’s a short tutorial on how to use it:

1. To begin with, make sure you are running PipeWire 1.3.82 or later, with the bluez plugin loaded (in WirePlumber).
2. Pair a mobile phone with your Linux system. You may use your desktop’s UI for that, or `bluetoothctl` on the command line.
3. Now, explore the API. The main object is `/org/pipewire/Telephony` on the `org.pipewire.Telephony` service: 

```shell
busctl --user introspect org.pipewire.Telephony /org/pipewire/Telephony
```

```bash
NAME                                TYPE      SIGNATURE  RESULT/VALUE  FLAGS
org.freedesktop.DBus.Introspectable interface -          -             -
.Introspect                         method    -          s             -
org.freedesktop.DBus.ObjectManager  interface -          -             -
.GetManagedObjects                  method    -          a{oa{sa{sv}}} -
.InterfacesAdded                    signal    oa{sa{sv}} -             -
.InterfacesRemoved                  sigsdptool browse 00:80:98:24:15:6D
nal    oas        -             -
org.ofono.Manager                   interface -          -             -
.GetModems                          method    -          a{oa{sv}}     -
.ModemAdded                         signal    oa{sv}     -             -
.ModemRemoved                       signal    o          -             -
```

4. You can list the available connected phones by calling `GetManagedObjects` (prefered) or `GetModems` from the oFono compatibility interface:
```shell
> busctl --user call org.pipewire.Telephony /org/pipewire/Telephony org.freedesktop.DBus.ObjectManager GetManagedObjects
a{oa{sa{sv}}} 1 "/org/pipewire/Telephony/ag1" 2 "org.pipewire.Telephony.AudioGateway1" 1 "Address" s "XX:XX:XX:XX:XX:XX" "org.pipewire.Telephony.AudioGatewayTransport1" 3 "Codec" y 0 "State" s "idle" "RejectSCO" b false
```

5. And based on this output, you can now explore the object that represents the connected phone:

```bash
> busctl --user introspect org.pipewire.Telephony /org/pipewire/Telephony/ag1
NAME                                          TYPE      SIGNATURE  RESULT/VALUE        FLAGS
org.freedesktop.DBus.Introspectable           interface -          -                   -
.Introspect                                   method    -          s                   -
org.freedesktop.DBus.ObjectManager            interface -          -                   -
.GetManagedObjects                            method    -          a{oa{sa{sv}}}       -
.InterfacesAdded                              signal    oa{sa{sv}} -                   -
.InterfacesRemoved                            signal    oas        -                   -
org.freedesktop.DBus.Properties               interface -          -                   -
.Get                                          method    ss         v                   -
.GetAll                                       method    s          a{sv}               -
.Set                                          method    ssv        -                   -
.PropertiesChanged                            signal    sa{sv}as   -                   -
org.ofono.VoiceCallManager                    interface -          -                   -
.CreateMultiparty                             method    -          -                   -
.Dial                                         method    s          -                   -
.GetCalls                                     method    -          a{oa{sv}}           -
.HangupAll                                    method    -          -                   -
.HoldAndAnswer                                method    -          -                   -
.ReleaseAndAnswer                             method    -          -                   -
.ReleaseAndSwap                               method    -          -                   -
.SendTones                                    method    s          -                   -
.SwapCalls                                    method    -          -                   -
.CallAdded                                    signal    oa{sv}     -                   -
.CallRemoved                                  signal    o          -                   -
org.pipewire.Telephony.AudioGateway1          interface -          -                   -
.CreateMultiparty                             method    -          -                   -
.Dial                                         method    s          -                   -
.HangupAll                                    method    -          -                   -
.HoldAndAnswer                                method    -          -                   -
.ReleaseAndAnswer                             method    -          -                   -
.ReleaseAndSwap                               method    -          -                   -
.SendTones                                    method    s          -                   -
.SwapCalls                                    method    -          -                   -
.Address                                      property  s          "XX:XX:XX:XX:XX:XX" const
org.pipewire.Telephony.AudioGatewayTransport1 interface -          -                   -
.Activate                                     method    -          -                   -
.Codec                                        property  y          0                   emits-change
```

6. Now you can start making phone calls (replace `+30XXXXXXXXXX` with an actual phone number):    
```bash
❯ busctl --user call org.pipewire.Telephony /org/pipewire/Telephony/ag1 org.pipewire.Telephony.AudioGateway1 Dial s +30XXXXXXXXXX
o "/org/pipewire/Telephony/ag1/call1"
```

7. Notice that the above command returns a “call” object. When a phone call is in progress, a “call” object is always available to represent it. Let’s explore it:    
```bash
❯ busctl --user introspect org.pipewire.Telephony /org/pipewire/Telephony/ag1/call1
NAME                                TYPE      SIGNATURE RESULT/VALUE    FLAGS
org.freedesktop.DBus.Introspectable interface -         -               -
.Introspect                         method    -         s               -
org.freedesktop.DBus.Properties     interface -         -               -
.Get                                method    ss        v               -
.GetAll                             method    s         a{sv}           -
.Set                                method    ssv       -               -
.PropertiesChanged                  signal    sa{sv}as  -               -
org.ofono.VoiceCall                 interface -         -               -
.Answer                             method    -         -               -
.GetProperties                      method    -         a{sv}           -
.Hangup                             method    -         -               -
.PropertyChanged                    signal    sv        -               -
org.pipewire.Telephony.Call1        interface -         -               -
.Answer                             method    -         -               -
.Hangup                             method    -         -               -
.IncomingLine                       property  s         ""              emits-change
.LineIdentification                 property  s         "+30XXXXXXXXXX" emits-change
.Multiparty                         property  b         false           emits-change
.Name                               property  s         ""              emits-change
.State                              property  s         "alerting"      emits-change
```

8. Finally, you may hang up the call like this:
```bash
❯ busctl --user call org.pipewire.Telephony /org/pipewire/Telephony/ag1/call1 org.pipewire.Telephony.Call1 Hangup
```

# Access Contact

## Contact Search


Get the permissions to access the phonebook from your PC.

1. Start the `obexctl` utility as root: `$ sudo obexctl`.
2. Connect to your phone's PBAP service: `[obex]# connect <phone_mac_address> pbap`.  
3. Navigate to the phonebook: `[<phone_mac_address>]# cd pb`.  
4. List the contacts with `ls`: `[<phone_mac_address>]/pb# ls`.  

|Directory Name|Description|Related Profile|
|---|---|---|
|`pb`|Main phone book|PBAP|
|`ich`|Incoming call history|PBAP|
|`och`|Outgoing call history|PBAP|
|`mch`|Missed call history|PBAP|
|`cch`|Combined call history|PBAP|
|`spd`|Speed dial contacts|PBAP|
|`fav`|Favorite contacts|PBAP|
