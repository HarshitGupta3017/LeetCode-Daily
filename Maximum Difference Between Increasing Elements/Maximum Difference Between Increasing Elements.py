# Solution for Maximum Difference Between Increasing Elements in PY

class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        minEle = nums[0]
        maxDiff = -1
        for j in range(len(nums)):
            if nums[j] > minEle:
                maxDiff = max(maxDiff, nums[j] - minEle)
            else:
                minEle = nums[j]
        return maxDiff
