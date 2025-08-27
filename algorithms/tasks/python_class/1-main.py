#!/usr/bin/python3
"""1-main.py - Test file for Task 1: BankAccount with basic attributes"""

BankAccount = __import__('1-bank').BankAccount

# Test instantiation with name and account_number
try:
    account = BankAccount("Francis Rombo", "987654321")
    print("BankAccount created successfully!")
    print(f"Account object: {account}")
    print(f"Account type: {type(account)}")
    
    # Check if attributes exist (even though they're private)
    print(f"Has _name attribute: {hasattr(account, '_name')}")
    print(f"Has _account_number attribute: {hasattr(account, '_account_number')}")
    print(f"Has _balance attribute: {hasattr(account, '_balance')}")
    
except Exception as e:
    print(f"Error: {e}")

print("=" * 50)