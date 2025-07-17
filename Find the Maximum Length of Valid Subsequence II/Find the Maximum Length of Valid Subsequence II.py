# Solution for Find the Maximum Length of Valid Subsequence II in PY

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [[1] * n for _ in range(k)]
        maxLength = 1

        for i in range(1, n):
            for j in range(i):
                mod = (nums[i] + nums[j]) % k
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j])
                maxLength = max(maxLength, dp[mod][i])

        return maxLength
