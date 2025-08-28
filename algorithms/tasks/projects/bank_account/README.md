# Personal Finance Manager Project

## 🎯 Project Overview
Build a comprehensive Personal Finance Manager application that helps users track income, expenses, savings goals, and generate financial reports. This project is designed to test your Python fundamentals through a modular, step-by-step implementation.

## 📚 Concepts Tested
- **Classes & Objects**: Custom classes for transactions, accounts, users
- **Data Types**: Strings, integers, floats, booleans, dates
- **Data Structures**: Lists, dictionaries, sets, tuples
- **Algorithms**: Sorting, searching, filtering, calculations
- **File I/O**: Reading/writing CSV and text files
- **Exception Handling**: Custom exceptions and error management
- **JSON**: Configuration and data serialization

---

## 📋 Detailed Implementation Instructions

### 0. Project Setup and Configuration

Write a module `project_setup` that defines project constants and configuration:

- Global constant: `DATA_FOLDER` (string, value: "data")
- Global constant: `BACKUP_FOLDER` (string, value: "backups")
- Global constant: `MAX_TRANSACTION_AMOUNT` (float, value: 1000000.0)
- Global constant: `DEFAULT_CURRENCY` (string, value: "USD")
- Global dictionary: `FILE_EXTENSIONS` with keys "csv", "json", "txt" and appropriate extensions as values
- Global dictionary: `TRANSACTION_CATEGORIES` with at least 8 expense categories (e.g., "Food", "Transport", etc.)
- Global dictionary: `ACCOUNT_TYPES` with keys "checking", "savings", "credit" and descriptions as values
- Global dictionary: `CONSOLE_COLORS` with keys "red", "green", "blue", "yellow", "reset" and ANSI color codes as values
- Function: `get_data_path(filename):` that returns the full path to a file in the data folder
- Function: `get_backup_path(filename):` that returns the full path to a file in the backup folder

**File:** `00_project_setup.py`

---

### 1. Custom Exception Classes

Write custom exception classes that inherit from appropriate base exceptions:

- Class `InvalidTransactionError` that inherits from `ValueError`:
  - Instantiation with message: `def __init__(self, message):`
  - Should store the message and call parent constructor
- Class `AccountNotFoundError` that inherits from `KeyError`:
  - Instantiation with account_id: `def __init__(self, account_id):`
  - Should format message as "Account {account_id} not found"
- Class `InsufficientFundsError` that inherits from `ValueError`:
  - Instantiation with required and available amounts: `def __init__(self, required, available):`
  - Should format message showing both amounts
- Class `DataValidationError` that inherits from `ValueError`:
  - Instantiation with field name and value: `def __init__(self, field, value):`
  - Should format message as "Invalid {field}: {value}"
- Class `FileOperationError` that inherits from `IOError`:
  - Instantiation with operation and filename: `def __init__(self, operation, filename):`
  - Should format message describing the failed operation

**File:** `01_custom_exceptions.py`

---

### 2. Date Utility Functions

Write a module with date handling utilities:

- Function: `validate_date_string(date_str):` that takes a date string in "YYYY-MM-DD" format
  - Returns `True` if valid date format, `False` otherwise
  - Should handle invalid dates like "2023-02-30"
- Function: `string_to_date(date_str):` that converts "YYYY-MM-DD" string to datetime.date object
  - Should raise `ValueError` if invalid format
- Function: `date_to_string(date_obj):` that converts datetime.date object to "YYYY-MM-DD" string
- Function: `get_current_date_string():` that returns today's date as "YYYY-MM-DD" string
- Function: `get_date_range(start_date, end_date):` that returns list of all dates between start and end (inclusive)
  - Parameters are datetime.date objects
  - Returns list of datetime.date objects
- Function: `get_month_start_end(year, month):` that returns tuple of (first_day, last_day) of given month
  - Returns tuple of datetime.date objects
- Function: `days_between(date1, date2):` that returns number of days between two dates
  - Returns integer (positive if date2 > date1)

**File:** `02_date_utils.py`

---

### 3. Input Validation Utilities

Write validation functions using regular expressions and other checks:

- Function: `validate_email(email):` that validates email format
  - Returns `True` if email contains @ symbol and valid domain format
  - Should check for basic pattern: text@domain.extension
- Function: `validate_amount(amount_str):` that validates monetary amounts
  - Returns `True` if string represents valid positive number with max 2 decimal places
  - Should handle strings like "123.45", "100", "0.50"
- Function: `validate_account_number(account_num):` that validates account number format
  - Returns `True` if string contains exactly 10 digits
