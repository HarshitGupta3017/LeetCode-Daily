# Solution for Minimum Operations to Make Binary Array Elements Equal to One I in PY

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n, ops = len(nums), 0
        for i in range(0, n - 2):
            if nums[i] == 0:
                nums[i] ^= 1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
                ops += 1
        if (nums[n - 1] == 0 or nums[n - 2] == 0):
            return -1
        return ops
