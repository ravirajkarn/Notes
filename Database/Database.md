---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-12 14:05::01 PM
tags:
  - Database
---
# DBMS Introduction

> [!NOTE] What is a Database(DB)?
> - Any collection of related information like Phone Book, Shopping List, Todo list, etc 
> - Databases can be stored in different way like On paper, in you mind, the computer, presentation, etc

# Database Management Systems (DBMS)
- A special software program that helps users create and maintain a database
	- Makes it easy to manage large amounts of information 
	- Handles Security
	- Backups 
	- Importing/exporting data 
	- concurrency
	- Interacts with software applications
		- Programming Languages


# C.R.U.D
# Create Read Update Delete


## Type of Databases
### 1. Relational Databases(SQL)
- Organize data into one or more tables
	- Each table has columns and rows
	- A unique key identifies each row

#### Example:
1. Student Table

| *ID# | Name   | Major     |
| ---- | ------ | --------- |
| 1    | Jack   | Biology   |
| 2    | kate   | Sociology |
| 3    | Claire | English   |
| 4    | John   | Chemistry |

2. Users Table 

| *username  | Password | Email |
| ---------- | -------- | ----- |
| jsmith22   | wordpass | ...   |
| catlover45 | apple223 | ...   |
| gamerkid   | ...      | ...   |
| giraffe    | ...      | ...   |
#### RDBMS
- Relational Database Management Systems (RDBMS)
	- Help users create and maintain a relational database
		- MySQL, Oracle, postgreSQL, mariaDB, etc.
- Structured Query Language(SQL)
	- Standardized language for interacting with RDBMS
	- Used to perform C.R.U.D operations, as well as other administrative tasks (user management, security, backup, etc).
	- Used to define table and structures 
	- SQL code used on one RDBMS is not always potable to another without modification.
### 2. Non-Relational (noSQL/ not just SQL)
- Organize data is anything but a traditional table
	- Key-value stores 
	- Documents (JSON, XML, etc)
	- Graphs
	- Flexible Tables
#### Non-RDBMS
- Non-Relational Database Management Systems (NRDBMS)
	- Help users create and maintain a non-relational database
		- mongoDB, dynamoDB, apache cassandra, firebase, etc
- Implementation Specific
	- Any non-relational database falls under this category, so there's no set language standard.
	- Most NRDBMS will implement their own language for performing C.R.U.D and administrative operations on the database.

## Concepts in DBMS
### 1. Database Queries
- Queries are requests made to the database management system for specific information
- As the database's structure become more and more complex.
- It become more difficult to get the specific pieces of information we want
- A google search is a query.