- Function: `validate_transaction_id(trans_id):` that validates transaction ID format
  - Returns `True` if string follows pattern: "TXN" + 8 digits (e.g., "TXN12345678")
- Function: `sanitize_input(text):` that cleans user input
  - Returns string with leading/trailing whitespace removed
  - Should convert to lowercase for comparison purposes
- Function: `is_positive_number(value):` that checks if value is positive number
  - Should handle both string and numeric inputs
  - Returns `True` if value represents positive number

**File:** `03_validation_utils.py`

---

### 4. Transaction Data Model

Write a class `Transaction` that represents a financial transaction:

- Private instance attribute: `transaction_id`
- Private instance attribute: `amount` 
- Private instance attribute: `category`
- Private instance attribute: `date`
- Private instance attribute: `description`
- Private instance attribute: `transaction_type` ("income" or "expense")
- Instantiation: `def __init__(self, transaction_id, amount, category, date, description, transaction_type):`
- Public instance method: `def get_transaction_id(self):` returns transaction ID
- Public instance method: `def get_amount(self):` returns amount as float
- Public instance method: `def get_category(self):` returns category string
- Public instance method: `def get_date(self):` returns date string
- Public instance method: `def get_description(self):` returns description
- Public instance method: `def get_transaction_type(self):` returns transaction type
- Public instance method: `def set_amount(self, amount):` sets new amount (must be positive)
- Public instance method: `def set_description(self, description):` sets new description
- Public instance method: `def to_dict(self):` returns dictionary with all transaction data
- Public instance method: `def is_valid(self):` returns `True` if all required fields are present and valid
- Magic method: `def __str__(self):` returns formatted string representation
- Magic method: `def __eq__(self, other):` compares transactions by ID
- Class method: `def from_dict(cls, data):` creates Transaction object from dictionary

**File:** `04_transaction_model.py`

---

### 5. Account Data Model

Write a class `Account` that represents a financial account:

- Private instance attribute: `account_id`
- Private instance attribute: `account_name`
- Private instance attribute: `balance` (initialized to 0.0)
- Private instance attribute: `account_type` ("checking", "savings", or "credit")
- Private instance attribute: `transaction_history` (initialized to empty list)
- Instantiation: `def __init__(self, account_id, account_name, account_type):`
- Public instance method: `def get_account_id(self):` returns account ID
- Public instance method: `def get_account_name(self):` returns account name
- Public instance method: `def get_balance(self):` returns current balance
- Public instance method: `def get_account_type(self):` returns account type
- Public instance method: `def get_transaction_count(self):` returns number of transactions
- Public instance method: `def deposit(self, amount):` adds money to account
  - Should validate amount is positive
  - Should update balance and add to transaction history
  - Returns `True` if successful, raises exception if invalid
- Public instance method: `def withdraw(self, amount):` removes money from account
  - Should check sufficient funds (unless credit account)
  - Should update balance and add to transaction history
  - Returns `True` if successful, raises `InsufficientFundsError` if needed
- Public instance method: `def get_transaction_history(self):` returns list of transaction IDs
- Public instance method: `def add_transaction(self, transaction_id):` adds transaction to history
- Public instance method: `def to_dict(self):` returns dictionary representation
- Public instance method: `def calculate_monthly_summary(self, year, month):` returns dict with income/expense totals for given month
- Magic method: `def __str__(self):` returns formatted account summary

**File:** `05_account_model.py`

---

### 6. User Data Model

Write a class `User` that represents an application user:

- Private instance attribute: `user_id`
- Private instance attribute: `name`
- Private instance attribute: `email`
- Private instance attribute: `accounts` (initialized to empty dictionary)
- Private instance attribute: `preferences` (initialized to empty dictionary)
- Instantiation: `def __init__(self, user_id, name, email):`
- Public instance method: `def get_user_id(self):` returns user ID
- Public instance method: `def get_name(self):` returns user name
- Public instance method: `def get_email(self):` returns email address
- Public instance method: `def set_name(self, name):` updates user name
- Public instance method: `def set_email(self, email):` updates email (with validation)
- Public instance method: `def add_account(self, account):` adds account to user's accounts
  - Parameter is Account object
  - Should store in accounts dictionary with account_id as key
- Public instance method: `def remove_account(self, account_id):` removes account from user
  - Should raise `AccountNotFoundError` if account doesn't exist
- Public instance method: `def get_account(self, account_id):` returns specific account
  - Should raise `AccountNotFoundError` if account doesn't exist
