// Solution for Best Time to Buy and Sell Stock V in CPP

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int maxTransactions) {

        int totalDays = prices.size();

        // dp[day][remainingTransactions][state]
        // state:
        // 0 -> neutral (no open transaction)
        // 1 -> holding a buy (must sell next)
        // 2 -> holding a short sell (must buy next)
        vector<vector<vector<long long>>> dp(
            totalDays + 1,
            vector<vector<long long>>(
                maxTransactions + 1,
                vector<long long>(3, INT_MIN)
            )
        );

        // -------------------------------
        // BASE CASE: after last day
        // -------------------------------
        for (int transactionsLeft = 0; transactionsLeft <= maxTransactions; transactionsLeft++) {
            dp[totalDays][transactionsLeft][0] = 0;        // valid end state
            dp[totalDays][transactionsLeft][1] = INT_MIN; // cannot hold buy
            dp[totalDays][transactionsLeft][2] = INT_MIN; // cannot hold short
        }

        // -------------------------------
        // Fill DP table bottom-up
        // -------------------------------
        for (int day = totalDays - 1; day >= 0; day--) {
            for (int transactionsLeft = 0; transactionsLeft <= maxTransactions; transactionsLeft++) {

                // ===========================
                // STATE 0: Neutral
                // ===========================
                // Option 1: Do nothing
                dp[day][transactionsLeft][0] =
                    dp[day + 1][transactionsLeft][0];

                if (transactionsLeft > 0) {
                    // Option 2: Buy stock
                    dp[day][transactionsLeft][0] =
                        max(dp[day][transactionsLeft][0],
                            -prices[day] + dp[day + 1][transactionsLeft][1]);

                    // Option 3: Short sell stock
                    dp[day][transactionsLeft][0] =
                        max(dp[day][transactionsLeft][0],
                            prices[day] + dp[day + 1][transactionsLeft][2]);
                }

                // ===========================
                // STATE 1: Holding Buy
                // ===========================
                // Option 1: Do nothing
                dp[day][transactionsLeft][1] =
                    dp[day + 1][transactionsLeft][1];

                if (transactionsLeft > 0) {
                    // Option 2: Sell stock (complete transaction)
                    dp[day][transactionsLeft][1] =
                        max(dp[day][transactionsLeft][1],
                            prices[day] + dp[day + 1][transactionsLeft - 1][0]);
                }

                // ===========================
                // STATE 2: Holding Short
                // ===========================
                // Option 1: Do nothing
                dp[day][transactionsLeft][2] =
                    dp[day + 1][transactionsLeft][2];

                if (transactionsLeft > 0) {
                    // Option 2: Buy back (complete transaction)
                    dp[day][transactionsLeft][2] =
                        max(dp[day][transactionsLeft][2],
                            -prices[day] + dp[day + 1][transactionsLeft - 1][0]);
                }
            }
        }

        // Start from day 0, K transactions, neutral state
        return dp[0][maxTransactions][0];
    }
};
