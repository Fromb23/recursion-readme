#!/usr/bin/python3
"""8-main.py - Test file for Task 8: Complete Banking System Integration"""

# Import all necessary components
from abc import ABC, abstractmethod

# Import all classes from previous tasks
BankAccount = __import__('7-bank').BankAccount
Bank = __import__('5-bank').Bank
BankingSystem = __import__('8-bank').BankingSystem

print("=== Testing Complete Banking System Integration ===")

# Test BankingSystem creation
banking_system = BankingSystem()
print(f"Banking system initialized")

print("\n=== Testing Multiple Banks Management ===")

# Test creating multiple banks
bank1_id = banking_system.create_bank("First National PyBank")
bank2_id = banking_system.create_bank("Community Trust Bank")
bank3_id = banking_system.create_bank("Business Banking Corp")

print(f"Created banks:")
print(f"  Bank 1 ID: {bank1_id}")
print(f"  Bank 2 ID: {bank2_id}")
print(f"  Bank 3 ID: {bank3_id}")

banks = banking_system.get_all_banks()
print(f"\nTotal banks in system: {len(banks)}")

print("\n=== Testing Account Number Generation ===")

# Test automatic account number generation
account_nums = []
for i in range(5):
    acc_num = banking_system.generate_account_number("savings")
    account_nums.append(acc_num)
    print(f"Generated savings account number: {acc_num}")

# Ensure no duplicates
print(f"All numbers unique: {len(account_nums) == len(set(account_nums))}")

print("\n=== Testing Customer Authentication ===")

# Test customer registration and authentication
customer_id = banking_system.register_customer("Alice Johnson", "alice@email.com", "secure123")
print(f"Registered customer ID: {customer_id}")

# Test authentication
auth_result = banking_system.authenticate_customer("alice@email.com", "secure123")
print(f"Authentication successful: {auth_result is not None}")

# Test wrong password
auth_result = banking_system.authenticate_customer("alice@email.com", "wrong123")
print(f"Wrong password rejected: {auth_result is None}")

print("\n=== Testing Account Creation Through System ===")

# Test creating accounts through the banking system
account1 = banking_system.create_system_account(
    bank_id=bank1_id,
    customer_id=customer_id,
    account_type="savings",
    minimum_balance=100
)
print(f"Created savings account: {account1.account_number}")

account2 = banking_system.create_system_account(
    bank_id=bank1_id,
    customer_id=customer_id,
    account_type="checking",
    overdraft_limit=500
)
print(f"Created checking account: {account2.account_number}")

# Create business account in different bank
customer2_id = banking_system.register_customer("Tech Corp LLC", "tech@corp.com", "business456")
account3 = banking_system.create_system_account(
    bank_id=bank2_id,
    customer_id=customer2_id,
    account_type="business",
    monthly_transaction_limit=200
)
print(f"Created business account: {account3.account_number}")

print("\n=== Testing Cross-Bank Transfers ===")

# Add funds to test transfers
account1.deposit(2000)
account3.deposit(5000)

print(f"Before transfer:")
print(f"  Account1 (Bank1): ${account1.balance}")
print(f"  Account3 (Bank2): ${account3.balance}")

# Test inter-bank transfer
success = banking_system.transfer_between_banks(
    from_bank_id=bank1_id,
    from_account=account1.account_number,
    to_bank_id=bank2_id,
    to_account=account3.account_number,
    amount=300
)

print(f"Inter-bank transfer successful: {success}")
print(f"After transfer:")
print(f"  Account1 (Bank1): ${account1.balance}")
print(f"  Account3 (Bank2): ${account3.balance}")

print("\n=== Testing Transaction History Across System ===")

# Perform various transactions
account1.deposit(500)
account2.withdraw(200)
account3.deposit(1000)

# Get system-wide transaction history
all_transactions = banking_system.get_system_transaction_history()
print(f"Total system transactions: {len(all_transactions)}")

# Show recent transactions
print("Recent system transactions:")
for i, trans in enumerate(all_transactions[-5:]):
    print(f"  {i+1}. {trans['account_number']}: {trans['type']} ${trans['amount']}")

print("\n=== Testing Account Freezing/Unfreezing ===")

# Test account management features
print(f"Account1 frozen status: {banking_system.is_account_frozen(account1.account_number)}")

# Freeze account
banking_system.freeze_account(account1.account_number, "Suspicious activity detected")
print(f"Account1 frozen status after freeze: {banking_system.is_account_frozen(account1.account_number)}")

# Try to withdraw from frozen account
try:
    account1.withdraw(100)
    print("ERROR: Frozen account should not allow withdrawals")
except Exception as e:
    print(f"✓ Frozen account withdrawal blocked: {e}")

# Unfreeze account
banking_system.unfreeze_account(account1.account_number)
print(f"Account1 frozen status after unfreeze: {banking_system.is_account_frozen(account1.account_number)}")