- Public instance method: `def get_all_accounts(self):` returns list of all Account objects
- Public instance method: `def get_total_balance(self):` returns sum of all account balances
- Public instance method: `def get_account_count(self):` returns number of accounts
- Public instance method: `def set_preference(self, key, value):` sets user preference
- Public instance method: `def get_preference(self, key, default=None):` gets user preference
- Public instance method: `def to_dict(self):` returns dictionary representation
- Magic method: `def __str__(self):` returns formatted user summary

**File:** `06_user_model.py`

---

### 7. Abstract Data Storage Base Class

Write an abstract base class `DataStorage` for data operations:

- Import `ABC` and `abstractmethod` from `abc` module
- Class `DataStorage` that inherits from `ABC`:
- Abstract method: `def save(self, data, filename):` for saving data
- Abstract method: `def load(self, filename):` for loading data
- Abstract method: `def delete(self, filename):` for deleting files
- Abstract method: `def exists(self, filename):` for checking file existence
- Concrete method: `def get_file_size(self, filename):` returns file size in bytes
  - Should return 0 if file doesn't exist
- Concrete method: `def backup_file(self, filename):` creates backup copy
  - Should add ".backup" extension to filename
  - Returns `True` if successful, `False` otherwise
- Concrete method: `def validate_filename(self, filename):` checks if filename is valid
  - Should check for valid characters and reasonable length
  - Returns `True` if valid, `False` otherwise

**File:** `07_data_storage.py`

---

### 8. CSV File Handler

Write a class `CSVHandler` that handles CSV file operations:

- Class `CSVHandler` that inherits from `DataStorage`
- Instance method: `def save(self, data, filename):` saves list of dictionaries to CSV
  - Should write headers based on dictionary keys
  - Should handle empty data gracefully
  - Should raise `FileOperationError` on write failure
- Instance method: `def load(self, filename):` loads CSV data as list of dictionaries
  - Should return empty list if file doesn't exist
  - Should handle CSV parsing errors gracefully
  - Should convert numeric strings back to numbers where appropriate
- Instance method: `def delete(self, filename):` deletes CSV file
  - Should return `True` if successful, `False` if file doesn't exist
- Instance method: `def exists(self, filename):` checks if CSV file exists
- Instance method: `def append_row(self, row_data, filename):` appends single row to existing CSV
  - Should handle case where file doesn't exist (create with headers)
  - Parameter row_data is dictionary
- Instance method: `def get_row_count(self, filename):` returns number of data rows (excluding header)
- Instance method: `def filter_rows(self, filename, filter_func):` returns rows matching filter function
  - filter_func takes row dictionary and returns boolean

**File:** `08_csv_handler.py`

---

### 9. JSON File Handler

Write a class `JSONHandler` that handles JSON file operations:

- Class `JSONHandler` that inherits from `DataStorage`
- Instance method: `def save(self, data, filename):` saves data as JSON
  - Should use proper indentation for readability
  - Should handle datetime objects by converting to strings
  - Should raise `FileOperationError` on write failure
- Instance method: `def load(self, filename):` loads JSON data
  - Should return `None` if file doesn't exist
  - Should handle JSON parsing errors gracefully
  - Should return parsed data structure (dict, list, etc.)
- Instance method: `def delete(self, filename):` deletes JSON file
  - Should return `True` if successful, `False` if file doesn't exist
- Instance method: `def exists(self, filename):` checks if JSON file exists
- Instance method: `def update_field(self, filename, field_path, new_value):` updates specific field
  - field_path is dot-separated path like "user.preferences.currency"
  - Should handle nested dictionaries
- Instance method: `def merge_data(self, filename, new_data):` merges new data with existing
  - Should preserve existing data and add/update with new_data
- Instance method: `def validate_json_structure(self, data, required_fields):` validates data structure
  - required_fields is list of field names that must be present
  - Returns `True` if valid, `False` otherwise

**File:** `09_json_handler.py`

---

### 10. File System Manager

Write a class `FileManager` for file system operations:

- Instance method: `def create_directory(self, directory_path):` creates directory if it doesn't exist
  - Should create parent directories as needed
  - Returns `True` if successful or already exists
- Instance method: `def list_files(self, directory_path, extension=None):` lists files in directory
  - If extension provided, filter by file extension
  - Returns list of filenames
- Instance method: `def get_file_info(self, filepath):` returns dictionary with file information
  - Should include size, modified date, creation date
  - Returns `None` if file doesn't exist
- Instance method: `def copy_file(self, source_path, destination_path):` copies file
  - Should create destination directory if needed
  - Returns `True` if successful, `False` otherwise
- Instance method: `def move_file(self, source_path, destination_path):` moves file
  - Returns `True` if successful, `False` otherwise
