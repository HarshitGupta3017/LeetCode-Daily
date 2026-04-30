// Solution for Maximum Path Score in a Grid in JAVA

class Solution {

    int dfs(int row, int col,
            int[][] grid,
            int remainingCost,
            int totalRows, int totalCols,
            int[][][] dp) {

        // ❌ Out of bounds
        if (row >= totalRows || col >= totalCols)
            return (int)-1e9;

        // ❌ Cost exceeded
        if (remainingCost < 0)
            return (int)-1e9;

        // ✅ Destination
        if (row == totalRows - 1 && col == totalCols - 1) {
            int cellCost = (grid[row][col] == 0 ? 0 : 1);
            if (remainingCost < cellCost)
                return (int)-1e9;
            return grid[row][col];
        }

        // 🔁 Memoization
        if (dp[row][col][remainingCost] != -1)
            return dp[row][col][remainingCost];

        int cellValue = grid[row][col];
        int cellCost = (cellValue == 0 ? 0 : 1);
        int nextRemainingCost = remainingCost - cellCost;

        int scoreRight = dfs(row, col + 1, grid,
                             nextRemainingCost, totalRows, totalCols, dp);

        int scoreDown = dfs(row + 1, col, grid,
                            nextRemainingCost, totalRows, totalCols, dp);

        int bestNextScore = Math.max(scoreRight, scoreDown);

        if (bestNextScore == (int)-1e9)
            return dp[row][col][remainingCost] = (int)-1e9;

        return dp[row][col][remainingCost] = bestNextScore + cellValue;
    }

    public int maxPathScore(int[][] grid, int k) {

        int totalRows = grid.length;
        int totalCols = grid[0].length;

        int[][][] dp = new int[totalRows][totalCols][k + 1];

        // Initialize DP with -1
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalCols; j++) {
                for (int c = 0; c <= k; c++) {
                    dp[i][j][c] = -1;
                }
            }
        }

        int maxScore = dfs(0, 0, grid, k, totalRows, totalCols, dp);

        return (maxScore < 0 ? -1 : maxScore);
    }
}
