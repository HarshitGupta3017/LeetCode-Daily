# Solution for Largest 3-Same-Digit Number in String in PY

class Solution:
    def largestGoodInteger(self, num: str) -> str:
        max_digit = ""

        for i in range(len(num) - 2):
            if num[i] == num[i + 1] == num[i + 2]:
                max_digit = max(max_digit, num[i])

        return max_digit * 3 if max_digit else ""
