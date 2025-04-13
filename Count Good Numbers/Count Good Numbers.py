# Solution for Count Good Numbers in PY

class Solution:

    def __init__(self):
        self.M = 1_000_000_007
    
    def findPower(self, a: int, b: int) -> int:
        if b == 0:
            return 1
        half = self.findPower(a, b // 2)
        result = (half * half) % self.M
        if b % 2 == 1:
            result = (result * a) % self.M
        return result

    def countGoodNumbers(self, n: int) -> int:
        return self.findPower(5, (n + 1) // 2) * self.findPower(4, n // 2) % self.M
