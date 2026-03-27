---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-03-27 10:42::11 AM
tags:
  - Git
---

# The Permanent Fix (So you don't have to keep pasting)

For Linux (looks like you're on a terminal):
Run this command to use the local credential helper:
```bash
git config --global credential.helper store
```
Note: This stores the token in plain text in a file. For a more secure "manager" on Linux, you might look into libsecret.