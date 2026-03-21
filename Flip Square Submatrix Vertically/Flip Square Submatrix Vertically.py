# Solution for Flip Square Submatrix Vertically in PY

class Solution:
    def reverseSubmatrix(self, grid, x, y, k):
        # Define boundaries
        topRow = x
        bottomRow = x + k - 1
        leftCol = y
        rightCol = y + k - 1

        # Swap rows
        while topRow < bottomRow:
            for col in range(leftCol, rightCol + 1):
                grid[topRow][col], grid[bottomRow][col] = (
                    grid[bottomRow][col],
                    grid[topRow][col],
                )

            topRow += 1
            bottomRow -= 1

        return grid
