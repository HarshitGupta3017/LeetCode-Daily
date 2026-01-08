# Solution for Max Dot Product of Two Subsequences in PY

class Solution:
    NEG_INF = -10**9

    def dfs(self, nums1, nums2, i, j, n, m, dp):

        # If either array is exhausted
        if i == n or j == m:
            return self.NEG_INF

        # Return memoized result
        if dp[i][j] is not None:
            return dp[i][j]

        # Dot product of current pair
        currentProduct = nums1[i] * nums2[j]

        # Option 1: Take both
        takeBoth = (
            currentProduct +
            self.dfs(nums1, nums2, i + 1, j + 1, n, m, dp)
        )

        # Option 2: Skip nums1 element
        skipFirst = self.dfs(nums1, nums2, i + 1, j, n, m, dp)

        # Option 3: Skip nums2 element
        skipSecond = self.dfs(nums1, nums2, i, j + 1, n, m, dp)

        # Store best result
        dp[i][j] = max(
            currentProduct,
            takeBoth,
            skipFirst,
            skipSecond
        )

        return dp[i][j]

    def maxDotProduct(self, nums1, nums2):
        n, m = len(nums1), len(nums2)

        # DP initialized with None
        dp = [[None] * m for _ in range(n)]

        return self.dfs(nums1, nums2, 0, 0, n, m, dp)
