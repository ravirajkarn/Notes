---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-16T18:09:00
tags:
  - Linux
  - command
  - feature
  - script
  - python
---
In XFCE switching windows like in  windows i.e. windows + \[Number\] to switch to desire windows. there is no in build feature like these in XFCE. 

# [Solution](https://askubuntu.com/questions/557084/any-way-to-open-windows-from-the-windows-bar-using-a-shortcut)

## Requirement
1. [wmctrl](wmctrl.md)
2. xprop

## Process

### Step 1:
```Bash
sudo apt-get install wmctrl
```
### Step 2:
Create a file name "panel_navigate" inside  ~/bin. panel_navigate has no extension.

```Bash
mkdir -p ~/bin && touch $_/panel_navigate
```

### Step 3:
open panel_navigate and past the python script.

```python
#!/usr/bin/env python3

import subprocess
import sys

def get_value(command):
    return subprocess.check_output(["/bin/bash", "-c", command]).decode("utf-8").strip()

def run_command(command):
    subprocess.Popen(["/bin/bash", "-c", command])

current_workspace = [l for l in get_value("wmctrl -d").splitlines() if l.split(" ")[2] == "*"][0][0]
wlist_ids = [item.split()[0:4] for item in get_value("wmctrl -l").splitlines()]
+-relevant = [item for item in wlist_ids if item[1] == current_workspace]
panel = []
for item in relevant:
    data = get_value("xprop -id "+item[0])
    if ("_TYPE_NORMAL" in data, "TYPE_DIALOG" in data).count(True) == 1:
        panel.append(item)
try:
    window = panel[int(sys.argv[1])-1][0]
    run_command("wmctrl -ia "+window)
except IndexError:
    pass
```

### Step 4:
Change panel settings:
- Go to Settings Manager > "Panel" > "Items" (tab) > "Window Buttons" >  
	- "Sorting order" > Choose: _Timestamp_
	- - "Window Grouping" > Choose: "Never"
- Add Keyboard shortcuts:
	- go to Settings Manager > "Keyboard" > "Application Shortcuts", choose "Add". Add the command:
```bash
panel_navigate 1
```
set it to the key combination `Ctrl+1`
Now you can choose:  
- to repeat this procedure to add `panel_navigate 2` under Ctrl+2 and so on (until 9)

(save option) _or_ (if you are not afraid to edit config files manually):
- you can edit the file:
    
```bash
~/.config/xfce4/xfconf/xfce-perchanel-xml/xfce4-keyboard-shortcuts.xml
```
in which the keyboard shortcuts (in `xfce`) are stored. Open the file with `mousepad` and look for a line like:
```bash
<property name="&lt;Primary&gt;1" type="string" value="panel_navigate 1"/>   
```

Copy the line, paste it on the next line (insert) and change both occurrences of 1 into 2, so you'll get:
```bash    
<property name="&lt;Primary&gt;1" type="string" value="panel_navigate 1"/>
<property name="&lt;Primary&gt;2" type="string" value="panel_navigate 2"/>
```
and so on..

## **Script Analysis:**

This Python script is designed to switch to a specific window on the current workspace using `wmctrl` and `xprop`. Here's a breakdown of its functionality:

1. **`get_value(command)` function:**
    
    - Executes a given shell `command` using `/bin/bash -c`.
    - Captures the standard output, decodes it as UTF-8, and removes leading/trailing whitespace.        
    - This is used to get information from `wmctrl` and `xprop`.

2. **`run_command(command)` function:**
    
    - Executes a given shell `command` using `/bin/bash -c`.        
    - Uses `subprocess.Popen` to run the command in a non-blocking way (it doesn't wait for the command to finish).

3. **Get Current Workspace:**
    
    - `get_value("wmctrl -d")` gets a list of all desktops.
    - It then filters this list to find the line where the third element is `*`, which indicates the current workspace.
    - `current_workspace` stores the numerical ID of the current workspace.

4. **Get Window List IDs:**
    
    - `get_value("wmctrl -l")` gets a list of all open windows.
    - `wlist_ids` stores a list of lists, where each inner list contains the window ID, desktop ID, and other information for each window.

5. **Filter Relevant Windows:**
	
    - `relevant` filters `wlist_ids` to include only windows that are on the `current_workspace`.

6. **Identify "Normal" or "Dialog" Windows:**
    - It iterates through the `relevant` windows.
    - For each window, it uses `xprop -id <window_id>` to get its properties.
    - It checks if the window's type is either `_NET_WM_WINDOW_TYPE_NORMAL` or `_NET_WM_WINDOW_TYPE_DIALOG`.    
    - If exactly one of these is true (i.e., it's a normal window or a dialog, but not both or neither), the window is added to the `panel` list. This likely aims to exclude utility windows like panels, desktops, or docks.

7. **Switch to the Desired Window:**
    - `try...except IndexError` block handles cases where an invalid argument is provided.
    - `sys.argv[1]` is expected to be a number representing the 1-based index of the window in the `panel` list that the user wants to switch to.
    - `panel[int(sys.argv[1])-1][0]` retrieves the window ID of the selected window.
    - `run_command("wmctrl -ia "+window)` activates (brings to the foreground and focuses) the selected window.