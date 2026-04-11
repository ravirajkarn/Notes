---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-03-28 16:31::24 PM
tags:
  - Linux
---
# Fonts
To install font in system .

- **For current user only:** `~/.local/share/fonts`
- **System-wide (for all users):** `/usr/local/share/fonts`

copy the content to the folder in above folder.

- **refresh the font cache** 
```bash
fc-cache -fv
```

- **To verify**
```bash
fc-list | grep -Ei "font_name"
```

| /usr/share/fonts/               | /usr/local/share/fonts/                |
| ------------------------------- | -------------------------------------- |
| for are kept by package manager | fonts are kept by every user manually. |
| System repository               | System Repository                      |
