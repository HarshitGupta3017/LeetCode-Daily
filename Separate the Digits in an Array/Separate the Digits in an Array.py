# Solution for Separate the Digits in an Array in PY

class Solution:
    def separateDigits(self, nums):
        return [int(d) for num in nums for d in str(num)]
