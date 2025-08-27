#!/usr/bin/python3
"""3-main.py - Test file for Task 3: BankAccount with setters and deposit"""

BankAccount = __import__('3-bank').BankAccount

try:
    account = BankAccount("Francis Rombo", "555666777")
    
    print(f"Initial account holder: {account.get_name()}")
    print(f"Initial balance: ${account.get_balance()}")
    
    account.set_name("Francis O. Rombo")
    account.set_balance(100)
    
    print(f"Updated name: {account.get_name()}")
    print(f"Updated balance: ${account.get_balance()}")
    
    print("\nTesting deposits:")
    account.deposit(500)
    print(f"Balance after $500 deposit: ${account.get_balance()}")
    
    account.deposit(250)
    print(f"Balance after $250 deposit: ${account.get_balance()}")
    
    print("\nTesting invalid deposit:")
    account.deposit(-100)
    account.deposit(0)
    print(f"Balance after invalid deposits: ${account.get_balance()}")
    
except Exception as e:
    print(f"Error: {e}")

print("=" * 50)