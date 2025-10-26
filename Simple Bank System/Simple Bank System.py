# Solution for Simple Bank System in PY

class Bank:
    def __init__(self, balance: List[int]):
        self.balance = balance

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if not self._valid(account1) or not self._valid(account2) or self.balance[account1 - 1] < money:
            return False
        self.balance[account1 - 1] -= money
        self.balance[account2 - 1] += money
        return True

    def deposit(self, account: int, money: int) -> bool:
        if not self._valid(account):
            return False
        self.balance[account - 1] += money
        return True

    def withdraw(self, account: int, money: int) -> bool:
        if not self._valid(account) or self.balance[account - 1] < money:
            return False
        self.balance[account - 1] -= money
        return True

    def _valid(self, account: int) -> bool:
        return 1 <= account <= len(self.balance)


# Example usage:
# obj = Bank([10, 100, 20, 50, 30])
# print(obj.transfer(2, 3, 50))
# print(obj.deposit(1, 20))
# print(obj.withdraw(3, 10))
