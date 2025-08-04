#!/usr/bin/python3

class BankAccount:
    def __init__(self, name, account_number):
        self._name = name
        self._account_number = account_number
        self._balance = 0
        self._transactions = []

    # Setters
    def set_name(self, name):
        self._name = name

    def set_balance(self, amount):
        self._balance = amount

    # Getters
    def get_name(self):
        return self._name

    def get_account_number(self):
        return self._account_number

    def get_balance(self):
        return self._balance

    # Core methods
    def deposit(self, amount):
        if amount > 0:
            self._balance += amount
            self.log_transaction("Deposit", amount)
        else:
            print("Invalid deposit amount.")

    def withdraw(self, amount):
        if amount <= self._balance:
            self._balance -= amount
            self.log_transaction("Withdraw", amount)
        else:
            print("Insufficient balance.")

    def log_transaction(self, trans_type, amount):
        transaction = {
                "type": trans_type,
                "amount": amount,
                "balance_after": self._balance
                }
        self._transactions.append(transaction)

    def get_transaction_log(self):
        return self._transactions

    def __str__(self):
        return "Account Holder: " + self._name + "\n" + \
                "Account Number: " + self._account_number + "\n" + \
                "Balance: $" + str(self._balance)
