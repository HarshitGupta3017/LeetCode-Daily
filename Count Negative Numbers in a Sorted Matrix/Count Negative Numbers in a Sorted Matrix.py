# Solution for Count Negative Numbers in a Sorted Matrix in PY

class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:

        total_rows = len(grid)
        total_cols = len(grid[0])

        negative_count = 0

        # Start from bottom-left corner
        row = total_rows - 1
        col = 0

        # Traverse until out of bounds
        while row >= 0 and col < total_cols:

            # If current value is negative,
            # all elements to the right are also negative
            if grid[row][col] < 0:
                negative_count += (total_cols - col)
                row -= 1  # move up
            else:
                col += 1  # move right

        return negative_count
