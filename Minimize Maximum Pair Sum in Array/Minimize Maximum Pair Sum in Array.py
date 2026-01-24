# Solution for Minimize Maximum Pair Sum in Array in PY

class Solution:
    def minPairSum(self, nums: List[int]) -> int:

        nums.sort()
        leftIndex = 0
        rightIndex = len(nums) - 1
        maximumPairSum = 0

        while leftIndex < rightIndex:
            currentPairSum = nums[leftIndex] + nums[rightIndex]
            maximumPairSum = max(maximumPairSum, currentPairSum)
            leftIndex += 1
            rightIndex -= 1

        return maximumPairSum