- Instance method: `def delete_file(self, filepath):` deletes single file
  - Returns `True` if successful, `False` if file doesn't exist
- Instance method: `def cleanup_old_files(self, directory_path, days_old):` removes files older than specified days
  - Returns number of files deleted
- Instance method: `def get_directory_size(self, directory_path):` returns total size of directory in bytes
- Instance method: `def ensure_file_permissions(self, filepath):` ensures file is readable/writable

**File:** `10_file_manager.py`

---

### 11. Data Validator

Write a class `DataValidator` for validating data integrity:

- Instance method: `def validate_transaction_data(self, transaction_dict):` validates transaction dictionary
  - Should check all required fields are present
  - Should validate data types and value ranges
  - Returns tuple: (is_valid, list_of_errors)
- Instance method: `def validate_account_data(self, account_dict):` validates account dictionary
  - Should check required fields and data types
  - Should validate account_type is valid option
  - Returns tuple: (is_valid, list_of_errors)
- Instance method: `def validate_user_data(self, user_dict):` validates user dictionary
  - Should check required fields and email format
  - Returns tuple: (is_valid, list_of_errors)
- Instance method: `def check_balance_consistency(self, account, transactions):` verifies account balance matches transaction history
  - account is Account object, transactions is list of Transaction objects
  - Returns `True` if consistent, `False` otherwise
- Instance method: `def validate_file_format(self, filename, expected_format):` validates file format
  - expected_format is "csv" or "json"
  - Returns `True` if file matches expected format
- Instance method: `def find_duplicate_transactions(self, transactions):` finds duplicate transactions
  - Returns list of transaction IDs that appear multiple times
- Instance method: `def validate_date_range(self, start_date, end_date):` validates date range
  - Returns `True` if start_date <= end_date and both are valid dates

**File:** `11_data_validator.py`

---

### 12. Backup System

Write a class `BackupSystem` for data backup and restore:

- Private instance attribute: `backup_directory`
- Private instance attribute: `max_backups` (default: 10)
- Instantiation: `def __init__(self, backup_directory, max_backups=10):`
- Instance method: `def create_backup(self, source_files):` creates timestamped backup
  - source_files is list of file paths to backup
  - Should create zip file with timestamp in name
  - Returns backup filename if successful, `None` otherwise
- Instance method: `def restore_from_backup(self, backup_filename, destination_directory):` restores from backup
  - Should extract all files from backup zip to destination
  - Returns `True` if successful, `False` otherwise
- Instance method: `def list_backups(self):` returns list of available backup files
  - Should return sorted list (newest first)
- Instance method: `def delete_backup(self, backup_filename):` deletes specific backup
  - Returns `True` if successful, `False` otherwise
- Instance method: `def cleanup_old_backups(self):` removes old backups beyond max_backups limit
  - Should keep the most recent backups
  - Returns number of backups deleted
- Instance method: `def get_backup_info(self, backup_filename):` returns backup information
  - Should return dictionary with size, creation date, file count
- Instance method: `def verify_backup_integrity(self, backup_filename):` checks if backup is valid
  - Should verify zip file can be opened and contains expected files
  - Returns `True` if backup is valid, `False` otherwise

**File:** `12_backup_system.py`

---

### 13. Transaction Manager

Write a class `TransactionManager` for transaction CRUD operations:

- Private instance attribute: `transactions` (initialized to empty dictionary, key=transaction_id)
- Private instance attribute: `csv_handler` (CSVHandler instance)
- Private instance attribute: `data_validator` (DataValidator instance)
- Instantiation: `def __init__(self):`
- Instance method: `def add_transaction(self, transaction):` adds new transaction
  - Parameter is Transaction object
  - Should validate transaction data before adding
  - Should assign unique transaction ID if not provided
  - Returns transaction ID if successful, raises exception if invalid
- Instance method: `def get_transaction(self, transaction_id):` retrieves specific transaction
  - Returns Transaction object or raises `KeyError` if not found
- Instance method: `def update_transaction(self, transaction_id, **kwargs):` updates transaction fields
  - Should validate new values before updating
  - Returns `True` if successful, `False` otherwise
- Instance method: `def delete_transaction(self, transaction_id):` removes transaction
  - Returns `True` if successful, `False` if transaction doesn't exist
- Instance method: `def get_all_transactions(self):` returns list of all Transaction objects
- Instance method: `def filter_transactions(self, **criteria):` filters transactions by criteria
  - Criteria can include: date_range, category, amount_range, transaction_type
  - Returns list of matching Transaction objects
