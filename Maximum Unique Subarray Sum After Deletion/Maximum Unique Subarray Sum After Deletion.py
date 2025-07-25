# Solution for Maximum Unique Subarray Sum After Deletion in PY

class Solution:
    def maxSum(self, nums: List[int]) -> int:
        seen = [-1] * 101
        maxSum = 0
        maxNegative = float('-inf')

        for num in nums:
            if num <= 0:
                maxNegative = max(maxNegative, num)
            elif seen[num] == -1:
                maxSum += num
                seen[num] = 1

        return maxNegative if maxSum == 0 else maxSum
