// Solution for Paths in Matrix Whose Sum Is Divisible by K in JAVA

class Solution {
    public int numberOfPaths(int[][] grid, int k) {

        int m = grid.length;
        int n = grid[0].length;
        int MOD = 1_000_000_007;

        // dp[i][j][r] → number of paths from (i,j) to (m-1,n-1) with remainder r
        int[][][] dp = new int[m + 1][n + 1][k + 1];

        // Base case at destination
        for (int rem = 0; rem < k; rem++) {
            int finalRem = (rem + grid[m - 1][n - 1]) % k;
            dp[m - 1][n - 1][rem] = (finalRem == 0 ? 1 : 0);
        }

        // Fill bottom-up
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1) continue;

                for (int rem = 0; rem < k; rem++) {

                    int updatedRem = (rem + grid[i][j]) % k;

                    int waysDown = (i + 1 < m ? dp[i + 1][j][updatedRem] : 0);
                    int waysRight = (j + 1 < n ? dp[i][j + 1][updatedRem] : 0);

                    dp[i][j][rem] = (waysDown + waysRight) % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
}
