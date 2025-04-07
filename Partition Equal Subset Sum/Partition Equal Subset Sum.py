# Solution for Partition Equal Subset Sum in PY

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        total = sum(nums)
        
        if total % 2 != 0:
            return False
        
        target = total // 2
        # DP table of size (n+1) x (target+1)
        t = [[False] * (target + 1) for _ in range(n + 1)]

        # Initialize first column to True (sum = 0)
        for i in range(n + 1):
            t[i][0] = True

        # Fill the table
        for i in range(1, n + 1):
            for j in range(1, target + 1):
                if nums[i - 1] <= j:
                    t[i][j] = t[i - 1][j - nums[i - 1]] or t[i - 1][j]
                else:
                    t[i][j] = t[i - 1][j]

        return t[n][target]
