---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-02-22T12:59:00
tags:
  - Cpp
  - Library
  - Header
---
\#include[\<iomanip>](https://en.cppreference.com/w/cpp/header/iomanip)

| Functions                                                                     |                                                                                                 |
| ----------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------- |
| [resetiosflags](https://en.cppreference.com/w/cpp/io/manip/resetiosflags)     | clears the specified ios_base flags <br>(function)                                              |
| [setiosflags](https://en.cppreference.com/w/cpp/io/manip/setiosflags)         | sets the specified ios_base flags <br>(function)                                                |
| [setbase](https://en.cppreference.com/w/cpp/io/manip/setbase)                 | changes the base used for integer I/O <br>(function)                                            |
| [setfill](https://en.cppreference.com/w/cpp/io/manip/setfill)                 | changes the fill character <br>(function template)                                              |
| [setprecision](https://en.cppreference.com/w/cpp/io/manip/setprecision)       | changes floating-point precision <br>(function)                                                 |
| [setw](https://en.cppreference.com/w/cpp/io/manip/setw)                       | changes the width of the next input/output field <br>(function)                                 |
| [get_money](https://en.cppreference.com/w/cpp/io/manip/get_money) <br>(C++11) | parses a monetary value <br>(function template)                                                 |
| [put_money](https://en.cppreference.com/w/cpp/io/manip/put_money) <br>(C++11) | formats and outputs a monetary value <br>(function template)                                    |
| [get_time](https://en.cppreference.com/w/cpp/io/manip/get_time) <br>(C++11)   | parses a date/time value of specified format <br>(function template)                            |
| [put_time](https://en.cppreference.com/w/cpp/io/manip/put_time) <br>(C++11)   | formats and outputs a date/time value according to the specified format <br>(function template) |
| [quoted](https://en.cppreference.com/w/cpp/io/manip/quoted) <br>(C++14)       | inserts and extracts quoted strings with embedded spaces <br>(function template)                |
## std::get_time

| Defined in header [\<iomanip>](https://en.cppreference.com/w/cpp/header/iomanip)                                                            |               |
| ------------------------------------------------------------------------------------------------------------------------------------------- | ------------- |
| template< class CharT > <br>/\*unspecified\*/ get_time( [std::tm](http://en.cppreference.com/w/cpp/chrono/c/tm)\* tmb, const CharT\* fmt ); | (since C++11) |

When used in an expression in >> get_time(tmb, fmt), parses the character input as a date/time value according to format string fmt according to the [std::time_get](https://en.cppreference.com/w/cpp/locale/time_get) facet of the locale currently imbued in the input stream in. The resultant value is stored in a [std::tm](https://en.cppreference.com/w/cpp/chrono/c/tm) object pointed to by tmb. 

### Parameters 

tmb - valid pointer to the [std::tm](https://en.cppreference.com/w/cpp/chrono/c/tm) object where the result will be stored
fmt - pointer to a null-terminated CharT string specifying the conversion format 
	The format string consists of zero or more conversion specifiers, whitespace characters, and ordinary characters (except %). Each ordinary character is expected to match one character in the input stream in case-insensitive comparison. Each whitespace character matches arbitrary whitespace in the input string. Each conversion specification begins with % character, optionally followed by E or O modifier (ignored if unsupported by the locale), followed by the character that determines the behavior of the specifier. The format specifiers match the POSIX function [strptime()](https://pubs.opengroup.org/onlinepubs/9699919799/functions/strptime.html):

| Conversion <br>specifier | Explanation                                                                                                                                        | Writes to fields          |
| :----------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------- |
| %                        | matches a literal %. The full conversion specification must be %%                                                                                  | (none)                    |
| t                        | matches any whitespace                                                                                                                             | (none)                    |
| n                        | matches any whitespace                                                                                                                             | (none)                    |
| Year                     |                                                                                                                                                    |                           |
| Y                        | parses full year as a 4 digit decimal number, leading zeroes permitted but not required                                                            | tm_year                   |
| EY                       | parses year in the alternative representation, e.g.平成23年 (year Heisei 23) which writes 2011 to tm_year in ja_JP locale                             | tm_year                   |
| y                        | parses last 2 digits of year as a decimal number. Range [69,99] results in values 1969 to 1999, range [00,68] results in 2000-2068                 | tm_year                   |
| Oy                       | parses last 2 digits of year using the alternative numeric system, e.g. 十一 is parsed as 11 in ja_JP locale                                         | tm_year                   |
| Ey                       | parses year as offset from locale's alternative calendar period %EC                                                                                | tm_year                   |
| C                        | parses the first 2 digits of year as a decimal number (range [00,99])                                                                              | tm_year                   |
| EC                       | parses the name of the base year (period) in the locale's alternative representation, e.g. 平成 (Heisei era) in ja_JP                                | tm_year                   |
| Month                    |                                                                                                                                                    |                           |
| b                        | parses the month name, either full or abbreviated, e.g. Oct                                                                                        | tm_mon                    |
| h                        | synonym of b                                                                                                                                       | tm_mon                    |
| B                        | synonym of b                                                                                                                                       | tm_mon                    |
| m                        | parses the month as a decimal number (range [01,12]), leading zeroes permitted but not required                                                    | tm_mon                    |
| Om                       | parses the month using the alternative numeric system, e.g. 十二 parses as 12 in ja_JP locale                                                        | tm_mon                    |
| Week                     |                                                                                                                                                    |                           |
| U                        | parses the week of the year as a decimal number (Sunday is the first day of the week) (range [00,53]), leading zeroes permitted but not required   | tm_year, tm_wday, tm_yday |
| OU                       | parses the week of the year, as by %U, using the alternative numeric system, e.g. 五十二 parses as 52 in ja_JP locale                                 | tm_year, tm_wday, tm_yday |
| W                        | parses the week of the year as a decimal number (Monday is the first day of the week) (range [00,53]), leading zeroes permitted but not required   | tm_year, tm_wday, tm_yday |
| OW                       | parses the week of the year, as by %W, using the alternative numeric system, e.g. 五十二 parses as 52 in ja_JP locale                                 | tm_year, tm_wday, tm_yday |
| Day of the year/month    |                                                                                                                                                    |                           |
| j                        | parses day of the year as a decimal number (range [001,366]), leading zeroes permitted but not required                                            | tm_yday                   |
| d                        | parses the day of the month as a decimal number (range [01,31]), leading zeroes permitted but not required                                         | tm_mday                   |
| Od                       | parses the day of the month using the alternative numeric system, e.g. 二十七 parses as 27 in ja_JP locale, leading zeroes permitted but not required | tm_mday                   |
| e                        | synonym of d                                                                                                                                       | tm_mday                   |
| Oe                       | synonym of Od                                                                                                                                      | tm_mday                   |
| Day of the week          |                                                                                                                                                    |                           |
| a                        | parses the name of the day of the week, either full or abbreviated, e.g. Fri                                                                       | tm_wday                   |
| A                        | synonym of a                                                                                                                                       | tm_wday                   |
| w                        | parses weekday as a decimal number, where Sunday is 0 (range [0-6])                                                                                | tm_wday                   |
| Ow                       | parses weekday as a decimal number, where Sunday is 0, using the alternative numeric system, e.g. 二 parses as 2 in ja_JP locale                    | tm_wday                   |
| Hour, minute, second     |                                                                                                                                                    |                           |
| H                        | parses the hour as a decimal number, 24 hour clock (range [00-23]), leading zeroes permitted but not required                                      | tm_hour                   |
| OH                       | parses hour from 24-hour clock using the alternative numeric system, e.g. 十八 parses as 18 in ja_JP locale                                          | tm_hour                   |
| I                        | parses hour as a decimal number, 12 hour clock (range [01,12]), leading zeroes permitted but not required                                          | tm_hour                   |
| OI                       | parses hour from 12-hour clock using the alternative numeric system, e.g. 六 reads as 06 in ja_JP locale                                            | tm_hour                   |
| M                        | parses minute as a decimal number (range [00,59]), leading zeroes permitted but not required                                                       | tm_min                    |
| OM                       | parses minute using the alternative numeric system, e.g. 二十五 parses as 25 in ja_JP locale                                                          | tm_min                    |
| S                        | parses second as a decimal number (range [00,60]), leading zeroes permitted but not required                                                       | tm_sec                    |
| OS                       | parses second using the alternative numeric system, e.g. 二十四 parses as 24 in ja_JP locale                                                          | tm_sec                    |
| Other                    |                                                                                                                                                    |                           |
| c                        | parses the locale's standard date and time string format, e.g. Sun Oct 17 04:41:13 2010 (locale dependent)                                         | all                       |
| Ec                       | parses the locale's alternative date and time string format, e.g. expecting 平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale    | all                       |
| x                        | parses the locale's standard date representation                                                                                                   | all                       |
| Ex                       | parses the locale's alternative date representation, e.g. expecting 平成23年 (year Heisei 23) instead of 2011年 (year 2011) in ja_JP locale            | all                       |
| X                        | parses the locale's standard time representation                                                                                                   | all                       |
| EX                       | parses the locale's alternative time representation                                                                                                | all                       |
| D                        | equivalent to "%m / %d / %y "                                                                                                                      | tm_mon, tm_mday, tm_year  |
| r                        | parses locale's standard 12-hour clock time (in POSIX, "%I : %M : %S %p")                                                                          | tm_hour, tm_min, tm_sec   |
| R                        | equivalent to "%H : %M"                                                                                                                            | tm_hour, tm_min           |
| T                        | equivalent to "%H : %M : %S"                                                                                                                       | tm_hour, tm_min, tm_sec   |
| p                        | parses the locale's equivalent of a.m. or p.m.                                                                                                     | tm_hour                   |
Note: tm_isdst is not written to, and needs to be set explicitly for use with functions such as mktime
### Return value 
An object of unspecified type such that 
- if in is an object of type [std::basic_istream](http://en.cppreference.com/w/cpp/io/basic_istream)<CharT, Traits>, the expression in >> get_time(tmb, fmt) 
- has type [std::basic_istream](http://en.cppreference.com/w/cpp/io/basic_istream)<CharT, Traits>& 
- has value in 
- behaves as if it called f(in, tmb, fmt) 
    
where the function f is defined as: 
```Cpp
template<class CharT, class Traits> 
voidf(std::basic_ios <CharT, Traits>&str, std::tm*tmb, constCharT*fmt) 
{ 
	using Iter = std::istreambuf_iterator<CharT, Traits>; 
    using TimeGet  = time_get<CharT, Iter>;    
       
    std::ios_base::iostate err = std::ios_base::goodbit
         
    const TimeGet& tg = std::use_facet<TimeGet>(str.getloc());       
         
    tg.get(Iter(str.rdbuf()), Iter(), str, err, tmb, fmt, fmt +Traits::length(fmt));

    if (err !=std::ios_base::goodbit)	    
	    str.setstate(err); 
}
```
#### Notes 
As specified in [std::time_get::do_get](https://en.cppreference.com/w/cpp/locale/time_get/get), which this function calls, it's unspecified if this function zero out the fields in *tmb that are not set directly by the conversion specifiers that appear in fmt: portable programs should initialize every field of *tmb to zero before calling std::get_time. 
#### Example 

```cpp
#include <iomanip> 
#include <iostream> 
#include <locale> 
#include <sstream>  
int main(){ 
    std::tm t ={}; 
    std::istringstream ss("2011-Februar-18 23:12:34"); 
    ss.imbue(std::locale("de_DE.utf-8"));        
    ss >>std::get_time(&t, "%Y-%b-%d %H:%M:%S");            
    if(ss.fail()) 
        std::cout <<"Parse failed\n"; 
    else 
        std::cout << std::put_time (&t, "%c")<<'\n'; 
}
```

Possible output: 

	Sun Feb 18 23:12:34 2011