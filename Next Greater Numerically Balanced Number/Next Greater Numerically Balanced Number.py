# Solution for Next Greater Numerically Balanced Number in PY

class Solution:
    def __init__(self):
        self.remainingCount = [0,1,2,3,4,5,6,7,8,9]

    def backtrack(self, n, current, digitsLeft):
        if digitsLeft == 0:
            for digit in range(1, 10):
                if self.remainingCount[digit] != 0 and self.remainingCount[digit] != digit:
                    return 0
            return current if current > n else 0

        result = 0
        for digit in range(1, 10):
            if 0 < self.remainingCount[digit] <= digitsLeft:
                self.remainingCount[digit] -= 1
                result = self.backtrack(n, current * 10 + digit, digitsLeft - 1)
                self.remainingCount[digit] += 1
                if result != 0:
                    break
        return result

    def nextBeautifulNumber(self, n: int) -> int:
        numLength = len(str(n))
        result = self.backtrack(n, 0, numLength)
        if result == 0:
            result = self.backtrack(n, 0, numLength + 1)
        return result
