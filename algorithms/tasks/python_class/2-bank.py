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
