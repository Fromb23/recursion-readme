#!/usr/bin/python3
"""0-main.py - Test file for Task 0: BankAccount with Properties"""

BankAccount = __import__('0-bank').BankAccount

print("=== Testing BankAccount with Properties ===")

# Test valid account creation
try:
    account = BankAccount("Francis Rombo", "PROP001")
    print(f"Account created successfully")
    print(f"Name: {account.name}")
    print(f"Account Number: {account.account_number}")
    print(f"Balance: ${account.balance}")
except Exception as e:
    print(f"Error creating account: {e}")

print("\n=== Testing Name Property Validation ===")

# Test valid name change
try:
    account.name = "Francis O. Rombo"
    print(f"Name updated to: {account.name}")
except Exception as e:
    print(f"Error updating name: {e}")

# Test invalid name (empty string)
try:
    account.name = ""
    print("ERROR: Empty name should have been rejected!")
except ValueError as e:
    print(f"✓ Correctly rejected empty name: {e}")
except Exception as e:
    print(f"Unexpected error: {e}")

# Test invalid name (non-string)
try:
    account.name = 12345
    print("ERROR: Non-string name should have been rejected!")
except ValueError as e:
    print(f"✓ Correctly rejected non-string name: {e}")
except Exception as e:
    print(f"Unexpected error: {e}")

print("\n=== Testing Read-only Properties ===")

# Test that balance is read-only
try:
    account.balance = 1000
    print("ERROR: Balance should be read-only!")
except AttributeError:
    print("✓ Balance property is correctly read-only")
except Exception as e:
    print(f"Unexpected error: {e}")

# Test that account_number is read-only
try:
    account.account_number = "NEW001"
    print("ERROR: Account number should be read-only!")
except AttributeError:
    print("✓ Account number property is correctly read-only")
except Exception as e:
    print(f"Unexpected error: {e}")

print("\n=== Testing Account Operations ===")

# Test deposits and withdrawals
account.deposit(500)
print(f"Balance after $500 deposit: ${account.balance}")

account.withdraw(200)
print(f"Balance after $200 withdrawal: ${account.balance}")

# Test string representation
print(f"\nAccount details:\n{account}")

print("=" * 50)