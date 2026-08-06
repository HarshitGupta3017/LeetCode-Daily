# Solution for Smallest Divisible Digit Product I in PY

class Solution:
    def digitProduct(self, n: int) -> int:
        product = 1
        while n > 0:
            product *= n % 10
            n //= 10
        return product

    def smallestNumber(self, n: int, t: int) -> int:
        candidate = n
        while True:
            if self.digitProduct(candidate) % t == 0:
                return candidate
            candidate += 1
