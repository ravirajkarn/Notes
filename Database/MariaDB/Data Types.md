---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-17 12:55::28 PM
tags:
  - MariaDB
  - Database
---
# Data Types 
Data Types in mariaDB. 


## 1. Null Value:
`NULL` represents an unknown value. It is _not_ an empty string (by default), or a zero value. These are all valid values, and are not `NULL` values.

When a table is [created](https://mariadb.com/docs/server/server-usage/tables/create-table) or the format [altered](https://mariadb.com/docs/server/reference/sql-statements/data-definition/alter/alter-table), columns can be specified as accepting `NULL` values, or not accepting them, with the `NULL` and `NOT NULL` clauses respectively.

```sql
CREATE TABLE customer (
	id INT NOT NULL, 
	 date_of_birth DATE NULL
	...
)
```

**Comparisons and Operators**
- **Standard Operators Fail:** You cannot use standard comparison operators (like `=`, `>`, `<`, or `!=`) with `NULL`. Any comparison with a `NULL` value will always return `NULL`, rather than true (1) or false (0).
- **NULL-Safe Operators:** To test for or compare `NULL` values, you must use specific operators such as `IS NULL`, `IS NOT NULL`, `ISNULL()`, `COALESCE()`, or the `NULL`-safe equal operator `<=>`.

**Sorting and Grouping**
- **Ordering:** When sorting results with `ORDER BY`, MariaDB considers `NULL` to have the lowest possible value. If you sort in descending (`DESC`) order, `NULL` values will appear last.
- **Equivalence:** For the purposes of `DISTINCT` and `GROUP BY` clauses, all `NULL` values are treated as equivalent to one another.

**Functions**
- **Standard Functions:** Most functions will return `NULL` if any of the parameters passed to them are `NULL`.
- **Aggregate Functions:** Functions like `SUM` and `AVG` completely ignore `NULL` values. The only exception is `COUNT(*)`, which counts rows regardless of whether they contain `NULL` values.

**Special Column Behaviors** In certain column types, inserting `NULL` acts as a shortcut for the `DEFAULT` keyword:
- **AUTO_INCREMENT****:** Inserting `NULL` automatically generates and inserts the next number in the auto-increment sequence.
- **TIMESTAMP****:** Inserting `NULL` assigns the current date and time.
- **Virtual/Persistent Columns:** Inserting `NULL` triggers the column's default value.

## 2. Numeric Data Type:
- [BOOLEAN](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/boolean) - Synonym for TINYINT(1)
- [INT1](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/int1) - Synonym for TINYINT
- [INT2](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/int2) - Synonym for SMALLINT
- [INT3](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/int3) - Synonym for MEDIUMINT
- [INT](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/int), INTEGER
- [INT4](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/int4) - Synonym for INT
- [INT8](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/int8) - Synonym for BIGINT
- [TINYINT](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/tinyint)
- [SMALLINT](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/smallint)
- [MEDIUMINT](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/mediumint)
- [BIGINT](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/bigint)
- [DECIMAL](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/decimal), DEC, NUMERIC, FIXED
- [FLOAT](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/float)
- [DOUBLE](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/double), DOUBLE PRECISION, REAL
- [BIT](https://mariadb.com/docs/server/reference/data-types/numeric-data-types/bit)
- [VECTOR](https://mariadb.com/docs/server/reference/sql-structure/vectors/vector)

## 3. Date and Time Date Type:
- [DATE](https://mariadb.com/docs/server/reference/data-types/date-and-time-data-types/date)
- [DATETIME](https://mariadb.com/docs/server/reference/data-types/date-and-time-data-types/datetime)
- [SQL_TSI_YEAR](https://mariadb.com/docs/server/reference/data-types/date-and-time-data-types/sql_tsi_year)
- [TIME](https://mariadb.com/docs/server/reference/data-types/date-and-time-data-types/time)
- [TIMESTAMP](https://mariadb.com/docs/server/reference/data-types/date-and-time-data-types/timestamp)
- [YEAR](https://mariadb.com/docs/server/reference/data-types/date-and-time-data-types/year-data-type)

## 4. String Data Types
**Standard Character and Binary Strings**
*   **`CHAR`**: A fixed-length character string (0 to 255 characters) that pads with spaces if the stored data is shorter than the defined length.
*   **`VARCHAR`**: A variable-length character string that can store up to 65,532 characters per row depending on character set limits.
*   **`BINARY`**: A fixed-length binary string that stores a specific number of bytes, padding with zero bytes if the data is shorter.
*   **`VARBINARY`**: A variable-length binary string type up to a specified maximum.

**TEXT Types (Variable-Length Character Strings)**
These types are used for storing larger amounts of character text:
*   **`TINYTEXT`**: Stores up to 255 characters.
*   **`TEXT`**: Stores up to 65,535 bytes of text data.
*   **`MEDIUMTEXT`**: Stores up to 16 megabytes (MB) of text data.
*   **`LONGTEXT`**: Stores up to 4 gigabytes (GB) of text data.

**BLOB Types (Binary Large Objects)**
These types are used for storing binary data (like images or non-text files):
*   **`TINYBLOB`**: Stores up to 255 bytes of binary data.
*   **`BLOB`**: Stores up to 65,535 bytes of binary data.
*   **`MEDIUMBLOB`**: Stores up to 16 MB of binary data.
*   **`LONGBLOB`**: Stores up to 4 GB of binary data.

**List / Choice Types**
*   **`ENUM`**: An enumeration type that can hold only *one* value chosen from a predefined list of string values.
*   **`SET`**: A string object that can hold *zero or more* values chosen from a predefined list of permitted strings.

**Specialized String Types**
*   **`INET4`**: Used for IPv4 addresses, storing them as 4-byte binary strings for efficient storage and retrieval.
*   **`INET6`**: Used for IPv6 addresses, storing them as 16-byte binary strings (also supports IPv4 mapping).
*   **`JSON`**: Specifically for storing JSON document structures.
*   **`UUID`**: Stores 128-bit Universally Unique Identifiers.
*   **`XMLTYPE`**: Used for storing XML data (available from MariaDB 12.3).
*   **`ROW`**: A type used specifically in stored programs to hold a complete row of data from a table or cursor.

**Oracle Compatibility and Synonyms**
MariaDB supports numerous synonyms and compatibility types to make migration from other database systems (like Oracle) easier. 
*   **Oracle Mode Types**: **`CLOB`** (alias for `LONGTEXT`), **`RAW`** (variable-length binary synonymous with `VARBINARY`), and **`VARCHAR2`** (variable-length string).
*   **Basic Synonyms**: Types like **`CHARACTER`**, **`CHAR BYTE`**, **`CHAR VARYING`**, **`VARCHARACTER`**.
*   **Long Synonyms**: **`LONG`**, **`LONG VARCHAR`**, **`LONG CHAR VARYING`**, **`LONG CHARACTER VARYING`**, **`LONG VARCHARACTER`** (all synonyms for `MEDIUMTEXT`), and **`LONG VARBINARY`** (synonym for `MEDIUMBLOB`).
*   **National Character Sets**: Data types prefixed with `NATIONAL` or `NCHAR` (e.g., **`NATIONAL CHAR`**, **`NATIONAL VARCHAR`**, **`NCHAR VARYING`**) are synonyms for their respective `CHAR` and `VARCHAR` base types but strictly utilize the predefined `utf8` or `utf8mb3` character sets.
## Auto Increment
he **AUTO_INCREMENT** attribute in MariaDB is used to automatically generate a unique numeric identity for new rows inserted into a table

- **Automatic Generation:** When you insert a new record and leave the `AUTO_INCREMENT` field as `NULL` or `DEFAULT`, MariaDB automatically increments the value. It also increments if you insert `0`, unless the `NO_AUTO_VALUE_ON_ZERO` SQL mode is enabled. By default, the sequence starts at `1` and can never generate a value lower than `0`.
- **Table Requirements:** Each table is restricted to having **only one** **AUTO_INCREMENT** **column**, and it **must be defined as a key** (though it is not strictly required to be a `PRIMARY KEY` or `UNIQUE` key)
- **Storage Engine Rules:** In the default InnoDB storage engine, if the key contains multiple columns, the `AUTO_INCREMENT` column must be the first one in the key. Furthermore, its state is persistent in InnoDB
- **Explicit Values:** You can manually insert an explicit value into the column, provided it doesn't already exist in the key. If this new value is higher than the current maximum, the sequence updates so that the next automatically generated value will be even higher. If the explicit value is lower than the current maximum, the internal sequence maximum remains unchanged.
- **Missing Values (Gaps):** `AUTO_INCREMENT` sequences frequently have gaps. If a row is deleted, explicitly updated, replaced, or if a transaction fails and rolls back, those generated values are lost and never reused. Because of this, it is recommended to use `AUTO_INCREMENT` values for chronological sorting rather than expecting a perfectly continuous, gapless numeric sequence.
- **Modifying and Viewing:** You can change the next value the sequence will use by executing an `ALTER TABLE` statement or by setting the `insert_id` server system variable. To see the last value generated by the sequence in your current session, you can use the `LAST_INSERT_ID()` function.


> [!example] 
> ```sql
> CREATE TABLE employees (
> 	id INT AUTO_INCREMENT PRIMARY KEY,
> 	name VARCHAR(100)
> );
> ```
