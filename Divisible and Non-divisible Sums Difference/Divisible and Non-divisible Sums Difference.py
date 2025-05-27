# Solution for Divisible and Non-divisible Sums Difference in PY

class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        totalSum = n * (n + 1) // 2
        countDivisibleByM = n // m
        sumDivisibleByM = m * countDivisibleByM * (countDivisibleByM + 1) // 2
        return totalSum - 2 * sumDivisibleByM
