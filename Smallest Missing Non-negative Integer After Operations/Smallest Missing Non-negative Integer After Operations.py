# Solution for Smallest Missing Non-negative Integer After Operations in PY

class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        n = len(nums)

        # List to store the frequency of each remainder class modulo 'value'
        remainder_frequency = [0] * value

        # Count how many numbers fall into each remainder class (0 to value - 1)
        for num in nums:
            remainder = (num % value + value) % value
            remainder_frequency[remainder] += 1

        current_number = 0

        # Try to build each integer starting from 0
        while True:
            remainder_class = current_number % value

            if remainder_frequency[remainder_class] > 0:
                remainder_frequency[remainder_class] -= 1
                current_number += 1
            else:
                # If we can't build this number, it's the MEX (minimum excluded)
                return current_number
