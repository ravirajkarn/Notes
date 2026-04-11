---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-27 19:23::30 PM
tags:
  - Linux
  - command
  - terminal
---
# tmux
`tmux` — terminal multiplexer

## Commands 
`tmux` :  Start new tmux session 
`tmux new -s <name>` : To create a new tmux session called \<name\>
`tmux a` : Attach to resent tmux session running in the background.
`tmux attach`: Attach to resent tmux session running in the background.
`tmux a -t <session index>` : Attach to the session index or session name.
`tmux ls` : list all the session
`tmux kill-session` : kill the resent session.
`tmux kill-session -t <name/session index>` : kill to terminate the given session.
`tmux kill-server` : This will kill all the sessions running.


## Keybinding
### Attach and detach 
**Ctrl+B d** : Detach from tmux session, leaving it running in the background 
**Ctrl+B &** : Exit and quit tmux 
**Ctrl+B ?** : List all key bindings (press Q to exit help screen) 
### Window management 
**Ctrl+B C** : Create new window 
**Ctrl+B N** : Move to next window 
**Ctrl+B P** : Move to previous window
**Ctrl+B L** : Move to last window 
**Ctrl+B 0-9** : Move to window by index number
**Ctrl+B W** : To navigate between the windows.
**Ctrl+B &** : kill the window.
### Split window into panes 
**Ctrl+B %** : Vertical split (panes side by side) 
**Ctrl+B "** : Horizontal split (one pane below the other) 
**Ctrl+B O** : Move to other pane 
**Ctrl+B !** : Remove all panes but the current one from the window 
**Ctrl+B Q** : Display window index numbers 
**Ctrl+B Ctrl-Up/Down** : Resize current pane (due north/south) 
**Ctrl+B Ctrl-Left/Right** : Resize current pane (due west/east)
**Ctrl+B X** : kill the pane
**Ctrl+B $ :** change session name.
### Multiplex 
**Ctrl+B :** : Access tmux command prompt 
**Ctrl+B :setw synchronize-panes on** : Synchronize panes (to send a command to many hosts)

### Configurations
_**Note:**_ All the configuration file are store in `#HOME/.tmux,conf`

`set -g mouse` this will enable all the mouse activity.
```.tmux.conf
# To enable nouse activity inside tmux
set -g mouse on

# To enable vi keybinding in tmux to nevigate around.
setw -g mode-keys vi

# To copy the selected text to the clipboard.
bind-key -T copy-mode-vi y send-keys -X copy-pipe-and-cancel "xclip -i -se c"
unbind -T copy-mode-vi Enter
bind-key -T copy-mode-vi Enter send-keys -X copy-pipe-and-cancel "xclip -i -se c"
```

----
## Customisation
### tmux in every session
To set tmux to start in starting of every session or every time you open the terminal.

In `.zshrc` or `.bashrc`
```bash
    if command -v tmux &> /dev/null && [ -z "$TMUX" ]; then
        tmux attach -t default || tmux new -s default
    fi
```
