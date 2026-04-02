# Solution for Maximum Amount of Money Robot Can Earn in PY

class Solution:
    def dfs(self, coins, row, col, rows, cols, remainingNeutralizations, dp):

        # BASE CASE
        if row == rows - 1 and col == cols - 1:
            if coins[row][col] < 0 and remainingNeutralizations > 0:
                return 0
            return coins[row][col]

        # OUT OF BOUNDS
        if row >= rows or col >= cols:
            return float('-inf')

        # MEMOIZATION
        if dp[row][col][remainingNeutralizations] != float('-inf'):
            return dp[row][col][remainingNeutralizations]

        # OPTION 1: TAKE CURRENT
        go_down = self.dfs(coins, row + 1, col, rows, cols, remainingNeutralizations, dp)
        go_right = self.dfs(coins, row, col + 1, rows, cols, remainingNeutralizations, dp)

        take_current = coins[row][col] + max(go_down, go_right)

        # OPTION 2: NEUTRALIZE
        neutralize = float('-inf')

        if coins[row][col] < 0 and remainingNeutralizations > 0:
            neutralize_down = self.dfs(coins, row + 1, col, rows, cols, remainingNeutralizations - 1, dp)
            neutralize_right = self.dfs(coins, row, col + 1, rows, cols, remainingNeutralizations - 1, dp)

            neutralize = max(neutralize_down, neutralize_right)

        dp[row][col][remainingNeutralizations] = max(take_current, neutralize)
        return dp[row][col][remainingNeutralizations]

    def maximumAmount(self, coins):
        rows, cols = len(coins), len(coins[0])

        # Initialize DP with -inf
        dp = [[[float('-inf')] * 3 for _ in range(cols)] for _ in range(rows)]

        return self.dfs(coins, 0, 0, rows, cols, 2, dp)
