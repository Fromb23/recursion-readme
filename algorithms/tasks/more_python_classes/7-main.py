#!/usr/bin/python3
"""7-main.py - Test file for Task 7: Abstract Account Base and Operator Overloading"""

from abc import ABC, abstractmethod
AbstractAccount = __import__('7-bank').AbstractAccount
BankAccount = __import__('7-bank').BankAccount

print("=== Testing Abstract Base Class ===")

# Test that AbstractAccount cannot be instantiated
try:
    abstract = AbstractAccount()
    print("ERROR: Abstract class should not be instantiable")
except TypeError as e:
    print(f"✓ Abstract class correctly non-instantiable: {e}")

print("\n=== Testing BankAccount Implementation ===")

# Test that BankAccount properly implements abstract methods
try:
    account1 = BankAccount("John Doe", "ABS001")
    account2 = BankAccount("Jane Smith", "ABS002")
    print(f"✓ BankAccount successfully created")
    print(f"Account 1: {account1.name}")
    print(f"Account 2: {account2.name}")
except Exception as e:
    print(f"Error creating BankAccount: {e}")

# Test abstract method implementations
print(f"Account 1 type: {account1.get_account_type()}")
print(f"Account 1 fees: ${account1.calculate_fees()}")

print("\n=== Testing Equality Operator (__eq__) ===")

# Test account equality (should compare by account number)
account3 = BankAccount("John Doe Jr", "ABS001")  # Same account number
account4 = BankAccount("John Doe", "ABS003")     # Different account number

print(f"account1 == account2: {account1 == account2}")  # Different numbers
print(f"account1 == account3: {account1 == account3}")  # Same numbers
print(f"account1 == account4: {account1 == account4}")  # Different numbers

# Test with different balances but same account number
account3.deposit(1000)
print(f"account1 balance: ${account1.balance}")
print(f"account3 balance: ${account3.balance}")
print(f"account1 == account3 (different balances): {account1 == account3}")

print("\n=== Testing Less Than Operator (__lt__) ===")

# Set up accounts with different balances for comparison
account1.deposit(500)
account2.deposit(1000)
account4.deposit(250)

print(f"Account balances:")
print(f"  account1: ${account1.balance}")
print(f"  account2: ${account2.balance}")