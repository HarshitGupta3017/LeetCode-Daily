# Solution for Magic Squares In Grid in PY

class Solution:
    def isMagicSquare(self, grid: List[List[int]], start_row: int, start_col: int) -> bool:
        # Ensure all numbers are distinct and in range [1, 9]
        unique_values = set()

        for r in range(3):
            for c in range(3):
                value = grid[start_row + r][start_col + c]
                if value < 1 or value > 9 or value in unique_values:
                    return False
                unique_values.add(value)

        # Target sum from first row
        target_sum = (
            grid[start_row][start_col] +
            grid[start_row][start_col + 1] +
            grid[start_row][start_col + 2]
        )

        # Check rows and columns
        for i in range(3):
            row_sum = (
                grid[start_row + i][start_col] +
                grid[start_row + i][start_col + 1] +
                grid[start_row + i][start_col + 2]
            )

            col_sum = (
                grid[start_row][start_col + i] +
                grid[start_row + 1][start_col + i] +
                grid[start_row + 2][start_col + i]
            )

            if row_sum != target_sum or col_sum != target_sum:
                return False

        # Check diagonals
        main_diagonal = (
            grid[start_row][start_col] +
            grid[start_row + 1][start_col + 1] +
            grid[start_row + 2][start_col + 2]
        )

        anti_diagonal = (
            grid[start_row][start_col + 2] +
            grid[start_row + 1][start_col + 1] +
            grid[start_row + 2][start_col]
        )

        return main_diagonal == target_sum and anti_diagonal == target_sum

    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        total_rows = len(grid)
        total_cols = len(grid[0])
        magic_square_count = 0

        # Slide a 3x3 window over the grid
        for row in range(total_rows - 2):
            for col in range(total_cols - 2):
                if self.isMagicSquare(grid, row, col):
                    magic_square_count += 1

        return magic_square_count
