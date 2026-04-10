class BankAccount:
    def __init__(self, account_number, name, balance):
        self.account_number = account_number
        self.name = name
        self.balance = balance

    def deposit(self, d):
        if d > 0:
            self.balance += d

    def withdrawing_money(self, w):
        if 0 < w <= self.balance:
            self.balance -= w

    def print_info(self):
        print("Account number: {}".format(self.account_number))
        print("Name: {}".format(self.name))
        print("Balance: {}".format(self.balance))

account_list = []

for i in range(10):
    number = int(input())
    name = input()
    balance = float(input())
    item = BankAccount(number, name, balance)
    account_list.append(item)

def max_balance(account_list):
    return max(account_list, key=lambda x: x.balance)

def sort_by_name(account_list):
    account_list.sort(key=lambda x: x.name, reverse=True)

    for i in account_list:
        i.print_info()