# Try withdrawal again
account1.withdraw(100)
print(f"Account1 balance after unfreezing and withdrawal: ${account1.balance}")

print("\n=== Testing Interest Calculations ===")

# Test system-wide interest application
print("Balances before interest:")
accounts_for_interest = [account1, account2, account3]
for acc in accounts_for_interest:
    print(f"  {acc.account_number}: ${acc.balance}")

banking_system.apply_system_wide_interest()

print("Balances after interest:")
for acc in accounts_for_interest:
    print(f"  {acc.account_number}: ${acc.balance}")

print("\n=== Testing Monthly Maintenance ===")

# Test monthly maintenance operations
maintenance_report = banking_system.run_monthly_maintenance()
print("Monthly maintenance completed:")
print(maintenance_report)

print("\n=== Testing Multi-Currency Support ===")

# Test currency conversion simulation
usd_amount = 1000
eur_amount = banking_system.convert_currency(usd_amount, "USD", "EUR")
gbp_amount = banking_system.convert_currency(usd_amount, "USD", "GBP")

print(f"Currency conversions from ${usd_amount} USD:")
print(f"  EUR: €{eur_amount:.2f}")
print(f"  GBP: £{gbp_amount:.2f}")

# Test creating account with different currency
account4 = banking_system.create_system_account(
    bank_id=bank3_id,
    customer_id=customer_id,
    account_type="savings",
    currency="EUR"
)
account4.deposit(1000)  # €1000
print(f"EUR account balance: €{account4.balance}")

print("\n=== Testing Account Statement Generation ===")

# Generate comprehensive account statements
statement1 = banking_system.generate_account_statement(account1.account_number)
print(f"Account statement generated for {account1.account_number}")
print("Statement preview (first 200 chars):")
print(statement1[:200] + "..." if len(statement1) > 200 else statement1)

print("\n=== Testing System Analytics and Reporting ===")

# Generate system analytics
analytics = banking_system.generate_system_analytics()
print("System Analytics:")
print(f"  Total Banks: {analytics['total_banks']}")
print(f"  Total Customers: {analytics['total_customers']}")
print(f"  Total Accounts: {analytics['total_accounts']}")
print(f"  Total System Balance: ${analytics['total_balance']:.2f}")
print(f"  Average Account Balance: ${analytics['avg_balance']:.2f}")

# Account type breakdown
print("Account Type Distribution:")
for acc_type, count in analytics['account_types'].items():
    print(f"  {acc_type.title()}: {count}")

print("\n=== Testing Account Backup and Restore ===")

# Test backup functionality
backup_data = banking_system.backup_account_data(account1.account_number)
print(f"Backup created for account {account1.account_number}")
print(f"Backup size: {len(str(backup_data))} characters")

# Simulate account data corruption and restore
original_balance = account1.balance
account1._balance = 0  # Simulate corruption
account1._transactions = []

print(f"After 'corruption': Balance = ${account1.balance}, Transactions = {len(account1.get_transaction_log())}")

# Restore from backup
banking_system.restore_account_data(account1.account_number, backup_data)
print(f"After restore: Balance = ${account1.balance}, Transactions = {len(account1.get_transaction_log())}")

print("\n=== Testing Error Handling and Edge Cases ===")

# Test various error conditions
try:
    banking_system.create_system_account("INVALID_BANK", customer_id, "savings")
    print("ERROR: Should reject invalid bank ID")
except ValueError as e:
    print(f"✓ Invalid bank ID rejected: {e}")

try:
    banking_system.transfer_between_banks(bank1_id, "FAKE001", bank2_id, account3.account_number, 100)
    print("ERROR: Should reject invalid account number")
except ValueError as e:
    print(f"✓ Invalid account rejected: {e}")

print("\n=== Final System Status Report ===")

# Generate comprehensive final report
final_report = banking_system.generate_comprehensive_report()
print("=== COMPREHENSIVE BANKING SYSTEM REPORT ===")
print(final_report)

print("\n=== Testing Account Factory Pattern ===")

# Test account factory pattern
factory_accounts = []
account_configs = [
    {"type": "savings", "name": "Factory Savings", "minimum_balance": 50},
    {"type": "checking", "name": "Factory Checking", "overdraft_limit": 1000},
    {"type": "business", "name": "Factory Business", "monthly_transaction_limit": 500},
]

for config in account_configs:
    acc = banking_system.create_account_via_factory(bank1_id, customer_id, config)
    factory_accounts.append(acc)
    print(f"Factory created: {acc.get_account_type()} - {acc.name}")

print(f"\nFactory pattern created {len(factory_accounts)} accounts successfully")

print("=" * 50)
print("=== ALL BANKING SYSTEM TESTS COMPLETED ===")
print("=" * 50)