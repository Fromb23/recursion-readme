#!/usr/bin/python3
"""0-main.py - Test file for Task 0: Empty BankAccount class"""

BankAccount = __import__('0-bank').BankAccount

# Test that the class can be instantiated
try:
    account = BankAccount()
    print("BankAccount class created successfully!")
    print(f"Type: {type(account)}")
    print(f"Class name: {account.__class__.__name__}")
except Exception as e:
    print(f"Error creating BankAccount: {e}")

print("=" * 50)