- Instance method: `def sort_transactions(self, sort_by="date", reverse=False):` returns sorted transaction list
  - sort_by options: "date", "amount", "category"
- Instance method: `def get_transactions_by_category(self):` returns dictionary grouped by category
- Instance method: `def save_to_file(self, filename):` saves all transactions to CSV file
- Instance method: `def load_from_file(self, filename):` loads transactions from CSV file

**File:** `13_transaction_manager.py`

---

### 14. Account Manager

Write a class `AccountManager` for managing multiple accounts:

- Private instance attribute: `accounts` (initialized to empty dictionary, key=account_id)
- Private instance attribute: `json_handler` (JSONHandler instance)
- Instantiation: `def __init__(self):`
- Instance method: `def create_account(self, account_name, account_type):` creates new account
  - Should generate unique account ID
  - Returns Account object
- Instance method: `def get_account(self, account_id):` retrieves specific account
  - Returns Account object or raises `AccountNotFoundError`
- Instance method: `def delete_account(self, account_id):` removes account
  - Should check account has zero balance before deletion
  - Returns `True` if successful, raises exception if balance non-zero
- Instance method: `def get_all_accounts(self):` returns list of all Account objects
- Instance method: `def transfer_money(self, from_account_id, to_account_id, amount):` transfers between accounts
  - Should validate both accounts exist and from_account has sufficient funds
  - Should create transaction records for both accounts
  - Returns `True` if successful, raises appropriate exception if failed
- Instance method: `def get_total_balance(self):` returns sum of all account balances
- Instance method: `def get_accounts_by_type(self, account_type):` returns list of accounts of specified type
- Instance method: `def calculate_net_worth(self):` calculates total net worth
  - Should handle credit accounts (negative balances) appropriately
- Instance method: `def save_accounts(self, filename):` saves all accounts to JSON file
- Instance method: `def load_accounts(self, filename):` loads accounts from JSON file

**File:** `14_account_manager.py`

---

### 15. Budget Calculator

Write a class `BudgetCalculator` for budget calculations and analysis:

- Private instance attribute: `budgets` (initialized to empty dictionary, key=category)
- Instance method: `def set_budget(self, category, amount, period="monthly"):` sets budget for category
  - period can be "weekly", "monthly", or "yearly"
  - Should store budget information in budgets dictionary
- Instance method: `def get_budget(self, category):` returns budget info for category
  - Returns dictionary with amount and period, or `None` if not set
- Instance method: `def calculate_spent_vs_budget(self, category, transactions, start_date, end_date):` compares spending to budget
  - Returns dictionary with budgeted_amount, actual_spent, difference, percentage_used
- Instance method: `def get_overspending_categories(self, transactions, start_date, end_date):` identifies overspending
  - Returns list of categories that exceeded their budgets
- Instance method: `def calculate_recommended_budget(self, transactions, months_of_history=6):` suggests budget amounts
  - Analyzes historical spending to recommend budgets
  - Returns dictionary with category: recommended_amount pairs
- Instance method: `def get_budget_summary(self, transactions, start_date, end_date):` generates budget report
  - Returns dictionary with summary for each budgeted category
- Instance method: `def calculate_savings_potential(self, transactions, income, period_days):` calculates potential savings
  - Returns dictionary with total_income, total_expenses, current_savings, potential_savings
- Instance method: `def track_budget_performance(self, transactions, year, month):` tracks monthly budget performance
  - Returns dictionary with performance metrics for the specified month

**File:** `15_budget_calculator.py`

---

### 16. Report Generator

Write a class `ReportGenerator` for creating financial reports:

- Instance method: `def generate_income_expense_report(self, transactions, start_date, end_date):` creates income/expense report
  - Returns dictionary with total_income, total_expenses, net_amount, transaction_count
- Instance method: `def generate_category_report(self, transactions, start_date, end_date):` creates spending by category report
  - Returns dictionary with categories as keys and amounts as values
- Instance method: `def generate_monthly_summary(self, transactions, year, month):` creates monthly summary
  - Returns dictionary with detailed monthly financial summary
- Instance method: `def generate_account_summary(self, accounts):` creates account overview report
  - Returns dictionary with account summaries and totals
- Instance method: `def generate_trend_analysis(self, transactions, months=6):` analyzes spending trends
  - Returns dictionary with monthly trends and comparisons
- Instance method: `def export_report_to_csv(self, report_data, filename):` exports report data to CSV
  - Should format data appropriately for CSV export
  - Returns `True` if successful, `False` otherwise
- Instance method: `def format_currency(self, amount):` formats amount as currency string
  - Should handle negative amounts and include currency symbol
