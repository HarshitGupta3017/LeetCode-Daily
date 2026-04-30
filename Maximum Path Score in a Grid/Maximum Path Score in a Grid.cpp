// Solution for Maximum Path Score in a Grid in CPP

class Solution {
public:

    // Recursive function to compute maximum score
    // row, col → current position in grid
    // remainingCost → how much cost budget is left (k)
    int dfs(int row, int col,
            vector<vector<int>>& grid,
            int remainingCost,
            int totalRows, int totalCols,
            vector<vector<vector<int>>>& dp) {

        // ❌ Out of bounds → invalid path
        if (row >= totalRows || col >= totalCols)
            return -1e9;

        // ❌ Cost exceeded → invalid path
        if (remainingCost < 0)
            return -1e9;

        // ✅ Reached destination cell
        if (row == totalRows - 1 && col == totalCols - 1) {

            // Determine cost of this cell
            int cellCost = (grid[row][col] == 0 ? 0 : 1);

            // If we can't afford this cell → invalid
            if (remainingCost < cellCost)
                return -1e9;

            // Otherwise, return its score (value)
            return grid[row][col];
        }

        // 🔁 If already computed, return cached result
        if (dp[row][col][remainingCost] != -1)
            return dp[row][col][remainingCost];

        // Current cell value (adds to score)
        int cellValue = grid[row][col];

        // Cost to step on this cell
        int cellCost = (cellValue == 0 ? 0 : 1);

        // Remaining cost after stepping on this cell
        int nextRemainingCost = remainingCost - cellCost;

        // Explore moving right
        int scoreRight = dfs(row, col + 1, grid,
                             nextRemainingCost, totalRows, totalCols, dp);

        // Explore moving down
        int scoreDown = dfs(row + 1, col, grid,
                            nextRemainingCost, totalRows, totalCols, dp);

        // Choose best of both directions
        int bestNextScore = max(scoreRight, scoreDown);

        // If both paths are invalid, mark this as invalid
        if (bestNextScore == -1e9)
            return dp[row][col][remainingCost] = -1e9;

        // Otherwise, add current cell value to best path
        return dp[row][col][remainingCost] = bestNextScore + cellValue;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {

        int totalRows = grid.size();
        int totalCols = grid[0].size();

        // 3D DP:
        // dp[row][col][remainingCost] → max score from (row,col) with remainingCost
        vector<vector<vector<int>>> dp(
            totalRows,
            vector<vector<int>>(totalCols, vector<int>(k + 1, -1))
        );

        // Start DFS from top-left (0,0) with full budget k
        int maxScore = dfs(0, 0, grid, k, totalRows, totalCols, dp);

        // If result is negative → no valid path
        return (maxScore < 0 ? -1 : maxScore);
    }
};
