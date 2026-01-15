# Solution for Maximize Area of Square Hole in Grid in PY

class Solution:
    """
    Finds the maximum number of consecutive removable bars.
    Example: [2,3,4] → 3 consecutive bars
    """
    def maxConsecutiveBars(self, bars):
        if not bars:
            return 0

        max_count = 1
        current_count = 1

        for i in range(1, len(bars)):
            if bars[i] == bars[i - 1] + 1:
                current_count += 1
            else:
                current_count = 1
            max_count = max(max_count, current_count)

        return max_count

    def maximizeSquareHoleArea(self, n, m, hBars, vBars):
        # Sort bars to detect consecutive removals
        hBars.sort()
        vBars.sort()

        max_horizontal = self.maxConsecutiveBars(hBars)
        max_vertical = self.maxConsecutiveBars(vBars)

        # Removing k consecutive bars creates (k + 1) free cells
        square_side = min(max_horizontal, max_vertical) + 1

        return square_side * square_side
