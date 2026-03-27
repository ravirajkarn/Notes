---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2023-12-27T12:59:00
tags:
  - Git
  - command
---
Save a file with extension (no file name eg:- "abc.gitignore"❌  ".gitignore ✔) ".gitignore" 

The rules for the patterns you can put in the .gitignore file are as follows:  
- Blank lines or lines starting with # are ignored.  
- \*[abc]   :- meaning (.a , .b & .c will ignored) 
- \*~ 
- \# ignore all .a files  
			\*.a 
- \# but do track lib.a, even though you're ignoring .a files above  
				! lib.a 

| \# only ignore | the TODO file in the current directory, not subdir/TODO |
| -------------- | ------------------------------------------------------- |
- \# ignore all files in any directory named build  
				build/ 
- \# ignore doc/notes.txt, but not doc/server/arch.txt  
				doc/\*.txt  
- \# ignore all .pdf files in the doc/ directory and any of its subdirectories  
				doc/\*\*/\*.pdf 
We can see more example in [github/gitignore: A collection of useful .gitignore templates](https://github.com/github/gitignore)