# Solution for Check Divisibility by Digit Sum and Product in PY

class Solution:
    def checkDivisibility(self, n: int) -> bool:
        original, total, product = n, 0, 1
        while n:
            n, d = divmod(n, 10)
            total += d
            product *= d
        return original % (total + product) == 0
