# More Python Classes - Advanced Banking System

This project builds upon the basic BankAccount class to explore advanced Object-Oriented Programming concepts in Python. You should have completed the basic BankAccount tasks before attempting these advanced concepts.

## Learning Objectives

- How to use Python properties (@property decorator)
- How to implement data validation using property setters
- How to use class attributes vs instance attributes
- How to implement class methods and static methods
- How to use inheritance to create specialized classes
- How to override methods in child classes
- How to implement multiple inheritance
- How to work with abstract base classes
- How to implement operator overloading
- How to create comprehensive banking system with multiple account types

## Requirements

- All files will be interpreted/compiled on Ubuntu 20.04 LTS using python3 (version 3.8.5)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/python3`
- Your code should use the pycodestyle (version 2.8.*)
- All files must be executable
- All modules should have documentation
- All classes should have documentation
- All functions (inside and outside a class) should have documentation
- You must have completed the basic BankAccount tasks (0-6) before starting these

## Advanced Tasks

### 0. BankAccount with Properties

Write a class `BankAccount` that uses properties for data access and validation:

- Private instance attribute: `_name`
- Private instance attribute: `_account_number`
- Private instance attribute: `_balance` (initialized to 0)
- Private instance attribute: `_transactions` (initialized to empty list)
- Property `name` with getter and setter:
  - Getter returns the account holder's name
  - Setter validates that name is a non-empty string, raises `ValueError` if invalid
- Property `balance` with getter only (read-only property)
- Property `account_number` with getter only (read-only property)
- Instantiation: `def __init__(self, name, account_number):`
- Public methods: `deposit`, `withdraw`, `log_transaction`, `get_transaction_log`, `__str__`
- You are not allowed to import any module

**File:** `0-bank.py`

---

### 1. BankAccount with Class Attributes and Methods

Write a class `BankAccount` that includes class attributes and methods: (based on `0-bank.py`)

- Class attribute: `bank_name = "PyBank"`
- Class attribute: `total_accounts = 0` (tracks number of accounts created)
- Class attribute: `interest_rate = 0.02` (2% annual interest)
- All previous instance attributes and properties
- Class method: `@classmethod def get_bank_info(cls):` returns bank name and total accounts
- Class method: `@classmethod def set_interest_rate(cls, rate):` sets the interest rate for all accounts
- Static method: `@staticmethod def validate_amount(amount):` validates if amount is positive number
- Instance method: `def apply_interest(self):` adds interest to the account balance
- Update `__init__` to increment `total_accounts`
- Update `deposit` and `withdraw` to use `validate_amount`
- You are not allowed to import any module

**File:** `1-bank.py`

---

### 2. SavingsAccount - Basic Inheritance

Write a class `SavingsAccount` that inherits from `BankAccount`: (based on `1-bank.py`)

- Inherits from `BankAccount`
- Additional instance attribute: `_minimum_balance = 100`
- Property `minimum_balance` with getter and setter
- Override `withdraw` method to ensure balance never goes below minimum balance
- If withdrawal would cause balance to go below minimum, print "Withdrawal denied. Minimum balance required: $[minimum_balance]"
- Additional method: `def get_account_type(self):` returns "Savings Account"
- Override `__str__` to include account type and minimum balance requirement
- You are not allowed to import any module

**File:** `2-bank.py`

---

### 3. CheckingAccount with Overdraft

Write a class `CheckingAccount` that inherits from `BankAccount`: (based on `1-bank.py`)

- Inherits from `BankAccount`
- Additional instance attribute: `_overdraft_limit = 500`
- Property `overdraft_limit` with getter and setter
- Override `withdraw` method to allow overdraft up to the limit
- If withdrawal exceeds balance + overdraft limit, print "Withdrawal denied. Overdraft limit exceeded."
- Additional method: `def get_overdraft_available(self):` returns available overdraft amount
- Additional method: `def get_account_type(self):` returns "Checking Account"
- Override `__str__` to include account type and available overdraft
- You are not allowed to import any module

**File:** `3-bank.py`

---

### 4. BusinessAccount with Transaction Fees

Write a class `BusinessAccount` that inherits from `CheckingAccount`: (based on `3-bank.py`)

- Inherits from `CheckingAccount`
- Additional class attribute: `transaction_fee = 2.50`
- Additional instance attribute: `_monthly_transaction_limit = 100`
- Additional instance attribute: `_transaction_count = 0`
- Property `monthly_transaction_limit` with getter and setter
- Override `deposit` and `withdraw` to:
  - Apply transaction fee after each transaction (deduct from balance)
  - Track transaction count
  - If monthly limit exceeded, charge additional fee of $5.00
- Additional method: `def reset_monthly_count(self):` resets transaction count to 0
- Additional method: `def get_remaining_transactions(self):` returns remaining free transactions
- Override `get_account_type` to return "Business Account"
- Override `__str__` to include business account details
- You are not allowed to import any module

**File:** `4-bank.py`

---

### 5. Bank Class - Composition and Account Management

Write a class `Bank` that manages multiple accounts: (based on previous bank files)

- Instance attribute: `_accounts = {}` (dictionary to store accounts by account number)
- Instance attribute: `_bank_name`
- Property `bank_name` with getter only
- Method: `def create_account(self, account_type, name, account_number, **kwargs):` 
  - Creates account based on type: "savings", "checking", or "business"
  - Returns the created account object
  - Raises `ValueError` for invalid account type or if account number already exists
- Method: `def get_account(self, account_number):` returns account object or None
- Method: `def close_account(self, account_number):` removes account from bank
- Method: `def get_total_deposits(self):` returns sum of all positive balances
- Method: `def get_accounts_by_type(self, account_type):` returns list of accounts of specified type
- Method: `def transfer_funds(self, from_account, to_account, amount):` transfers money between accounts
- Method: `def generate_bank_report(self):` returns formatted string with bank statistics
- You are not allowed to import any module

**File:** `5-bank.py`

---

### 6. Premium Account with Multiple Inheritance

Write classes that demonstrate multiple inheritance:

First, create a `RewardsProgram` class:
- Method: `def earn_points(self, amount):` calculates reward points (1 point per $10)
- Method: `def redeem_points(self, points):` converts points to cash (100 points = $1)
- Attribute: `_points_balance = 0`
- Property `points_balance` with getter only

Then create a `PremiumAccount` class that inherits from both `CheckingAccount` and `RewardsProgram`:
- Inherits from both `CheckingAccount` and `RewardsProgram`
- Override `deposit` to earn reward points
- Additional method: `def get_premium_benefits(self):` returns list of benefits
- Override `get_account_type` to return "Premium Account"
- Override `__str__` to include points balance
- You are not allowed to import any module

**File:** `6-bank.py`

---

### 7. Abstract Account Base and Operator Overloading

Write an abstract base class and implement operator overloading:

First, create an `AbstractAccount` class:
- Use `from abc import ABC, abstractmethod`
- Abstract method: `@abstractmethod def get_account_type(self):`
- Abstract method: `@abstractmethod def calculate_fees(self):`

Then update your `BankAccount` to inherit from `AbstractAccount` and implement operator overloading:
- Inherit from `AbstractAccount`
- Implement required abstract methods
- Operator `__eq__`: compare accounts by account number
- Operator `__lt__`: compare accounts by balance (for sorting)
- Operator `__add__`: return combined balance of two accounts (don't modify accounts)
- Operator `__iadd__`: deposit amount to account (account += amount should work like deposit)
- Operator `__isub__`: withdraw amount from account (account -= amount should work like withdraw)
- Operator `__repr__`: return detailed string representation for developers
- You are allowed to import `abc` module only

**File:** `7-bank.py`

---

### 8. Complete Banking System Integration

Create a comprehensive banking system that ties everything together:

Write a `BankingSystem` class that:
- Manages multiple `Bank` instances
- Implements account number generation
- Provides customer authentication simulation
- Includes transaction history across all banks
- Implements account transfer between different banks
- Provides comprehensive reporting and analytics
- Includes error handling and logging simulation
- Implements account freezing/unfreezing functionality
- Provides interest calculation for all accounts
- Includes monthly maintenance operations

Additional features:
- Account factory pattern for creating different account types
- Transaction processing with validation
- Account statement generation
- Multi-currency support simulation (USD, EUR, GBP)
- Account backup and restore functionality
- You are not allowed to import any module except `abc`

**File:** `8-bank.py`

---

## Testing

Each task should be tested with corresponding main files that demonstrate the new concepts:

### Example Testing 2-bank.py (SavingsAccount)

```python
#!/usr/bin/python3
BankAccount = __import__('1-bank').BankAccount
SavingsAccount = __import__('2-bank').SavingsAccount

# Test inheritance
savings = SavingsAccount("Alice Cooper", "SAV001")
print(f"Account type: {savings.get_account_type()}")
print(f"Minimum balance: ${savings.minimum_balance}")

# Test deposit (inherited)
savings.deposit(500)
print(savings)

# Test withdrawal with minimum balance restriction
savings.withdraw(450)  # Should be denied
savings.withdraw(350)  # Should work
print(f"Final balance: ${savings.balance}")
```

## Repository

- **GitHub repository:** `recursion-readme`
- **Directory:** `more_python_classes`
- **Files:** `0-bank.py`, `1-bank.py`, `2-bank.py`, `3-bank.py`, `4-bank.py`, `5-bank.py`, `6-bank.py`, `7-bank.py`, `8-bank.py`

## Prerequisites

You must have completed the basic Python Classes project (0x06-python-classes) before attempting these advanced concepts.

## Author

This project is part of the Advanced Python Classes learning curriculum.