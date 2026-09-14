---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-08 06:27::11 AM
tags:
  - testing
---
# Smoke Testing
**The "Did it catch on fire?" test.**

The term originates from hardware testing: when you plug a new device in for the first time, does smoke come out? If it does, you unplug it immediately—there's no point in testing the volume buttons.

- **Purpose:** To verify that the most critical, foundational functions of a new software build are working correctly before committing to more exhaustive testing. It answers the question: _Is this build stable enough to test?_
- **Scope (Broad but Shallow):** It touches the entire application from end to end, but only the most vital "happy paths." (e.g., Can the application launch? Can a user log in? Can a user navigate to the main dashboard?)
- **Execution:** Highly scripted and usually automated. It is run every time a new build is deployed to a QA or staging environment.
- **Outcome:** If it fails, the build is immediately rejected and sent back to the developers.

Other YouTube points.
- Smoke Testing is performed to ensure the software application build is stable or not.
- The word smoke test comes from electronic hardware testing.
- Smoke testing is also known as "Build Verification Testing" or "Confidence Testing".
- Smoke testing is performed by either developers or testers.
- Smoke testing we only focus on the positive flow of the application and enter only valid data but not the invalid data.
- Smoke Testing can find blockers defects at early stage.
- Smoke Testing doesn't required new test cases instead they can be picked up form existing test case.
- **Smoke Testing detect basic key functionality of the software application.**
- Also Know as Build Verification Testing