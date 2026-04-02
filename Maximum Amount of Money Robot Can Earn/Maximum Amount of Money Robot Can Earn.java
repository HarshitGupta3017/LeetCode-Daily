// Solution for Maximum Amount of Money Robot Can Earn in JAVA

class Solution {

    /*
        DP State:
        dp[row][col][remainingNeutralizations]
    */
    public int dfs(int[][] coins,
                   int row, int col,
                   int rows, int cols,
                   int remainingNeutralizations,
                   int[][][] dp) {

        // BASE CASE
        if (row == rows - 1 && col == cols - 1) {
            if (coins[row][col] < 0 && remainingNeutralizations > 0)
                return 0;
            return coins[row][col];
        }

        // OUT OF BOUNDS
        if (row >= rows || col >= cols) {
            return Integer.MIN_VALUE;
        }

        // MEMOIZATION
        if (dp[row][col][remainingNeutralizations] != Integer.MIN_VALUE) {
            return dp[row][col][remainingNeutralizations];
        }

        // OPTION 1: TAKE CURRENT
        int goDown = dfs(coins, row + 1, col, rows, cols, remainingNeutralizations, dp);
        int goRight = dfs(coins, row, col + 1, rows, cols, remainingNeutralizations, dp);

        int takeCurrent = coins[row][col] + Math.max(goDown, goRight);

        // OPTION 2: NEUTRALIZE
        int neutralize = Integer.MIN_VALUE;

        if (coins[row][col] < 0 && remainingNeutralizations > 0) {
            int neutralizeDown = dfs(coins, row + 1, col, rows, cols, remainingNeutralizations - 1, dp);
            int neutralizeRight = dfs(coins, row, col + 1, rows, cols, remainingNeutralizations - 1, dp);

            neutralize = Math.max(neutralizeDown, neutralizeRight);
        }

        return dp[row][col][remainingNeutralizations] =
                Math.max(takeCurrent, neutralize);
    }

    public int maximumAmount(int[][] coins) {
        int rows = coins.length;
        int cols = coins[0].length;

        int[][][] dp = new int[rows][cols][3];

        // Initialize with MIN_VALUE
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = Integer.MIN_VALUE;
                }
            }
        }

        return dfs(coins, 0, 0, rows, cols, 2, dp);
    }
}
