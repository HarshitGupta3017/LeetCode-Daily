# Solution for Count Operations to Obtain Zero in PY

class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        count = 0
        while num1 > 0 and num2 > 0:
            count += num1 // num2
            num1 %= num2
            num1, num2 = num2, num1  # swap
        return count
