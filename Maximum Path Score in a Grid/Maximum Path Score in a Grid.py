# Solution for Maximum Path Score in a Grid in PY

class Solution:
    def dfs(self, row, col, grid, remainingCost, totalRows, totalCols, dp):
        # ❌ Out of bounds
        if row >= totalRows or col >= totalCols:
            return -10**9

        # ❌ Cost exceeded
        if remainingCost < 0:
            return -10**9

        # ✅ Destination
        if row == totalRows - 1 and col == totalCols - 1:
            cellCost = 0 if grid[row][col] == 0 else 1
            if remainingCost < cellCost:
                return -10**9
            return grid[row][col]

        # 🔁 Memoization
        if dp[row][col][remainingCost] != -1:
            return dp[row][col][remainingCost]

        cellValue = grid[row][col]
        cellCost = 0 if cellValue == 0 else 1
        nextRemainingCost = remainingCost - cellCost

        scoreRight = self.dfs(row, col + 1, grid,
                              nextRemainingCost, totalRows, totalCols, dp)

        scoreDown = self.dfs(row + 1, col, grid,
                             nextRemainingCost, totalRows, totalCols, dp)

        bestNextScore = max(scoreRight, scoreDown)

        if bestNextScore == -10**9:
            dp[row][col][remainingCost] = -10**9
            return -10**9

        dp[row][col][remainingCost] = bestNextScore + cellValue
        return dp[row][col][remainingCost]

    def maxPathScore(self, grid, k):
        totalRows = len(grid)
        totalCols = len(grid[0])

        dp = [[[-1] * (k + 1) for _ in range(totalCols)] for _ in range(totalRows)]

        maxScore = self.dfs(0, 0, grid, k, totalRows, totalCols, dp)

        return -1 if maxScore < 0 else maxScore
