# Solution for Paths in Matrix Whose Sum Is Divisible by K in PY

class Solution:
    def numberOfPaths(self, grid, k):
        m = len(grid)
        n = len(grid[0])
        MOD = 10**9 + 7

        # dp[i][j][r] → number of ways from (i,j) to bottom-right with remainder r
        dp = [[[0] * (k + 1) for _ in range(n + 1)] for _ in range(m + 1)]

        # Base case at destination
        for rem in range(k):
            final_rem = (rem + grid[m - 1][n - 1]) % k
            dp[m - 1][n - 1][rem] = 1 if final_rem == 0 else 0

        # Bottom-up filling
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):

                if i == m - 1 and j == n - 1:
                    continue

                for rem in range(k):

                    updated_rem = (rem + grid[i][j]) % k

                    ways_down = dp[i + 1][j][updated_rem] if i + 1 < m else 0
                    ways_right = dp[i][j + 1][updated_rem] if j + 1 < n else 0

                    dp[i][j][rem] = (ways_down + ways_right) % MOD

        return dp[0][0][0]
