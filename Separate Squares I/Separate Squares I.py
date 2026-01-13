# Solution for Separate Squares I in PY

class Solution:
    def isBottomAreaEnough(self, squares, mid_y, total_area):
        bottom_area = 0.0

        for x, y, l in squares:
            top_y = y + l
            bottom_y = y

            # Full square below
            if mid_y > top_y:
                bottom_area += l * l
            # Partial square below
            elif mid_y > bottom_y:
                bottom_area += (mid_y - y) * l

        return bottom_area >= total_area / 2.0

    def separateSquares(self, squares):
        low = float('inf')
        high = float('-inf')
        total_area = 0.0

        # Compute total area and bounds
        for x, y, l in squares:
            total_area += l * l
            low = min(low, y)
            high = max(high, y + l)

        result_y = 0.0

        # Binary search with precision tolerance
        while high - low > 1e-5:
            mid_y = low + (high - low) / 2.0

            if self.isBottomAreaEnough(squares, mid_y, total_area):
                result_y = mid_y
                high = mid_y
            else:
                low = mid_y

        return result_y
