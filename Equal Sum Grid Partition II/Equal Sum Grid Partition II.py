# Solution for Equal Sum Grid Partition II in PY

class Solution:
    def check(self, grid, total_sum):
        rows, cols = len(grid), len(grid[0])

        top_values = set()
        top_sum = 0

        for r in range(rows - 1):

            for c in range(cols):
                top_values.add(grid[r][c])
                top_sum += grid[r][c]

            bottom_sum = total_sum - top_sum
            diff = top_sum - bottom_sum

            if diff == 0:
                return True

            if diff == grid[0][0]:
                return True
            if diff == grid[0][cols - 1]:
                return True
            if diff == grid[r][0]:
                return True

            if r > 0 and cols > 1 and diff in top_values:
                return True

        return False

    def canPartitionGrid(self, grid):
        rows, cols = len(grid), len(grid[0])

        total_sum = sum(sum(row) for row in grid)

        if self.check(grid, total_sum):
            return True

        # reverse rows
        grid.reverse()
        if self.check(grid, total_sum):
            return True
        grid.reverse()

        # transpose
        transposed = [[grid[r][c] for r in range(rows)] for c in range(cols)]

        if self.check(transposed, total_sum):
            return True

        transposed.reverse()
        if self.check(transposed, total_sum):
            return True

        return False
