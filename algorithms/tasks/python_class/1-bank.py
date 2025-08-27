#!/usr/bin/python

class BankAccount():

    def __init__(self, name, account_number):
        self._name = name
        self._account_number = account_number
        self._balance = 0
