---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-04-09 17:01::45 PM
tags:
  - Git
  - command
---
# Lost Commit hash
## Find the lost commit hash
`git reflog`:  list all the lost commit hash.

## Undo The reset
### Move the branch back
`git reset --hard <commit-hash>` : This Puts your branch exactly where it was before. 

### Create a new "recovery" branch 
`git branch revovery-branch <commit-hash>` : Put the commit to recovery-branch. 