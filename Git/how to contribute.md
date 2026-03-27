---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-03-10 16:44::23 PM
tags:
  - Git
---
# Gemini said
Contributing to a project via Git follows a standard "Fork and Pull Request" workflow. This ensures the main codebase remains stable while allowing anyone to propose changes.

Here is the step-by-step technical process for a proper contribution.

## 1. Set Up Your Environment
Before writing code, you need a personal copy of the repository to work on.
1. **Fork the Repository:** On GitHub (or GitLab/Bitbucket), click the Fork button. This creates a copy of the repository under your own account.
2. **Clone Your Fork:** Download your forked version to your local machine.

``` bash
git clone https://github.com/YOUR_USERNAME/repository-name.git
cd repository-name
```
3. **Configure Upstream:** To keep your fork updated with the original project, add the original repository as a remote named upstream.

```bash
git remote add upstream https://github.com/ORIGINAL_OWNER/repository-name.git
```
## 2. Branching and Development
Never work directly on the main branch. Creating a feature branch keeps your work isolated.

1. **Sync with Upstream:** Ensure your local main is up to date.
``` bash
git checkout main
git pull upstream main
```
2. **Create a Feature Branch:** Use a descriptive name for your branch (e.g., fix-login-bug or add-user-profile).
```bash
git checkout -b feature/your-feature-name
```
## 3. Committing and Pushing
Once you’ve made your changes, you need to save them and move them to the cloud.

1. **Stage and Commit:**

```bash
git add .
git commit -m "Brief description of what you changed"
```

> [!tip] Tip: 
> Follow the project's commit message conventions (e.g., "feat: add search bar").


2. **Push to Your Fork:** Push the branch to your forked repository on GitHub.

```bash
git push origin feature/your-feature-name
```
## 4. Opening a Pull Request (PR)
Now that your code is on GitHub, you need to ask the original maintainers to review it.
	1. Navigate to the original repository on GitHub. You will often see a yellow banner saying **"Compare & pull request"** for your recently pushed branch.
1. **Click "Create pull request".**
2. **Describe Your Changes:** Explain why you made the change and how you tested it.
3. **Submit:** The maintainers will review your code. They might ask for changes, which you can make by committing and pushing to the same branch; the PR will update automatically.

|**Remote Name**|**Points To...**|**Purpose**|
|---|---|---|
|**`origin`**|Your forked repo|Where you push your branches and PRs.|
|**`upstream`**|The original repo|Where you pull the latest official updates.