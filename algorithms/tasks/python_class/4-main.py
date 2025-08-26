#!/usr/bin/python3
"""4-main.py - Test file for Task 4: BankAccount with withdrawal"""

BankAccount = __import__('4-bank').BankAccount

# Test all functionality including withdrawal
try:
    account = BankAccount("Emma Brown", "111222333")
    
    # Initial setup
    print(f"Account holder: {account.get_name()}")
    print(f"Initial balance: ${account.get_balance()}")
    
    # Add some money
    account.deposit(1000)
    print(f"Balance after $1000 deposit: ${account.get_balance()}")
    
    # Test successful withdrawals
    print("\nTesting withdrawals:")
    account.withdraw(300)
    print(f"Balance after $300 withdrawal: ${account.get_balance()}")
    
    account.withdraw(200)
    print(f"Balance after $200 withdrawal: ${account.get_balance()}")
    
    # Test withdrawal of exact balance
    account.withdraw(500)
    print(f"Balance after $500 withdrawal: ${account.get_balance()}")
    
    # Test insufficient funds
    print("\nTesting insufficient funds:")
    account.withdraw(100)
    account.withdraw(1)
    print(f"Final balance: ${account.get_balance()}")
    
except Exception as e:
    print(f"Error: {e}")

print("=" * 50)