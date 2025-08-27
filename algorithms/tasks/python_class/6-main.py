#!/usr/bin/python3
"""6-main.py - Test file for Task 6: BankAccount with string representation"""

BankAccount = __import__('6-bank').BankAccount

try:
    print("=== Creating and testing BankAccount ===")
    account = BankAccount("Grace Taylor", "789123456")
    
    print("Initial account state:")
    print(account)
    print()

    print("=== Performing transactions ===")
    account.deposit(1500)
    print("After $1500 deposit:")
    print(account)
    print()
    
    account.deposit(750)
    account.withdraw(500)
    account.withdraw(250)
    
    print("After additional transactions:")
    print(account)
    print()
    
    print("=== Testing invalid operations ===")
    account.deposit(-100)
    account.withdraw(3000)
    
    print("After invalid operations (no change expected):")
    print(account)
    print()
    
    print("=== Complete Transaction History ===")
    transactions = account.get_transaction_log()
    if transactions:
        for i, transaction in enumerate(transactions, 1):
            print(f"Transaction {i}:")
            print(f"  Type: {transaction['type']}")
            print(f"  Amount: ${transaction['amount']}")
            print(f"  Balance After: ${transaction['balance_after']}")
            print()
    else:
        print("No transactions found.")
    
    print("=== Testing name change ===")
    account.set_name("Grace T. Taylor")
    print("After name change:")
    print(account)
    
except Exception as e:
    print(f"Error: {e}")