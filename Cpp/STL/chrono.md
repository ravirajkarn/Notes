---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2024-08-05T12:46:00
tags:
  - Chrono
  - Time
  - Date
  - STL
  - Header
---
# [#include \<chrono>](https://en.cppreference.com/w/cpp/header/chrono) (since C++11)  
## Introduction
### Core Concepts 
- **Duration:** Represent time spans (e.g., 2 seconds, 50 milliseconds). 
- **Time Points:** Represent specific points in time relative to an epoch. 
- **Clocks:** Provide ways to obtain current time points. 
### Key Features 
#### Precision: 
- Offers various duration units (nanoseconds, microseconds, milliseconds, seconds, minutes, hours, etc.) to choose the appropriate level of precision for your application.  
- Allows for custom duration units through template specialization. 
#### Flexibility:
- Supports different clock types (system_clock, steady_clock, high_resolution_clock) for various use cases. 
- Provides arithmetic operations on durations and time points (addition, subtraction, comparison). 
- Enables casting between different duration units. 
#### Clarity:
- Enhances code readability with clear and expressive syntax. 
- Avoids ambiguous time representations.
### Core Components 
- #### Duration: 
    - Represents a time span. 
    - Can be created with various units (e.g., std::chrono::seconds(5)). 
    - Supports arithmetic operations and comparisons. 
    - Can be cast to other duration units. 
- #### Time Point: 
    - Represents a specific point in time relative to an epoch. 
    - Obtained from clocks. 
    - Supports arithmetic operations with duration. 
    - Can be compared to other time points. 
- #### Clocks: 
    - Provide access to the system's time. 
    - ##### Three main types:  
        - **system_clock:** Represents system-wide real-time clock (affected by system time adjustments). 
        - **steady_clock:** Monotonically increasing clock, not affected by system time changes. 
        - **high_resolution_clock:** Clock with the shortest tick period available on the system. 
### Additional Features 
- **Calendar support:** While not as extensive as dedicated date/time libraries, chrono provides some basic calendar-related functionalities. 
- **Time zone handling:** Though not directly supported, chrono can be combined with external libraries for time zone conversions. 
- **I/O operations:** Can be used with iostream for formatting and outputting time-related data.


