---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-03-28 19:01::38 PM
tags:
  - Linux
  - command
---

# Kitty
It is a terminal which use GPU.

---
## Fonts 
**Method 1:** Identify Available Fonts
- **Command**: Run `kitty +list-fonts` in your terminal.
- **Action**: Note the exact name of the font family you wish to use (e.g., "JetBrains Mono" or "Fira Code").
**Method 2:** Use the Interactive Font Chooser (Easiest)
- **Command**: Run `kitten choose-fonts`.
- **Usage**: Follow the on-screen prompts to filter font families, preview them, and select specific variants (bold, italic, etc.). This automatically updates your configuration.
**Method 3:** Manually Edit the Configuration
- **Open the file**: If it doesn't exist, create it: `nano ~/.config/kitty/kitty.conf`.
-  **Add/Update the font lines**:
```conf
font_family      JetBrains Mono
bold_font        auto
italic_font      auto
bold_italic_font auto
font_size        12.0
```
- Using `auto` for bold/italic variants allows kitty to automatically find the appropriate matches for your main font family.
- **Save and Reload**: Save the file. You may need to restart kitty or press `Ctrl+Shift+F5` to reload the configuration.
- To open the configuration `Ctrl+Shift+F2`. It will open the current configuration file. if there's none then it open a new configuration file. 