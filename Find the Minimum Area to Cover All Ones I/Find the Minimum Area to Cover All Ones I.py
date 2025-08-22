# Solution for Find the Minimum Area to Cover All Ones I in PY

class Solution:
    def minimumArea(self, grid: list[list[int]]) -> int:
        totalRows, totalCols = len(grid), len(grid[0])
        minRow, maxRow, minCol, maxCol = totalRows, -1, totalCols, -1
        for row in range(totalRows):
            for col in range(totalCols):
                if grid[row][col] == 1:
                    minRow = min(minRow, row)
                    maxRow = max(maxRow, row)
                    minCol = min(minCol, col)
                    maxCol = max(maxCol, col)
        return (maxRow - minRow + 1) * (maxCol - minCol + 1)
