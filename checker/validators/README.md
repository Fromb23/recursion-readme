# Validators

This directory contains task-specific validators used by the main `checker` program to validate Python scripts before execution.

## 🧪 Purpose

Each validator enforces strict formatting and implementation rules specific to the task, such as:

- Shebang presence
- Correct function signature
- Presence of docstrings
- Disallowing forbidden constructs (e.g., loops in recursion)
- Matching the expected output (when applicable)

## 📁 Structure

validators/
├── validators.h # Common header for all validators
├── validators.c # Dispatches to appropriate validator based on task name
├── recursion_validator.c # Validator for the "recursion" task
├── factorial_validator.c # Validator for the "factorial" task

## ✅ How It Works

The main checker calls `validate_task()` from `validators/validators.c`, which dispatches to the appropriate function depending on `task->task_name`.

```c
int validate_task(Task *task);
```

For example:

recursion calls validate_recursion_file(filepath)

factorial calls validate_factorial_file(filepath)

Each validator performs its own logic and returns:

0 on success

1 on failure (along with a descriptive error via typewrite())

📌 Rules Enforced
Recursion Task
File must start with #!/usr/bin/env python3

Second line must be blank

Third line must be: def recursion(n):

Must contain a docstring immediately after the function

No for or while loops allowed

Factorial Task
Same as recursion above, except:

Function must be: def factorial(n):

Output must match expected values

No loops

✍️ Notes
Validators are independent. Failing one will skip output checking.

New tasks must have a corresponding validator or the system will raise an error.

typewriter/typewriter.h is used for animated, readable error messages.
