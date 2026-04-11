---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-08-04T08:25:00
tags:
  - Cpp
  - class
---
We should avoid the use of friend in class.

eg.:

```Cpp
#ifndef HEADER_HPP_
#define HEADER_HPP_

class Geeks {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    Geeks() {
        private_variable = 10;
        protected_variable = 99;
    }

    // friend class declaration
    friend class GFG;
    friend class header;
};

#endif // HEADER_HPP_                                                                                                                     
```

```Cpp
#include <iostream>
#include "header.hpp"

using namespace std;

// class GFG is declared as a friend
// inside class Geeks, therefore
// Class GFG can access private members
// of class Geeks.
class GFG {
public:
    void display(Geeks& t) {
        cout << "The value of Private Variable = "
             << t.private_variable << endl;
        cout << "The value of Protected Variable = "
             << t.protected_variable << endl;
    }
};

int main() {
    Geeks g;
    GFG fri;
    fri.display(g);
    return 0;
}
```