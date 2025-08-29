#!/usr/bin/python3
"""6-main.py - Test file for Task 6: Premium Account with Multiple Inheritance"""

CheckingAccount = __import__('3-bank').CheckingAccount
RewardsProgram = __import__('6-bank').RewardsProgram
PremiumAccount = __import__('6-bank').PremiumAccount

print("=== Testing RewardsProgram Class ===")

# Test RewardsProgram independently
rewards = RewardsProgram()
print(f"Initial points balance: {rewards.points_balance}")

# Test earning points
rewards.earn_points(100)
print(f"Points after earning from $100: {rewards.points_balance}")

rewards.earn_points(250)
print(f"Points after earning from $250: {rewards.points_balance}")

# Test redeeming points
cash_value = rewards.redeem_points(100)
print(f"Redeemed 100 points for: ${cash_value}")
print(f"Points balance after redemption: {rewards.points_balance}")

# Test redeeming more points than available
cash_value = rewards.redeem_points(1000)
print(f"Attempted to redeem 1000 points, got: ${cash_value}")
print(f"Points balance: {rewards.points_balance}")

print("\n=== Testing PremiumAccount Creation ===")

# Test PremiumAccount creation (multiple inheritance)
premium = PremiumAccount("Victoria Secret", "PREM001")
print(f"Premium account created: {premium.name}")
print(f"Account type: {premium.get_account_type()}")
print(f"Initial balance: ${premium.balance}")
print(f"Initial points: {premium.points_balance}")
print(f"Overdraft limit: ${premium.overdraft_limit}")

print("\n=== Testing Premium Benefits ===")

# Test premium benefits
benefits = premium.get_premium_benefits()
print("Premium benefits:")
for benefit in benefits:
    print(f"  - {benefit}")

print("\n=== Testing Deposit with Points Earning ===")

# Test deposit that earns points
print(f"Before deposit: Balance=${premium.balance}, Points={premium.points_balance}")
premium.deposit(500)
print(f"After $500 deposit: Balance=${premium.balance}, Points={premium.points_balance}")

premium.deposit(1250)
print(f"After $1250 deposit: Balance=${premium.balance}, Points={premium.points_balance}")

print("\n=== Testing Points Redemption ===")

# Test redeeming points for cash
points_to_redeem = 100
cash_back = premium.redeem_points(points_to_redeem)
print(f"Redeemed {points_to_redeem} points for ${cash_back} cash")
print(f"Current balance: ${premium.balance}")
print(f"Current points: {premium.points_balance}")

print("\n=== Testing Inherited CheckingAccount Features ===")

# Test overdraft (inherited from CheckingAccount)
premium.withdraw(2000)  # Should use overdraft
print(f"After $2000 withdrawal: Balance=${premium.balance}")
print(f"Available overdraft: ${premium.get_overdraft_available()}")
print(f"Points balance: {premium.points_balance}")

# Test another deposit to earn more points
premium.deposit(800)
print(f"After $800 deposit: Balance=${premium.balance}, Points={premium.points_balance}")

print("\n=== Testing Method Resolution Order (MRO) ===")

# Show MRO to understand multiple inheritance
print("Method Resolution Order:")
for i, cls in enumerate(PremiumAccount.__mro__):
    print(f"  {i+1}. {cls.__name__}")

print("\n=== Testing String Representation ===")

# Test enhanced __str__ method
print("PremiumAccount string representation:")
print(premium)

print("\n=== Comparing Account Types ===")

# Compare different account types side by side
print("\n--- Account Comparison ---")

# Regular CheckingAccount
regular_checking = CheckingAccount("Regular User", "CHK999")
regular_checking.deposit(500)
regular_checking.withdraw(100)

print(f"Regular Checking:")
print(f"  Balance: ${regular_checking.balance}")
print(f"  Type: {regular_checking.get_account_type()}")
print(f"  Points: N/A")

# PremiumAccount
premium2 = PremiumAccount("Premium User", "PREM002")
premium2.deposit(500)  # Earns points
premium2.withdraw(100)

print(f"\nPremium Account:")
print(f"  Balance: ${premium2.balance}")
print(f"  Type: {premium2.get_account_type()}")
print(f"  Points: {premium2.points_balance}")

print("\n=== Testing Edge Cases ===")

# Test large deposit for significant points
premium.deposit(10000)  # Should earn 1000 points
print(f"After $10,000 deposit: Points={premium.points_balance}")

# Test redeeming all points
total_points = premium.points_balance
cash_back = premium.redeem_points(total_points)
print(f"Redeemed all {total_points} points for ${cash_back}")
print(f"Remaining points: {premium.points_balance}")

# Test deposit after points redemption
premium.deposit(300)
print(f"After $300 deposit: Points={premium.points_balance}")

print("\n=== Testing Multiple Premium Accounts ===")

# Test multiple premium accounts
premium_accounts = []
for i in range(3):
    acc = PremiumAccount(f"Premium User {i+1}", f"PREM00{i+3}")
    acc.deposit(1000 + (i * 500))
    premium_accounts.append(acc)

print("Multiple Premium Accounts Summary:")
for i, acc in enumerate(premium_accounts):
    print(f"  Account {i+1}: ${acc.balance} balance, {acc.points_balance} points")

print("=" * 50)
