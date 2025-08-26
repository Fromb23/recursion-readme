# Python Classes - Bank Account

This project contains tasks to help you learn Object-Oriented Programming (OOP) in Python by building a BankAccount class step by step.

## Learning Objectives

- How to use private attributes
- How to use getters and setters in Python
- How to use properties
- How to handle validation in class methods
- How to implement class methods that interact with each other
- How to maintain transaction history

## Requirements

- All files will be interpreted/compiled on Ubuntu 20.04 LTS using python3 (version 3.8.5)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/python3`
- Your code should use the pycodestyle (version 2.8.*)
- All files must be executable
- All modules should have documentation
- All classes should have documentation
- All functions (inside and outside a class) should have documentation

## Tasks

### 0. Empty BankAccount class

Write an empty class `BankAccount` that defines a bank account:

- You are not allowed to import any module

**File:** `0-bank.py`

```python
#!/usr/bin/python3
"""Module that defines an empty BankAccount class"""


class BankAccount:
    """Empty BankAccount class"""
    pass
```

---

### 1. BankAccount with basic attributes

Write a class `BankAccount` that defines a bank account by: (based on `0-bank.py`)

- Private instance attribute: `name`
- Private instance attribute: `account_number`
- Private instance attribute: `balance` (initialized to 0)
- Instantiation with `name` and `account_number`: `def __init__(self, name, account_number):`
- You are not allowed to import any module

**File:** `1-bank.py`

---

### 2. BankAccount with getters

Write a class `BankAccount` that defines a bank account by: (based on `1-bank.py`)

- Private instance attribute: `name`
- Private instance attribute: `account_number`
- Private instance attribute: `balance` (initialized to 0)
- Instantiation with `name` and `account_number`: `def __init__(self, name, account_number):`
- Public instance method: `def get_name(self):` that returns the account holder's name
- Public instance method: `def get_account_number(self):` that returns the account number
- Public instance method: `def get_balance(self):` that returns the current balance
- You are not allowed to import any module

**File:** `2-bank.py`

---

### 3. BankAccount with setters and deposit

Write a class `BankAccount` that defines a bank account by: (based on `2-bank.py`)

- Private instance attribute: `name`
- Private instance attribute: `account_number`
- Private instance attribute: `balance` (initialized to 0)
- Instantiation with `name` and `account_number`: `def __init__(self, name, account_number):`
- Public instance method: `def get_name(self):` that returns the account holder's name
- Public instance method: `def get_account_number(self):` that returns the account number
- Public instance method: `def get_balance(self):` that returns the current balance
- Public instance method: `def set_name(self, name):` that sets the account holder's name
- Public instance method: `def set_balance(self, amount):` that sets the balance
- Public instance method: `def deposit(self, amount):` that adds money to the account
  - If `amount` is greater than 0, add it to the balance
  - If `amount` is not positive, print "Invalid deposit amount."
- You are not allowed to import any module

**File:** `3-bank.py`

---

### 4. BankAccount with withdrawal

Write a class `BankAccount` that defines a bank account by: (based on `3-bank.py`)

- Private instance attribute: `name`
- Private instance attribute: `account_number`
- Private instance attribute: `balance` (initialized to 0)
- Instantiation with `name` and `account_number`: `def __init__(self, name, account_number):`
- Public instance method: `def get_name(self):` that returns the account holder's name
- Public instance method: `def get_account_number(self):` that returns the account number
- Public instance method: `def get_balance(self):` that returns the current balance
- Public instance method: `def set_name(self, name):` that sets the account holder's name
- Public instance method: `def set_balance(self, amount):` that sets the balance
- Public instance method: `def deposit(self, amount):` that adds money to the account
  - If `amount` is greater than 0, add it to the balance
  - If `amount` is not positive, print "Invalid deposit amount."
- Public instance method: `def withdraw(self, amount):` that removes money from the account
  - If `amount` is less than or equal to the current balance, subtract it from the balance
  - If there are insufficient funds, print "Insufficient balance."
- You are not allowed to import any module

**File:** `4-bank.py`

---

### 5. BankAccount with transaction logging

Write a class `BankAccount` that defines a bank account by: (based on `4-bank.py`)

- Private instance attribute: `name`
- Private instance attribute: `account_number`
- Private instance attribute: `balance` (initialized to 0)
- Private instance attribute: `transactions` (initialized to empty list)
- Instantiation with `name` and `account_number`: `def __init__(self, name, account_number):`
- Public instance method: `def get_name(self):` that returns the account holder's name
- Public instance method: `def get_account_number(self):` that returns the account number
- Public instance method: `def get_balance(self):` that returns the current balance
- Public instance method: `def set_name(self, name):` that sets the account holder's name
- Public instance method: `def set_balance(self, amount):` that sets the balance
- Public instance method: `def deposit(self, amount):` that adds money to the account and logs the transaction
- Public instance method: `def withdraw(self, amount):` that removes money from the account and logs the transaction
- Public instance method: `def log_transaction(self, trans_type, amount):` that records transaction details
  - Creates a dictionary with "type", "amount", and "balance_after" keys
  - Appends the transaction to the transactions list
- Public instance method: `def get_transaction_log(self):` that returns the list of all transactions
- You are not allowed to import any module

**File:** `5-bank.py`

---

### 6. BankAccount with string representation

Write a class `BankAccount` that defines a bank account by: (based on `5-bank.py`)

- Private instance attribute: `name`
- Private instance attribute: `account_number`
- Private instance attribute: `balance` (initialized to 0)
- Private instance attribute: `transactions` (initialized to empty list)
- Instantiation with `name` and `account_number`: `def __init__(self, name, account_number):`
- Public instance method: `def get_name(self):` that returns the account holder's name
- Public instance method: `def get_account_number(self):` that returns the account number
- Public instance method: `def get_balance(self):` that returns the current balance
- Public instance method: `def set_name(self, name):` that sets the account holder's name
- Public instance method: `def set_balance(self, amount):` that sets the balance
- Public instance method: `def deposit(self, amount):` that adds money to the account and logs the transaction
- Public instance method: `def withdraw(self, amount):` that removes money from the account and logs the transaction
- Public instance method: `def log_transaction(self, trans_type, amount):` that records transaction details
- Public instance method: `def get_transaction_log(self):` that returns the list of all transactions
- Public instance method: `def __str__(self):` that returns a string representation of the account
  - Format: "Account Holder: [name]\nAccount Number: [account_number]\nBalance: $[balance]"
- You are not allowed to import any module

**File:** `6-bank.py`

---

## Testing

Each task should be tested with a corresponding main file. For example:

### Testing 6-bank.py

```python
#!/usr/bin/python3
BankAccount = __import__('6-bank').BankAccount

# Create a new bank account
account = BankAccount("John Doe", "123456789")

# Test deposits
account.deposit(1000)
account.deposit(500)

# Test withdrawals
account.withdraw(200)
account.withdraw(2000)  # Should show insufficient balance

# Print account details
print(account)

# Show transaction history
print("\nTransaction History:")
for transaction in account.get_transaction_log():
    print(f"{transaction['type']}: ${transaction['amount']}, Balance after: ${transaction['balance_after']}")
```

## Repository

- **GitHub repository:** `recursion-readme`
- **Directory:** `0x06-python-classes`
- **Files:** `0-bank.py`, `1-bank.py`, `2-bank.py`, `3-bank.py`, `4-bank.py`, `5-bank.py`, `6-bank.py`

## Author

This project is part of the Python Classes learning curriculum.