# Solution for Count the Number of Fair Pairs in PY

class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        res = 0
        for i in range(len(nums)):
            x = bisect_left(nums, lower - nums[i], i + 1)
            y = bisect_right(nums, upper - nums[i], i + 1)
            res += (y - x)
        return res
