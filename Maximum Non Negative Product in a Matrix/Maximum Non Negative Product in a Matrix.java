// Solution for Maximum Non Negative Product in a Matrix in JAVA

class Solution {
    public int maxProductPath(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        long MOD = 1_000_000_007;

        // dp[r][c][0] = max product
        // dp[r][c][1] = min product
        long[][][] dp = new long[rows][cols][2];

        // Base case
        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = grid[0][0];

        // First row
        for (int col = 1; col < cols; col++) {
            long val = grid[0][col];
            dp[0][col][0] = dp[0][col - 1][0] * val;
            dp[0][col][1] = dp[0][col - 1][1] * val;
        }

        // First column
        for (int row = 1; row < rows; row++) {
            long val = grid[row][0];
            dp[row][0][0] = dp[row - 1][0][0] * val;
            dp[row][0][1] = dp[row - 1][0][1] * val;
        }

        // Fill rest
        for (int row = 1; row < rows; row++) {
            for (int col = 1; col < cols; col++) {
                long val = grid[row][col];

                long topMax = dp[row - 1][col][0];
                long topMin = dp[row - 1][col][1];

                long leftMax = dp[row][col - 1][0];
                long leftMin = dp[row][col - 1][1];

                long[] candidates = new long[]{
                    topMax * val,
                    topMin * val,
                    leftMax * val,
                    leftMin * val
                };

                long maxVal = candidates[0];
                long minVal = candidates[0];

                for (long x : candidates) {
                    maxVal = Math.max(maxVal, x);
                    minVal = Math.min(minVal, x);
                }

                dp[row][col][0] = maxVal;
                dp[row][col][1] = minVal;
            }
        }

        long result = dp[rows - 1][cols - 1][0];

        if (result < 0) return -1;

        return (int)(result % MOD);
    }
}
