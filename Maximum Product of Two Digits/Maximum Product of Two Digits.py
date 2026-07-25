# Solution for Maximum Product of Two Digits in PY

class Solution:
    def maxProduct(self, n: int) -> int:
        first = second = 0

        while n > 0:
            x = n % 10

            if x > first:
                second = first
                first = x
            elif x > second:
                second = x

            n //= 10

        return first * second
