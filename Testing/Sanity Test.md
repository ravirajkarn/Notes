---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-08 06:27::43 AM
tags:
  - testing
---

# Sanity Testing
**The "Did we actually fix what we meant to fix?" test.**

Sanity testing occurs _after_ a software build has passed a smoke test, typically when a minor change, new feature, or bug fix has been introduced.

- **Purpose:** To determine if the specific new changes work as intended and that the immediate surrounding functionality wasn't broken in the process. It answers the question: _Is it rational to proceed with deep testing on this specific component?_
- **Scope (Narrow and Deep):** It does not test the whole application. It focuses only on the component that was recently altered and its direct dependencies. (e.g., If the checkout cart was updated, a sanity test ensures you can still add items, remove items, and calculate the total).
- **Execution:** Often unscripted and manual, relying on the tester's intuition and knowledge of the application.
- **Outcome:** If it fails, the specific feature or bug ticket is rejected, though the rest of the application might still be deemed stable.

YouTube Points: 
- *Narrow and Deep Testing*: Focus on a particular functionality of a function and we go deep and test.
- *Subset of Regression*: Suppose we have 100 set of regression testing we choose some test case from Sanity Testing
- Perform by Tester.
- Unscripted Testing.
- Sanity testing help in quickly identify defects in the core functionality.
- 