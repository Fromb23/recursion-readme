#!/usr/bin/python3
"""4-main.py - Test file for Task 4: BusinessAccount with Transaction Fees"""

CheckingAccount = __import__('3-bank').CheckingAccount
BusinessAccount = __import__('4-bank').BusinessAccount

print("=== Testing BusinessAccount with Transaction Fees ===")

# Test BusinessAccount creation
business = BusinessAccount("Tech Startup Inc", "BUS001")
print(f"Account created: {business.name}")
print(f"Account type: {business.get_account_type()}")
print(f"Transaction fee: ${business.transaction_fee}")
print(f"Monthly limit: {business.monthly_transaction_limit}")
print(f"Remaining transactions: {business.get_remaining_transactions()}")

print("\n=== Testing Transaction Fees ===")

# Test deposit with fee
business.deposit(1000)
print(f"Balance after $1000 deposit (minus fee): ${business.balance}")
print(f"Remaining transactions: {business.get_remaining_transactions()}")

# Test withdrawal with fee
business.withdraw(200)
print(f"Balance after $200 withdrawal (minus fee): ${business.balance}")
print(f"Remaining transactions: {business.get_remaining_transactions()}")

print("\n=== Testing Multiple Transactions ===")

# Perform several transactions to see fee accumulation
for i in range(5):
    business.deposit(100)
    print(f"Transaction {i+3}: Balance = ${business.balance}, Remaining = {business.get_remaining_transactions()}")

print("\n=== Testing Monthly Limit Approach ===")

# Get close to monthly limit
current_transactions = 100 - business.get_remaining_transactions()
remaining = business.get_remaining_transactions()
print(f"Current transactions used: {current_transactions}")
print(f"Remaining free transactions: {remaining}")

# Use up remaining free transactions
for i in range(min(5, remaining)):
    business.deposit(50)
    print(f"Free transaction {i+1}: Balance = ${business.balance}, Remaining = {business.get_remaining_transactions()}")

print("\n=== Testing Excess Transaction Penalties ===")

# Now exceed the monthly limit (should incur extra $5 fee)
print("Exceeding monthly limit:")
business.deposit(100)
print(f"Balance after excess transaction: ${business.balance}")
print(f"Remaining transactions: {business.get_remaining_transactions()}")

# Another excess transaction
business.withdraw(75)
print(f"Balance after another excess transaction: ${business.balance}")

print("\n=== Testing Monthly Reset ===")

# Test resetting monthly transaction count
print(f"Before reset - remaining transactions: {business.get_remaining_transactions()}")
business.reset_monthly_count()
print(f"After reset - remaining transactions: {business.get_remaining_transactions()}")

# Test that fees go back to normal
business.deposit(200)
print(f"Balance after reset deposit (normal fee): ${business.balance}")

print("\n=== Testing Overdraft with Fees ===")

# Test overdraft functionality (inherited from CheckingAccount)
print(f"Current balance: ${business.balance}")
print(f"Overdraft limit: ${business.overdraft_limit}")
print(f"Available overdraft: ${business.get_overdraft_available()}")

# Withdraw more than balance (should use overdraft and charge fee)
withdrawal_amount = business.balance + 100
business.withdraw(withdrawal_amount)
print(f"Balance after overdraft withdrawal: ${business.balance}")
print(f"Available overdraft: ${business.get_overdraft_available()}")

print("\n=== Testing Property Modifications ===")

# Test changing monthly limit
business.monthly_transaction_limit = 50
print(f"New monthly limit: {business.monthly_transaction_limit}")
print(f"Remaining transactions: {business.get_remaining_transactions()}")

print("\n=== Testing String Representation ===")
print("BusinessAccount string representation:")
print(business)

print("\n=== Inheritance Chain Comparison ===")

# Compare different account types
checking = CheckingAccount("Regular Business", "CHK003")
checking.deposit(1000)
checking.withdraw(200)
print(f"\nChecking account balance (no fees): ${checking.balance}")

business2 = BusinessAccount("Another Business", "BUS002")
business2.deposit(1000)
business2.withdraw(200)
print(f"Business account balance (with fees): ${business2.balance}")

print("=" * 50)