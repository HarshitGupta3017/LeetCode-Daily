# Solution for Equal Sum Grid Partition I in PY

class Solution:
    def canPartitionGrid(self, grid):
        rows = len(grid)
        cols = len(grid[0])

        total_sum = 0

        row_sum = [0] * rows
        col_sum = [0] * cols

        # Compute total_sum, row_sum, col_sum
        for r in range(rows):
            for c in range(cols):
                total_sum += grid[r][c]
                row_sum[r] += grid[r][c]
                col_sum[c] += grid[r][c]

        # If total sum is odd → cannot partition
        if total_sum % 2 != 0:
            return False

        # Check horizontal cut
        top_sum = 0
        for r in range(rows - 1):
            top_sum += row_sum[r]
            if top_sum * 2 == total_sum:
                return True

        # Check vertical cut
        left_sum = 0
        for c in range(cols - 1):
            left_sum += col_sum[c]
            if left_sum * 2 == total_sum:
                return True

        return False
