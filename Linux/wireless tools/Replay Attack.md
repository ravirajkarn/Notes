---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-25 20:00::59 PM
tags:
  - hacking
  - Linux
  - wireless
---
### The "Replay Attack" Vulnerability 🕵️‍♂️

The problem is that for a given password in air, the hash is always the same. An attacker might not know your actual password, but they can still "sniff" the airwaves and capture that hash.

Since the attacker has a perfect copy of your password's hash, they can simply **"replay"** it to the access point at a later time. The access point will receive the valid hash, compare it to its own, see that they match, and grant the attacker full access to the network.
