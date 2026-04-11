---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-07-27T13:45:00
tags:
  - STL
  - List
  - Time
  - Date
  - C
---
# C Date and time utilities 

## Functions 

| Time manipulation                                                                       |                                                                                                                                        |
| --------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| [difftime](https://en.cppreference.com/w/cpp/chrono/c/difftime)                         | computes the difference between times <br>(function)                                                                                   |
| [time](https://en.cppreference.com/w/cpp/chrono/c/time)                                 | returns the current time of the system as time since epoch <br>(function)                                                              |
| [clock](https://en.cppreference.com/w/cpp/chrono/c/clock)                               | returns raw processor clock time since the program is started <br>(function)                                                           |
| [timespec_get](https://en.cppreference.com/w/cpp/chrono/c/timespec_get) <br><br>(C++17) | returns the calendar time in seconds and nanoseconds based on a given time base <br>(function)                                         |
| **Format conversions**                                                                  |                                                                                                                                        |
| [asctime](https://en.cppreference.com/w/cpp/chrono/c/asctime)                           | converts a [std::tm](https://en.cppreference.com/w/cpp/chrono/c/tm) object to a textual representation <br>(function)                  |
| [ctime](https://en.cppreference.com/w/cpp/chrono/c/ctime)                               | converts a [std::time_t](https://en.cppreference.com/w/cpp/chrono/c/time_t) object to a textual representation <br>(function)          |
| [strftime](https://en.cppreference.com/w/cpp/chrono/c/strftime)                         | converts a [std::tm](https://en.cppreference.com/w/cpp/chrono/c/tm) object to custom textual representation <br>(function)             |
| [wcsftime](https://en.cppreference.com/w/cpp/chrono/c/wcsftime)                         | converts a [std::tm](https://en.cppreference.com/w/cpp/chrono/c/tm) object to custom wide string textual representation <br>(function) |
| [gmtime](https://en.cppreference.com/w/cpp/chrono/c/gmtime)                             | converts time since epoch to calendar time expressed as Universal Coordinated Time <br>(function)                                      |
| [localtime](https://en.cppreference.com/w/cpp/chrono/c/localtime)                       | converts time since epoch to calendar time expressed as local time <br>(function)                                                      |
| [mktime](https://en.cppreference.com/w/cpp/chrono/c/mktime)                             | converts calendar time to time since epoch <br>(function)                                                                              |
## Constants 

| [CLOCKS_PER_SEC](https://en.cppreference.com/w/cpp/chrono/c/CLOCKS_PER_SEC) | number of processor clock ticks per second <br>(macro constant) |
| --------------------------------------------------------------------------- | --------------------------------------------------------------- |

## Types 

| [std::tm](C%20Date%20and%20time%20utilities.md#[std%20tm](https%20//en.cppreference.com/w/cpp/chrono/c/tm)) | calendar time type <br>(class)               |
| ----------------------------------------------------------------------------------------------------------- | -------------------------------------------- |
| [std::time_t](#[std%20time_t](https%20//en.cppreference.com/w/cpp/chrono/c/time_t))                         | time since epoch type <br>(typedef)          |
| [clock_t](https://en.cppreference.com/w/cpp/chrono/c/clock_t)                                               | process running time <br>(typedef)           |
| [timespec](https://en.cppreference.com/w/cpp/chrono/c/timespec) <br>(C++17)                                 | time in seconds and nanoseconds <br>(struct) |
# [std::time_t](https://en.cppreference.com/w/cpp/chrono/c/time_t)
Arithmetic type capable of representing times. 

Although not defined, this is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to [POSIX time](https://en.wikipedia.org/wiki/Unix_time). 

Also provided are the C-style date and time functions, such as [std::time_t](https://en.cppreference.com/w/cpp/chrono/c/time_t), [std::difftime](https://en.cppreference.com/w/cpp/chrono/c/difftime), and [CLOCKS_PER_SEC](https://en.cppreference.com/w/cpp/chrono/c/CLOCKS_PER_SEC)

# [std::tm](https://en.cppreference.com/w/cpp/chrono/c/tm)
Structure holding a calendar date and time broken down into its components. 
Member objects 


| int tm_sec   | seconds after the minute – \[​0​, 61\]\(until C++11\) \[​0​, 60\]\(since C++11)[note 1](https://en.cppreference.com/w/cpp/chrono/c/tm#cite_note-leapsecond-1) <br>(public member object) |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| int tm_min   | minutes after the hour – [​0​, 59] <br>(public member object)                                                                                                                               |
| int tm_hour  | hours since midnight – [​0​, 23] <br>(public member object)                                                                                                                                 |
| int tm_mday  | day of the month – [1, 31] <br>(public member object)                                                                                                                                       |
| int tm_mon   | months since January – [​0​, 11] <br>(public member object)                                                                                                                                 |
| int tm_year  | years since 1900 <br>(public member object)                                                                                                                                                 |
| int tm_wday  | days since Sunday – [​0​, 6] <br>(public member object)                                                                                                                                     |
| int tm_yday  | days since January 1 – [​0​, 365] <br>(public member object)                                                                                                                                |
| int tm_isdst | Daylight Saving Time flag. The value is positive if DST is in effect, zero if not and negative if no information is available. <br>(public member object)                                   |

1. [↑](https://en.cppreference.com/w/cpp/chrono/c/tm#cite_ref-leapsecond_1-0) Range allows for a positive leap second. Two leap seconds in the same minute are not allowed (the range [​0​, 61] was a defect introduced in C89 and corrected in C99). 
### Notes 
BSD, GNU and musl C library support two additional members, which are standardized in [POSIX.1-2024](https://pubs.opengroup.org/onlinepubs/9799919799/basedefs/time.h.html). 

| long tm_gmtoff      | seconds east of UTC <br>(public member object)   |
| ------------------- | ------------------------------------------------ |
| const char* tm_zone | timezone abbreviation <br>(public member object) |

# std::mktime 

It convert the tm into time_t 
Syntax: 
[std::time_t](http://en.cppreference.com/w/cpp/chrono/c/time_t) mktime( [std::tm](http://en.cppreference.com/w/cpp/chrono/c/tm)* time );

# std::localtime() 

It convert std::time_t into std::tm 
Syntax:
[std::tm](http://en.cppreference.com/w/cpp/chrono/c/tm)* localtime( const [std::time_t](http://en.cppreference.com/w/cpp/chrono/c/time_t)* time );