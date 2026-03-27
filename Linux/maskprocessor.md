---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-10-29 14:42::20 PM
tags:
  - hacking
  - Linux
  - wifi
  - wireless
  - bluetooth
  - Hash
  - wordlist
  - command
---
# maskprocessor
## Description

Maskprocessor is a high-performance word generator with a per-position configurable charset packed into a single stand-alone binary.

Ever thought that, I know some character of the password rest I don't know. This type of thing can help us to reduse time taken for cracking the password.
## command
```bash
mp64 --help
```

```bash
High-Performance word generator with a per-position configureable charset

Usage: mp64 [options]... mask

* Startup:

  -V,  --version             Print version
  -h,  --help                Print help

* Increment:

  -i,  --increment=NUM:NUM   Enable increment mode. 1st NUM=start, 2nd NUM=stop
                             Example: -i 4:8 searches lengths 4-8 (inclusive)

* Misc:

       --combinations        Calculate number of combinations
       --hex-charset         Assume charset is given in hex
  -q,  --seq-max=NUM         Maximum number of multiple sequential characters
  -r,  --occurrence-max=NUM  Maximum number of occurrence of a character

* Resources:

  -s,  --start-at=WORD       Start at specific position
  -l,  --stop-at=WORD        Stop at specific position

* Files:

  -o,  --output-file=FILE    Output-file

* Custom charsets:

  -1,  --custom-charset1=CS  User-defineable charsets
  -2,  --custom-charset2=CS  Example:
  -3,  --custom-charset3=CS  --custom-charset1=?dabcdef
  -4,  --custom-charset4=CS  sets charset ?1 to 0123456789abcdef

* Built-in charsets:

  ?l = abcdefghijklmnopqrstuvwxyz
  ?u = ABCDEFGHIJKLMNOPQRSTUVWXYZ
  ?d = 0123456789
  ?s =  !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
  ?a = ?l?u?d?s
  ?b = 0x00 - 0xff
```

```bash
mp64 -o password.txt pass?d
```