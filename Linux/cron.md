---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-02T18:49:00
tags:
  - Linux
  - command
---
The task schedular for Linux. Cron is a daemon used to execute scheduled commands automatically. 

The commands for a cron job are stored in the crontab file on a Linux system, which is usually found in /etc/crontab. Display the contents of your crontab file with `crontab -l`. 

Edit the crontab file with `crontab -e`. 

Some systems default to the [Vi editor](https://opensource.com/article/20/12/vi-text-editor) for cron editing. You can override this setting using [environment variables](https://opensource.com/article/19/8/what-are-environment-variables): 
```Bash
EDITOR=nano crontab -e
```
This allows you to use the [nano editor](https://opensource.com/article/20/12/gnu-nano) to edit your personal crontab (if you don't have one yet, one is created automatically for you). 

All crontab commands have parameters denoted by an asterisk until you insert an integer value. The first represents minutes, then hours, day of the month, month of the year, and finally, day of the week. 

Comments are preceded by a hash. Cron ignores comments, so they're a great way to leave yourself notes about what a command does and why it's important. 

## A sample cron job 

Suppose you want to scan your home directory for viruses and malware with [clamscan](https://opensource.com/business/15/9/keeping-your-linux-system-safe) every week on Monday at 10AM. You also want to back up your home directory every week on Tuesday at 9AM. Using cron and crontab files ensures that your system maintenance occurs every week whether you remember to run those utilities or not. 

Edit your crontab file to include the following, using your own username instead of "don" (my user name): 

```Bash
# Scan my home directory for viruses 0 10 * * 1 clamscan -ir /home/don # Backup my home directory 0 9 * * 2 tar -zcf /var/backups/home.tgz /home/don
```

If you're using the nano editor, save your work with Ctrl+O to write the file out and Ctrl+X to exit the editor. After editing the file, use crontab -l to list the contents of your cron file to ensure that it has been properly saved. 

You can create crontab jobs for any job required on your system. This takes full advantage of the cron daemon. 

## Scheduling from the Linux command line 

It's no secret that the hardest part of cron is coming up with the right values for those leading asterisks. There are websites, like [crontab.guru](https://crontab.guru/), that dynamically translate cron time into human-readable translations, and Opensource.com has a [cron cheat sheet](https://opensource.com/downloads/linux-cron-cheat-sheet) you can download to help you keep it straight. 

Additionally, most modern cron systems feature shortcuts to common values, including: 

- @hourly : Run once an hour (0 * * * *) 
- @daily : Run once a day (0 0 * * *) 
- @weekly : Run once a week (0 0 * * 0) 
- @monthly : Run once a month (0 0 1 * *) 
- @reboot : Run once after reboot

## Capture Output
To capture all output from a cron job, including both standard output (stdout) and standard error (stderr), you need to redirect these streams to a file or another destination.

The most common method involves using shell redirection operators within your crontab entry:

Code

```
* * * * * /path/to/command >> /path/to/logfile.log 2>&1
```

Explanation of the components:

- `* * * * *`: This represents the cron schedule (minute, hour, day of month, month, day of week).
- `/path/to/command`: This is the command or script you want to execute.
- `>> /path/to/logfile.log`: This redirects standard output (stdout) and appends it to the specified log file. If the file doesn't exist, it will be created. Using `>>` ensures that new output is added to the end of the file, rather than overwriting previous content (which `>` would do).
- `2>&1`: This is crucial for capturing stderr. It redirects file descriptor 2 (standard error) to the same location as file descriptor 1 (standard output). Since stdout is already being redirected to `/path/to/logfile.log`, this effectively sends stderr to the same log file.