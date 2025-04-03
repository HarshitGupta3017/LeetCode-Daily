# Solution for Maximum Value of an Ordered Triplet II in PY

class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        maxPrefix = nums[0]
        maxSuffix = [0] * n
        maxSuffix[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            maxSuffix[i] = max(maxSuffix[i + 1], nums[i])
        maxVal = 0
        for j in range(1, n - 1):
            maxVal = max(maxVal, (maxPrefix - nums[j]) * maxSuffix[j + 1])
            maxPrefix = max(maxPrefix, nums[j])
        return maxVal
