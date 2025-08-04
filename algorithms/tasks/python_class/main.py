from bank_account import BankAccount

def run_check():
    print("=== Bank Account Class Check ===")

    # Step 1: create account
    acc = BankAccount("Rombo", "001122")

    # Step 2: test setters/getters
    acc.set_name("Francis Rombo")
    print("Account Holder:", acc.get_name())
    print("Account Number:", acc.get_account_number())

    # Step 3: deposit money
    acc.deposit(1000)
    acc.deposit(500)

    # Step 4: withdraw money
    acc.withdraw(300)

    # Step 5: print current balance
    print("Balance:", acc.get_balance())

    # Step 6: print all transaction history
    print("\nTransaction History:")
    for entry in acc.get_transaction_log():
        print(entry)

    # Step 7: print string representation
    print("\nAccount Summary:")
    print(acc)

if __name__ == "__main__":
    run_check()
