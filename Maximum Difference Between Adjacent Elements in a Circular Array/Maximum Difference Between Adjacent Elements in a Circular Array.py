# Solution for Maximum Difference Between Adjacent Elements in a Circular Array in PY

class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        maxDiff = 0
        for i in range(n):
            maxDiff = max(maxDiff, abs(nums[i] - nums[(i + 1) % n]))
        return maxDiff