- Instance method: `def create_transaction_list_report(self, transactions):` creates formatted transaction list
  - Returns list of formatted transaction strings for display
- Instance method: `def calculate_financial_ratios(self, income, expenses, savings):` calculates key financial ratios
  - Returns dictionary with savings_rate, expense_ratio, and other key metrics

**File:** `16_report_generator.py`

---

### 17. Goal Tracker

Write a class `GoalTracker` for tracking savings goals:

- Private instance attribute: `goals` (initialized to empty dictionary, key=goal_id)
- Instance method: `def create_goal(self, name, target_amount, target_date, description=""):` creates new savings goal
  - Should generate unique goal ID
  - Should validate target_amount is positive and target_date is in future
  - Returns goal ID if successful
- Instance method: `def get_goal(self, goal_id):` retrieves specific goal
  - Returns goal dictionary or raises `KeyError` if not found
- Instance method: `def update_goal_progress(self, goal_id, amount_saved):` updates progress toward goal
  - Should add amount to current progress
  - Returns `True` if successful, `False` otherwise
- Instance method: `def delete_goal(self, goal_id):` removes goal
  - Returns `True` if successful, `False` if goal doesn't exist
- Instance method: `def get_all_goals(self):` returns list of all goals
- Instance method: `def calculate_goal_progress(self, goal_id):` calculates progress percentage
  - Returns percentage (0-100) of goal completion
- Instance method: `def get_goals_by_status(self, status):` filters goals by completion status
  - status can be "active", "completed", "overdue"
  - Returns list of matching goals
- Instance method: `def calculate_monthly_savings_needed(self, goal_id):` calculates required monthly savings
  - Based on remaining amount and time to target date
  - Returns monthly amount needed
- Instance method: `def check_goal_deadlines(self):` checks for approaching deadlines
  - Returns list of goals with deadlines within 30 days
- Instance method: `def generate_goal_report(self):` creates summary report of all goals
  - Returns dictionary with goal statistics and summaries

**File:** `17_goal_tracker.py`

---

### 18. Analytics Engine

Write a class `AnalyticsEngine` for financial analysis and insights:

- Instance method: `def calculate_spending_trends(self, transactions, months=6):` analyzes spending patterns
  - Returns dictionary with monthly spending trends and percentage changes
- Instance method: `def identify_unusual_transactions(self, transactions, threshold_multiplier=3.0):` finds outlier transactions
  - Uses statistical analysis to find transactions significantly above average
  - Returns list of unusual Transaction objects
- Instance method: `def calculate_category_percentages(self, transactions):` calculates spending distribution
  - Returns dictionary with category: percentage pairs
- Instance method: `def predict_future_balance(self, account, months=3):` predicts account balance
  - Uses historical data to predict future balance
  - Returns list of predicted monthly balances
- Instance method: `def analyze_income_stability(self, transactions):` analyzes income consistency
  - Returns dictionary with income statistics and stability metrics
- Instance method: `def find_recurring_transactions(self, transactions):` identifies recurring payments
  - Groups similar transactions that occur regularly
  - Returns dictionary with recurring transaction patterns
- Instance method: `def calculate_seasonal_patterns(self, transactions):` identifies seasonal spending patterns
  - Returns dictionary with spending patterns by month/quarter
- Instance method: `def generate_insights(self, transactions, accounts):` generates financial insights
  - Returns list of text insights about spending patterns and opportunities
- Instance method: `def calculate_expense_growth_rate(self, transactions, periods=12):` calculates expense growth
  - Returns percentage growth rate of expenses over specified periods

**File:** `18_analytics_engine.py`

---

### 19. Menu System

Write a class `MenuSystem` for console-based user interface:

- Private instance attribute: `menus` (dictionary storing menu configurations)
- Instantiation: `def __init__(self):`
- Instance method: `def create_main_menu(self):` creates main menu structure
  - Should define menu options with keys and descriptions
  - Should store in menus dictionary with key "main"
- Instance method: `def create_transaction_menu(self):` creates transaction management menu
  - Should define options for add, view, edit, delete transactions
- Instance method: `def create_account_menu(self):` creates account management menu
  - Should define options for account operations
- Instance method: `def create_report_menu(self):` creates report generation menu
  - Should define options for different report types
- Instance method: `def display_menu(self, menu_name):` displays specified menu
  - Should show menu title and numbered options
  - Should include option to return to previous menu
- Instance method: `def get_menu_choice(self, menu_name):` gets user's menu selection
  - Should validate input and return selected option key
  - Should handle invalid inputs gracefully
