#!/usr/bin/python3
"""5-main.py - Test file for Task 5: Bank Class - Composition and Account Management"""

# Import all account types
BankAccount = __import__('1-bank').BankAccount
SavingsAccount = __import__('2-bank').SavingsAccount
CheckingAccount = __import__('3-bank').CheckingAccount
BusinessAccount = __import__('4-bank').BusinessAccount
Bank = __import__('5-bank').Bank

print("=== Testing Bank Class - Account Management ===")

# Test Bank creation
bank = Bank("First National PyBank")
print(f"Bank created: {bank.bank_name}")

print("\n=== Testing Account Creation ===")

# Test creating different types of accounts
try:
    savings = bank.create_account("savings", "Alice Cooper", "SAV001")
    print(f"✓ Savings account created: {savings.get_account_type()}")
except Exception as e:
    print(f"Error creating savings: {e}")

try:
    checking = bank.create_account("checking", "Bob Dylan", "CHK001")
    print(f"✓ Checking account created: {checking.get_account_type()}")
except Exception as e:
    print(f"Error creating checking: {e}")

try:
    business = bank.create_account("business", "Tech Corp Ltd", "BUS001")
    print(f"✓ Business account created: {business.get_account_type()}")
except Exception as e:
    print(f"Error creating business: {e}")

print("\n=== Testing Account Retrieval ===")

# Test getting accounts
account = bank.get_account("SAV001")
if account:
    print(f"Retrieved account: {account.name} - {account.get_account_type()}")
else:
    print("Account not found")

# Test non-existent account
account = bank.get_account("FAKE001")
if account:
    print(f"ERROR: Should not have found account")
else:
    print("✓ Correctly returned None for non-existent account")

print("\n=== Testing Duplicate Account Number ===")

# Test creating account with existing number
try:
    duplicate = bank.create_account("savings", "Charlie Brown", "SAV001")
    print("ERROR: Should not allow duplicate account numbers")
except ValueError as e:
    print(f"✓ Correctly rejected duplicate: {e}")

print("\n=== Testing Invalid Account Type ===")

# Test invalid account type
try:
    invalid = bank.create_account("invalid", "Dave Matthews", "INV001")
    print("ERROR: Should not allow invalid account type")
except ValueError as e:
    print(f"✓ Correctly rejected invalid type: {e}")

print("\n=== Testing Account Operations and Tracking ===")

# Add money to accounts for testing
savings.deposit(1000)
checking.deposit(1500)
business.deposit(2000)

print(f"Savings balance: ${savings.balance}")
print(f"Checking balance: ${checking.balance}")
print(f"Business balance: ${business.balance}")

# Test total deposits calculation
total = bank.get_total_deposits()
print(f"Total deposits across all accounts: ${total}")

print("\n=== Testing Accounts by Type ===")

# Get accounts by type
savings_accounts = bank.get_accounts_by_type("savings")
print(f"Savings accounts: {len(savings_accounts)}")
for acc in savings_accounts:
    print(f"  - {acc.name}: ${acc.balance}")

checking_accounts = bank.get_accounts_by_type("checking")
print(f"Checking accounts: {len(checking_accounts)}")

business_accounts = bank.get_accounts_by_type("business")
print(f"Business accounts: {len(business_accounts)}")

print("\n=== Testing Fund Transfers ===")

# Test transfer between accounts
print(f"Before transfer:")
print(f"  Savings: ${savings.balance}")
print(f"  Checking: ${checking.balance}")

success = bank.transfer_funds("SAV001", "CHK001", 300)
if success:
    print(f"✓ Transfer successful")
    print(f"After $300 transfer:")
    print(f"  Savings: ${savings.balance}")
    print(f"  Checking: ${checking.balance}")
else:
    print("Transfer failed")

# Test invalid transfer (insufficient funds)
success = bank.transfer_funds("SAV001", "CHK001", 10000)
if success:
    print("ERROR: Transfer should have failed")
else:
    print("✓ Transfer correctly rejected (insufficient funds)")

# Test transfer with non-existent account
success = bank.transfer_funds("FAKE001", "CHK001", 100)
if success:
    print("ERROR: Transfer should have failed")
else:
    print("✓ Transfer correctly rejected (account not found)")

print("\n=== Testing Account Closure ===")

# Create and close an account
temp_account = bank.create_account("savings", "Temporary User", "TEMP001")
print(f"Created temporary account: {temp_account.name}")

success = bank.close_account("TEMP001")
if success:
    print("✓ Account closed successfully")
    
    # Verify account is gone
    closed_account = bank.get_account("TEMP001")
    if closed_account is None:
        print("✓ Account properly removed from bank")
    else:
        print("ERROR: Account still exists after closure")
else:
    print("Account closure failed")

print("\n=== Testing Bank Report ===")

# Generate comprehensive bank report
report = bank.generate_bank_report()
print("Bank Report:")
print(report)

print("\n=== Testing with Additional Accounts ===")

# Create more accounts to test comprehensive functionality
bank.create_account("savings", "Emily Stone", "SAV002", minimum_balance=200)
bank.create_account("checking", "Frank Ocean", "CHK002", overdraft_limit=1000)
bank.create_account("business", "Global Corp", "BUS002", monthly_transaction_limit=150)

# Add some balances
bank.get_account("SAV002").deposit(5000)
bank.get_account("CHK002").deposit(800)
bank.get_account("BUS002").deposit(15000)

# Generate final report
print("\n=== Final Bank Report ===")
final_report = bank.generate_bank_report()
print(final_report)

print("=" * 50)
