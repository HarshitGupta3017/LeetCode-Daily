# Solution for Number of Smooth Descent Periods of a Stock in PY

class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:

        total_descent_periods = 0
        current_streak = 1  # single day is valid

        for i in range(1, len(prices)):
            if prices[i - 1] - prices[i] == 1:
                current_streak += 1
            else:
                total_descent_periods += current_streak * (current_streak + 1) // 2
                current_streak = 1

        # Add last streak
        total_descent_periods += current_streak * (current_streak + 1) // 2

        return total_descent_periods
