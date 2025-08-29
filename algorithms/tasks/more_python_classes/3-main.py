#!/usr/bin/python3
"""3-main.py - Test file for Task 3: CheckingAccount with Overdraft"""

BankAccount = __import__('1-bank').BankAccount
CheckingAccount = __import__('3-bank').CheckingAccount

print("=== Testing CheckingAccount with Overdraft ===")

# Test CheckingAccount creation
checking = CheckingAccount("Edward Norton", "CHK001")
print(f"Account created: {checking.name}")
print(f"Account type: {checking.get_account_type()}")
print(f"Overdraft limit: ${checking.overdraft_limit}")
print(f"Initial balance: ${checking.balance}")
print(f"Available overdraft: ${checking.get_overdraft_available()}")

print("\n=== Testing Normal Operations ===")

# Test normal deposit and withdrawal
checking.deposit(300)
print(f"Balance after $300 deposit: ${checking.balance}")
print(f"Available overdraft: ${checking.get_overdraft_available()}")

checking.withdraw(150)
print(f"Balance after $150 withdrawal: ${checking.balance}")
print(f"Available overdraft: ${checking.get_overdraft_available()}")

print("\n=== Testing Overdraft Usage ===")

# Test withdrawal that uses overdraft
print(f"Current balance: ${checking.balance}")
print(f"Attempting to withdraw $300 (will use overdraft):")
checking.withdraw(300)
print(f"Balance after overdraft withdrawal: ${checking.balance}")
print(f"Available overdraft remaining: ${checking.get_overdraft_available()}")

# Test another overdraft withdrawal
print(f"\nAttempting to withdraw another $200:")
checking.withdraw(200)
print(f"Balance: ${checking.balance}")
print(f"Available overdraft: ${checking.get_overdraft_available()}")

print("\n=== Testing Overdraft Limit ===")

# Test withdrawal that exceeds overdraft limit
print(f"Attempting to withdraw $400 (should exceed limit):")
checking.withdraw(400)
print(f"Balance remains: ${checking.balance}")
print(f"Available overdraft: ${checking.get_overdraft_available()}")

# Test exact limit withdrawal
available = checking.get_overdraft_available()
print(f"\nAttempting to withdraw exactly ${available} (should work):")
checking.withdraw(available)
print(f"Balance: ${checking.balance}")
print(f"Available overdraft: ${checking.get_overdraft_available()}")

print("\n=== Testing Overdraft Limit Property ===")

# Test overdraft limit modification
checking.overdraft_limit = 1000
print(f"New overdraft limit: ${checking.overdraft_limit}")
print(f"Available overdraft with new limit: ${checking.get_overdraft_available()}")

print("\n=== Testing Recovery from Overdraft ===")

# Test depositing money to recover from overdraft
print(f"Current balance: ${checking.balance}")
checking.deposit(600)
print(f"Balance after $600 deposit: ${checking.balance}")
print(f"Available overdraft: ${checking.get_overdraft_available()}")

print("\n=== Testing String Representation ===")
print("CheckingAccount string representation:")
print(checking)

print("\n=== Comparing with Regular BankAccount ===")

regular = BankAccount("Regular User", "REG002")
regular.deposit(100)

print(f"\nRegular account balance: ${regular.balance}")
print("Attempting $200 withdrawal from regular account:")
regular.withdraw(200)  # Should be denied
print(f"Regular account balance: ${regular.balance}")

checking2 = CheckingAccount("Checking User", "CHK002")
checking2.deposit(100)
print(f"\nChecking account balance: ${checking2.balance}")
print("Attempting $200 withdrawal from checking account:")
checking2.withdraw(200)  # Should work with overdraft
print(f"Checking account balance: ${checking2.balance}")

print("=" * 50)