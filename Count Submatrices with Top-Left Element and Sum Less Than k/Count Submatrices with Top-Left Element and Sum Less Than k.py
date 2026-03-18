# Solution for Count Submatrices with Top-Left Element and Sum Less Than k in PY

class Solution:
    def countSubmatrices(self, grid, k):
        totalRows = len(grid)
        totalCols = len(grid[0])

        validSubmatrixCount = 0

        for row in range(totalRows):
            for col in range(totalCols):

                # Add top
                if row > 0:
                    grid[row][col] += grid[row - 1][col]

                # Add left
                if col > 0:
                    grid[row][col] += grid[row][col - 1]

                # Subtract overlap
                if row > 0 and col > 0:
                    grid[row][col] -= grid[row - 1][col - 1]

                # Check condition
                if grid[row][col] <= k:
                    validSubmatrixCount += 1
                else:
                    # Optimization
                    break

        return validSubmatrixCount
