---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-07-19 09:44::50 AM
tags:
  - python
  - sqlite
---
# sqlite3

First, we need to create a new database and open a database connection to allow `sqlite3` to work with it. Call [`sqlite3.connect()`](https://docs.python.org/3/library/sqlite3.html#sqlite3.connect "sqlite3.connect") to create a connection to the database `tutorial.db` in the current working directory, implicitly creating it if it does not exist:
```python
import sqlite3
con = sqlite3.connect("tutorial.db")
```
The returned [`Connection`](https://docs.python.org/3/library/sqlite3.html#sqlite3.Connection "sqlite3.Connection") object `con` represents the connection to the on-disk database.

In order to execute SQL statements and fetch results from SQL queries, we will need to use a database cursor. Call [`con.cursor()`](https://docs.python.org/3/library/sqlite3.html#sqlite3.Connection.cursor "sqlite3.Connection.cursor") to create the [`Cursor`](https://docs.python.org/3/library/sqlite3.html#sqlite3.Cursor "sqlite3.Cursor"):
```python 
cur = con.cursor()
```

Now that we’ve got a database connection and a cursor, we can create a database table `movie` with columns for title, release year, and review score. For simplicity, we can just use column names in the table declaration – thanks to the [flexible typing](https://www.sqlite.org/flextypegood.html) feature of SQLite, specifying the data types is optional. Execute the `CREATE TABLE` statement by calling [`cur.execute(...)`](https://docs.python.org/3/library/sqlite3.html#sqlite3.Cursor.execute "sqlite3.Cursor.execute"):
```python
cur.execute("CREATE TABLE movie(title, year, score)")
```

We can verify that the new table has been created by querying the `sqlite_master` table built-in to SQLite, which should now contain an entry for the `movie` table definition (see [The Schema Table](https://www.sqlite.org/schematab.html) for details). Execute that query by calling [`cur.execute(...)`](https://docs.python.org/3/library/sqlite3.html#sqlite3.Cursor.execute "sqlite3.Cursor.execute"), assign the result to `res`, and call [`res.fetchone()`](https://docs.python.org/3/library/sqlite3.html#sqlite3.Cursor.fetchone "sqlite3.Cursor.fetchone") to fetch the resulting row:

```python
res = cur.execute("SELECT name FROM sqlite_master")
res.fetchone()
('movie',)
```


close the database connection once it is no longer in use by calling the `close()` method of the `Connection` object:
```python 
conn.close()
```

To catch an error if it occurs during database creation, you can wrap the code inside a `try...except` statement as follows:

```python
import sqlite3  
try:     
	with sqlite3.connect("my.db") as conn:         
		# interact with database         
		pass 
except sqlite3.OperationalError as e:     
	print("Failed to open database:", e)
```
