#include <fmt/core.h>
#include <chrono>
#include <thread>
#include <fmt/chrono.h>

#define HEAD fmt::print("\n{:->25}\n\n", 0 );


void fun1(void){

    HEAD;
    std::chrono::milliseconds mil(1000); //~ New thing to learn.
    mil = mil*60;

    fmt::print("Duration (in periods): {} milliseconds.\n", mil.count());
    fmt::print("Duration (in seconds): {} seconds.\n", (mil.count()*std::chrono::milliseconds::period::num / std::chrono::milliseconds::period::den));
}

void fun2(void){ //~ New thing to learn.
    HEAD;

    //* Learn how to use high_resolution_clock

    auto now = std::chrono::high_resolution_clock::now();
    
    // Some time-consuming operation
    for (int i = 0; i < 1000000; ++i) {
        // Do something
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( end - now );

    fmt::print("Elapsed time: {} miliseconds.\n", duration.count());
}

void fun3(void){
    HEAD;
    //* Learn How to break/wait for some time and continue further with sleep_for.
    
    fmt::print("wait for 2 second.\n");
    std::this_thread::sleep_for(std::chrono::seconds(2)); //~ New thing to learn.
    fmt::print("done waiting!\n");
}

void fun4(void){
    HEAD;
    //* Learn How to use system_clock.

    auto now = std::chrono::system_clock::now();

    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    fmt::print("Current time: {:%Y-%m-%d %H:%M:%S}\n", fmt::localtime(now_time)); //~ New thing to learn.
    // std::cout << "Current time: " << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << '\n'; //~ std::put_time is define in #include<iomanip>
}

void fun5(void){
    HEAD;
    //* Learn How to use steady_clock

    std::chrono::steady_clock::time_point clock_begin = std::chrono::steady_clock::now();

    fmt::print("\nprint out 1000 stars ....\n");
    for (int i = 0; i < 1001; i++)
    fmt::print("*");

    std::chrono::steady_clock::time_point clock_end = std::chrono::steady_clock::now();

    std::chrono::steady_clock::duration time_span = clock_end - clock_begin;
    double nanosecond = double(time_span.count())*std::chrono::steady_clock::period::num/std::chrono::steady_clock::period::den;

    fmt::print("It took {} seconds.", nanosecond); 
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

void fun6(void){
    HEAD;
    //* Converting from steady_clock to system_clock:

    auto steady_now = std::chrono::steady_clock::now();
    auto system_now = std::chrono::time_point_cast<std::chrono::system_clock::duration>(steady_now);

    // Now 'system_now' represents the equivalent point in time in system_clock
    // You can use it for displaying or scheduling tasks based on system time

    fmt::print("steady clock value {0} is converted into system clock value {1}.\n", std::chrono::duration_cast<std::chrono::milliseconds>(steady_now.time_since_epoch()).count(), std::chrono::duration_cast<std::chrono::milliseconds>(system_now.time_since_epoch()).count());

    //* Converting from system_clock to steady_clock:

    auto system_now2 = std::chrono::system_clock::now();
    auto steady_now2 = std::chrono::time_point_cast<std::chrono::steady_clock::duration>(system_now2);

    fmt::print("system clock value {0} is converted into steady clock value {1}.\n", std::chrono::duration_cast<std::chrono::milliseconds>(system_now2.time_since_epoch()).count(), std::chrono::duration_cast<std::chrono::milliseconds>(steady_now2.time_since_epoch()).count()); 
}

/*
* Using the chrono Library for Date of Birth
* Unfortunately, the chrono library in C++ is primarily designed for time measurements and durations,
* not for representing calendar dates. It's better suited for calculating time differences, measuring 
* performance, and handling time-related computations.
*
* Some popular options include:
*  # Boost.Date_Time: Offers a comprehensive set of tools for date and time manipulation. //~(I will use this.)
*  # Howard Hinnant's date library: Provides a modern and efficient date/time library.
*/


int main(){
    fun1();
    fun2();
    fun3();
    fun4();
    fun5();
    fun6();

    return 0;
}