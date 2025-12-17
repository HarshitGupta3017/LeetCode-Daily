# Solution for Best Time to Buy and Sell Stock V in PY

from typing import List

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:

        n = len(prices)
        NEG_INF = -10**18

        # dp[day][remainingTransactions][state]
        # state:
        # 0 -> neutral
        # 1 -> holding buy
        # 2 -> holding short
        dp = [[[NEG_INF] * 3 for _ in range(k + 1)] for _ in range(n + 1)]

        # -------------------------------
        # Base case
        # -------------------------------
        for t in range(k + 1):
            dp[n][t][0] = 0
            dp[n][t][1] = NEG_INF
            dp[n][t][2] = NEG_INF

        # -------------------------------
        # Bottom-up DP
        # -------------------------------
        for day in range(n - 1, -1, -1):
            for t in range(k + 1):

                # ===========================
                # State 0: Neutral
                # ===========================
                dp[day][t][0] = dp[day + 1][t][0]

                if t > 0:
                    # Buy
                    dp[day][t][0] = max(
                        dp[day][t][0],
                        -prices[day] + dp[day + 1][t][1]
                    )

                    # Short sell
                    dp[day][t][0] = max(
                        dp[day][t][0],
                        prices[day] + dp[day + 1][t][2]
                    )

                # ===========================
                # State 1: Holding Buy
                # ===========================
                dp[day][t][1] = dp[day + 1][t][1]

                if t > 0:
                    dp[day][t][1] = max(
                        dp[day][t][1],
                        prices[day] + dp[day + 1][t - 1][0]
                    )

                # ===========================
                # State 2: Holding Short
                # ===========================
                dp[day][t][2] = dp[day + 1][t][2]

                if t > 0:
                    dp[day][t][2] = max(
                        dp[day][t][2],
                        -prices[day] + dp[day + 1][t - 1][0]
                    )

        return dp[0][k][0]
