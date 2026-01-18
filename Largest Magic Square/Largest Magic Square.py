# Solution for Largest Magic Square in PY

class Solution:
    def largestMagicSquare(self, grid):

        rows = len(grid)
        cols = len(grid[0])

        # Row prefix sums
        row_sum = [[0] * cols for _ in range(rows)]
        for r in range(rows):
            row_sum[r][0] = grid[r][0]
            for c in range(1, cols):
                row_sum[r][c] = row_sum[r][c - 1] + grid[r][c]

        # Column prefix sums
        col_sum = [[0] * cols for _ in range(rows)]
        for c in range(cols):
            col_sum[0][c] = grid[0][c]
            for r in range(1, rows):
                col_sum[r][c] = col_sum[r - 1][c] + grid[r][c]

        # Try square sizes from largest to smallest
        for side in range(min(rows, cols), 1, -1):

            for i in range(rows - side + 1):
                for j in range(cols - side + 1):

                    # Expected sum from the first row
                    expected_sum = (
                        row_sum[i][j + side - 1] -
                        (row_sum[i][j - 1] if j > 0 else 0)
                    )

                    is_magic = True

                    # Check rows
                    for r in range(i + 1, i + side):
                        current_row_sum = (
                            row_sum[r][j + side - 1] -
                            (row_sum[r][j - 1] if j > 0 else 0)
                        )
                        if current_row_sum != expected_sum:
                            is_magic = False
                            break
                    if not is_magic:
                        continue

                    # Check columns
                    for c in range(j, j + side):
                        current_col_sum = (
                            col_sum[i + side - 1][c] -
                            (col_sum[i - 1][c] if i > 0 else 0)
                        )
                        if current_col_sum != expected_sum:
                            is_magic = False
                            break
                    if not is_magic:
                        continue

                    # Check diagonals
                    diag_sum = 0
                    anti_diag_sum = 0
                    for d in range(side):
                        diag_sum += grid[i + d][j + d]
                        anti_diag_sum += grid[i + d][j + side - 1 - d]

                    if diag_sum == expected_sum and anti_diag_sum == expected_sum:
                        return side

        return 1
