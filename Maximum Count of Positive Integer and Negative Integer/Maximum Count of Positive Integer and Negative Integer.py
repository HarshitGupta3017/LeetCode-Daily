# Solution for Maximum Count of Positive Integer and Negative Integer in PY

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        pos = len(nums) - bisect.bisect_left(nums, 1)
        neg = bisect.bisect_right(nums, -1)
        return max(pos, neg)
