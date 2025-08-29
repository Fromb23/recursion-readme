#!/usr/bin/python3
"""1-main.py - Test file for Task 1: BankAccount with Class Attributes and Methods"""

BankAccount = __import__('1-bank').BankAccount

print("=== Testing Class Attributes and Methods ===")

# Test initial class attributes
print(f"Bank Name: {BankAccount.bank_name}")
print(f"Initial Total Accounts: {BankAccount.total_accounts}")
print(f"Interest Rate: {BankAccount.interest_rate}")

print("\n=== Testing Account Creation and Total Count ===")

# Create multiple accounts and test total_accounts increment
account1 = BankAccount("Alice Johnson", "CLS001")
print(f"Total accounts after creating account1: {BankAccount.total_accounts}")

account2 = BankAccount("Bob Wilson", "CLS002")
print(f"Total accounts after creating account2: {BankAccount.total_accounts}")

account3 = BankAccount("Carol Davis", "CLS003")
print(f"Total accounts after creating account3: {BankAccount.total_accounts}")

print("\n=== Testing Class Methods ===")

# Test get_bank_info class method
bank_info = BankAccount.get_bank_info()
print(f"Bank info: {bank_info}")

# Test set_interest_rate class method
BankAccount.set_interest_rate(0.035)
print(f"New interest rate: {BankAccount.interest_rate}")

print("\n=== Testing Static Method ===")

# Test validate_amount static method
print(f"Validate 100: {BankAccount.validate_amount(100)}")
print(f"Validate -50: {BankAccount.validate_amount(-50)}")
print(f"Validate 0: {BankAccount.validate_amount(0)}")
print(f"Validate 'abc': {BankAccount.validate_amount('abc')}")

print("\n=== Testing Enhanced Operations ===")

# Test deposits with validation
account1.deposit(1000)
account1.deposit(-100)  # Should be rejected due to validation
print(f"Account1 balance: ${account1.balance}")

# Test apply_interest method
initial_balance = account1.balance
account1.apply_interest()
print(f"Balance before interest: ${initial_balance}")
print(f"Balance after interest: ${account1.balance}")

# Test withdrawal with validation
account1.withdraw(200)
account1.withdraw(-50)  # Should be rejected due to validation
print(f"Account1 final balance: ${account1.balance}")

print("\n=== Testing Multiple Accounts with Interest ===")

account2.deposit(2000)
account3.deposit(1500)

print("Balances before interest:")
print(f"Account2: ${account2.balance}")
print(f"Account3: ${account3.balance}")

account2.apply_interest()
account3.apply_interest()

print("Balances after interest:")
print(f"Account2: ${account2.balance}")
print(f"Account3: ${account3.balance}")

print(f"\nFinal bank info: {BankAccount.get_bank_info()}")

print("=" * 50)
