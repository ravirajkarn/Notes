---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-02-13 11:30::05 AM
tags:
  - Git
---

# Clone only one folder
1. **Clone the repository** without checking out files immediately:
```bash
git clone --filter=blob:none --no-checkout <repository-url>
cd <repository-directory>
```
	1. `--filter=blob:none`: Skips downloading the contents of all files until they are specifically requested.
	2. `--no-checkout`: Prevents Git from checking out the full file tree.

2. **Initialize Sparse Checkout** in "cone" mode:    ```
```bash
git sparse-checkout init --cone
```
	1. `--cone`: Optimizes for specific directory structures.
3. **Specify the folder** you want to keep:
```bash
git sparse-checkout set <path/to/your/folder>
```
	1. Replace `<path/to/your/folder>` with the actual path inside the repository (e.g., `src/assets`).
4. **Checkout the content**:
```bash
git checkout <branch-name>
```
	1. Replace `<branch-name>` with the branch you need, usually `main` or `master`



# If you want to rest it
now you want to fetch all the file.
```bash
git sparse-checkout disable
```

if the files do not appear immediately or if you have unsaved changes that are blocking the checkout, you may need to force a reset.
```bash
git reset --herd HEAD
```