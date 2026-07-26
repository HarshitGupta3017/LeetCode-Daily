# Solution for Maximum Product of Three Numbers in PY

class Solution:
    def maximumProduct(self, nums):
        nums.sort()
        n = len(nums)

        # Case 1: Product of the three largest numbers
        top_three = nums[n - 1] * nums[n - 2] * nums[n - 3]

        # Case 2: Product of the two smallest (most negative)
        # numbers and the largest number
        two_neg_one_pos = nums[0] * nums[1] * nums[n - 1]

        return max(top_three, two_neg_one_pos)
