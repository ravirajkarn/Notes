---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2023-12-27T12:59:00
tags:
  - Git
  - command
---

Command    
-  `git  init`  :  To  create  the  directory  into  git  repository.  
-  `git  add    <file>`  :  To  add  the  "file"  that  you  want  to  track  or  to  stage.  
-  `git  reset  HEAD  <file>`  :  To  unstage  a  staged  file.      
-  `git  commit`  :  To  initiate  the  commit.  
-  `git  clone  <url>`  :  To  crate  a  clone  of  entire  repository  to  your  pc.  
-  `git  clone  <url>  <address/filename>`  :  Same  as  above  difference  is  you  can  give  desire  name  to  file.  
-  `git  status`  :  To  check  the  status  
-  `git  status  -s`  or  `git  status  --short`  :  Short  Status    
                            ??          Untagged  
                            A           new  file  to  stage  
                            M           modified  file  
-  `git  commit`  :  To  commit  changes  
-  `git  commit  -a  -m  "the  massage"`  :  To  skip  staging  
-  `git  rm  <file>`  :  To  stage  the  removal  of  file  
-  `git  mv  <file_frome>  <file_to>`  :  To  rename  a  file  
-  `git  log`  :  To  the  changes  history  
-  `git  log  --pretty=oneline`
  eg:-  
![](git%20log2.png)
![](git%20log%20--pretty=format.png)
-  `git  log  --since=2.weeks`  :  Limited  log  output  
			`--author`  :  search  by  author  
		    `--grep`  :  Search  by  keyword
![](git%20log1.png)
  -  `git  commit  --amend`  :  To  change  the  previous  commit  massage  
Note:-  Only  amend  commits  that  are  still  local  and  have  not  been  pushed  somewhere.  Amending  previously  pushed  commits  and  force  pushing  the  branch  will  cause  problems  for  your  collaborators.  For  more  on  what  happens  when  you  do  this  and  how  to  recover  if  you’re  on  the  receiving  end  read  The  Perils  of  Rebasing  

-  (Pg.-  53)  `git  reset  HEAD  <file>`  :  To  unstaging  a  staged  file  
-  (Pg.-  54)  `git  checkout  <file>`  :  To  replace  the  file  with  previously  staged  or  committed  file
-  (Pg.-  55)  `git  restore  --staged  <file>`  :  It  is  an  alternative  of  `git  reset  HEAD  <file>`
-  (Pg.-  56)  `git  restore  <file>`  :  It  is  an  alternative  of  `git  reset`