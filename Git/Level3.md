---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-01-23 13:49::40 PM
tags:
  - Git
---
## taking some commit into other branch
> [!success] copy commit
> `git cherry-pick` :- It will take some commit into it's own branch.
> ![[gitcherry-pickC2C4.jpg]]

---
# Cherry-Pick  a commit from another repository.
- `git remote add other-repo <url-of-repo>` : add other repository from the remote server.
- `git fetch other-repo` : fetch the details from other repository.
- `git cherry-pick <commit-hash>` cherry pick from other repository.
- `git remote remove other repo` : remove the remote