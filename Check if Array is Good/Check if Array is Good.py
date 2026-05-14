# Solution for Check if Array is Good in PY

class Solution:
    def isGood(self, nums):

        nums.sort()

        expected_max = len(nums) - 1

        # Check sequence: 1,2,3,...,n-1
        for i in range(expected_max):
            if nums[i] != i + 1:
                return False

        # Last element must be n
        return nums[expected_max] == expected_max
