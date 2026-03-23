# Solution for Maximum Non Negative Product in a Matrix in PY

class Solution:
    def maxProductPath(self, grid):
        rows, cols = len(grid), len(grid[0])
        MOD = 10**9 + 7

        # dp[r][c] = (maxProduct, minProduct)
        dp = [[(0, 0) for _ in range(cols)] for _ in range(rows)]

        # Base case
        dp[0][0] = (grid[0][0], grid[0][0])

        # First row
        for col in range(1, cols):
            val = grid[0][col]
            prev_max, prev_min = dp[0][col - 1]
            dp[0][col] = (prev_max * val, prev_min * val)

        # First column
        for row in range(1, rows):
            val = grid[row][0]
            prev_max, prev_min = dp[row - 1][0]
            dp[row][0] = (prev_max * val, prev_min * val)

        # Fill rest
        for row in range(1, rows):
            for col in range(1, cols):
                val = grid[row][col]

                top_max, top_min = dp[row - 1][col]
                left_max, left_min = dp[row][col - 1]

                candidates = [
                    top_max * val,
                    top_min * val,
                    left_max * val,
                    left_min * val
                ]

                dp[row][col] = (max(candidates), min(candidates))

        result = dp[rows - 1][cols - 1][0]

        return -1 if result < 0 else result % MOD