- Instance method: `def show_header(self):` displays application header/title
- Instance method: `def show_footer(self):` displays application footer
- Instance method: `def clear_screen(self):` clears console screen
- Instance method: `def pause_for_user(self):` waits for user to press enter

**File:** `19_menu_system.py`

---

### 20. Input Handler Module
Write a module `input_handler.py` that handles all user input processing:
- Function: `def get_integer_input(prompt, min_value=None, max_value=None):` 
  - Prompts user for integer input with validation
  - Parameters: prompt message, optional min/max values
  - Returns valid integer or raises `DataValidationError`
- Function: `def get_float_input(prompt, min_value=0.0):` 
  - Prompts user for float input (for monetary amounts)
  - Parameters: prompt message, minimum value (default 0.0)
  - Returns valid float with 2 decimal places
- Function: `def get_string_input(prompt, min_length=1, max_length=100):` 
  - Prompts user for string input with length validation
  - Parameters: prompt message, min/max length constraints
  - Returns validated string (stripped of whitespace)
- Function: `def get_date_input(prompt):` 
  - Prompts user for date in YYYY-MM-DD format
  - Uses `date_utils.py` for validation
  - Returns datetime.date object or raises `DataValidationError`
- Function: `def get_choice_input(prompt, choices):` 
  - Prompts user to select from a list of choices
  - Parameters: prompt message, list of valid choices
  - Returns selected choice (case-insensitive matching)
- Function: `def get_yes_no_input(prompt):` 
  - Prompts user for yes/no confirmation
  - Accepts variations: y/yes/n/no (case-insensitive)
  - Returns boolean True/False
- Function: `def retry_input(func, max_attempts=3):` 
  - Wrapper function that retries input on validation errors
  - Parameters: input function to retry, maximum attempts
  - Returns valid input or raises exception after max attempts
- All functions should handle `KeyboardInterrupt` gracefully
- Import required modules: `custom_exceptions`, `date_utils`, `validation_utils`
**File:** `20_input_handler.py`

---

### 21. Output Formatter Module
Write a module `output_formatter.py` that handles display formatting and presentation:
- Function: `def format_currency(amount, currency_symbol="$"):` 
  - Formats monetary amounts with currency symbol
  - Parameters: amount (float), currency symbol (default "$")
  - Returns formatted string like "$1,234.56"
- Function: `def format_date(date_obj, format_string="%Y-%m-%d"):` 
  - Formats date objects for display
  - Parameters: datetime object, format string
  - Returns formatted date string
- Function: `def create_table(headers, rows, title=None):` 
  - Creates formatted table from data
  - Parameters: list of headers, list of row data, optional title
  - Returns formatted table string with borders and alignment
- Function: `def format_transaction_list(transactions):` 
  - Formats list of Transaction objects for display
  - Creates table with columns: Date, Description, Category, Amount, Balance
  - Uses color coding: green for income, red for expenses
- Function: `def format_account_summary(account):` 
  - Formats Account object summary for display
  - Shows account name, type, balance, and recent transactions
  - Returns formatted multi-line string
- Function: `def format_report(report_data, report_type):` 
  - Formats report data based on report type
  - Parameters: dictionary of report data, report type string
  - Handles different report types: "monthly", "category", "budget"
- Function: `def paginate_output(content, lines_per_page=20):` 
  - Splits long content into pages
  - Parameters: content string, lines per page
  - Returns generator yielding page content
- Function: `def add_color(text, color_code):` 
  - Adds ANSI color codes to text
  - Uses color codes from `project_setup.py`
  - Parameters: text string, color code constant
- Function: `def clear_screen():` 
  - Clears console screen (cross-platform)
- Import required modules: `project_setup`, `transaction_model`, `account_model`
**File:** `21_output_formatter.py`

---

### 22. Application Controller Module
Write a class `AppController` that coordinates the main application workflow:
- Private instance attribute: `user` (current User object)
- Private instance attribute: `transaction_manager` (TransactionManager instance)
- Private instance attribute: `account_manager` (AccountManager instance)
- Private instance attribute: `report_generator` (ReportGenerator instance)
- Private instance attribute: `goal_tracker` (GoalTracker instance)
- Private instance attribute: `running` (boolean for main loop control)
- Instantiation: `def __init__(self):`
  - Initializes all manager instances
  - Sets up user session (load existing or create new)
- Public instance method: `def start_application(self):` 
  - Main application entry point
  - Shows welcome message and main menu
  - Handles main application loop until user exits
- Public instance method: `def handle_transaction_menu(self):` 
  - Displays transaction management menu
  - Options: Add, Edit, Delete, View transactions
  - Delegates to appropriate transaction_manager methods
