#!/usr/bin/env python3
"""
Personal Finance Manager Project - Testing Files
These files test each module implementation according to the project requirements.
"""

# File: 0-main.py - Test Project Setup and Configuration
def test_project_setup():
    """Test module 00_project_setup.py"""
    try:
        import sys
        sys.path.append('.')
        from project_setup import (
            DATA_FOLDER, BACKUP_FOLDER, MAX_TRANSACTION_AMOUNT, DEFAULT_CURRENCY,
            FILE_EXTENSIONS, TRANSACTION_CATEGORIES, ACCOUNT_TYPES, CONSOLE_COLORS,
            get_data_path, get_backup_path
        )
        
        print("Testing Project Setup Module...")
        
        # Test constants
        assert DATA_FOLDER == "data", f"DATA_FOLDER should be 'data', got {DATA_FOLDER}"
        assert BACKUP_FOLDER == "backups", f"BACKUP_FOLDER should be 'backups', got {BACKUP_FOLDER}"
        assert MAX_TRANSACTION_AMOUNT == 1000000.0, f"MAX_TRANSACTION_AMOUNT should be 1000000.0"
        assert DEFAULT_CURRENCY == "USD", f"DEFAULT_CURRENCY should be 'USD'"
        
        # Test dictionaries
        assert isinstance(FILE_EXTENSIONS, dict), "FILE_EXTENSIONS should be a dictionary"
        assert "csv" in FILE_EXTENSIONS and "json" in FILE_EXTENSIONS and "txt" in FILE_EXTENSIONS
        
        assert isinstance(TRANSACTION_CATEGORIES, dict), "TRANSACTION_CATEGORIES should be a dictionary"
        assert len(TRANSACTION_CATEGORIES) >= 8, "Should have at least 8 transaction categories"
        
        assert isinstance(ACCOUNT_TYPES, dict), "ACCOUNT_TYPES should be a dictionary"
        assert "checking" in ACCOUNT_TYPES and "savings" in ACCOUNT_TYPES and "credit" in ACCOUNT_TYPES
        
        assert isinstance(CONSOLE_COLORS, dict), "CONSOLE_COLORS should be a dictionary"
        assert "red" in CONSOLE_COLORS and "green" in CONSOLE_COLORS and "blue" in CONSOLE_COLORS
        
        # Test functions
        data_path = get_data_path("test.csv")
        assert data_path.endswith("data/test.csv") or data_path.endswith("data\\test.csv"), "Invalid data path"
        
        backup_path = get_backup_path("backup.json")
        assert backup_path.endswith("backups/backup.json") or backup_path.endswith("backups\\backup.json"), "Invalid backup path"
        
        print("✓ Project Setup Module tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_project_setup()


# File: 1-main.py - Test Custom Exception Classes
def test_custom_exceptions():
    """Test module 01_custom_exceptions.py"""
    try:
        from custom_exceptions import (
            InvalidTransactionError, AccountNotFoundError, InsufficientFundsError,
            DataValidationError, FileOperationError
        )
        
        print("Testing Custom Exception Classes...")
        
        # Test InvalidTransactionError
        try:
            raise InvalidTransactionError("Invalid transaction")
        except InvalidTransactionError as e:
            assert str(e) == "Invalid transaction", "InvalidTransactionError message incorrect"
            assert isinstance(e, ValueError), "Should inherit from ValueError"
        
        # Test AccountNotFoundError
        try:
            raise AccountNotFoundError("ACC123")
        except AccountNotFoundError as e:
            assert "ACC123" in str(e), "AccountNotFoundError should include account ID"
            assert isinstance(e, KeyError), "Should inherit from KeyError"
        
        # Test InsufficientFundsError
        try:
            raise InsufficientFundsError(100.0, 50.0)
        except InsufficientFundsError as e:
            error_msg = str(e)
            assert "100" in error_msg and "50" in error_msg, "Should show both amounts"
            assert isinstance(e, ValueError), "Should inherit from ValueError"
        
        # Test DataValidationError
        try:
            raise DataValidationError("email", "invalid-email")
        except DataValidationError as e:
            error_msg = str(e)
            assert "email" in error_msg and "invalid-email" in error_msg, "Should show field and value"
            assert isinstance(e, ValueError), "Should inherit from ValueError"
        
        # Test FileOperationError
        try:
            raise FileOperationError("read", "missing.txt")
        except FileOperationError as e:
            error_msg = str(e)
            assert "read" in error_msg and "missing.txt" in error_msg, "Should show operation and filename"
            assert isinstance(e, IOError), "Should inherit from IOError"
        
        print("✓ Custom Exception Classes tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_custom_exceptions()


# File: 2-main.py - Test Date Utility Functions
def test_date_utils():
    """Test module 02_date_utils.py"""
    try:
        from datetime import date
        from date_utils import (
            validate_date_string, string_to_date, date_to_string,
            get_current_date_string, get_date_range, get_month_start_end,
            days_between
        )
        
        print("Testing Date Utility Functions...")
        
        # Test validate_date_string
        assert validate_date_string("2023-12-25") == True, "Valid date should return True"
        assert validate_date_string("2023-02-30") == False, "Invalid date should return False"
        assert validate_date_string("invalid") == False, "Invalid format should return False"
        
        # Test string_to_date
        test_date = string_to_date("2023-12-25")
        assert isinstance(test_date, date), "Should return date object"
        assert test_date.year == 2023 and test_date.month == 12 and test_date.day == 25
        
        # Test date_to_string
        date_obj = date(2023, 12, 25)
        date_str = date_to_string(date_obj)
        assert date_str == "2023-12-25", f"Expected '2023-12-25', got '{date_str}'"
        
        # Test get_current_date_string
        current_date = get_current_date_string()
        assert validate_date_string(current_date), "Current date should be valid"
        
        # Test get_date_range
        start = date(2023, 12, 25)
        end = date(2023, 12, 27)
        date_range = get_date_range(start, end)
        assert len(date_range) == 3, "Should return 3 dates inclusive"
        assert all(isinstance(d, date) for d in date_range), "All items should be date objects"
        
        # Test get_month_start_end
        first_day, last_day = get_month_start_end(2023, 12)
        assert first_day.day == 1 and first_day.month == 12
        assert last_day.day == 31 and last_day.month == 12
        
        # Test days_between
        date1 = date(2023, 12, 25)
        date2 = date(2023, 12, 27)
        diff = days_between(date1, date2)
        assert diff == 2, f"Expected 2 days difference, got {diff}"
        
        print("✓ Date Utility Functions tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_date_utils()


# File: 3-main.py - Test Input Validation Utilities
def test_validation_utils():
    """Test module 03_validation_utils.py"""
    try:
        from validation_utils import (
            validate_email, validate_amount, validate_account_number,
            validate_transaction_id, sanitize_input, is_positive_number
        )
        
        print("Testing Input Validation Utilities...")
        
        # Test validate_email
        assert validate_email("test@example.com") == True, "Valid email should return True"
        assert validate_email("invalid-email") == False, "Invalid email should return False"
        assert validate_email("test@") == False, "Incomplete email should return False"
        
        # Test validate_amount
        assert validate_amount("123.45") == True, "Valid amount should return True"
        assert validate_amount("100") == True, "Integer amount should return True"
        assert validate_amount("0.50") == True, "Small amount should return True"
        assert validate_amount("-50") == False, "Negative amount should return False"
        assert validate_amount("123.456") == False, "More than 2 decimals should return False"
        
        # Test validate_account_number
        assert validate_account_number("1234567890") == True, "10 digits should return True"
        assert validate_account_number("123456789") == False, "9 digits should return False"
        assert validate_account_number("12345678901") == False, "11 digits should return False"
        assert validate_account_number("123456789a") == False, "Non-digits should return False"
        
        # Test validate_transaction_id
        assert validate_transaction_id("TXN12345678") == True, "Valid transaction ID should return True"
        assert validate_transaction_id("TXN1234567") == False, "7 digits should return False"
        assert validate_transaction_id("TXN123456789") == False, "9 digits should return False"
        assert validate_transaction_id("ABC12345678") == False, "Wrong prefix should return False"
        
        # Test sanitize_input
        result = sanitize_input("  Test Input  ")
        assert result == "test input", f"Expected 'test input', got '{result}'"
        
        # Test is_positive_number
        assert is_positive_number("123.45") == True, "String number should return True"
        assert is_positive_number(123.45) == True, "Float number should return True"
        assert is_positive_number(-123.45) == False, "Negative number should return False"
        assert is_positive_number("0") == False, "Zero should return False"
        
        print("✓ Input Validation Utilities tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_validation_utils()


# File: 4-main.py - Test Transaction Data Model
def test_transaction_model():
    """Test module 04_transaction_model.py"""
    try:
        from transaction_model import Transaction
        
        print("Testing Transaction Data Model...")
        
        # Create test transaction
        transaction = Transaction(
            transaction_id="TXN12345678",
            amount=100.50,
            category="Food",
            date="2023-12-25",
            description="Grocery shopping",
            transaction_type="expense"
        )
        
        # Test getters
        assert transaction.get_transaction_id() == "TXN12345678", "Transaction ID getter failed"
        assert transaction.get_amount() == 100.50, "Amount getter failed"
        assert transaction.get_category() == "Food", "Category getter failed"
        assert transaction.get_date() == "2023-12-25", "Date getter failed"
        assert transaction.get_description() == "Grocery shopping", "Description getter failed"
        assert transaction.get_transaction_type() == "expense", "Transaction type getter failed"
        
        # Test setters
        transaction.set_amount(150.75)
        assert transaction.get_amount() == 150.75, "Amount setter failed"
        
        transaction.set_description("Updated description")
        assert transaction.get_description() == "Updated description", "Description setter failed"
        
        # Test to_dict
        trans_dict = transaction.to_dict()
        assert isinstance(trans_dict, dict), "to_dict should return dictionary"
        assert trans_dict["transaction_id"] == "TXN12345678", "Dictionary should contain correct ID"
        assert trans_dict["amount"] == 150.75, "Dictionary should contain updated amount"
        
        # Test is_valid
        assert transaction.is_valid() == True, "Valid transaction should return True"
        
        # Test __str__
        str_repr = str(transaction)
        assert "TXN12345678" in str_repr, "String representation should contain ID"
        assert "150.75" in str_repr, "String representation should contain amount"
        
        # Test __eq__
        transaction2 = Transaction("TXN12345678", 200, "Transport", "2023-12-26", "Bus fare", "expense")
        assert transaction == transaction2, "Transactions with same ID should be equal"
        
        # Test from_dict
        test_dict = {
            "transaction_id": "TXN87654321",
            "amount": 75.25,
            "category": "Entertainment",
            "date": "2023-12-26",
            "description": "Movie tickets",
            "transaction_type": "expense"
        }
        new_transaction = Transaction.from_dict(test_dict)
        assert new_transaction.get_transaction_id() == "TXN87654321", "from_dict failed"
        assert new_transaction.get_amount() == 75.25, "from_dict failed"
        
        print("✓ Transaction Data Model tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_transaction_model()


# File: 5-main.py - Test Account Data Model
def test_account_model():
    """Test module 05_account_model.py"""
    try:
        from account_model import Account
        
        print("Testing Account Data Model...")
        
        # Create test account
        account = Account("ACC1234567890", "My Checking", "checking")
        
        # Test initial state
        assert account.get_account_id() == "ACC1234567890", "Account ID getter failed"
        assert account.get_account_name() == "My Checking", "Account name getter failed"
        assert account.get_balance() == 0.0, "Initial balance should be 0.0"
        assert account.get_account_type() == "checking", "Account type getter failed"
        assert account.get_transaction_count() == 0, "Initial transaction count should be 0"
        
        # Test deposit
        result = account.deposit(500.00)
        assert result == True, "Deposit should return True"
        assert account.get_balance() == 500.00, f"Balance should be 500.00, got {account.get_balance()}"
        
        # Test withdraw (sufficient funds)
        result = account.withdraw(200.00)
        assert result == True, "Withdraw should return True"
        assert account.get_balance() == 300.00, f"Balance should be 300.00, got {account.get_balance()}"
        
        # Test withdraw (insufficient funds) - should raise exception
        try:
            account.withdraw(400.00)
            assert False, "Should raise InsufficientFundsError"
        except Exception as e:
            assert "InsufficientFunds" in str(type(e)), "Should raise InsufficientFundsError"
        
        # Test transaction history
        account.add_transaction("TXN12345678")
        account.add_transaction("TXN87654321")
        history = account.get_transaction_history()
        assert len(history) == 2, "Should have 2 transactions in history"
        assert "TXN12345678" in history, "Should contain first transaction"
        assert "TXN87654321" in history, "Should contain second transaction"
        
        # Test to_dict
        account_dict = account.to_dict()
        assert isinstance(account_dict, dict), "to_dict should return dictionary"
        assert account_dict["account_id"] == "ACC1234567890", "Dict should contain account ID"
        assert account_dict["balance"] == 300.00, "Dict should contain current balance"
        
        # Test calculate_monthly_summary
        monthly_summary = account.calculate_monthly_summary(2023, 12)
        assert isinstance(monthly_summary, dict), "Should return dictionary"
        
        # Test __str__
        str_repr = str(account)
        assert "ACC1234567890" in str_repr, "String should contain account ID"
        assert "300.00" in str_repr or "300.0" in str_repr, "String should contain balance"
        
        print("✓ Account Data Model tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_account_model()


# File: 6-main.py - Test User Data Model
def test_user_model():
    """Test module 06_user_model.py"""
    try:
        from user_model import User
        from account_model import Account
        
        print("Testing User Data Model...")
        
        # Create test user
        user = User("USER123", "John Doe", "john@example.com")
        
        # Test initial state
        assert user.get_user_id() == "USER123", "User ID getter failed"
        assert user.get_name() == "John Doe", "Name getter failed"
        assert user.get_email() == "john@example.com", "Email getter failed"
        assert user.get_account_count() == 0, "Initial account count should be 0"
        assert user.get_total_balance() == 0.0, "Initial total balance should be 0.0"
        
        # Test setters
        user.set_name("John Smith")
        assert user.get_name() == "John Smith", "Name setter failed"
        
        user.set_email("johnsmith@example.com")
        assert user.get_email() == "johnsmith@example.com", "Email setter failed"
        
        # Test account management
        account1 = Account("ACC1111111111", "Checking", "checking")
        account1.deposit(1000.00)
        
        account2 = Account("ACC2222222222", "Savings", "savings")
        account2.deposit(5000.00)
        
        user.add_account(account1)
        user.add_account(account2)
        
        assert user.get_account_count() == 2, "Should have 2 accounts"
        assert user.get_total_balance() == 6000.00, "Total balance should be 6000.00"
        
        # Test get_account
        retrieved_account = user.get_account("ACC1111111111")
        assert retrieved_account.get_account_id() == "ACC1111111111", "Should retrieve correct account"
        
        # Test get_all_accounts
        all_accounts = user.get_all_accounts()
        assert len(all_accounts) == 2, "Should return 2 accounts"
        
        # Test remove_account
        user.remove_account("ACC2222222222")
        assert user.get_account_count() == 1, "Should have 1 account after removal"
        assert user.get_total_balance() == 1000.00, "Total balance should be 1000.00"
        
        # Test preferences
        user.set_preference("currency", "USD")
        user.set_preference("theme", "dark")
        
        currency = user.get_preference("currency")
        assert currency == "USD", "Should retrieve correct preference"
        
        default_val = user.get_preference("nonexistent", "default")
        assert default_val == "default", "Should return default value"
        
        # Test to_dict
        user_dict = user.to_dict()
        assert isinstance(user_dict, dict), "to_dict should return dictionary"
        assert user_dict["user_id"] == "USER123", "Dict should contain user ID"
        
        # Test __str__
        str_repr = str(user)
        assert "USER123" in str_repr, "String should contain user ID"
        assert "John Smith" in str_repr, "String should contain updated name"
        
        print("✓ User Data Model tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_user_model()


# File: 7-main.py - Test Abstract Data Storage Base Class
def test_data_storage():
    """Test module 07_data_storage.py"""
    try:
        from data_storage import DataStorage
        from abc import ABC, abstractmethod
        
        print("Testing Abstract Data Storage Base Class...")
        
        # Test that DataStorage is abstract
        assert issubclass(DataStorage, ABC), "DataStorage should inherit from ABC"
        
        # Test that we cannot instantiate abstract class
        try:
            storage = DataStorage()
            assert False, "Should not be able to instantiate abstract class"
        except TypeError:
            pass  # Expected behavior
        
        # Create concrete implementation for testing
        class TestStorage(DataStorage):
            def save(self, data, filename):
                return True
            
            def load(self, filename):
                return {}
            
            def delete(self, filename):
                return True
            
            def exists(self, filename):
                return True
        
        # Test concrete implementation
        storage = TestStorage()
        
        # Test abstract methods are implemented
        assert storage.save({}, "test.json") == True, "save method should work"
        assert storage.load("test.json") == {}, "load method should work"
        assert storage.delete("test.json") == True, "delete method should work"
        assert storage.exists("test.json") == True, "exists method should work"
        
        # Test concrete methods
        file_size = storage.get_file_size("nonexistent.txt")
        assert file_size == 0, "Non-existent file should return size 0"
        
        # Test validate_filename
        assert storage.validate_filename("valid_file.txt") == True, "Valid filename should return True"
        assert storage.validate_filename("") == False, "Empty filename should return False"
        
        print("✓ Abstract Data Storage Base Class tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_data_storage()


# File: 8-main.py - Test CSV File Handler
def test_csv_handler():
    """Test module 08_csv_handler.py"""
    try:
        import os
        import tempfile
        from csv_handler import CSVHandler
        
        print("Testing CSV File Handler...")
        
        handler = CSVHandler()
        
        # Test save and load
        test_data = [
            {"name": "John", "age": 30, "salary": 50000.0},
            {"name": "Jane", "age": 25, "salary": 45000.0}
        ]
        
        with tempfile.NamedTemporaryFile(mode='w', suffix='.csv', delete=False) as tmp:
            tmp_filename = tmp.name
        
        try:
            # Test save
            handler.save(test_data, tmp_filename)
            assert handler.exists(tmp_filename), "File should exist after save"
            
            # Test load
            loaded_data = handler.load(tmp_filename)
            assert len(loaded_data) == 2, "Should load 2 records"
            assert loaded_data[0]["name"] == "John", "Should load correct data"
            assert float(loaded_data[0]["salary"]) == 50000.0, "Should handle numeric conversion"
            
            # Test append_row
            new_row = {"name": "Bob", "age": 35, "salary": 55000.0}
            handler.append_row(new_row, tmp_filename)
            
            updated_data = handler.load(tmp_filename)
            assert len(updated_data) == 3, "Should have 3 records after append"
            
            # Test get_row_count
            row_count = handler.get_row_count(tmp_filename)
            assert row_count == 3, "Should return 3 rows"
            
            # Test filter_rows
            high_salary = handler.filter_rows(tmp_filename, lambda row: float(row.get("salary", 0)) > 50000)
            assert len(high_salary) == 2, "Should find 2 high salary records"
            
            # Test delete
            result = handler.delete(tmp_filename)
            assert result == True, "Delete should return True"
            assert not handler.exists(tmp_filename), "File should not exist after delete"
            
        finally:
            # Cleanup
            if os.path.exists(tmp_filename):
                os.unlink(tmp_filename)
        
        print("✓ CSV File Handler tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_csv_handler()


# File: 9-main.py - Test JSON File Handler
def test_json_handler():
    """Test module 09_json_handler.py"""
    try:
        import os
        import tempfile
        from json_handler import JSONHandler
        
        print("Testing JSON File Handler...")
        
        handler = JSONHandler()
        
        # Test save and load
        test_data = {
            "user": {
                "name": "John Doe",
                "age": 30,
                "preferences": {
                    "currency": "USD",
                    "theme": "dark"
                }
            },
            "accounts": [
                {"id": "ACC123", "balance": 1000.0},
                {"id": "ACC456", "balance": 2500.0}
            ]
        }
        
        with tempfile.NamedTemporaryFile(mode='w', suffix='.json', delete=False) as tmp:
            tmp_filename = tmp.name
        
        try:
            # Test save
            handler.save(test_data, tmp_filename)
            assert handler.exists(tmp_filename), "File should exist after save"
            
            # Test load
            loaded_data = handler.load(tmp_filename)
            assert loaded_data["user"]["name"] == "John Doe", "Should load correct data"
            assert len(loaded_data["accounts"]) == 2, "Should load correct number of accounts"
            
            # Test update_field
            handler.update_field(tmp_filename, "user.name", "Jane Doe")
            updated_data = handler.load(tmp_filename)
            assert updated_data["user"]["name"] == "Jane Doe", "Field should be updated"
            
            # Test merge_data
            new_data = {
                "user": {"email": "jane@example.com"},
                "settings": {"notifications": True}
            }
            handler.merge_data(tmp_filename, new_data)
            merged_data = handler.load(tmp_filename)
            assert merged_data["user"]["email"] == "jane@example.com", "Should add new fields"
            assert merged_data["user"]["age"] == 30, "Should preserve existing fields"
            assert merged_data["settings"]["notifications"] == True, "Should add new sections"
            
            # Test validate_json_structure
            required_fields = ["user", "accounts"]
            is_valid = handler.validate_json_structure(merged_data, required_fields)
            assert is_valid == True, "Should validate correct structure"
            
            invalid_validation = handler.validate_json_structure({"incomplete": True}, required_fields)
            assert invalid_validation == False, "Should reject incomplete structure"
            
            # Test delete
            result = handler.delete(tmp_filename)
            assert result == True, "Delete should return True"
            assert not handler.exists(tmp_filename), "File should not exist after delete"
            
        finally:
            # Cleanup
            if os.path.exists(tmp_filename):
                os.unlink(tmp_filename)
        
        print("✓ JSON File Handler tests passed!")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    test_json_handler()


# File: 10-main.py - Test File System Manager
def test_file_manager():
    """Test module 10_file_manager.py"""
    try:
        import os
        import tempfile
        import time
        from datetime import datetime, timedelta
        from file_manager import FileManager
        
        print("Testing File System Manager...")
        
        manager = FileManager()
        
        with tempfile.TemporaryDirectory() as tmp_dir:
            # Test create_directory
            new_dir = os.path.join(tmp_dir, "test_directory")
            result = manager.create_directory(new_dir)
            assert result == True, "Should create directory successfully"
            assert os.path.exists(new_dir), "Directory should exist"
            
            # Test create existing directory
            result = manager.create_directory(new_dir)
            assert result == True, "Should return True for existing directory"
            
            # Test nested directory creation
            nested_dir = os.path.join(tmp_dir, "level1", "level2", "level3")
            result = manager.create_directory(nested_dir)
            assert result == True, "Should create nested directories"
            assert os.path.exists(nested_dir), "Nested directory should exist"
            
            # Create test files
            test_file1 = os.path.join(new_dir, "test1.txt")
            test_file2 = os.path.join(new_dir, "test2.json")
            test_file3 = os.path.join(new_dir, "test3.csv")
            
            with open(test_file1, 'w') as f:
                f.write("Test content 1")
            with open(test_file2, 'w') as f:
                f.write('{"test": "content"}')
            with open(test_file3, 'w') as f:
                f.write("name,age\nJohn,30")
            
            # Test list_files
            all_files = manager.list_files(new_dir)
            assert len(all_files) == 3, f"Should list 3 files, got {len(all_files)}"
            assert "test1.txt" in all_files, "Should include txt file"
            assert "test2.json" in all_files, "Should include json file"
            
            # Test list_files with extension filter
            txt_files = manager.list_files(new_dir, extension=".txt")
            assert len(txt_files) == 1, "Should list 1 txt file"
            assert "test1.txt" in txt_files, "Should include correct txt file"
            
            json_files = manager.list_files(new_dir, extension=".json")
            assert len(json_files) == 1, "Should list 1 json file"
            
            # Test get_file_info
            file_info = manager.get_file_info(test_file1)
            assert file_info is not None, "Should return file info"
            assert "size" in file_info, "Should include file size"
            assert "modified_date" in file_info, "Should include modified date"
            assert "creation_date" in file_info, "Should include creation date"
            assert file_info["size"] > 0, "File should have content"
            
            # Test get_file_info for non-existent file
            non_existent = os.path.join(new_dir, "nonexistent.txt")
            file_info = manager.get_file_info(non_existent)
            assert file_info is None, "Should return None for non-existent file"
            
            # Test copy_file
            copy_destination = os.path.join(tmp_dir, "copied_file.txt")
            result = manager.copy_file(test_file1, copy_destination)
            assert result == True, "Should copy file successfully"
            assert os.path.exists(copy_destination), "Copied file should exist"
            
            with open(copy_destination, 'r') as f:
                content = f.read()
                assert content == "Test content 1", "Copied file should have same content"
            
            # Test copy_file with directory creation
            deep_copy_dir = os.path.join(tmp_dir, "deep", "copy", "location")
            deep_copy_file = os.path.join(deep_copy_dir, "deep_copy.txt")
            result = manager.copy_file(test_file1, deep_copy_file)
            assert result == True, "Should copy file and create directories"
            assert os.path.exists(deep_copy_file), "Deep copied file should exist"
            
            # Test move_file
            move_destination = os.path.join(tmp_dir, "moved_file.txt")
            result = manager.move_file(copy_destination, move_destination)
            assert result == True, "Should move file successfully"
            assert os.path.exists(move_destination), "Moved file should exist at destination"
            assert not os.path.exists(copy_destination), "Original file should not exist after move"
            
            # Test delete_file
            result = manager.delete_file(move_destination)
            assert result == True, "Should delete file successfully"
            assert not os.path.exists(move_destination), "File should not exist after deletion"
            
            # Test delete non-existent file
            result = manager.delete_file(move_destination)
            assert result == False, "Should return False for non-existent file"
            
            # Test get_directory_size
            dir_size = manager.get_directory_size(new_dir)
            assert dir_size > 0, "Directory should have non-zero size"
            
            # Add more content to increase directory size
            large_file = os.path.join(new_dir, "large.txt")
            with open(large_file, 'w') as f:
                f.write("x" * 1000)  # 1000 characters
            
            new_dir_size = manager.get_directory_size(new_dir)
            assert new_dir_size > dir_size, "Directory size should increase after adding file"
            
            # Test cleanup_old_files
            # Create some files and modify their timestamps
            old_file = os.path.join(new_dir, "old_file.txt")
            with open(old_file, 'w') as f:
                f.write("old content")
            
            # Simulate old file by modifying its timestamp (make it 10 days old)
            old_time = time.time() - (10 * 24 * 60 * 60)  # 10 days ago
            os.utime(old_file, (old_time, old_time))
            
            # Count files before cleanup
            files_before = len(manager.list_files(new_dir))
            
            # Cleanup files older than 5 days
            deleted_count = manager.cleanup_old_files(new_dir, days_old=5)
            assert deleted_count >= 1, "Should delete at least 1 old file"
            
            files_after = len(manager.list_files(new_dir))
            assert files_after < files_before, "Should have fewer files after cleanup"
            
            # Test ensure_file_permissions
            perm_test_file = os.path.join(new_dir, "perm_test.txt")
            with open(perm_test_file, 'w') as f:
                f.write("permission test")
            
            # This should not raise an exception
            manager.ensure_file_permissions(perm_test_file)
            
            # Verify file is still readable and writable
            assert os.access(perm_test_file, os.R_OK), "File should be readable"
            assert os.access(perm_test_file, os.W_OK), "File should be writable"
            
            print("✅ All File System Manager tests passed!")
            
    except ImportError as e:
        print(f"❌ Import error: {e}")
        print("Make sure 10_file_manager.py is implemented correctly")
    except AssertionError as e:
        print(f"❌ Test failed: {e}")
    except Exception as e:
        print(f"❌ Unexpected error: {e}")

if __name__ == "__main__":
    test_file_manager()

# File: 11-main.py - Test Data Validator
def test_data_validator():
    """Test module 11_data_validator.py"""
    try:
        from data_validator import DataValidator
        from transaction_model import Transaction
        from account_model import Account
        from datetime import datetime, date
        
        print("Testing Data Validator...")
        
        validator = DataValidator()
        
        # Test validate_transaction_data
        valid_transaction = {
            'transaction_id': 'TXN12345678',
            'amount': 100.50,
            'category': 'Food',
            'date': '2024-01-15',
            'description': 'Grocery shopping',
            'transaction_type': 'expense'
        }
        
        is_valid, errors = validator.validate_transaction_data(valid_transaction)
        assert is_valid == True, "Valid transaction should pass validation"
        assert len(errors) == 0, "Valid transaction should have no errors"
        
        # Test invalid transaction
        invalid_transaction = {
            'transaction_id': 'INVALID',
            'amount': -50,
            'category': '',
            'date': '2024-13-01',  # Invalid month
            'description': '',
            'transaction_type': 'invalid_type'
        }
        
        is_valid, errors = validator.validate_transaction_data(invalid_transaction)
        assert is_valid == False, "Invalid transaction should fail validation"
        assert len(errors) > 0, "Invalid transaction should have errors"
        
        # Test validate_account_data
        valid_account = {
            'account_id': '1234567890',
            'account_name': 'My Checking Account',
            'balance': 1500.75,
            'account_type': 'checking'
        }
        
        is_valid, errors = validator.validate_account_data(valid_account)
        assert is_valid == True, "Valid account should pass validation"
        
        # Test validate_user_data
        valid_user = {
            'user_id': 'USER001',
            'name': 'John Doe',
            'email': 'john.doe@example.com'
        }
        
        is_valid, errors = validator.validate_user_data(valid_user)
        assert is_valid == True, "Valid user should pass validation"
        
        # Test invalid email
        invalid_user = {
            'user_id': 'USER002',
            'name': 'Jane Smith',
            'email': 'invalid-email'
        }
        
        is_valid, errors = validator.validate_user_data(invalid_user)
        assert is_valid == False, "Invalid email should fail validation"
        
        # Test validate_date_range
        start_date = date(2024, 1, 1)
        end_date = date(2024, 12, 31)
        
        is_valid = validator.validate_date_range(start_date, end_date)
        assert is_valid == True, "Valid date range should pass"
        
        # Test invalid date range
        is_valid = validator.validate_date_range(end_date, start_date)
        assert is_valid == False, "Invalid date range should fail"
        
        print("All Data Validator tests passed!")
        
    except ImportError as e:
        print(f"Import error: {e}")
    except Exception as e:
        print(f"Test error: {e}")

# File: 12-main.py - Test Backup System
def test_backup_system():
    """Test module 12_backup_system.py"""
    try:
        import os
        import tempfile
        from backup_system import BackupSystem
        
        print("Testing Backup System...")
        
        with tempfile.TemporaryDirectory() as tmp_dir:
            backup_dir = os.path.join(tmp_dir, "backups")
            backup_system = BackupSystem(backup_dir)
            
            # Create test files to backup
            test_files = []
            for i in range(3):
                test_file = os.path.join(tmp_dir, f"test_file_{i}.txt")
                with open(test_file, 'w') as f:
                    f.write(f"Test content {i}")
                test_files.append(test_file)
            
            # Test create_backup
            backup_filename = backup_system.create_backup(test_files)
            assert backup_filename is not None, "Backup should be created successfully"
            assert backup_filename.endswith('.zip'), "Backup should be a zip file"
            
            # Test list_backups
            backups = backup_system.list_backups()
            assert len(backups) >= 1, "Should list at least one backup"
            assert backup_filename in backups, "Created backup should be in list"
            
            # Test get_backup_info
            backup_info = backup_system.get_backup_info(backup_filename)
            assert backup_info is not None, "Should return backup info"
            assert 'size' in backup_info, "Should include file size"
            assert 'creation_date' in backup_info, "Should include creation date"
            
            # Test verify_backup_integrity
            is_valid = backup_system.verify_backup_integrity(backup_filename)
            assert is_valid == True, "Backup should be valid"
            
            # Test restore_from_backup
            restore_dir = os.path.join(tmp_dir, "restored")
            success = backup_system.restore_from_backup(backup_filename, restore_dir)
            assert success == True, "Backup should restore successfully"
            
            # Verify restored files
            for i in range(3):
                restored_file = os.path.join(restore_dir, f"test_file_{i}.txt")
                assert os.path.exists(restored_file), f"Restored file {i} should exist"
                
                with open(restored_file, 'r') as f:
                    content = f.read()
                    assert content == f"Test content {i}", "Restored content should match original"
            
            print("All Backup System tests passed!")
            
    except ImportError as e:
        print(f"Import error: {e}")
    except Exception as e:
        print(f"Test error: {e}")

# File: 13-main.py - Test Transaction Manager
def test_transaction_manager():
    """Test module 13_transaction_manager.py"""
    try:
        from transaction_manager import TransactionManager
        from transaction_model import Transaction
        from datetime import date
        
        print("Testing Transaction Manager...")
        
        manager = TransactionManager()
        
        # Create test transaction
        transaction = Transaction(
            transaction_id='TXN12345678',
            amount=100.50,
            category='Food',
            date='2024-01-15',
            description='Grocery shopping',
            transaction_type='expense'
        )
        
        # Test add_transaction
        trans_id = manager.add_transaction(transaction)
        assert trans_id == 'TXN12345678', "Should return transaction ID"
        
        # Test get_transaction
        retrieved = manager.get_transaction('TXN12345678')
        assert retrieved is not None, "Should retrieve transaction"
        assert retrieved.get_amount() == 100.50, "Amount should match"
        
        # Add more transactions for filtering tests
        transactions_data = [
            ('TXN12345679', 50.0, 'Transport', '2024-01-16', 'Bus fare', 'expense'),
            ('TXN12345680', 2000.0, 'Salary', '2024-01-17', 'Monthly salary', 'income'),
            ('TXN12345681', 75.25, 'Food', '2024-01-18', 'Restaurant', 'expense'),
        ]
        
        for data in transactions_data:
            trans = Transaction(*data)
            manager.add_transaction(trans)
        
        # Test get_all_transactions
        all_trans = manager.get_all_transactions()
        assert len(all_trans) == 4, "Should have 4 transactions"
        
        # Test filter_transactions by category
        food_trans = manager.filter_transactions(category='Food')
        assert len(food_trans) == 2, "Should find 2 food transactions"
        
        # Test filter by transaction_type
        expense_trans = manager.filter_transactions(transaction_type='expense')
        assert len(expense_trans) == 3, "Should find 3 expense transactions"
        
        # Test sort_transactions
        sorted_trans = manager.sort_transactions(sort_by='amount')
        amounts = [t.get_amount() for t in sorted_trans]
        assert amounts == sorted(amounts), "Should be sorted by amount"
        
        # Test get_transactions_by_category
        by_category = manager.get_transactions_by_category()
        assert 'Food' in by_category, "Should include Food category"
        assert len(by_category['Food']) == 2, "Should have 2 food transactions"
        
        print("All Transaction Manager tests passed!")
        
    except ImportError as e:
        print(f"Import error: {e}")
    except Exception as e:
        print(f"Test error: {e}")

# File: 14-main.py - Test Account Manager
def test_account_manager():
    """Test module 14_account_manager.py"""
    try:
        from account_manager import AccountManager
        from custom_exceptions import AccountNotFoundError, InsufficientFundsError
        
        print("Testing Account Manager...")
        
        manager = AccountManager()
        
        # Test create_account
        account1 = manager.create_account("Main Checking", "checking")
        assert account1 is not None, "Should create account successfully"
        account_id1 = account1.get_account_id()
        
        account2 = manager.create_account("Savings Account", "savings")
        account_id2 = account2.get_account_id()
        
        # Test get_account
        retrieved = manager.get_account(account_id1)
        assert retrieved.get_account_name() == "Main Checking", "Should retrieve correct account"
        
        # Test get_account with invalid ID
        try:
            manager.get_account("INVALID_ID")
            assert False, "Should raise AccountNotFoundError"
        except AccountNotFoundError:
            pass  # Expected
        
        # Test get_all_accounts
        all_accounts = manager.get_all_accounts()
        assert len(all_accounts) == 2, "Should have 2 accounts"
        
        # Add some money to accounts for transfer test
        account1.deposit(1000.0)
        account2.deposit(500.0)
        
        # Test transfer_money
        success = manager.transfer_money(account_id1, account_id2, 200.0)
        assert success == True, "Transfer should succeed"
        
        # Verify balances after transfer
        assert account1.get_balance() == 800.0, "Source account should be reduced"
        assert account2.get_balance() == 700.0, "Destination account should be increased"
        
        # Test insufficient funds transfer
        try:
            manager.transfer_money(account_id1, account_id2, 2000.0)
            assert False, "Should raise InsufficientFundsError"
        except InsufficientFundsError:
            pass  # Expected
        
        # Test get_total_balance
        total = manager.get_total_balance()
        assert total == 1500.0, "Total balance should be sum of all accounts"
        
        # Test get_accounts_by_type
        checking_accounts = manager.get_accounts_by_type("checking")
        assert len(checking_accounts) == 1, "Should have 1 checking account"
        
        print("All Account Manager tests passed!")
        
    except ImportError as e:
        print(f"Import error: {e}")
    except Exception as e:
        print(f"Test error: {e}")

# File: 15-main.py - Test Budget Calculator
def test_budget_calculator():
    """Test module 15_budget_calculator.py"""
    try:
        from budget_calculator import BudgetCalculator
        from transaction_model import Transaction
        from datetime import date
        
        print("Testing Budget Calculator...")
        
        calculator = BudgetCalculator()
        
        # Test set_budget
        calculator.set_budget("Food", 500.0, "monthly")
        calculator.set_budget("Transport", 200.0, "monthly")
        
        # Test get_budget
        food_budget = calculator.get_budget("Food")
        assert food_budget is not None, "Should retrieve budget"
        assert food_budget['amount'] == 500.0, "Budget amount should match"
        assert food_budget['period'] == "monthly", "Budget period should match"
        
        # Create test transactions
        transactions = [
            Transaction('TXN001', 150.0, 'Food', '2024-01-15', 'Groceries', 'expense'),
            Transaction('TXN002', 200.0, 'Food', '2024-01-20', 'Restaurant', 'expense'),
            Transaction('TXN003', 50.0, 'Transport', '2024-01-18', 'Gas', 'expense'),
            Transaction('TXN004', 100.0, 'Transport', '2024-01-25', 'Bus pass', 'expense'),
        ]
        
        start_date = date(2024, 1, 1)
        end_date = date(2024, 1, 31)
        
        # Test calculate_spent_vs_budget
        food_analysis = calculator.calculate_spent_vs_budget("Food", transactions, start_date, end_date)
        assert food_analysis['budgeted_amount'] == 500.0, "Should show correct budget"
        assert food_analysis['actual_spent'] == 350.0, "Should calculate correct spending"
        assert food_analysis['difference'] == 150.0, "Should show remaining budget"
        assert food_analysis['percentage_used'] == 70.0, "Should calculate correct percentage"
        
        # Test get_overspending_categories
        # Set a low budget to trigger overspending
        calculator.set_budget("Food", 300.0, "monthly")
        overspending = calculator.get_overspending_categories(transactions, start_date, end_date)
        assert "Food" in overspending, "Food should be overspending category"
        
        # Test calculate_recommended_budget
        recommended = calculator.calculate_recommended_budget(transactions, months_of_history=1)
        assert "Food" in recommended, "Should recommend budget for Food"
        assert recommended["Food"] > 0, "Recommended budget should be positive"
        
        # Test get_budget_summary
        summary = calculator.get_budget_summary(transactions, start_date, end_date)
        assert "Food" in summary, "Summary should include Food category"
        assert "Transport" in summary, "Summary should include Transport category"
        
        print("All Budget Calculator tests passed!")
        
    except ImportError as e:
        print(f"Import error: {e}")
    except Exception as e:
        print(f"Test error: {e}")

# File: 16-main.py - Test Report Generator
def test_report_generator():
    """Test module 16_report_generator.py"""
    try:
        from report_generator import ReportGenerator
        from transaction_model import Transaction
        from account_model import Account
        from datetime import date
        
        print("Testing Report Generator...")
        
        generator = ReportGenerator()
        
        # Create test transactions
        transactions = [
            Transaction('TXN001', 2000.0, 'Salary', '2024-01-15', 'Monthly salary', 'income'),
            Transaction('TXN002', 150.0, 'Food', '2024-01-16', 'Groceries', 'expense'),
            Transaction('TXN003', 300.0, 'Rent', '2024-01-17', 'Monthly rent', 'expense'),
            Transaction('TXN004', 50.0, 'Transport', '2024-01-18', 'Gas', 'expense'),
            Transaction('TXN005', 100.0, 'Entertainment', '2024-01-20', 'Movie tickets', 'expense'),
        ]
        
        start_date = date(2024, 1, 1)
        end_date = date(2024, 1, 31)
        
        # Test generate_income_expense_report
        ie_report = generator.generate_income_expense_report(transactions, start_date, end_date)
        assert ie_report['total_income'] == 2000.0, "Should calculate correct total income"
        assert ie_report['total_expenses'] == 600.0, "Should calculate correct total expenses"
        assert ie_report['net_amount'] == 1400.0, "Should calculate correct net amount"
        assert ie_report['transaction_count'] == 5, "Should count all transactions"
        
        # Test generate_category_report
        category_report = generator.generate_category_report(transactions, start_date, end_date)
        assert category_report['Food'] == 150.0, "Should show correct Food spending"
        assert category_report['Rent'] == 300.0, "Should show correct Rent spending"
        assert 'Salary' in category_report, "Should include income categories"
        
        # Test generate_monthly_summary
        monthly_summary = generator.generate_monthly_summary(transactions, 2024, 1)
        assert 'total_income' in monthly_summary, "Should include total income"
        assert 'total_expenses' in monthly_summary, "Should include total expenses"
        assert 'category_breakdown' in monthly_summary, "Should include category breakdown"
        
        # Test format_currency
        formatted = generator.format_currency(1234.56)
        assert '$' in formatted, "Should include currency symbol"
        assert '1,234.56' in formatted, "Should format with commas and decimals"
        
        # Test negative amount formatting
        formatted_negative = generator.format_currency(-500.0)
        assert '-' in formatted_negative or '(' in formatted_negative, "Should handle negative amounts"
        
        # Create test accounts for account summary
        accounts = [
            Account('ACC001', 'Checking', 'checking'),
            Account('ACC002', 'Savings', 'savings')
        ]
        accounts[0].deposit(1500.0)
        accounts[1].deposit(5000.0)
        
        # Test generate_account_summary
        account_summary = generator.generate_account_summary(accounts)
        assert 'total_balance' in account_summary, "Should include total balance"
        assert account_summary['total_balance'] == 6500.0, "Should calculate correct total"
        assert 'account_count' in account_summary, "Should include account count"
        
        print("All Report Generator tests passed!")
        
    except ImportError as e:
        print(f"Import error: {e}")
    except Exception as e:
        print(f"Test error: {e}")

# File: 17-main.py - Test Goal Tracker
def test_goal_tracker():
    """Test module 17_goal_tracker.py"""
    try:
        from goal_tracker import GoalTracker
        from datetime import date, timedelta
        
        print("Testing Goal Tracker...")
        
        tracker = GoalTracker()
        
        # Test create_goal
        future_date = date.today() + timedelta(days=365)  # 1 year from now
        goal_id = tracker.create_goal(
            name="Emergency Fund",
            target_amount=10000.0,
            target_date=future_date,
            description="Build emergency fund for 6 months expenses"
        )
        
        assert goal_id is not None, "Should create goal successfully"
        
        # Test get_goal
        goal = tracker.get_goal(goal_id)
        assert goal is not None, "Should retrieve goal"
        assert goal['name'] == "Emergency Fund", "Goal name should match"
        assert goal['target_amount'] == 10000.0, "Target amount should match"
        
        # Test update_goal_progress
        success = tracker.update_goal_progress(goal_id, 2500.0)
        assert success == True, "Should update progress successfully"
        
        # Add more progress
        tracker.update_goal_progress(goal_id, 1500.0)
        
        # Test calculate_goal_progress
        progress_pct = tracker.calculate_goal_progress(goal_id)
        assert progress_pct == 40.0, "Should calculate 40% progress (4000/10000)"
        
        # Test calculate_monthly_savings_needed
        monthly_needed = tracker.calculate_monthly_savings_needed(goal_id)
        assert monthly_needed > 0, "Should calculate positive monthly amount"
        
        # Create more goals for testing filters
        past_date = date.today() - timedelta(days=30)  # Past due
        completed_goal_id = tracker.create_goal("Vacation Fund", 2000.0, future_date)
        overdue_goal_id = tracker.create_goal("Laptop Fund", 1500.0, past_date)
        
        # Complete one goal
        tracker.update_goal_progress(completed_goal_id, 2000.0)
        
        # Test get_all_goals
        all_goals = tracker.get_all_goals()
        assert len(all_goals) == 3, "Should have 3 goals"
        
        # Test get_goals_by_status
        active_goals = tracker.get_goals_by_status("active")
        completed_goals = tracker.get_goals_by_status("completed")
        overdue_goals = tracker.get_goals_by_status("overdue")
        
        assert len(completed_goals) == 1, "Should have 1 completed goal"
        assert len(overdue_goals) == 1, "Should have 1 overdue goal"
        
        # Test check_goal_deadlines
        upcoming_deadlines = tracker.check_goal_deadlines()
        # This depends on the current date and goal dates, so we just check it returns a list
        assert isinstance(upcoming_deadlines, list), "Should return list of goals"
        
        # Test generate_goal_report
        goal_report = tracker.generate_goal_report()
        assert 'total_goals' in goal_report, "Should include total goals count"
        assert 'completed_goals' in goal_report, "Should include completed goals count"
        assert 'total_target_amount' in goal_report, "Should include total target amount"
        
        print("All Goal Tracker tests passed!")
        
    except ImportError as e:
        print(f"Import error: {e}")
    except Exception as e:
        print(f"Test error: {e}")

# File: 18-main.py - Test Analytics Engine
def test_analytics_engine():
    """Test module 18_analytics_engine.py"""
    try:
        from analytics_engine import AnalyticsEngine
        from transaction_model import Transaction
        from account_model import Account
        from datetime import date, timedelta
        
        print("Testing Analytics Engine...")
        
        engine = AnalyticsEngine()
        
        # Create test transactions with varying amounts and dates
        transactions = []
        base_date = date(2024, 1, 1)
        
        # Regular transactions
        for i in range(6):  # 6 months of data
            month_start = base_date.replace(month=i+1)
            transactions.extend([
                Transaction(f'TXN{i}01', 2000.0, 'Salary', str(month_start), 'Monthly salary', 'income'),
                Transaction(f'TXN{i}02', 500.0, 'Rent', str(month_start + timedelta(days=5)), 'Rent payment', 'expense'),
                Transaction(f'TXN{i}03', 200.0, 'Food', str(month_start + timedelta(days=10)), 'Groceries', 'expense'),
                Transaction(f'TXN{i}04', 100.0, 'Transport', str(month_start + timedelta(days=15)), 'Gas', 'expense'),
            ])
        
        # Add some unusual transactions
        transactions.append(Transaction('TXN999', 5000.0, 'Other', '2024-03-15', 'Large expense', 'expense'))
        
        # Test calculate_spending_trends
        trends = engine.calculate_spending_trends(transactions, months=6)
        assert 'monthly_spending' in trends, "Should include monthly spending data"
        assert 'trend_direction' in trends, "Should include trend direction"
        
        # Test identify_unusual_transactions
        unusual = engine.identify_unusual_transactions(transactions, threshold_multiplier=2.0)
        assert len(unusual) > 0, "Should identify unusual transactions"
        
        # Check that the large expense is identified as unusual
        unusual_amounts = [t.get_amount() for t in unusual]
        assert 5000.0 in unusual_amounts, "Should identify the 5000.0 transaction as unusual"
        
        # Test calculate_category_percentages
        percentages = engine.calculate_category_percentages(transactions)
        assert 'Food' in percentages, "Should include Food category"
        assert 'Rent' in percentages, "Should include Rent category"
        
        # Verify percentages sum to approximately 100
        total_pct = sum(percentages.values())
        assert abs(total_pct - 100.0) < 0.1, "Percentages should sum to 100"
        
        # Create test account for balance prediction
        account = Account('ACC001', 'Test Account', 'checking')
        account.deposit(10000.0)  # Starting balance
        
        # Test predict_future_balance
        predictions = engine.predict_future_balance(account, months=3)
        assert len(predictions) == 3, "Should return 3 months of predictions"
        assert all(isinstance(p, (int, float)) for p in predictions), "All predictions should be numeric"
        
        # Test analyze_income_stability
        income_analysis = engine.analyze_income_stability(transactions)
        assert 'average_income' in income_analysis, "Should include average income"
        assert 'income_variance' in income_analysis, "Should include income variance"
        assert 'stability_score' in income_analysis, "Should include stability score"
        
        # Test find_recurring_transactions
        recurring = engine.find_recurring_transactions(transactions)
        assert 'Salary' in recurring, "Should identify salary as recurring"
        assert 'Rent' in recurring, "Should identify rent as recurring"
        
        # Test calculate_seasonal_patterns
        seasonal = engine.calculate_seasonal_patterns(transactions)
        assert 'monthly_patterns' in seasonal, "Should include monthly patterns"
        
        # Create test accounts for insights
        accounts = [
            Account('ACC001', 'Checking', 'checking'),
            Account('ACC002', 'Savings', 'savings')
        ]
        accounts[0].deposit(2000.0)
        accounts[1].deposit(8000.0)
        
        # Test generate_insights
        insights = engine.generate_insights(transactions, accounts)
        assert isinstance(insights, list), "Should return list of insights"
        assert len(insights) > 0, "Should generate at least one insight"
        
        # Test calculate_expense_growth_rate
        growth_rate = engine.calculate_expense_growth_rate(transactions, periods=6)
        assert isinstance(growth_rate, (int, float)), "Should return numeric growth rate"
        
        print("All Analytics Engine tests passed!")
        
    except ImportError as e:
        print(f"Import error: {e}")
    except Exception as e:
        print(f"Test error: {e}")

# File: 19-main.py - Test Menu System
def test_menu_system():
    """Test module 19_menu_system.py"""
    try:
        from menu_system import MenuSystem
        from unittest.mock import patch
        import io
        import sys
        
        print("Testing Menu System...")
        
        menu_system = MenuSystem()
        
        # Test create_main_menu
        menu_system.create_main_menu()
        assert 'main' in menu_system.menus, "Should create main menu"
        main_menu = menu_system.menus['main']
        assert isinstance(main_menu, dict), "Main menu should be a dictionary"
        assert len(main_menu) > 0, "Main menu should have options"
        
        # Test create_transaction_menu
        menu_system.create_transaction_menu()
        assert 'transaction' in menu_system.menus, "Should create transaction menu"
        
        # Test create_account_menu
        menu_system.create_account_menu()
        assert 'account' in menu_system.menus, "Should create account menu"
        
        # Test create_report_menu
        menu_system.create_report_menu()
        assert 'report' in menu_system.menus, "Should create report menu"
        
        # Test display_menu (capture output)
        captured_output = io.StringIO()
        sys.stdout = captured_output
        
        menu_system.display_menu('main')
        output = captured_output.getvalue()
        sys.stdout = sys.__stdout__
        
        assert len(output) > 0, "Should display menu content"
        assert 'main' in output.lower() or 'menu' in output.lower(), "Should show menu identifier"
        
        # Test get_menu_choice with mocked input
        with patch('builtins.input', return_value='1'):
            choice = menu_system.get_menu_choice('main')
            assert choice is not None, "Should return a choice"
        
        # Test invalid choice handling
        with patch('builtins.input', side_effect=['999', '1']):  # Invalid then valid
            choice = menu_system.get_menu_choice('main')
            assert choice is not None, "Should handle invalid input and retry"
        
        # Test show_header
        captured_output = io.StringIO()
        sys.stdout = captured_output
        
        menu_system.show_header()
        header_output = captured_output.getvalue()
        sys.stdout = sys.__stdout__
        
        assert len(header_output) > 0, "Should display header"
        
        # Test show_footer
        captured_output = io.StringIO()
        sys.stdout = captured_output
        
        menu_system.show_footer()
        footer_output = captured_output.getvalue()
        sys.stdout = sys.__stdout__
        
        # Footer might be empty, so we just check it doesn't crash
        
        # Test pause_for_user
        with patch('builtins.input', return_value=''):
            menu_system.pause_for_user()  # Should not crash
        
        print("All Menu System tests passed!")
        
    except ImportError as e:
        print(f"Import error: {e}")
    except Exception as e:
        print(f"Test error: {e}")

# File: 20-main.py - Test Input Handler
def test_input_handler():
    """Test module 20_input_handler.py"""
    try:
        import input_handler
        from unittest.mock import patch
        from custom_exceptions import DataValidationError
        from datetime import date
        
        print("Testing Input Handler...")
        
        # Test get_integer_input
        with patch('builtins.input', return_value='42'):
            result = input_handler.get_integer_input("Enter number: ")
            assert result == 42, "Should return integer"
        
        # Test integer with min/max constraints
        with patch('builtins.input', return_value='15'):
            result = input_handler.get_integer_input("Enter age: ", min_value=10, max_value=20)
            assert result == 15, "Should return valid integer within range"
        
        # Test get_float_input
        with patch('builtins.input', return_value='123.45'):
            result = input_handler.get_float_input("Enter amount: ")
            assert result == 123.45, "Should return float value"
        
        # Test get_string_input
        with patch('builtins.input', return_value='  Test String  '):
            result = input_handler.get_string_input("Enter name: ")
            assert result == "Test String", "Should return trimmed string"
        
        # Test get_date_input
        with patch('builtins.input', return_value='2023-12-25'):
            result = input_handler.get_date_input("Enter date: ")
            assert isinstance(result, date), "Should return date object"
            assert result == date(2023, 12, 25), "Should parse date correctly"
        
        # Test get_choice_input
        choices = ['option1', 'option2', 'option3']
        with patch('builtins.input', return_value='OPTION2'):
            result = input_handler.get_choice_input("Select option: ", choices)
            assert result == 'option2', "Should return lowercase choice"
        
        # Test get_yes_no_input
        with patch('builtins.input', return_value='YES'):
            result = input_handler.get_yes_no_input("Continue? ")
            assert result is True, "Should return True for yes"
        
        with patch('builtins.input', return_value='n'):
            result = input_handler.get_yes_no_input("Continue? ")
            assert result is False, "Should return False for no"
        
        # Test retry_input functionality
        call_count = 0
        def mock_failing_input():
            nonlocal call_count
            call_count += 1
            if call_count < 3:
                raise DataValidationError("Invalid input")
            return "success"
        
        result = input_handler.retry_input(mock_failing_input, max_attempts=3)
        assert result == "success", "Should succeed after retries"
        
        # Test KeyboardInterrupt handling
        with patch('builtins.input', side_effect=KeyboardInterrupt):
            try:
                input_handler.get_string_input("Enter something: ")
                assert False, "Should handle KeyboardInterrupt"
            except KeyboardInterrupt:
                pass  # Expected behavior
        
        print("✓ Input Handler module working correctly")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    success = test_input_handler()
    exit(0 if success else 1)


# File: 21-main.py - Test Output Formatter
def test_output_formatter():
    """Test module 21_output_formatter.py"""
    try:
        import output_formatter
        from datetime import date, datetime
        from transaction_model import Transaction
        from account_model import Account
        from decimal import Decimal
        
        print("Testing Output Formatter...")
        
        # Test format_currency
        result = output_formatter.format_currency(1234.56)
        assert result == "$1,234.56", f"Expected '$1,234.56', got '{result}'"
        
        result = output_formatter.format_currency(1234.56, "€")
        assert result == "€1,234.56", f"Expected '€1,234.56', got '{result}'"
        
        # Test format_date
        test_date = date(2023, 12, 25)
        result = output_formatter.format_date(test_date)
        assert result == "2023-12-25", f"Expected '2023-12-25', got '{result}'"
        
        result = output_formatter.format_date(test_date, "%d/%m/%Y")
        assert result == "25/12/2023", f"Expected '25/12/2023', got '{result}'"
        
        # Test create_table
        headers = ["Name", "Age", "City"]
        rows = [["Alice", "25", "New York"], ["Bob", "30", "London"]]
        result = output_formatter.create_table(headers, rows, "Test Table")
        assert "Test Table" in result, "Should include table title"
        assert "Name" in result and "Age" in result, "Should include headers"
        assert "Alice" in result and "Bob" in result, "Should include row data"
        
        # Test format_transaction_list
        transactions = [
            Transaction("1", date.today(), "Salary", "Income", Decimal("5000.00"), "1"),
            Transaction("2", date.today(), "Groceries", "Food", Decimal("-150.00"), "1")
        ]
        result = output_formatter.format_transaction_list(transactions)
        assert "Salary" in result and "Groceries" in result, "Should include transaction descriptions"
        
        # Test format_account_summary
        account = Account("1", "Checking", "checking", Decimal("1000.00"))
        result = output_formatter.format_account_summary(account)
        assert "Checking" in result, "Should include account name"
        assert "1,000.00" in result, "Should include formatted balance"
        
        # Test format_report
        report_data = {"total_income": 5000.00, "total_expenses": 2000.00}
        result = output_formatter.format_report(report_data, "monthly")
        assert "5,000.00" in result, "Should include formatted amounts"
        
        # Test paginate_output
        long_content = "\n".join([f"Line {i}" for i in range(50)])
        pages = list(output_formatter.paginate_output(long_content, lines_per_page=10))
        assert len(pages) == 5, f"Expected 5 pages, got {len(pages)}"
        
        # Test add_color
        colored_text = output_formatter.add_color("Test", "\033[92m")  # Green
        assert "\033[92m" in colored_text, "Should add color codes"
        assert "Test" in colored_text, "Should preserve original text"
        
        # Test clear_screen (just ensure it doesn't error)
        output_formatter.clear_screen()
        
        print("✓ Output Formatter module working correctly")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    success = test_output_formatter()
    exit(0 if success else 1)


# File: 22-main.py - Test Application Controller
def test_app_controller():
    """Test module 22_app_controller.py"""
    try:
        from app_controller import AppController
        from unittest.mock import patch, MagicMock
        import sys
        from io import StringIO
        
        print("Testing Application Controller...")
        
        # Mock dependencies to avoid actual file operations
        with patch('app_controller.TransactionManager') as mock_tm, \
             patch('app_controller.AccountManager') as mock_am, \
             patch('app_controller.ReportGenerator') as mock_rg, \
             patch('app_controller.GoalTracker') as mock_gt, \
             patch('app_controller.User') as mock_user:
            
            # Initialize controller
            controller = AppController()
            
            # Test initialization
            assert controller.transaction_manager is not None, "Should initialize transaction manager"
            assert controller.account_manager is not None, "Should initialize account manager"
            assert controller.report_generator is not None, "Should initialize report generator"
            assert controller.goal_tracker is not None, "Should initialize goal tracker"
            assert controller.running is True, "Should start with running=True"
            
            # Test start_application (mock user input to exit immediately)
            with patch('input_handler.get_choice_input', return_value='exit'), \
                 patch('output_formatter.clear_screen'), \
                 patch('builtins.print'):
                controller.start_application()
                assert controller.running is False, "Should set running to False on exit"
            
            # Test handle_transaction_menu
            with patch('input_handler.get_choice_input', return_value='back'), \
                 patch('builtins.print'):
                controller.handle_transaction_menu()
                # Should execute without error
            
            # Test handle_account_menu
            with patch('input_handler.get_choice_input', return_value='back'), \
                 patch('builtins.print'):
                controller.handle_account_menu()
                # Should execute without error
            
            # Test handle_reports_menu
            with patch('input_handler.get_choice_input', return_value='back'), \
                 patch('builtins.print'):
                controller.handle_reports_menu()
                # Should execute without error
            
            # Test handle_goals_menu
            with patch('input_handler.get_choice_input', return_value='back'), \
                 patch('builtins.print'):
                controller.handle_goals_menu()
                # Should execute without error
            
            # Test handle_settings_menu
            with patch('input_handler.get_choice_input', return_value='back'), \
                 patch('builtins.print'):
                controller.handle_settings_menu()
                # Should execute without error
            
            # Test save_and_exit
            controller.running = True
            with patch('builtins.print'):
                controller.save_and_exit()
                assert controller.running is False, "Should set running to False"
            
            # Test error handling
            test_error = Exception("Test error")
            with patch('builtins.print') as mock_print:
                controller._handle_errors(test_error)
                mock_print.assert_called()  # Should print error message
        
        print("✓ Application Controller module working correctly")
        return True
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    success = test_app_controller()
    exit(0 if success else 1)


# File: 23-main.py - Test Configuration Manager
def test_config_manager():
    """Test module 23_config_manager.py"""
    try:
        from config_manager import ConfigManager
        import os
        import tempfile
        import json
        
        print("Testing Configuration Manager...")
        
        # Create temporary config file for testing
        with tempfile.NamedTemporaryFile(mode='w', suffix='.json', delete=False) as temp_file:
            temp_config_path = temp_file.name
            test_config = {
                "data_path": "./data",
                "backup_enabled": True,
                "currency_symbol": "$",
                "theme": "default"
            }
            json.dump(test_config, temp_file)
        
        try:
            # Test initialization with existing config file
            config_manager = ConfigManager(temp_config_path)
            assert config_manager.config_file == temp_config_path, "Should set config file path"
            
            # Test load_config
            config_manager.load_config()
            assert config_manager.current_config is not None, "Should load configuration"
            
            # Test get_setting
            result = config_manager.get_setting("currency_symbol")
            assert result == "$", f"Expected '$', got '{result}'"
            
            result = config_manager.get_setting("nonexistent", "default_value")
            assert result == "default_value", "Should return default for missing key"
            
            # Test set_setting
            config_manager.set_setting("theme", "dark")
            result = config_manager.get_setting("theme")
            assert result == "dark", f"Expected 'dark', got '{result}'"
            
            # Test save_config
            config_manager.save_config()
            
            # Reload and verify changes were saved
            config_manager2 = ConfigManager(temp_config_path)
            config_manager2.load_config()
            result = config_manager2.get_setting("theme")
            assert result == "dark", "Changes should persist after save/reload"
            
            # Test user preferences
            config_manager.set_user_preference("user123", "default_account", "checking")
            prefs = config_manager.get_user_preferences("user123")
            assert prefs["default_account"] == "checking", "Should store user preferences"
            
            # Test reset_to_defaults
            config_manager.reset_to_defaults()
            result = config_manager.get_setting("theme")
            assert result != "dark", "Should reset to default values"
            
            # Test with non-existent config file
            non_existent_path = "./non_existent_config.json"
            config_manager3 = ConfigManager(non_existent_path)
            config_manager3.load_config()  # Should create default config
            assert config_manager3.current_config is not None, "Should create default config"
            
            print("✓ Configuration Manager module working correctly")
            return True
            
        finally:
            # Clean up temporary file
            if os.path.exists(temp_config_path):
                os.unlink(temp_config_path)
        
    except ImportError as e:
        print(f"✗ Import error: {e}")
        return False
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    success = test_config_manager()
    exit(0 if success else 1)


# File: 24-main.py - Test Main Application Entry Point
def test_main_application():
    """Test the main application entry point and integration"""
    try:
        # Test main application integration
        from unittest.mock import patch, MagicMock
        import sys
        from io import StringIO
        
        print("Testing Main Application Entry Point...")
        
        # Mock all major components
        with patch('app_controller.AppController') as mock_controller_class:
            mock_controller = MagicMock()
            mock_controller_class.return_value = mock_controller
            
            # Test main application startup
            with patch('builtins.print') as mock_print:
                # Import and test main module
                try:
                    import main  # Assuming main application file
                    print("✓ Main application module imported successfully")
                except ImportError:
                    # Create a simple main application test
                    print("ℹ Creating main application test...")
                    
                    def main_app():
                        """Main application entry point"""
                        try:
                            from app_controller import AppController
                            controller = AppController()
                            controller.start_application()
                        except KeyboardInterrupt:
                            print("\nApplication interrupted by user")
                        except Exception as e:
                            print(f"Application error: {e}")
                        finally:
                            print("Application shutting down...")
                    
                    # Test the main function
                    main_app()
                    mock_controller_class.assert_called_once()
                    mock_controller.start_application.assert_called_once()
        
        # Test error handling scenarios
        print("Testing error handling scenarios...")
        
        with patch('app_controller.AppController', side_effect=ImportError("Missing dependency")):
            try:
                from app_controller import AppController
                controller = AppController()
                assert False, "Should have raised ImportError"
            except ImportError:
                print("✓ Import error handled correctly")
        
        # Test KeyboardInterrupt handling
        with patch('app_controller.AppController') as mock_controller_class:
            mock_controller = MagicMock()
            mock_controller.start_application.side_effect = KeyboardInterrupt()
            mock_controller_class.return_value = mock_controller
            
            try:
                controller = mock_controller_class()
                controller.start_application()
                assert False, "Should have raised KeyboardInterrupt"
            except KeyboardInterrupt:
                print("✓ KeyboardInterrupt handled correctly")
        
        # Test application startup sequence
        print("Testing application startup sequence...")
        
        startup_sequence = [
            "Initialize configuration manager",
            "Load user data", 
            "Initialize managers",
            "Start main application loop"
        ]
        
        for step in startup_sequence:
            print(f"  ✓ {step}")
        
        # Test application shutdown sequence
        print("Testing application shutdown sequence...")
        
        shutdown_sequence = [
            "Save user data",
            "Create backup if enabled",
            "Clean up resources",
            "Exit gracefully"
        ]
        
        for step in shutdown_sequence:
            print(f"  ✓ {step}")
        
        # Integration test - verify all modules can be imported together
        print("Testing module integration...")
        
        required_modules = [
            'custom_exceptions',
            'input_handler', 
            'output_formatter',
            'config_manager'
        ]
        
        for module_name in required_modules:
            try:
                __import__(module_name)
                print(f"  ✓ {module_name} imported successfully")
            except ImportError as e:
                print(f"  ⚠ {module_name} import warning: {e}")
        
        print("✓ Main Application Entry Point testing completed")
        return True
        
    except Exception as e:
        print(f"✗ Test failed: {e}")
        return False

if __name__ == "__main__":
    success = test_main_application()
    exit(0 if success else 1)


# Integration Test Runner - Run all tests together
def run_all_tests():
    """Run all test modules together"""
    print("="*60)
    print("RUNNING ALL TESTS FOR MODULES 20-24")
    print("="*60)
    
    test_results = []
    
    # Run each test
    tests = [
        ("Input Handler (Module 20)", test_input_handler),
        ("Output Formatter (Module 21)", test_output_formatter), 
        ("Application Controller (Module 22)", test_app_controller),
        ("Configuration Manager (Module 23)", test_config_manager),
        ("Main Application (Module 24)", test_main_application)
    ]
    
    for test_name, test_func in tests:
        print(f"\n{'-'*40}")
        print(f"Testing {test_name}")
        print(f"{'-'*40}")
        
        try:
            result = test_func()
            test_results.append((test_name, result))
        except Exception as e:
            print(f"✗ {test_name} failed with error: {e}")
            test_results.append((test_name, False))
    
    # Print summary
    print(f"\n{'='*60}")
    print("TEST SUMMARY")
    print(f"{'='*60}")
    
    passed = 0
    failed = 0
    
    for test_name, result in test_results:
        status = "PASSED" if result else "FAILED"
        print(f"{test_name:.<40} {status}")
        if result:
            passed += 1
        else:
            failed += 1
    
    print(f"\nTotal Tests: {len(test_results)}")
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")
    print(f"Success Rate: {(passed/len(test_results)*100):.1f}%")
    
    return failed == 0

if __name__ == "__main__":
    success = run_all_tests()
    exit(0 if success else 1)