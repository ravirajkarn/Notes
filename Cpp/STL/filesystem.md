---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2025-11-26 02:33::17 AM
tags:
  - Cpp
  - STL
  - Header
---
# [\<filesystem>](https://en.cppreference.com/w/cpp/header/filesystem)
It is stander file system management you could say that it handle path or file like is this file is available or this path is present.
### Classes
| Defined in header [\<filesystem>](https://en.cppreference.com/w/cpp/header/filesystem.html "cpp/header/filesystem")                                                         |                                                                                                                      |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| Defined in namespace `std::filesystem`                                                                                                                                      |                                                                                                                      |
| [path](https://en.cppreference.com/w/cpp/filesystem/path.html "cpp/filesystem/path")<br><br>(C++17)                                                                         | represents a path  <br>(class)                                                                                       |
| [filesystem_error](https://en.cppreference.com/w/cpp/filesystem/filesystem_error.html "cpp/filesystem/filesystem error")<br>(C++17)                                         | an exception thrown on file system errors  <br>(class)                                                               |
| [directory_entry](https://en.cppreference.com/w/cpp/filesystem/directory_entry.html "cpp/filesystem/directory entry")<br><br>(C++17)                                        | a directory entry  <br>(class)                                                                                       |
| [directory_iterator](https://en.cppreference.com/w/cpp/filesystem/directory_iterator.html "cpp/filesystem/directory iterator")<br><br>(C++17)                               | an iterator to the contents of the directory  <br>(class)                                                            |
| [recursive_directory_iterator](https://en.cppreference.com/w/cpp/filesystem/recursive_directory_iterator.html "cpp/filesystem/recursive directory iterator")<br><br>(C++17) | an iterator to the contents of a directory and its subdirectories  <br>(class)                                       |
| [file_status](https://en.cppreference.com/w/cpp/filesystem/file_status.html "cpp/filesystem/file status")<br><br>(C++17)                                                    | represents file type and permissions  <br>(class)                                                                    |
| [space_info](https://en.cppreference.com/w/cpp/filesystem/space_info.html "cpp/filesystem/space info")<br><br>(C++17)                                                       | information about free and available space on the filesystem  <br>(class)                                            |
| [file_type](https://en.cppreference.com/w/cpp/filesystem/file_type.html "cpp/filesystem/file type")<br><br>(C++17)                                                          | the type of a file  <br>(enum)                                                                                       |
| [perms](https://en.cppreference.com/w/cpp/filesystem/perms.html "cpp/filesystem/perms")<br><br>(C++17)                                                                      | identifies file system permissions  <br>(enum)                                                                       |
| [perm_options](https://en.cppreference.com/w/cpp/filesystem/perm_options.html "cpp/filesystem/perm options")<br><br>(C++17)                                                 | specifies semantics of permissions operations  <br>(enum)                                                            |
| [copy_options](https://en.cppreference.com/w/cpp/filesystem/copy_options.html "cpp/filesystem/copy options")<br><br>(C++17)                                                 | specifies semantics of copy operations  <br>(enum)                                                                   |
| [directory_options](https://en.cppreference.com/w/cpp/filesystem/directory_options.html "cpp/filesystem/directory options")<br><br>(C++17)                                  | options for iterating directory contents  <br>(enum)                                                                 |
| [file_time_type](https://en.cppreference.com/w/cpp/filesystem/file_time_type.html "cpp/filesystem/file time type")<br><br>(C++17)                                           | represents file time values  <br>(typedef)                                                                           |

### Non-member functionsDefined in header 
| [\<filesystem>](https://en.cppreference.com/w/cpp/header/filesystem.html "cpp/header/filesystem")                                                                                                                                                                    |                                                                                                                      |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| Defined in namespace `std::filesystem`                                                                                                                                                                                                                               |                                                                                                                      |
| [absolute](https://en.cppreference.com/w/cpp/filesystem/absolute.html "cpp/filesystem/absolute")<br><br>(C++17)                                                                                                                                                      | composes an absolute path  <br>(function)                                                                            |
| [canonical](https://en.cppreference.com/w/cpp/filesystem/canonical.html "cpp/filesystem/canonical")<br>[weakly_canonical](https://en.cppreference.com/w/cpp/filesystem/canonical.html "cpp/filesystem/canonical")<br>(C++17)                                         | composes a canonical path  <br>(function)                                                                            |
| [relative](https://en.cppreference.com/w/cpp/filesystem/relative.html "cpp/filesystem/relative")<br>[proximate](https://en.cppreference.com/w/cpp/filesystem/relative.html "cpp/filesystem/relative")<br>(C++17)                                                     | composes a relative path  <br>(function)                                                                             |
| [copy](https://en.cppreference.com/w/cpp/filesystem/copy.html "cpp/filesystem/copy")<br><br>(C++17)                                                                                                                                                                  | copies files or directories  <br>(function)                                                                          |
| [copy_file](https://en.cppreference.com/w/cpp/filesystem/copy_file.html "cpp/filesystem/copy file")<br><br>(C++17)                                                                                                                                                   | copies file contents  <br>(function)                                                                                 |
| [copy_symlink](https://en.cppreference.com/w/cpp/filesystem/copy_symlink.html "cpp/filesystem/copy symlink")<br><br>(C++17)                                                                                                                                          | copies a symbolic link  <br>(function)                                                                               |
| [create_directory](https://en.cppreference.com/w/cpp/filesystem/create_directory.html "cpp/filesystem/create directory")(C++17)<br>[create_directories](https://en.cppreference.com/w/cpp/filesystem/create_directory.html "cpp/filesystem/create directory")(C++17) | creates new directory  <br>(function)                                                                                |
| [create_hard_link](https://en.cppreference.com/w/cpp/filesystem/create_hard_link.html "cpp/filesystem/create hard link")<br><br>(C++17)                                                                                                                              | creates a hard link  <br>(function)                                                                                  |
| [create_symlink](https://en.cppreference.com/w/cpp/filesystem/create_symlink.html "cpp/filesystem/create symlink")(C++17)<br>[create_directory_symlink](https://en.cppreference.com/w/cpp/filesystem/create_symlink.html "cpp/filesystem/create symlink")(C++17)     | creates a symbolic link  <br>(function)                                                                              |
| [current_path](https://en.cppreference.com/w/cpp/filesystem/current_path.html "cpp/filesystem/current path")<br><br>(C++17)                                                                                                                                          | returns or sets the current working directory  <br>(function)                                                        |
| [exists](https://en.cppreference.com/w/cpp/filesystem/exists.html "cpp/filesystem/exists")<br><br>(C++17)                                                                                                                                                            | checks whether path refers to existing file system object  <br>(function)                                            |
| [equivalent](https://en.cppreference.com/w/cpp/filesystem/equivalent.html "cpp/filesystem/equivalent")<br><br>(C++17)                                                                                                                                                | checks whether two paths refer to the same file system object  <br>(function)                                        |
| [file_size](https://en.cppreference.com/w/cpp/filesystem/file_size.html "cpp/filesystem/file size")<br><br>(C++17)                                                                                                                                                   | returns the size of a file  <br>(function)                                                                           |
| [hard_link_count](https://en.cppreference.com/w/cpp/filesystem/hard_link_count.html "cpp/filesystem/hard link count")<br><br>(C++17)                                                                                                                                 | returns the number of hard links referring to the specific file  <br>(function)                                      |
| [last_write_time](https://en.cppreference.com/w/cpp/filesystem/last_write_time.html "cpp/filesystem/last write time")<br><br>(C++17)                                                                                                                                 | gets or sets the time of the last data modification  <br>(function)                                                  |
| [permissions](https://en.cppreference.com/w/cpp/filesystem/permissions.html "cpp/filesystem/permissions")<br><br>(C++17)                                                                                                                                             | modifies file access permissions  <br>(function)                                                                     |
| [read_symlink](https://en.cppreference.com/w/cpp/filesystem/read_symlink.html "cpp/filesystem/read symlink")<br><br>(C++17)                                                                                                                                          | obtains the target of a symbolic link  <br>(function)                                                                |
| [remove](https://en.cppreference.com/w/cpp/filesystem/remove.html "cpp/filesystem/remove")(C++17)<br>[remove_all](https://en.cppreference.com/w/cpp/filesystem/remove.html "cpp/filesystem/remove")(C++17)                                                           | removes a file or empty directory  <br>removes a file or directory and all its contents, recursively  <br>(function) |
| [rename](https://en.cppreference.com/w/cpp/filesystem/rename.html "cpp/filesystem/rename")<br><br>(C++17)                                                                                                                                                            | moves or renames a file or directory  <br>(function)                                                                 |
| [resize_file](https://en.cppreference.com/w/cpp/filesystem/resize_file.html "cpp/filesystem/resize file")<br><br>(C++17)                                                                                                                                             | changes the size of a regular file by truncation or zero-fill  <br>(function)                                        |
| [space](https://en.cppreference.com/w/cpp/filesystem/space.html "cpp/filesystem/space")<br><br>(C++17)                                                                                                                                                               | determines available free space on the file system  <br>(function)                                                   |
| [status](https://en.cppreference.com/w/cpp/filesystem/status.html "cpp/filesystem/status")(C++17)<br>[symlink_status](https://en.cppreference.com/w/cpp/filesystem/status.html "cpp/filesystem/status")(C++17)                                                       | determines file attributes  <br>determines file attributes, checking the symlink target  <br>(function)              |
| [temp_directory_path](https://en.cppreference.com/w/cpp/filesystem/temp_directory_path.html "cpp/filesystem/temp directory path")<br><br>(C++17)                                                                                                                     | returns a directory suitable for temporary files  <br>(function)                                                     |

##### File types
| [is_block_file](https://en.cppreference.com/w/cpp/filesystem/is_block_file.html "cpp/filesystem/is block file")<br><br>(C++17)             | checks whether the given path refers to block device  <br>(function)               |
| ------------------------------------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------- |
| [is_character_file](https://en.cppreference.com/w/cpp/filesystem/is_character_file.html "cpp/filesystem/is character file")<br><br>(C++17) | checks whether the given path refers to a character device  <br>(function)         |
| [is_directory](https://en.cppreference.com/w/cpp/filesystem/is_directory.html "cpp/filesystem/is directory")<br><br>(C++17)                | checks whether the given path refers to a directory  <br>(function)                |
| [is_empty](https://en.cppreference.com/w/cpp/filesystem/is_empty.html "cpp/filesystem/is empty")<br><br>(C++17)                            | checks whether the given path refers to an empty file or directory  <br>(function) |
| [is_fifo](https://en.cppreference.com/w/cpp/filesystem/is_fifo.html "cpp/filesystem/is fifo")<br><br>(C++17)                               | checks whether the given path refers to a named pipe  <br>(function)               |
| [is_other](https://en.cppreference.com/w/cpp/filesystem/is_other.html "cpp/filesystem/is other")<br><br>(C++17)                            | checks whether the argument refers to an _other_ file  <br>(function)              |
| [is_regular_file](https://en.cppreference.com/w/cpp/filesystem/is_regular_file.html "cpp/filesystem/is regular file")<br><br>(C++17)       | checks whether the argument refers to a regular file  <br>(function)               |
| [is_socket](https://en.cppreference.com/w/cpp/filesystem/is_socket.html "cpp/filesystem/is socket")<br><br>(C++17)                         | checks whether the argument refers to a named IPC socket  <br>(function)           |
| [is_symlink](https://en.cppreference.com/w/cpp/filesystem/is_symlink.html "cpp/filesystem/is symlink")<br><br>(C++17)                      | checks whether the argument refers to a symbolic link  <br>(function)              |
| [status_known](https://en.cppreference.com/w/cpp/filesystem/status_known.html "cpp/filesystem/status known")<br><br>(C++17)                | checks whether file status is known                                                |

Key features and functionalities:
- **Path manipulation:** 
    The `std::filesystem::path` class represents file system paths and offers methods for manipulating path components, such as extracting filenames, extensions, and parent directories.
    
- **File and directory operations:**
    - `create_directory()` and `create_directories()`: Create single or multiple nested directories.
    - `remove()` and `remove_all()`: Delete files or directories (including their contents recursively).
    - `copy()`, `copy_file()`, `copy_symlink()`: Copy files, directories, or symbolic links.
    - `rename()`: Rename or move files and directories.
    
- **Querying file system information:**
    - `exists()`: Check if a path refers to an existing file or directory.
    - `is_directory()`, `is_regular_file()`, `is_symlink()`: Determine the type of a file system entry.
    - `file_size()`: Get the size of a regular file.
    - `last_write_time()`: Retrieve the last modification time of a file or directory.
    - `permissions()`: Get or set file/directory permissions.
    - `current_path()`: Get or set the current working directory.
    
- **Directory iteration:**
    - `directory_iterator`: Iterates non-recursively through the entries of a single directory.
    - `recursive_directory_iterator`: Iterates recursively through a directory and its subdirectories.
    
- **Error handling:** 
    Most functions have overloads that accept an `std::error_code` parameter to handle errors gracefully without throwing exceptions.

Example Usage (creating a directory and listing its contents):
```cpp
#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::path myDirectory = "my_new_directory";

    // Create a directory
    if (std::filesystem::create_directory(myDirectory)) {
        std::cout << "Directory created: " << myDirectory << std::endl;
    } else {
        std::cout << "Failed to create directory or it already exists." << std::endl;
    }

    // List contents of the current directory
    std::cout << "\nContents of current directory:" << std::endl;
    for (const auto& entry : std::filesystem::directory_iterator(".")) {
        std::cout << entry.path().filename() << std::endl;
    }

    // Clean up (remove the created directory)
    std::filesystem::remove(myDirectory); 

    return 0;
}
```