- Public instance method: `def handle_account_menu(self):` 
  - Displays account management menu
  - Options: Create account, View accounts, Transfer money
  - Delegates to account_manager methods
- Public instance method: `def handle_reports_menu(self):` 
  - Displays reports menu
  - Options: Monthly report, Category report, Budget analysis
  - Uses report_generator to create and display reports
- Public instance method: `def handle_goals_menu(self):` 
  - Displays savings goals menu
  - Options: Create goal, View goals, Update progress
  - Delegates to goal_tracker methods
- Public instance method: `def handle_settings_menu(self):` 
  - Displays application settings menu
  - Options: Backup data, Restore data, User preferences
  - Uses backup_system and config_manager
- Public instance method: `def save_and_exit(self):` 
  - Saves all data before exiting
  - Creates backup if configured
  - Sets running flag to False
- Private instance method: `def _load_user_session(self):` 
  - Loads existing user data or creates new user
  - Handles user authentication/selection
- Private instance method: `def _handle_errors(self, error):` 
  - Centralized error handling for all operations
  - Logs errors and shows user-friendly messages
- Import required modules: all manager classes, `input_handler`, `output_formatter`, `menu_system`
**File:** `22_app_controller.py`

---

### 23. Configuration Manager Module
Write a class `ConfigManager` that handles application configuration:
- Private instance attribute: `config_file` (path to config file)
- Private instance attribute: `default_config` (dictionary of default settings)
- Private instance attribute: `current_config` (dictionary of current settings)
- Instantiation: `def __init__(self, config_file="config.json"):`
  - Sets config file path
  - Defines default configuration dictionary
  - Loads existing config or creates default
- Public instance method: `def load_config(self):` 
  - Loads configuration from JSON file
  - Uses default values if file doesn't exist
  - Handles file reading errors gracefully
- Public instance method: `def save_config(self):` 
  - Saves current configuration to JSON file
  - Creates config file if it doesn't exist
  - Uses `json_handler` for file operations
- Public instance method: `def get_setting(self, key, default=None):` 
  - Retrieves specific configuration value
  - Parameters: setting key, default value if not found
  - Returns setting value or default
- Public instance method: `def set_setting(self, key, value):` 
  - Updates specific configuration value
  - Parameters: setting key, new value
  - Validates value type against defaults
- Public instance method: `def reset_to_defaults(self):` 
  - Resets all settings to default values
  - Saves updated configuration to file
- Public instance method: `def get_user_preferences(self, user_id):` 
  - Retrieves user-specific preferences
  - Parameters: user ID string
  - Returns dictionary of user preferences
- Public instance method: `def set_user_preference(self, user_id, key, value):` 
  - Sets user-specific preference
  - Parameters: user ID, preference key, value
  - Creates user preferences section if needed
- Private instance method: `def _create_default_config(self):` 
  - Creates default configuration dictionary
  - Includes: data paths, backup settings, display preferences, currency settings
- Private instance method: `def _validate_config(self, config):` 
  - Validates configuration structure and values
  - Ensures all required keys are present
  - Returns validated configuration dictionary
- Import required modules: `json_handler`, `file_manager`, `custom_exceptions`
**File:** `23_config_manager.py`

---

### 24. Main Application Entry Point
Write a module `main_app.py` that serves as the main application entry point:
- Function: `def initialize_application():` 
  - Sets up application directory structure
  - Initializes configuration manager
  - Creates necessary data directories
  - Returns initialized AppController instance
- Function: `def setup_error_handling():` 
  - Sets up global exception handling
  - Configures logging system
  - Defines error recovery procedures
- Function: `def display_welcome_message():` 
  - Shows application welcome screen
  - Displays version information and features
  - Shows loading progress if needed
- Function: `def cleanup_on_exit():` 
  - Performs cleanup operations before exit
  - Saves any pending data
  - Closes file handles and connections
- Function: `def handle_startup_errors(error):` 
  - Handles errors that occur during startup
  - Provides user-friendly error messages
  - Offers recovery options when possible
- Function: `def check_system_requirements():` 
  - Verifies Python version compatibility
  - Checks for required file permissions
  - Validates system resources
- Function: `def main():` 
  - Main function that orchestrates application startup
  - Calls initialization functions in proper order
  - Starts the main application controller
  - Handles graceful shutdown
- Global exception handler using `try/except` around main execution
- Entry point check: `if __name__ == "__main__":`
- Import required modules: `app_controller`, `config_manager`, `file_manager`, `project_setup`, `custom_exceptions`, `sys`, `logging`
**File:** `24_main_app.py`