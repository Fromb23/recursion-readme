#!/usr/bin/python3
"""2-main.py - Test file for Task 2: SavingsAccount - Basic Inheritance"""

BankAccount = __import__('1-bank').BankAccount
SavingsAccount = __import__('2-bank').SavingsAccount

print("=== Testing SavingsAccount Inheritance ===")

# Test SavingsAccount creation
savings = SavingsAccount("Diana Prince", "SAV001")
print(f"Account created: {savings.name}")
print(f"Account type: {savings.get_account_type()}")
print(f"Minimum balance: ${savings.minimum_balance}")
print(f"Initial balance: ${savings.balance}")

print("\n=== Testing Inherited Methods ===")

# Test that inherited methods work
savings.deposit(500)
print(f"Balance after $500 deposit: ${savings.balance}")

# Test apply_interest (inherited from BankAccount)
savings.apply_interest()
print(f"Balance after interest: ${savings.balance}")

print("\n=== Testing Minimum Balance Withdrawal Restrictions ===")

# Test normal withdrawal (should work)
savings.withdraw(50)
print(f"Balance after $50 withdrawal: ${savings.balance}")

# Test withdrawal that would violate minimum balance
print("\nTrying to withdraw $400 (would go below minimum):")
savings.withdraw(400)
print(f"Balance remains: ${savings.balance}")

# Test withdrawal that respects minimum balance
withdrawable = savings.balance - savings.minimum_balance
print(f"\nWithdrawing ${withdrawable} (respecting minimum balance):")
savings.withdraw(withdrawable)
print(f"Balance after withdrawal: ${savings.balance}")

# Try to withdraw even $1 more
print(f"\nTrying to withdraw $1 more:")
savings.withdraw(1)
print(f"Balance remains: ${savings.balance}")

print("\n=== Testing Minimum Balance Property ===")

# Test minimum balance getter and setter
print(f"Current minimum balance: ${savings.minimum_balance}")

# Change minimum balance
savings.minimum_balance = 200
print(f"New minimum balance: ${savings.minimum_balance}")

# Test withdrawal with new minimum balance
print(f"\nTrying withdrawal with new minimum balance requirement:")
savings.withdraw(50)  # Should be denied since balance is only $100
print(f"Balance: ${savings.balance}")

print("\n=== Testing String Representation ===")
print("SavingsAccount string representation:")
print(savings)

print("\n=== Comparing with Regular BankAccount ===")

regular = BankAccount("Regular User", "REG001")
regular.deposit(500)

print(f"\nRegular account balance: ${regular.balance}")
regular.withdraw(450)  # Should work fine
print(f"Regular account after $450 withdrawal: ${regular.balance}")

print(f"\nSavings account balance: ${savings.balance}")
savings.deposit(500)
print(f"Savings account after $500 deposit: ${savings.balance}")
savings.withdraw(450)  # Should be restricted
print(f"Savings account after attempted $450 withdrawal: ${savings.balance}")

print("=" * 50)