```Cpp
#include <fmt/core.h> 
#include <chrono> 
#include <thread> 
#include <fmt/chrono.h> 
#define HEAD fmt::print("\n{:->25}\n\n", 0 ); 

void fun1(void){ 
    HEAD; 
    std::chrono::milliseconds mil(1000); //~ New thing to learn. 
    mil = mil*60; 
    fmt::print("Duration (in periods): {} milliseconds.\n", mil.count()); 
    fmt::print("Duration (in seconds): {} seconds.\n", (mil.count()*std::chrono::milliseconds::period::num / std::chrono::milliseconds::period::den)); 
} 

void fun2(void){ //~ New thing to learn. 
    HEAD; 
    //* Learn how to use high_resolution_clock 
    auto now = std::chrono::high_resolution_clock::now(); 

    // Some time-consuming operation 
    for (int i = 0; i < 1000000; ++i) { 
        // Do something 
    } 

    auto end = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - now ); 
    fmt::print("Elapsed time: {} miliseconds.\n", duration.count()); 
} 

void fun3(void){ 
    HEAD; 
    //* Learn How to break/wait for some time and continue further withww sleep_for. 

    fmt::print("wait for 2 second.\n"); 
    std::this_thread::sleep_for(std::chrono::seconds(2)); //~ New thing to learn. 
    fmt::print("done waiting!\n"); 
} 

void fun4(void){ 
    HEAD; 
    //* Learn How to use system_clock. 
    auto now = std::chrono::system_clock::now(); 
    std::time_t now_time = std::chrono::system_clock::to_time_t(now); 
    fmt::print("Current time: {:%Y-%m-%d %H:%M:%S}\n", fmt::localtime(now_time)); //~ New thing to learn. 
    // std::cout << "Current time: " << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << '\n'; //~ std::put_time is define in #include<iomanip> 
} 

void fun5(void){ 
    HEAD; 
    //* Learn How to use steady_clock
std::chrono::steady_clock::time_point clock_begin = std::chrono::steady_clock::now(); 
    fmt::print("\nprint out 1000 stars ....\n"); 
    for (int i = 0; i < 1001; i++) 
    fmt::print("*"); 
    std::chrono::steady_clock::time_point clock_end = std::chrono::steady_clock::now(); 
    std::chrono::steady_clock::duration time_span = clock_end - clock_begin; 
     double nanosecond = double(time_span.count())*std::chrono::steady_clock::period::num/std::chrono::steady_clock::period::den; 
    fmt::print("It took {} seconds.", nanosecond);  
} 

/** 
 *  
 * The differences between std::chrono::steady_clock and std::chrono::system_clock in C++: 
 *  
 * ### Steady Clock (std::chrono::steady_clock): 
 *  
 * # Provides a monotonic clock that is not affected by system time adjustments (e.g., changes due to daylight saving time or clock synchronization). 
 * # Guarantees that time intervals measured using this clock are always non-negative and consistent. 
 * # Useful for measuring elapsed time, benchmarking, and performance profiling. 
 * # May not reflect the actual wall-clock time (i.e., it doesn’t match the time displayed on your clock). 
 *  
 * ### System Clock (std::chrono::system_clock): 
 *  
 * # Represents the system-wide real-time wall clock. 
 * # Affected by system time adjustments (e.g., time zone changes, leap seconds). 
 * # Provides the current time as perceived by the user or system. 
 * # Used for displaying the current date and time, scheduling tasks, and working with calendar-based time. 
 *  
 */ 

void fun6(void){ 
    HEAD; 
    //* Converting from steady_clock to system_clock: 
    auto steady_now = std::chrono::steady_clock::now(); 
    auto system_now = std::chrono::time_point_cast<std::chrono::system_clock::duration>(steady_now); 
    // Now 'system_now' represents the equivalent point in time in system_clock 
    // You can use it for displaying or scheduling tasks based on system time 
    fmt::print("steady clock value {0} is converted into system clock value {1}.\n", std::chrono::duration_cast<std::chrono::milliseconds>(steady_now.time_since_epoch()).count(), std::chrono::duration_cast<std::chrono::milliseconds>(system_now.time_since_epoch()).count()); 
    //* Converting from system_clock to steady_clock:
    auto system_now2 = std::chrono::system_clock::now();
  auto steady_now2 = std::chrono::time_point_cast<std::chrono::steady_clock::duration>(system_now2);
	fmt::print("system clock value {0} is converted into steady clock value {1}.\n", std::chrono::duration_cast<std::chrono::milliseconds>(system_now2.time_since_epoch()).count(), std::chrono::duration_cast<std::chrono::milliseconds>(steady_now2.time_since_epoch()).count());  
} 
/* 
* Using the chrono Library for Date of Birth 
* Unfortunately, the chrono library in C++ is primarily designed for time measurements and durations, 
* not for representing calendar dates. It's better suited for calculating time differences, measuring  
* performance, and handling time-related computations. 
* 
* Some popular options include: 
*  # Boost.Date_Time: Offers a comprehensive set of tools for date and time manipulation. //~(I will use this.) 
*  # Howard Hinnant's date library: Provides a modern and efficient date/time library. 
*/ 

int main(){ 
    fun1(); 
    fun2(); 
    fun3(); 
    fun4(); 
    fun5(); 
    fun6(); 
    return 0; 
}
```

![](Date.cpp)

