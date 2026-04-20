---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-19 01:47::51 AM 
tags:
---
# xclip
xclip is a command line utility that is designed to run on any system with an X11 implementation. It provides an interface to X selections (“the clipboard”) from the command line. It can read data from standard in or a file and place it in an X selection for pasting into other X applications. xclip can also print an X selection to standard out, which can then be redirected to a file or another program.

```zsh
root@kali:~ xclip -h 
Usage: xclip [OPTION] [FILE]... 
Access an X server selection for reading or writing. 

	-i, -in read text into X selection from standard input or files (default) 
	-o, -out prints the selection to standard out (generally for piping to a file or program) 
	-l, -loops number of selection requests to wait for before exiting 
	-d, -display X display to connect to (eg localhost:0") 
	-h, -help usage information 
		-selection selection to access ("primary", "secondary", "clipboard" or "buffer-cut") 
		-noutf8 don't treat text as utf-8, use old unicode 
		-target use the given target atom 
		-rmlastnl remove the last newline character if present 
		-version version information 
		-silent errors only, run in background (default) 
		-quiet run in foreground, show what's happening 
		-verbose running commentary 

Report bugs to <astrand@lysator.liu.se>
```