---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-07T18:58:00
tags:
  - Linux
  - command
  - vim
---
# vim
## Introduction
It is a command line text editor tool. According to legends it is very powerful tool for text editing.

Vimtutor : start vim tutorial to learn vim.

## Keybinding
1. `ctrl+c`: for Normal Mode. Same as press `esc` key.

## MOVING THE CURSOR
**To move the cursor, press the h,j,k,l keys as indicated. **
<div>
<span style="margin-left:60px">^</span><br>
<span style="margin-left:60px">k</span><span style="margin-left:110px">Hint:  The h key is at the left and moves left.</span><br>
<span>&lt; h</span><span style="margin-left:70px">l &gt;</span><span style="margin-left:110px">The l key is at the right and moves right.</span><br>
<span style="margin-left:60px">j</span><span style="margin-left:170px">The j key looks like a down arrow.</span><br>
<span style="margin-left:60px">v</span>
</div>

## Keys 
1. `:q!`--> This exits the editor, DISCARDING any changes you have made.
2. `x` --> delete the character under the cursor.
3. `i` --> insert **before** the cursor.
4. `I` --> Insert text at the **beginning**. 
5. `a` --> append **after** the line.
6. `A` --> append at the **end** of the line.
7. `:wq` --> **save** a file and exit.
8. `dw` --> **delete** word from **right**.
9. `dd` --> delete **whole** line this will also **store** the deleted line in the buffer.
10. `rx` --> **replace** the character at the cursor with x.
11. `R` --> replace more than one character.
12. `ce` --> deletes the words and places you in Insert mode.
13. `cc` --> deletes the **whole line** and places you in Insert mode.
14. `p` --> put the clipboard text **after** the cursor.
15. `P` --> put the clipboard text **before** the cursor.
16. `%` --> Type %  to find a **matching ),], or }** .
17. `:!` --> :! followed by an **external command** to execute that command.
18. `:w` --> :w write or save as or save.
19. `:r` --> :r \<file-name>
20. `v` --> motion to select a text.
21. `v` + `:w FILENAME` --> save the visually selected lines in file FILENAME.
22. `o` --> insert line below and place you in Insert Mode.
23. `O` --> insert line above and place you in Insert Mode.
## ON OPERATORS AND MOTIONS

Many commands that change text are made from an operator and a motion.
The format for a delete command with the  d  delete operator is as follows:
	d   motion

Where:
	d      - is the delete operator.
	motion - is what the operator will operate on (listed below).

A short list of motions:
    w - until the start of the next word, EXCLUDING its first character.
    e - to the end of the current word, INCLUDING the last character.
    $ - to the end of the line, INCLUDING the last character.

## USING A COUNT FOR A MOTION

**Typing a number before a motion repeats it that many times.**
  1. Move the cursor to the start of the line below marked --->.
  2. Type  2w  to move the cursor two words forward.
  3. Type  3e  to move the cursor to the end of the third word forward.
  4. Type  0  (zero) to move to the start of the line. 
 
## CURSOR LOCATION AND FILE STATUS 
  1. CTRL-G to show your location in the file and the file status.
  2. Press  G  to move you to the bottom of the file. 
  3. Type  gg  to move you to the start of the file.
  4. Type the number of the line you were on and then G. This will return you to that line.
## THE SEARCH COMMAND
  
  1. In Normal mode type the  /  character.  Notice that it and the cursor appear at the bottom of the screen as with the  :  command.
  2. To search for the same phrase again, simply type  n .
     To search for the same phrase in the opposite direction, type  N .
  3. To search for a phrase in the backward direction, use  ?  instead of  / .
  4. To go back to where you came from press CTRL-O (Keep Ctrl down while pressing the letter o). Repeat to go back further. CTRL-I goes forward.
## THE SUBSTITUTE COMMAND

To substitute new for the first old in a line type    :s/old/new
To substitute new for all 'old's on a line type       :s/old/new/g
To substitute phrases between two line #'s type       :#,#s/old/new/g
To substitute all occurrences in the file type        :%s/old/new/g
To ask for confirmation each time add 'c'             :%s/old/new/gc

## COPY AND PASTE TEXT

**Use the  y  operator to copy text and  p  to paste it**

:NOTE : You can also use  y  as an operator:  yw  yanks one word, yy  yanks the whole line, then  p  puts that line.

## SET OPTION
  
**Set an option so a search or substitute ignores case**
  1. Set the 'ic' (Ignore case) option by entering:   :set ic
  2. Now search for 'ignore' again by pressing  n
     Notice that Ignore and IGNORE are now also found.
  3. Set the 'hlsearch' and 'incsearch' options:  :set hls is
  4. To disable ignoring case enter:  :set noic

NOTE:  To remove the highlighting of matches enter:   :nohlsearch
NOTE:  If you want to ignore case for just one search command, use  \c
       in the phrase:  /ignore\c \<ENTER>

Typing ":set xxx" sets the option "xxx".  Some options are:
        'ic' 'ignorecase'       ignore upper/lower case when searching
        'is' 'incsearch'        show partial matches for a search phrase
        'hls' 'hlsearch'        highlight all matching phrases
You can either use the long or the short option name.
  5. Prepend "no" to switch an option off:   :set noic











