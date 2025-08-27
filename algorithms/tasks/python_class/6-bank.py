#!/usr/bin/python

class BankAccount():

    def __init__(self, name, account_number):
        self._name = name
        self._account_number = account_number
        self._balance = 0
        self._transactions = []

    def get_name(self):
        return self._name

    def get_account_number(self):
        return self._account_number

    def get_balance(self):
        return self._balance

    def set_name(self, name):
        self._name = name
        return self._name

    def set_balance(self, amount):
        self._balance = amount

    def deposit(self, amount):
        if amount > 0:
            self._balance += amount
        if amount < 0:
            print("Invalid deposit amount")

    def withdraw(self, amount):
        if amount <= self._balance:
            self._balance -= amount
            return self._balance
        else:
            print("Insufficient balance")

    def log_transaction(self, trans_type, amount):
        transaction = {
                "type" : trans_type,
                "amount" : amount,
                "balance_after" : self._balance
                }

        self._transactions.append(transaction)

    def get_transaction_log(self):
        return self._transactions

    def __str__(self):
        return f"Account Holder: {self._name} Account Number: {self._account_number} Balance: {self._balance}"
