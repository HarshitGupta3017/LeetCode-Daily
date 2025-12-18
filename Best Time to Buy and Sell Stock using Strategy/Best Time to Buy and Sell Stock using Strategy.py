# Solution for Best Time to Buy and Sell Stock using Strategy in PY

class Solution:
    def maxProfit(self, prices, strategy, k):
        total_days = len(prices)

        # ---------------------------------------------
        # STEP 1: Compute base profit
        # ---------------------------------------------
        base_profit = 0
        daily_profit = [0] * total_days

        for i in range(total_days):
            daily_profit[i] = prices[i] * strategy[i]
            base_profit += daily_profit[i]

        # ---------------------------------------------
        # STEP 2: Sliding window
        # ---------------------------------------------
        original_window_profit = 0
        modified_window_profit = 0
        best_extra_gain = 0

        left = 0

        for right in range(total_days):
            original_window_profit += daily_profit[right]

            # Second half of window → SELL
            if right - left + 1 > k // 2:
                modified_window_profit += prices[right]

            # Shrink window if size > k
            if right - left + 1 > k:
                original_window_profit -= daily_profit[left]
                modified_window_profit -= prices[left + k // 2]
                left += 1

            # Evaluate when window size == k
            if right - left + 1 == k:
                gain = modified_window_profit - original_window_profit
                best_extra_gain = max(best_extra_gain, gain)

        # ---------------------------------------------
        # STEP 3: Final answer
        # ---------------------------------------------
        return base_profit + best_extra_gain
