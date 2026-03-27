---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-03-27 10:54::31 AM
tags:
  - Git
  - Git-LFS
---

# git large file system(lfs)
how to use:
**Step 1:**
Do Normal initialisation with git.
**Step 2:**
```bash
git lfs install
```
**Step 3:**
In each Git repository where you want to use Git LFS, select the file types you'd like Git LFS to manage (or directly edit your .gitattributes). You can configure additional file extensions at anytime.
```bash
git lfs track "*.psd"
```
Now make sure .gitattributes is tracked:
```bash
git add .gitattributes
```
