# Solution for Minimum Operations to Make Array Sum Divisible by K in PY

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(nums) % k
