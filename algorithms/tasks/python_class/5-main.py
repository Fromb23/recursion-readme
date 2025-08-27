#!/usr/bin/python3
"""5-main.py - Test file for Task 5: BankAccount with transaction logging"""

BankAccount = __import__('5-bank').BankAccount

try:
    account = BankAccount("Frank Miller", "444555666")
    
    print(f"Account holder: {account.get_name()}")
    print(f"Account number: {account.get_account_number()}")
    print(f"Initial balance: ${account.get_balance()}")
    
    account.deposit(1000)
    account.deposit(500)
    account.deposit(250)
    
    account.withdraw(300)
    account.withdraw(150)
    
    account.deposit(-50)
    account.withdraw(2000)
    
    print(f"\nFinal balance: ${account.get_balance()}")
    
    print("\nTransaction History:")
    transactions = account.get_transaction_log()
    if transactions:
        for i, transaction in enumerate(transactions, 1):
            print(f"{i}. {transaction['type']}: ${transaction['amount']}, Balance after: ${transaction['balance_after']}")
    else:
        print("No transactions recorded.")
    
    print(f"\nTotal transactions: {len(transactions)}")
    
except Exception as e:
    print(f"Error: {e}")

print("=" * 50)