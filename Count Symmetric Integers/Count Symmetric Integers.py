# Solution for Count Symmetric Integers in PY

class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        count = 0
        for num in range(low, high + 1):
            if num < 100 and num % 11 == 0:
                count += 1
            elif 1000 <= num <= 9999:
                first = num // 1000
                second = (num // 100) % 10
                third = (num // 10) % 10
                fourth = num % 10
                if first + second == third + fourth:
                    count += 1
        return count