## Date and time library 
The chrono library defines several main types as well as utility functions and common typedefs: 
- [clocks](https://en.cppreference.com/w/cpp/chrono#Clocks) 
- [time points](https://en.cppreference.com/w/cpp/chrono#Time_point) 
- [durations](https://en.cppreference.com/w/cpp/chrono#Duration) 

| - [calendar](https://en.cppreference.com/w/cpp/chrono#Calendar) dates <br>- [time zone](https://en.cppreference.com/w/cpp/chrono#Time_zone) information | (since C++20) |
| ------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------- |

### Clocks 
A clock consists of a starting point (or epoch) and a tick rate. For example, a clock may have an epoch of January 1, 1970 and tick every second. C++ defines several clock types: 

| Defined in header [\<chrono>](https://en.cppreference.com/w/cpp/header/chrono)                      |                                                                                                                                                            |
| --------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Defined in namespace std::chrono                                                                    |                                                                                                                                                            |
| [system_clock](https://en.cppreference.com/w/cpp/chrono/system_clock) <br>(C++11)                   | wall clock time from the system-wide realtime clock <br>(class)                                                                                            |
| [steady_clock](https://en.cppreference.com/w/cpp/chrono/steady_clock) <br>(C++11)                   | monotonic clock that will never be adjusted <br>(class)                                                                                                    |
| [high_resolution_clock](https://en.cppreference.com/w/cpp/chrono/high_resolution_clock) <br>(C++11) | the clock with the shortest tick period available <br>(class)                                                                                              |
| [is_clockis_clock_v](https://en.cppreference.com/w/cpp/chrono/is_clock) <br>(C++20)                 | determines if a type is a [Clock](https://en.cppreference.com/w/cpp/named_req/Clock) <br>(class template) (variable template)                              |
| [utc_clock](https://en.cppreference.com/w/cpp/chrono/utc_clock) <br>(C++20)                         | [Clock](https://en.cppreference.com/w/cpp/named_req/Clock) for Coordinated Universal Time (UTC) <br>(class)                                                |
| [tai_clock](https://en.cppreference.com/w/cpp/chrono/tai_clock) <br>(C++20)                         | [Clock](https://en.cppreference.com/w/cpp/named_req/Clock) for International Atomic Time (TAI) <br>(class)                                                 |
| [gps_clock](https://en.cppreference.com/w/cpp/chrono/gps_clock) <br>(C++20)                         | [Clock](https://en.cppreference.com/w/cpp/named_req/Clock) for GPS time <br>(class)                                                                        |
| [file_clock](https://en.cppreference.com/w/cpp/chrono/file_clock) <br>(C++20)                       | [Clock](https://en.cppreference.com/w/cpp/named_req/Clock) used for [file time](https://en.cppreference.com/w/cpp/filesystem/file_time_type) <br>(typedef) |
| [local_t](https://en.cppreference.com/w/cpp/chrono/local_t) <br>(C++20)                             | pseudo-clock representing local time <br>(class)                                                                                                           |
### Time point 
A time point is a duration of time that has passed since the epoch of a specific clock. 

| Defined in header [\<chrono>](https://en.cppreference.com/w/cpp/header/chrono)                      |                                                                                               |
| --------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |
| Defined in namespace std::chrono                                                                    |                                                                                               |
| [time_point](https://en.cppreference.com/w/cpp/chrono/time_point) <br>(C++11)                       | a point in time <br>(class template)                                                          |
| [clock_time_conversion](https://en.cppreference.com/w/cpp/chrono/clock_time_conversion) <br>(C++20) | traits class defining how to convert time points of one clock to another <br>(class template) |
| [clock_cast](https://en.cppreference.com/w/cpp/chrono/clock_cast) <br>(C++20)                       | convert time points of one clock to another <br>(function template)                           |

### Duration 
A duration consists of a span of time, defined as some number of ticks of some time unit. For example, "42 seconds" could be represented by a duration consisting of 42 ticks of a 1-second time unit. 

| Defined in header [\<chrono>](https://en.cppreference.com/w/cpp/header/chrono) |                                      |
| ------------------------------------------------------------------------------ | ------------------------------------ |
| Defined in namespace std::chrono                                               |                                      |
| [duration](https://en.cppreference.com/w/cpp/chrono/duration) <br>(C++11)      | a time interval <br>(class template) |

### Time of day (since C++20) 
hh_mm_ss splits a duration representing time elapsed since midnight into hours, minutes, seconds, and fractional seconds, as applicable. It is primarily a formatting tool. 

| Defined in header [\<chrono>](https://en.cppreference.com/w/cpp/header/chrono)          |                                                                |
| --------------------------------------------------------------------------------------- | -------------------------------------------------------------- |
| Defined in namespace std::chrono                                                        |                                                                |
| [hh_mm_ss](https://en.cppreference.com/w/cpp/chrono/hh_mm_ss) <br>(C++20)               | represents a time of day <br>(class template)                  |
| [is_amis_pmmake12make24](https://en.cppreference.com/w/cpp/chrono/hour_fun) <br>(C++20) | translates between a 12h/24h format time of day <br>(function) |

### Calendar (since C++20) 
| Defined in header [\<chrono>](https://en.cppreference.com/w/cpp/header/chrono)                          |                                                                                                                                                                                                                             |
| ------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Defined in namespace std::chrono                                                                        |                                                                                                                                                                                                                             |
| [last_spec](https://en.cppreference.com/w/cpp/chrono/last_spec) <br>(C++20)                             | tag class indicating the last day or weekday in a month <br>(class)                                                                                                                                                         |
| [day](https://en.cppreference.com/w/cpp/chrono/day) <br>(C++20)                                         | represents a day of a month <br>(class)                                                                                                                                                                                     |
| [month](https://en.cppreference.com/w/cpp/chrono/month) <br>(C++20)                                     | represents a month of a year <br>(class)                                                                                                                                                                                    |
| [year](https://en.cppreference.com/w/cpp/chrono/year) <br>(C++20)                                       | represents a year in the Gregorian calendar <br>(class)                                                                                                                                                                     |
| [weekday](https://en.cppreference.com/w/cpp/chrono/weekday) <br>(C++20)                                 | represents a day of the week in the Gregorian calendar <br>(class)                                                                                                                                                          |
| [weekday_indexed](https://en.cppreference.com/w/cpp/chrono/weekday_indexed) <br>(C++20)                 | represents the nth [weekday](https://en.cppreference.com/w/cpp/chrono/weekday) of a month <br>(class)                                                                                                                       |
| [weekday_last](https://en.cppreference.com/w/cpp/chrono/weekday_last) <br>(C++20)                       | represents the last [weekday](https://en.cppreference.com/w/cpp/chrono/weekday) of a month <br>(class)                                                                                                                      |
| [month_day](https://en.cppreference.com/w/cpp/chrono/month_day) <br>(C++20)                             | represents a specific [day](https://en.cppreference.com/w/cpp/chrono/day) of a specific [month](https://en.cppreference.com/w/cpp/chrono/month) <br>(class)                                                                 |
| [month_day_last](https://en.cppreference.com/w/cpp/chrono/month_day_last) <br>(C++20)                   | represents the last day of a specific [month](https://en.cppreference.com/w/cpp/chrono/month) <br>(class)                                                                                                                   |
| [month_weekday](https://en.cppreference.com/w/cpp/chrono/month_weekday) <br>(C++20)                     | represents the nth [weekday](https://en.cppreference.com/w/cpp/chrono/weekday) of a specific [month](https://en.cppreference.com/w/cpp/chrono/month) <br>(class)                                                            |
| [month_weekday_last](https://en.cppreference.com/w/cpp/chrono/month_weekday_last) <br>(C++20)           | represents the last [weekday](https://en.cppreference.com/w/cpp/chrono/weekday) of a specific [month](https://en.cppreference.com/w/cpp/chrono/month) <br>(class)                                                           |
| [year_month](https://en.cppreference.com/w/cpp/chrono/year_month) <br>(C++20)                           | represents a specific [month](https://en.cppreference.com/w/cpp/chrono/month) of a specific [year](https://en.cppreference.com/w/cpp/chrono/year) <br>(class)                                                               |
| [year_month_day](https://en.cppreference.com/w/cpp/chrono/year_month_day) <br>(C++20)                   | represents a specific [year](https://en.cppreference.com/w/cpp/chrono/year), [month](https://en.cppreference.com/w/cpp/chrono/month), and [day](https://en.cppreference.com/w/cpp/chrono/day) <br>(class)                   |
| [year_month_day_last](https://en.cppreference.com/w/cpp/chrono/year_month_day_last) <br>(C++20)         | represents the last day of a specific [year](https://en.cppreference.com/w/cpp/chrono/year) and [month](https://en.cppreference.com/w/cpp/chrono/month)<br>(class)                                                          |
| [year_month_weekday](https://en.cppreference.com/w/cpp/chrono/year_month_weekday) <br>(C++20)           | represents the nth [weekday](https://en.cppreference.com/w/cpp/chrono/weekday) of a specific [year](https://en.cppreference.com/w/cpp/chrono/year) and [month](https://en.cppreference.com/w/cpp/chrono/month) <br>(class)  |
| [year_month_weekday_last](https://en.cppreference.com/w/cpp/chrono/year_month_weekday_last) <br>(C++20) | represents the last [weekday](https://en.cppreference.com/w/cpp/chrono/weekday) of a specific [year](https://en.cppreference.com/w/cpp/chrono/year) and [month](https://en.cppreference.com/w/cpp/chrono/month) <br>(class) |
| [operator/](https://en.cppreference.com/w/cpp/chrono/operator_slash) <br>(C++20)                        | conventional syntax for Gregorian calendar date creation <br>(function)                                                                                                                                                     |

### ​Time zone (since C++20) 
| Defined in header [\<chrono>](https://en.cppreference.com/w/cpp/header/chrono)                                        |                                                                                                                                    |
| --------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| Defined in namespace std::chrono                                                                                      |                                                                                                                                    |
| [tzdb](https://en.cppreference.com/w/cpp/chrono/tzdb) <br>(C++20)                                                     | describes a copy of the [IANA time zone database](https://www.iana.org/time-zones) <br>(class)                                     |
| [tzdb_list](https://en.cppreference.com/w/cpp/chrono/tzdb_list) <br>(C++20)                                           | represents a linked list of [tzdb](https://en.cppreference.com/w/cpp/chrono/tzdb) <br>(class)                                      |
| [get_tzdbget_tzdb_listreload_tzdbremote_version](https://en.cppreference.com/w/cpp/chrono/tzdb_functions) <br>(C++20) | accesses and controls the global time zone database information <br>(function)                                                     |
| [locate_zone](https://en.cppreference.com/w/cpp/chrono/locate_zone) <br><br>(C++20)                                   | locates a [time_zone](https://en.cppreference.com/w/cpp/chrono/time_zone) based on its name <br>(function)                         |
| [current_zone](https://en.cppreference.com/w/cpp/chrono/current_zone) <br>(C++20)                                     | returns the current [time_zone](https://en.cppreference.com/w/cpp/chrono/time_zone) <br>(function)                                 |
| [time_zone](https://en.cppreference.com/w/cpp/chrono/time_zone) <br>(C++20)                                           | represents a time zone <br>(class)                                                                                                 |
| [sys_info](https://en.cppreference.com/w/cpp/chrono/sys_info) <br>(C++20)                                             | represents information about a time zone at a particular time point <br>(class)                                                    |
| [local_info](https://en.cppreference.com/w/cpp/chrono/local_info) <br>(C++20)                                         | represents information about a local time to UNIX time conversion <br>(class)                                                      |
| [choose](https://en.cppreference.com/w/cpp/chrono/choose) <br>(C++20)                                                 | selects how an ambiguous local time should be resolved <br>(enum)                                                                  |
| [zoned_traits](https://en.cppreference.com/w/cpp/chrono/zoned_traits) <br>(C++20)                                     | traits class for time zone pointers used by [zoned_time](https://en.cppreference.com/w/cpp/chrono/zoned_time) <br>(class template) |
| [zoned_time](https://en.cppreference.com/w/cpp/chrono/zoned_time) <br>(C++20)                                         | represents a time zone and a time point <br>(class)                                                                                |
| [leap_second](https://en.cppreference.com/w/cpp/chrono/leap_second) <br>(C++20)                                       | contains information about a leap second insertion <br>(class)                                                                     |
| [leap_second_info](https://en.cppreference.com/w/cpp/chrono/utc_clock/leap_second_info) <br>(C++20)                   | leap second insertion information <br>(class)                                                                                      |
| [get_leap_second_info](https://en.cppreference.com/w/cpp/chrono/utc_clock/get_leap_second_info) <br>(C++20)           | obtains leap second insertion information from a utc_time object <br>(function template)                                           |
| [time_zone_link](https://en.cppreference.com/w/cpp/chrono/time_zone_link) <br>(C++20)                                 | represents an alternative name for a time zone <br>(class)                                                                         |
| [nonexistent_local_time](https://en.cppreference.com/w/cpp/chrono/nonexistent_local_time) <br>(C++20)                 | exception thrown to report that a local time is nonexistent <br>(class)                                                            |
| [ambiguous_local_time](https://en.cppreference.com/w/cpp/chrono/ambiguous_local_time) <br>(C++20)                     | exception thrown to report that a local time is ambiguous <br>(class)                                                              |

### Literals (since C++14) 
| Defined in header [\<chrono>](https://en.cppreference.com/w/cpp/header/chrono)          |                                                                                                                               |
| --------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| Defined in inline namespace std::literals::chrono_literals                              |                                                                                                                               |
| [operator""y](https://en.cppreference.com/w/cpp/chrono/operator%22%22y) <br>(C++20)     | a std::chrono::year literal representing a particular year <br>(function)                                                     |
| [operator""d](https://en.cppreference.com/w/cpp/chrono/operator%22%22d) <br>(C++20)     | a std::chrono::day literal representing a day of a month <br>(function)                                                       |
| [operator""h](https://en.cppreference.com/w/cpp/chrono/operator%22%22h) <br>(C++14)     | a [std::chrono::duration](https://en.cppreference.com/w/cpp/chrono/duration) literal representing hours <br>(function)        |
| [operator""min](https://en.cppreference.com/w/cpp/chrono/operator%22%22min) <br>(C++14) | a [std::chrono::duration](https://en.cppreference.com/w/cpp/chrono/duration) literal representing minutes <br>(function)      |
| [operator""s](https://en.cppreference.com/w/cpp/chrono/operator%22%22s) <br>(C++14)     | a [std::chrono::duration](https://en.cppreference.com/w/cpp/chrono/duration) literal representing seconds <br>(function)      |
| [operator""ms](https://en.cppreference.com/w/cpp/chrono/operator%22%22ms) <br>(C++14)   | a [std::chrono::duration](https://en.cppreference.com/w/cpp/chrono/duration) literal representing milliseconds <br>(function) |
| [operator""us](https://en.cppreference.com/w/cpp/chrono/operator%22%22us) <br>(C++14)   | a [std::chrono::duration](https://en.cppreference.com/w/cpp/chrono/duration) literal representing microseconds <br>(function) |
| [operator""ns](https://en.cppreference.com/w/cpp/chrono/operator%22%22ns) <br>(C++14)   | a [std::chrono::duration](https://en.cppreference.com/w/cpp/chrono/duration) literal representing nanoseconds <br>(function)  |

### Chrono I/O (since C++20) 
| Defined in header [\<chrono>](https://en.cppreference.com/w/cpp/header/chrono) |                                                              |
| ------------------------------------------------------------------------------ | ------------------------------------------------------------ |
| Defined in namespace std::chrono                                               |                                                              |
| [parse](https://en.cppreference.com/w/cpp/chrono/parse) <br>(C++20)            | parses a chrono object from a stream <br>(function template) |
# [C Date and time utilities](C%20Date%20and%20time%20utilities.md)

