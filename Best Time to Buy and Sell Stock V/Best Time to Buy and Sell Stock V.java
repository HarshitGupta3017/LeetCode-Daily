// Solution for Best Time to Buy and Sell Stock V in JAVA

class Solution {
    public long maximumProfit(int[] prices, int k) {

        int n = prices.length;
        long NEG_INF = Long.MIN_VALUE / 4;

        // dp[day][remainingTransactions][state]
        // state:
        // 0 -> neutral
        // 1 -> holding buy
        // 2 -> holding short
        long[][][] dp = new long[n + 1][k + 1][3];

        // -------------------------------
        // Base case: after last day
        // -------------------------------
        for (int t = 0; t <= k; t++) {
            dp[n][t][0] = 0;
            dp[n][t][1] = NEG_INF;
            dp[n][t][2] = NEG_INF;
        }

        // -------------------------------
        // Bottom-up DP
        // -------------------------------
        for (int day = n - 1; day >= 0; day--) {
            for (int t = 0; t <= k; t++) {

                // ===========================
                // State 0: Neutral
                // ===========================
                dp[day][t][0] = dp[day + 1][t][0]; // do nothing

                if (t > 0) {
                    // Buy
                    dp[day][t][0] = Math.max(
                        dp[day][t][0],
                        -prices[day] + dp[day + 1][t][1]
                    );

                    // Short sell
                    dp[day][t][0] = Math.max(
                        dp[day][t][0],
                        prices[day] + dp[day + 1][t][2]
                    );
                }

                // ===========================
                // State 1: Holding Buy
                // ===========================
                dp[day][t][1] = dp[day + 1][t][1]; // do nothing

                if (t > 0) {
                    // Sell
                    dp[day][t][1] = Math.max(
                        dp[day][t][1],
                        prices[day] + dp[day + 1][t - 1][0]
                    );
                }

                // ===========================
                // State 2: Holding Short
                // ===========================
                dp[day][t][2] = dp[day + 1][t][2]; // do nothing

                if (t > 0) {
                    // Buy back
                    dp[day][t][2] = Math.max(
                        dp[day][t][2],
                        -prices[day] + dp[day + 1][t - 1][0]
                    );
                }
            }
        }

        return dp[0][k][0];
    }
}
