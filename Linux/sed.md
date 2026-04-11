---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-09-18 11:08::26 AM
tags:
  - command
  - Linux
---
### **Sed Command Syntax:**

The **basic syntax** for using the **SED command** in Linux is:

**`sed [OPTIONS] 'COMMAND' [INPUTFILE...]`**

where,

- **'OPTIONS':** These are optional flags that modify the behavior of the sed command.
- **'COMMAND'**: This defines the command or sequence of commands to execute on the input file.
- **'INPUTFILE'**: One or more input files to be processed.

## Commonly Used SED Command Options

Below are some of the most frequently used **SED** [**command**](https://www.geeksforgeeks.org/linux-unix/linux-commands/) **options,** let's check them out:

| Option   | Description                           |
| -------- | ------------------------------------- |
| **`-i`** | Edit the file in-place (overwrite)    |
| **`-n`** | Suppress automatic printing of lines. |
| **`-e`** | Allows multiple commands.             |
| **`-f`** | Reads sed commands from a file.       |
| **`-r`** | Use extended regular expressions.     |

## **Practical Examples of SED Command Usage**

Here are some basic **SED commands** that will help you get started with text manipulation.

Consider the below text file as an input.

**`cat > geekfile.txt`**

```text
unix is great os. unix is opensource. unix is free os.
learn operating system.
unix linux which one you choose.
unix is easy to learn.unix is a multiuser os.Learn unix .unix is a powerful.
```
### **1. Sample Commands**

Replacing or substituting string: Sed command is mostly used to replace the text in a file. The below simple sed command replaces the word "unix" with "linux" in the file.

**`sed 's/unix/linux/' geekfile.txt`**

**Output:**
```text
linux is great os. unix is opensource. unix is free os.
learn operating system.
linux linux which one you choose.
linux is easy to learn.unix is a multiuser os.Learn unix .unix is a powerful.
```
Here the **"s"** specifies the substitution operation. The **"/"** are delimiters. The **"unix"** is the search pattern and the **"linux"** is the replacement string. By default, the sed command replaces the first occurrence of the pattern in each line and it won't replace the second, third...occurrence in the line.

### **2. Replacing the nth Occurrence of a Pattern in a Line**

To replace only the **nth occurance** of a word in a line, use the following syntax:

 `sed 's/old_word/new_word/n' filename`

Use the '/1', '/2' etc. flags to replace the first, second occurrence of a pattern in a line. The below command replaces the second occurrence of the word **"unix"** with **"linux"** in a line.

**`sed 's/unix/linux/2' geekfile.txt`**

**Output:**
```text
unix is great os. linux is opensource. unix is free os.
learn operating system.
unix linux which one you choose.
unix is easy to learn.linux is a multiuser os.Learn unix .unix is a powerful.
```
### **3. Replacing all the Occurrence of the Pattern in a Line**

Here, we will use the **g** flag to replace **all the occurances** of a pattern in a line. Let's check out the syntax below:

`sed 's/old_word/new_word/g' filename`

The substitute flag /g (global replacement) specifies the sed command to replace all the occurrences of the string in the line.

**`sed 's/unix/linux/g' geekfile.txt`**

**Output:**
```text
linux is great os. linux is opensource. linux is free os.
learn operating system.
linux linux which one you choose.
linux is easy to learn.linux is a multiuser os.Learn linux .linux is a powerful.
```
### **4. Replacing from nth Occurrence to all Occurrences in a Line**

Use the combination of /1, /2 etc and /g to replace all the patterns from the nth occurrence of a pattern in a line. The following sed command replaces the third, fourth, fifth... **"unix"** word with **"linux"** word in a line.

**`sed 's/unix/linux/3g' geekfile.txt`**

**Output:**

```text
unix is great os. unix is opensource. linux is free os.
learn operating system.
unix linux which one you choose.
unix is easy to learn.unix is a multiuser os.Learn linux .linux is a powerful.
```
### **5. Parenthesize First Character of Each Word**

This sed example prints the first character of every word in parenthesis.

**`echo "Welcome To The Geek Stuff" | sed 's/\(\b[A-Z]\)/\(\1\)/g'`**

**Output:**

```text
(W)elcome (T)o (T)he (G)eek (S)tuff
```
### **6. Replacing String on a Specific Line Number**

You can restrict the sed command to replace the string on a specific line number. An example is

**`sed '3 s/unix/linux/' geekfile.txt`**

**Output:**

```text
unix is great os. unix is opensource. unix is free os.
learn operating system.
linux linux which one you choose.
unix is easy to learn.unix is a multiuser os.Learn unix .unix is a powerful.
```
The above sed command replaces the string only on the third line.

### **7. Duplicating the Replaced Line with /p flag**

The **/p** print flag prints the replaced line twice on the terminal. If a line does not have the search pattern and is not replaced, then the **/p** prints that line only once.

**`sed 's/unix/linux/p' geekfile.txt`**

**Output:**

```text
linux is great os. unix is opensource. unix is free os.
linux is great os. unix is opensource. unix is free os.
learn operating system.
linux linux which one you choose.
linux linux which one you choose.
linux is easy to learn.unix is a multiuser os.Learn unix .unix is a powerful.
linux is easy to learn.unix is a multiuser os.Learn unix .unix is a powerful.
```
### **8. Printing Only the Replaced Lines**

Use the -n option along with the /p print flag to display only the replaced lines. Here the **-n** option suppresses the duplicate rows generated by the /p flag and prints the replaced lines only one time.

**`sed -n 's/unix/linux/p' geekfile.txt`**

**Output:**

```text
linux is great os. unix is opensource. unix is free os.
linux linux which one you choose.
linux is easy to learn.unix is a multiuser os.Learn unix .unix is a powerful.
```
If you use -n alone without /p, then the sed does not print anything.

### **9. Replacing String on a Range of Lines**

You can specify a range of line numbers to the sed command for replacing a string.

**`sed '1,3 s/unix/linux/' geekfile.txt`**

**Output:**

```text
linux is great os. unix is opensource. unix is free os.
learn operating system.
linux linux which one you choose.
unix is easy to learn.unix is a multiuser os.Learn unix .unix is a powerful.
```
Here the sed command replaces the lines with range from 1 to 3. Another example is

**`sed '2,$ s/unix/linux/' geekfile.txt`**

**Output:**

```text
unix is great os. unix is opensource. unix is free os.
learn operating system.
linux linux which one you choose.
linux is easy to learn.unix is a multiuser os.Learn unix .unix is a powerful
```
Here $ indicates the last line in the file. So the sed command replaces the text from second line to last line in the file.

### **10. Deleting Lines from a Particular File**

SED command can also be used for deleting lines from a particular file. SED command is used for performing deletion operation without even opening the file

**Examples:**
#### 1. To Delete a particular line say n in this example

**Syntax:**
`sed 'nd' filename.txt`

**Example:**
`sed '5d' filename.txt`

#### 2. To Delete a last line

**Syntax:**
`sed '$d' filename.txt`

#### 3. To Delete line from range x to y

**Syntax:**
`sed 'x,yd' filename.txt`

**Example:**
`sed '3,6d' filename.txt`

#### 4. To Delete from nth to last line

**Syntax:**
`sed 'nth,$d' filename.txt`

**Example:**
`sed '12,$d' filename.txt`

#### 5. To Delete pattern matching line

**Syntax:**
`sed '/pattern/d' filename.txt`

**Example:**
`sed '/abc/d' filename.txt`
