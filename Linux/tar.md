---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-01-21T17:09:00
tags:
  - Linux
  - command
---
Type man tar for more information, but this command should do the trick: 

`tar -xvzf community_images.tar.gz`

To explain a little further, tar collected all the files into one package, community_images.tar. The gzip program applied compression, hence the gz extension. So the command does a couple things: 

   `f`: this must be the last flag of the command, and the tar file must be immediately after. It tells tar the name and path of the compressed file. 
   `z`: tells tar to decompress the archive using gzip 
   `x`: tar can collect files or extract them. x does the latter. 
   `v`: makes tar talk a lot. Verbose output shows you all the files being extracted. 

To extract into a custom folder, add the -C option with a folder name of your choice: 

`tar -xvzf community_images.tar.gz -C some_custom_folder_name`