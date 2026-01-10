# Solution for Minimum ASCII Delete Sum for Two Strings in PY

class Solution:
    def solve(self, i, j, s1, s2, m, n, dp):

        # If both strings are fully processed
        if i >= m and j >= n:
            return 0

        # If s1 is exhausted
        if i >= m:
            return ord(s2[j]) + self.solve(i, j + 1, s1, s2, m, n, dp)

        # If s2 is exhausted
        if j >= n:
            return ord(s1[i]) + self.solve(i + 1, j, s1, s2, m, n, dp)

        # Return memoized result
        if dp[i][j] != -1:
            return dp[i][j]

        # Characters match
        if s1[i] == s2[j]:
            dp[i][j] = self.solve(i + 1, j + 1, s1, s2, m, n, dp)
            return dp[i][j]

        # Option 1: delete from s1
        deleteFromS1 = (
            ord(s1[i]) +
            self.solve(i + 1, j, s1, s2, m, n, dp)
        )

        # Option 2: delete from s2
        deleteFromS2 = (
            ord(s2[j]) +
            self.solve(i, j + 1, s1, s2, m, n, dp)
        )

        dp[i][j] = min(deleteFromS1, deleteFromS2)
        return dp[i][j]

    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)

        # dp[i][j] = min delete sum for s1[i:] and s2[j:]
        dp = [[-1] * n for _ in range(m)]

        return self.solve(0, 0, s1, s2, m, n, dp)
