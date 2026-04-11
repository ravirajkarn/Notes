---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-24 15:28::36 PM
tags:
  - Cpp
  - Index
  - Database
---

# SQLite

## Data type:
### Numeric Data Types:
| Data Type     | Description                                            | Range                                                   |
| ------------- | ------------------------------------------------------ | ------------------------------------------------------- |
| BIGINT        | Large integer numbers                                  | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| INT           | Standard integer values                                | -2,147,483,648 to 2,147,483,647                         |
| SMALLINT      | Small integers                                         | -32,768 to 32,767                                       |
| TINYINT       | Very small integers                                    | 0 to 255                                                |
| DECIMAL       | Exact fixed-point numbers (e.g., for financial values) | -10^38 + 1 to 10^38 - 1                                 |
| NUMERIC       | Similar to DECIMAL, used for precision data            | -10^38 + 1 to 10^38 - 1                                 |
|  FLOAT  | Approximate numeric values                             | -1.79E+308 to 1.79E+308                                 |
|  REAL   | Similar to FLOAT, but with less precision              | -3.40E+38 to 3.40E+38                                   |
### Character and String Data Types
|  Data Type     |  Description                                                                                          |
| -------------------- | ----------------------------------------------------------------------------------------------------------- |
|  Char          | The maximum length of 8000 characters. (Fixed-Length non-Unicode Characters)                                |
|  Varchar       | The maximum length of 8000 characters. (Variable-Length non-Unicode Characters)                             |
|  Varchar(max)  | The maximum length of  2^31 - 1  characters(SQL Server 2005 only). (Variable Length non-Unicode data) |
|  Text          | The maximum length of 2,127,483,647 characters(Variable Length non-Unicode data)                            |
### Date and Time Data Type
|  Data Type  |  Description                                                    |  Storage Size  |
| ----------------- | --------------------------------------------------------------------- | -------------------- |
|  DATE       | stores the data of date (year, month, day)                            | 3 Bytes              |
|  TIME       | stores the data of time (hour, minute,second)                         | 3 Bytes              |
|  DATETIME   | store both the data and time (year, month, day, hour, minute, second) | 8 Bytes              |
Other data type are:
- Boolean: denoted by `BIT`
- XML Data Type: denoted by `XML`
- Binary Data type
- Unicode character
- JSON Data Type: denoted by `JSONB`