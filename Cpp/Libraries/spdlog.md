---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-23 14:14::19 PM
tags:
  - Cpp
  - Library
  - log
---

# spdlog

In simple terms:

- When creating log using spdlog you need to decide where the log will appear i.e. console or file or both.
## console
```cpp
spdlog::info("Welcome to spdlog!");
spdlog::error("Some error message with arg: {}", 1);
    
spdlog::warn("Easy padding in numbers like {:08d}", 12);
spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
spdlog::info("Support for floats {:03.2f}", 1.23456);
spdlog::info("Positional args are {1} {0}..", "too", "supported");
spdlog::info("{:<30}", "left aligned");
    
spdlog::set_level(spdlog::level::debug); // Set *global* log level to debug
spdlog::debug("This message should be displayed..\n\n");    
    
// change log pattern
spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    
// Compile time log levels
// Note that this does not change the current log level, it will only
// remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
SPDLOG_TRACE("Some trace message with param {}", 42);
SPDLOG_DEBUG("Some debug messag");
```

```cpp
// create a color multi-threaded logger
auto console = spdlog::stdout_color_mt("console");    
auto err_logger = spdlog::stderr_color_mt("stderr");    
spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)\n\n\n");
```

## files

Important note: 
- always check for duplicate  `logger name` else it will give fetal error. 
- `spdlog` maintains a global registry (a list) of all active loggers, identified by their name strings (e.g., "NetworkLogger").
```
// Queries the global registry: "Do you already have a logger named 'logger_name'?"
auto existing_logger = spdlog::get(logger_name);
```

- **If found:** It returns a `std::shared_ptr` to the live logger object.
    
- **If NOT found:** It returns `nullptr`.
```cpp
std::string logger_name;
auto existing_logger = spdlog::get(logger_name);
if (existing_logger) {
	return existing_logger; // Returns a COPY of the shared_ptr (Safe)
}
```
### simple file / basic file

```cpp
#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
try
{
	//creating/opning file where log is going to written.
	auto logger = spdlog::basic_logger_mt("basic_logger", "logs/destination");	
	new_log->set_pattern("[%d-%m-%Y %H:%M:%S.%e] [%n] [%l] : %v"); // seting patter optional
	new_log->flush_on(spdlog::level::trace); // starting flush and declare level
	logger->critical("this is critical"); // your log that is to be wrriten.
}
catch (const spdlog::spdlog_ex &ex)
{
	std::cout << "log int failed: " << ex.what() << std::endl << std::flush;
}
```

### basic file sink
```cpp
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

int main()
{
	auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("mylog.log"); // opening file 
	auto log = std::make_shared<spdlog::logger>(logger_name, log_file); // linking the file with the logger.
	new_log->flush_on(spdlog::level::trace); // starting flush and declare level
	logger->critical("this is critical");
}
```

### rotating file 
rotating file will change the pre-existing log file to log1 -> log2, and log2 -> log3 so on based on your parameter.

like in this snippet max file size is 5MB and number of file is 3.
```cpp
// Create the Sink/file 
static auto log_file = std::make_shared<spdlog::sinks::rotating_file_sink_mt>( "logs/music_player.log", 1024 * 1024 * 5, 3 );
auto log = std::make_shared<spdlog::logger>(logger_name, log_file);
```

## Console and file both
```cpp

 // 1. Create a console sink (for colored output to stdout)
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::info); // Set minimum level for console output
    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v"); // Custom pattern for console

    // 2. Create a file sink (for logging to a file)
    // The file "mylog.log" will be created if it doesn't exist.
    // Ensure the directory for the file exists if you use a relative path like "logs/mylog.log".
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("mylog.log", true); // true for append mode
    file_sink->set_level(spdlog::level::trace); // Set minimum level for file output
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v"); // Custom pattern for file

    // 3. Combine the sinks into a vector
    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};

    // 4. Create a logger with the combined sinks
    auto logger = std::make_shared<spdlog::logger>("my_app_logger", sinks.begin(), sinks.end());
    logger->set_level(spdlog::level::trace); // Set overall logger level
    spdlog::register_logger(logger); // Register the logger globally

    // 5. Use the logger to output messages
    logger->trace("This is a trace message.");
    logger->debug("This is a debug message.");
    logger->info("This is an info message.");
    logger->warn("This is a warning message.");
    logger->error("This is an error message.");
    logger->critical("This is a critical message.");

    // Optional: Flush the logger to ensure all messages are written to the file
    logger->flush();

    // Optional: Drop the logger when no longer needed (releases resources)
    spdlog::drop("my_app_logger");

```
-----
## The Level Hierarchy (Lowest to Highest)

