---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-01-23 12:14::27 PM
tags:
  - Git
---
## New Branch
> [!success] Branching
> - `git branch newImage` :- creating new branch
> - `git checkout newImage` :- switch to new branch
> - `git switch newImage` :- alternative of `git checkout`. It is _experimental_.
> - `git checkout -b newImage` :- you can combine `git brach` and `git checkout` which will create new branch and check out to it

## Merging

> [!success] Merging
> - `git merge bugFix` :- merge two different branch into one.

> [!success] Rebasing 
> - `git rebase bugFix` :-It look like working in parallel. copies one work to another.
> - `git rebase -i overHere` :- it will launch a window to reorder your commit.
> ![[gitRebse.png]]

