// Solution for Find the Maximum Number of Fruits Collected in JAVA

class Solution {
    public int maxCollectedFruits(int[][] fruits) {
        int n = fruits.length;

        // Step 1: Child 1 collects from diagonal
        int maxFruits = 0;
        for (int i = 0; i < n; i++) {
            maxFruits += fruits[i][i];
        }

        // Step 2: Prepare DP matrix
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i < j && i + j < n - 1) || (i > j && i + j < n - 1)) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = fruits[i][j];
                }
            }
        }

        // Step 3: Child 2 (i < j)
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int fromTopLeft = (j - 1 >= 0) ? dp[i - 1][j - 1] : 0;
                int fromTop = dp[i - 1][j];
                int fromTopRight = (j + 1 < n) ? dp[i - 1][j + 1] : 0;

                dp[i][j] += Math.max(fromTopLeft, Math.max(fromTop, fromTopRight));
            }
        }

        // Step 4: Child 3 (i > j)
        for (int j = 1; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                int fromTopLeft = (i - 1 >= 0 && j - 1 >= 0) ? dp[i - 1][j - 1] : 0;
                int fromLeft = dp[i][j - 1];
                int fromBottomLeft = (i + 1 < n && j - 1 >= 0) ? dp[i + 1][j - 1] : 0;

                dp[i][j] += Math.max(fromTopLeft, Math.max(fromLeft, fromBottomLeft));
            }
        }

        // Step 5: Total collected fruits
        return maxFruits + dp[n - 2][n - 1] + dp[n - 1][n - 2];
    }
}
