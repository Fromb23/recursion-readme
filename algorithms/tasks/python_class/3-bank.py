#!/usr/bin/python

class BankAccount():

    def __init__(self, name, account_number):
        self._name = name
        self._account_number = account_number
        self._balance = 0

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