When you set a level, **that level and everything above it** is enabled.

| **Level Enum (spdlog::level::...)** | **Description**                            | **Example Use Case**                                       |
| ----------------------------------- | ------------------------------------------ | ---------------------------------------------------------- |
| **`trace`**                         | Lowest level. Extremely verbose.           | "Entering function X", "Loop iteration i=50"               |
| **`debug`**                         | Diagnostic information.                    | "User clicked button", "Data loaded from DB"               |
| **`info`**                          | **(Default)** General operational events.  | "App started", "User logged in", "Listening on port 80"    |
| **`warn`**                          | Something odd happened, but app continues. | "Config file missing, using defaults", "High memory usage" |
| **`error`**                         | Operation failed, but app keeps running.   | "Database timeout", "Failed to save file"                  |
| **`critical`**                      | Severe error, app might crash.             | "Memory corruption", "Disk full"                           |
| **`off`**                           | Disables logging completely.               | Unit tests where you want silence.                         |

----
## most efficient code I written. 
this is header file
```cpp
#pragma once

#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>

inline std::shared_ptr<spdlog::logger> logger(std::string logger_name = "log") {
	try
	{
		// 1. Check if exists
		auto existing_logger = spdlog::get(logger_name);
		if (existing_logger) {
			return existing_logger; // Returns a COPY of the shared_ptr (Safe)
		}

		// 2. Create the Sink
		static auto log_file = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/music_player.log", 1024 * 1024 * 5, 3);

		// 3. Create the Logger
		auto log = std::make_shared<spdlog::logger>(logger_name, log_file);

		log->set_pattern("[%d-%m-%Y %H:%M:%S.%e] [%n] [%l] : %v");
		log->flush_on(spdlog::level::trace);

		// 4. Register
		spdlog::register_logger(log);

		return log; // Returns a COPY of the shared_ptr (Safe)
	}
	catch (const std::exception& e)
	{
		std::cerr << "Logger init failed: " << e.what() << '\n';
		return nullptr;
	}
}
```
------
To create a log file using `spdlog`, you need to set up a file sink and associate it with a logger. Here's how you can do it: Include necessary headers.

``` CPP
#include <spdlog/spdlog.h>    
#include <spdlog/sinks/basic_file_sink.h> // For basic file logging    

// Or for rotating files: 
#include <spdlog/sinks/rotating_file_sink.h>
```

Create a file sink.

You can choose between different file sinks depending on your needs.

- `basic_file_sink_mt` (multi-threaded) or `basic_file_sink_st` (single-threaded): For a simple log file.
- `rotating_file_sink_mt` or `rotating_file_sink_st`: For log files that rotate (e.g., based on size or time).


``` Cpp
// Example for a basic file sink:
auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("mylog.txt", true); // "mylog.txt" is the filename, true means append to existing file
    
// Example for a rotating file sink (rotates after 5MB and keeps 3 old files):
auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("rotating_log.txt", 1024 * 1024 * 5, 3);
```

- **Create a logger with the file sink:**

You can create a logger that only logs to the file, or a multisink logger that also logs to the console.

```Cpp
// Logger only to file:
auto file_logger = std::make_shared<spdlog::logger>("my_file_logger", file_sink);

// Multisink logger (console and file):
auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
auto multisink_logger = std::make_shared<spdlog::logger>("my_multisink_logger", sinks.begin(), sinks.end());
```

Register and use the logger.

It's good practice to register your logger so you can retrieve it later by name.

```cpp
spdlog::register_logger(file_logger);

// Set a log level for the logger (optional):
file_logger->set_level(spdlog::level::info);

// Log messages:
file_logger->info("This message will go to the file.");
file_logger->warn("A warning message.");
```

- **Important Notes:**
    - **Thread Safety:** Use `_mt` sinks for multi-threaded applications to ensure thread-safe logging.
    - **File Paths:** Relative paths for log files are relative to the directory from where your executable is run. You can provide absolute paths if needed.
    - **Flushing:** `spdlog` typically flushes logs automatically, but you can explicitly call `logger->flush()` if immediate writing to the file is critical.
    - **Shutdown:** Ensure `spdlog::shutdown()` is called before your application exits to flush any remaining log messages and release resources.