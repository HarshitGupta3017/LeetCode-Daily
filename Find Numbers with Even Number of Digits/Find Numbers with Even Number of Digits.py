# Solution for Find Numbers with Even Number of Digits in PY

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        count = 0
        for num in nums:
            if 10 <= num <= 99 or 1000 <= num <= 9999 or num == 100000:
                count += 1
        return count
