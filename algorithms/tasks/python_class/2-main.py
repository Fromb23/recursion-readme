#!/usr/bin/python3
"""2-main.py - Test file for Task 2: BankAccount with getters"""

BankAccount = __import__('2-bank').BankAccount

# Test instantiation and getter methods
try:
    account = BankAccount("Francis Rombo", "123456789")
    
    # Test getter methods
    print(f"Account holder: {account.get_name()}")
    print(f"Account number: {account.get_account_number()}")
    print(f"Initial balance: ${account.get_balance()}")
    
    # Test with different account
    account2 = BankAccount("SmartahyperTech", "987654321")
    print(f"\nSecond account holder: {account2.get_name()}")
    print(f"Second account number: {account2.get_account_number()}")
    print(f"Second account balance: ${account2.get_balance()}")
    
except Exception as e:
    print(f"Error: {e}")

print("=" * 50)