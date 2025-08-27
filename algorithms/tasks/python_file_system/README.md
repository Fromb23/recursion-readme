# Python File System Operations

This project teaches you how to work with files and directories in Python. You'll learn to read, write, update, and delete files, work with different file formats, handle JSON data, and manage file systems programmatically.

## Learning Objectives

- How to open, read, and close files in Python
- How to write data to files using different modes
- How to handle file exceptions and errors
- How to work with file paths and directories
- How to read and write JSON data
- How to perform file operations safely with context managers
- How to work with CSV files and structured data
- How to handle binary files
- How to manage file permissions and metadata
- How to create backup and file management systems

## Requirements

- All files will be interpreted/compiled on Ubuntu 20.04 LTS using python3 (version 3.8.5)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/python3`
- Your code should use the pycodestyle (version 2.8.*)
- All files must be executable
- All modules should have documentation
- All functions should have documentation
- Handle file operations safely and close files properly
- Use appropriate exception handling for file operations

## Tasks

### 0. Basic File Reading

Write a function `read_file(filename="")` that reads a text file (UTF8) and prints it to stdout:

- Use the `with` statement to open files
- Handle file not found errors gracefully
- Print error message if file doesn't exist
- Don't raise exceptions, print error messages instead
- You are not allowed to import any module

**File:** `0-read_file.py`

**Example:**
```python
read_file("my_file_0.txt")
```

---

### 1. Write to a File

Write a function `write_file(filename="", text="")` that writes a string to a text file (UTF8):

- Use the `with` statement
- Create the file if it doesn't exist
- Overwrite the file content if it exists
- Return the number of characters written
- Handle any file writing errors
- You are not allowed to import any module

**File:** `1-write_file.py`

**Example:**
```python
nb_characters = write_file("my_first_file.txt", "This is my first file in Python\n")
print(nb_characters)
```

---

### 2. Append to a File

Write a function `append_write(filename="", text="")` that appends a string to the end of a text file (UTF8):

- Use the `with` statement
- Create the file if it doesn't exist
- Append to the end of the file if it exists
- Return the number of characters added
- Handle file errors appropriately
- You are not allowed to import any module

**File:** `2-append_write.py`

**Example:**
```python
nb_characters = append_write("file_append.txt", "This School is so cool!\n")
print(nb_characters)
```

---

### 3. JSON String to Object

Write a function `from_json_string(my_str)` that returns an object (Python data structure) represented by a JSON string:

- Use the `json` module
- Handle JSON decode errors gracefully
- Return `None` if the string is not valid JSON
- Document what types of objects can be returned
- You must import `json` module

**File:** `3-to_json_string.py`

**Example:**
```python
my_list = [1, 2, 3]
s = to_json_string(my_list)
print(s)
print(type(s))
```

---

### 4. Object to JSON String

Write a function `to_json_string(my_obj)` that returns the JSON representation of an object (string):

- Use the `json` module
- Handle objects that cannot be serialized
- Return empty string for non-serializable objects
- Support lists, dictionaries, strings, numbers, booleans, and None
- You must import `json` module

**File:** `4-from_json_string.py`

**Example:**
```python
s = '[1, 2, 3]'
my_list = from_json_string(s)
print(my_list)
print(type(my_list))
```

---

### 5. Save Object to JSON File

Write a function `save_to_json_file(my_obj, filename)` that writes an Object to a text file, using a JSON representation:

- Use the `json` module and `with` statement
- Handle file writing errors
- Handle JSON serialization errors
- Create file if it doesn't exist, overwrite if it does
- Use UTF-8 encoding
- You must import `json` module

**File:** `5-save_to_json_file.py`

**Example:**
```python
my_list = [1, 2, 3]
save_to_json_file(my_list, "my_list.json")
```

---

### 6. Load Object from JSON File

Write a function `load_from_json_file(filename)` that creates an Object from a JSON file:

- Use the `json` module and `with` statement
- Handle file not found errors
- Handle JSON decode errors
- Return `None` if file doesn't exist or contains invalid JSON
- Use UTF-8 encoding
- You must import `json` module

**File:** `6-load_from_json_file.py`

**Example:**
```python
my_list = load_from_json_file("my_list.json")
print(my_list)
print(type(my_list))
```

---

### 7. Command Line Arguments to JSON

Write a script that adds all arguments to a Python list, and saves them to a file:

- Script name: `7-add_item.py`
- Save to file: `add_item.json`
- Use functions from previous tasks (`save_to_json_file` and `load_from_json_file`)
- If file doesn't exist, create it with the arguments
- If file exists, load current content and append new arguments
- Handle command line arguments using `sys.argv`
- You must import `sys` and use functions from previous tasks

**File:** `7-add_item.py`

**Usage:**
```bash
./7-add_item.py
./7-add_item.py Best School
./7-add_item.py Best School 89 Python C
```

---

### 8. Class to JSON Dictionary

Write a function `class_to_json(obj)` that returns the dictionary description with simple data structure for JSON serialization of an object:

- `obj` is an instance of a Class
- All attributes of the obj Class are serializable: list, dictionary, string, integer and boolean
- Return a dictionary containing all serializable attributes
- Handle nested objects appropriately
- You are not allowed to import any module

**File:** `8-class_to_json.py`

**Example:**
```python
class MyClass:
    def __init__(self, name):
        self.name = name
        self.number = 0

m = MyClass("John")
m.number = 89
print(class_to_json(m))
```

---

### 9. Student Class with JSON Methods

Write a class `Student` that defines a student:

- Public instance attributes: `first_name`, `last_name`, `age`
- Instantiation: `def __init__(self, first_name, last_name, age):`
- Public method: `def to_json(self):` that retrieves a dictionary representation of a Student instance
- Use the function from task 8
- You are not allowed to import any module

**File:** `9-student.py`

**Example:**
```python
students = [Student("John", "Doe", 23), Student("Bob", "Dylan", 27)]

