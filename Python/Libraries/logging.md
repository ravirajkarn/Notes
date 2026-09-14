---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-08 08:24::04 AM
tags:
  - python
  - log
---
# logging

This module defines functions and classes which implement a flexible event logging system for applications and libraries.

```python
import logging
import mylib
logger = logging.getLogger(__name__)

def main():
    logging.basicConfig(filename='myapp.log', level=logging.INFO)
    logger.info('Started')
    mylib.do_something()
    logger.info('Finished')

if __name__ == '__main__':
    main()
```