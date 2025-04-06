# Solution for Largest Divisible Subset in PY

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        dp = [1] * n
        prev_idx = [-1] * n
        last_idx, maxL = 0, 1
        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        prev_idx[i] = j
                    if dp[i] > maxL:
                        maxL = dp[i]
                        last_idx = i
        res = []
        while last_idx != -1:
            res.append(nums[last_idx])
            last_idx = prev_idx[last_idx]
        return res