for student in students:
    j_student = student.to_json()
    print(j_student)
```

---

### 10. Student Class with Attribute Filter

Write a class `Student` based on `9-student.py`:

- Add public method: `def to_json(self, attrs=None):` that retrieves a dictionary representation of a Student instance
- If `attrs` is a list of strings, only attribute names contained in this list are retrieved
- Otherwise, all attributes are retrieved
- Handle invalid attribute names gracefully
- You are not allowed to import any module

**File:** `10-student.py`

**Example:**
```python
student_1 = Student("John", "Doe", 23)
j_student_1 = student_1.to_json()
j_student_2 = student_1.to_json(['first_name', 'age'])
j_student_3 = student_1.to_json(['middle_name', 'age'])
```

---

### 11. Student Class with Reload from JSON

Write a class `Student` based on `10-student.py`:

- Add public method: `def reload_from_json(self, json):` that replaces all attributes of the Student instance
- `json` is a dictionary containing attribute names and values
- Only update attributes that exist in the dictionary
- Handle missing attributes gracefully
- Validate data types appropriately
- You are not allowed to import any module

**File:** `11-student.py`

**Example:**
```python
student_1 = Student("John", "Doe", 23)
j_student_1 = student_1.to_json()
student_1.reload_from_json({'first_name': "Bob", 'age': 89})
```

---

### 12. Pascal's Triangle to File

Write a function `pascal_triangle(n)` that returns a list of lists of integers representing Pascal's triangle of n:

- Add function `save_pascal_triangle(n, filename)` that generates Pascal's triangle and saves it to a JSON file
- Handle edge cases (n <= 0)
- Use previous JSON functions to save the triangle
- Include proper error handling
- You must import `json` module

**File:** `12-pascal_triangle.py`

**Example:**
```python
triangle = pascal_triangle(5)
save_pascal_triangle(5, "pascal_5.json")
```

---

### 13. Search and Update in JSON File

Write a function `search_replace_in_file(filename, search_string, replace_string)` that searches and replaces text in a file:

- Read file content
- Replace all occurrences of search_string with replace_string
- Write back to the same file
- Handle file errors appropriately
- Use UTF-8 encoding
- Return the number of replacements made
- You are not allowed to import any module

**File:** `13-search_replace.py`

**Example:**
```python
replacements = search_replace_in_file("replace_me.txt", "Python", "C")
print(f"Made {replacements} replacements")
```

---

### 14. Log File Parser

Write a function `parse_log_file(filename)` that reads a log file and returns statistics:

- Parse lines in format: "IP - [timestamp] method path status size"
- Return dictionary with statistics: total_requests, status_codes, total_size, unique_ips
- Handle malformed lines gracefully
- Use efficient file reading for large files
- Support different log formats
- You are not allowed to import any module except `re` for regex

**File:** `14-log_parser.py`

**Example:**
```python
stats = parse_log_file("access.log")
print(f"Total requests: {stats['total_requests']}")
```

---

### 15. Advanced File Manager

Write a class `FileManager` that provides advanced file operations:

- Method: `def copy_file(self, source, destination):` - Copy file with metadata
- Method: `def move_file(self, source, destination):` - Move/rename file
- Method: `def delete_file(self, filename):` - Delete file safely
- Method: `def get_file_info(self, filename):` - Get file size, modification time, permissions
- Method: `def create_backup(self, filename):` - Create backup with timestamp
- Method: `def list_directory(self, path):` - List directory contents with details
- Handle all file operations errors appropriately
- Use context managers where appropriate
- You must import `os`, `shutil`, and `datetime` modules

**File:** `15-file_manager.py`

**Example:**
```python
fm = FileManager()
fm.copy_file("source.txt", "backup.txt")
info = fm.get_file_info("source.txt")
print(info)
```

---

## Testing

Each task should be tested to ensure proper functionality:

### Testing Example for Task 5

```python
#!/usr/bin/python3
save_to_json_file = __import__('5-save_to_json_file').save_to_json_file

filename = "my_list.json"
my_list = [1, 2, 3]
save_to_json_file(my_list, filename)

filename = "my_dict.json"
my_dict = { 
    'id': 12,
    'name': "John",
    'places': [ "San Francisco", "Tokyo" ],
    'is_active': True,
    'info': {
        'age': 36,
        'average': 3.14
    }
}
save_to_json_file(my_dict, filename)

try:
    filename = "my_set.json"
    my_set = { 132, 3 }
    save_to_json_file(my_set, filename)
except Exception as e:
    print("[{}] {}".format(e.__class__.__name__, e))
```

## Repository

- **GitHub repository:** `recursion-readme`
- **Directory:** `0x0B-python-input_output`
- **Files:** `0-read_file.py`, `1-write_file.py`, `2-append_write.py`, `3-to_json_string.py`, `4-from_json_string.py`, `5-save_to_json_file.py`, `6-load_from_json_file.py`, `7-add_item.py`, `8-class_to_json.py`, `9-student.py`, `10-student.py`, `11-student.py`, `12-pascal_triangle.py`, `13-search_replace.py`, `14-log_parser.py`, `15-file_manager.py`

## Prerequisites

You should have completed:
- Basic Python programming concepts
- Python Classes (0x06-python-classes)
- More Classes (0x07-python-more_classes)

## Important Notes

- Always use the `with` statement when working with files
- Handle exceptions appropriately - don't let your programs crash
- Use UTF-8 encoding for text files
- Be careful with file permissions and existing files
- Test with both existing and non-existing files
- Consider memory usage when working with large files
- Always validate input data before writing to files

## Author

This project is part of the Python File System Operations learning curriculum.