---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-23 12:02::41 PM
tags:
  - Cpp
  - Linux
  - log
---
# Log

There is no single "law," but there is a **De Facto Industry Standard** that 99% of modern enterprise applications follow.

The standard has shifted from **Unstructured Text** (easy for humans to read) to **Structured JSON** (easy for machines/dashboards to read).

Here is the breakdown of the modern standard.

-----

### 1\. The "Production" Standard (JSON)

In production (servers, cloud, microservices), logs are consumed by tools like Splunk, Datadog, or ELK (Elasticsearch). These tools require **Structured Logging**.

**The Format:**

```json
{
  "timestamp": "2025-11-23T11:57:00.123Z",
  "level": "ERROR",
  "service_name": "payment_gateway",
  "correlation_id": "req-12345-abcde",
  "thread_id": "14023",
  "message": "Transaction failed due to timeout",
  "context": {
    "user_id": 42,
    "transaction_amount": 100.50,
    "currency": "USD",
    "error_code": 504
  },
  "source": {
    "file": "TransactionManager.cpp",
    "line": 88
  }
}
```

**Why this is standard:**

  * **Queryable:** You can search `context.user_id = 42` instantly.
  * **No Parsing:** You don't need complex Regular Expressions to extract data.

-----

### 2\. The "Development" Standard (Console/Text)

When you are running the app locally on Linux or in your IDE, JSON is hard to read. The standard "Human-Readable" format usually follows this pattern:

**The Pattern:**
`[TIMESTAMP] [LEVEL] [THREAD/LOGGER] MESSAGE {CONTEXT}`

**The Example:**

```text
[2025-11-23 11:57:00] [ERROR] [PaymentService] Transaction failed. User:42 Error:Timeout
```

-----

### 3\. The Anatomy of a Perfect Log Entry

Regardless of JSON or Text, every standard log **must** contain these 5 fields:

| Field | Standard | Why? |
| :--- | :--- | :--- |
| **Timestamp** | **ISO 8601** (`YYYY-MM-DDTHH:mm:ss.sssZ`) | Must include Timezone (usually UTC 'Z') so logs from different countries line up. |
| **Level** | `TRACE` \< `DEBUG` \< `INFO` \< `WARN` \< `ERROR` \< `FATAL` | Allows filtering. "Show me only Errors". |
| **Correlation ID** | UUID (e.g., `a1b2-c3d4`) | **Crucial.** A unique ID generated at the start of a request and passed to every function/service. It links all logs for one user action together. |
| **Message** | Static String | "User logged in" (Do not put variable data here). |
| **Context** | Key-Value Pairs | Variables go here (`user_id=5`, `ip=192.168.1.1`). |

-----

### 4\. How to do this in C++ (The Standard Tool)

Do not use `std::cout` or `printf`. They are not thread-safe, have no levels, and slow down your app.

The C++ industry standard is **spdlog**. It handles formatting, async logging (fast), and file rotation automatically.

**Installation (Conan):**
`conan install . --requires=spdlog/1.12.0`

**Usage (spdlog):**

```cpp
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {
    // 1. Text Logging (for your console)
    spdlog::info("Welcome to the app!");
    
    // 2. Logging with Context (The C++20/fmt way)
    int user_id = 42;
    std::string error = "Timeout";
    
    // This automatically formats nicely:
    spdlog::error("Transaction failed for user {0} with error: {1}", user_id, error);
    
    // 3. Set Level (Hide debug logs in release)
    spdlog::set_level(spdlog::level::debug); 
    
    return 0;
}
```

### 5\. What NOT to Log (Security Standard)

To comply with security standards (GDPR, PCI-DSS), never log:

1.  **Passwords** (obviously).
2.  **Auth Tokens / Session IDs** (hackers can steal sessions).
3.  **PII (Personally Identifiable Information)** like Credit Card Numbers or Phone Numbers, unless masked (`****-****-****-1234`).

**Next Step:** Would you like to see a C++ helper class that generates a **Correlation ID** (UUID) automatically for every new request so you can track a user's journey through your logs?
