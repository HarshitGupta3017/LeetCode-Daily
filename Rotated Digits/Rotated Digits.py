# Solution for Rotated Digits in PY

class Solution:
    def rotatedDigits(self, n):

        def is_good(num):
            has_change = False

            while num > 0:
                digit = num % 10

                if digit in (3, 4, 7):
                    return False

                if digit in (2, 5, 6, 9):
                    has_change = True

                num //= 10

            return has_change

        count = 0
        for i in range(1, n + 1):
            if is_good(i):
                count += 1

        return count
