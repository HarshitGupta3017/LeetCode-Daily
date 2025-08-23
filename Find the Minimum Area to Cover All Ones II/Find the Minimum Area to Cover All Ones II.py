# Solution for Find the Minimum Area to Cover All Ones II in PY

from typing import List

class Solution:
    def computeBoundingArea(self, rowStart: int, rowEnd: int, colStart: int, colEnd: int, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        minRow, maxRow, minCol, maxCol = rows, -1, cols, -1
        for r in range(rowStart, rowEnd):
            for c in range(colStart, colEnd):
                if grid[r][c] == 1:
                    minRow = min(minRow, r)
                    maxRow = max(maxRow, r)
                    minCol = min(minCol, c)
                    maxCol = max(maxCol, c)
        if maxRow == -1:
            return 0
        return (maxRow - minRow + 1) * (maxCol - minCol + 1)

    def computeMinAreaSum(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        minAreaSum = float("inf")
        for rowSplit in range(1, rows):
            for colSplit in range(1, cols):
                topArea = self.computeBoundingArea(0, rowSplit, 0, cols, grid)
                bottomLeftArea = self.computeBoundingArea(rowSplit, rows, 0, colSplit, grid)
                bottomRightArea = self.computeBoundingArea(rowSplit, rows, colSplit, cols, grid)
                minAreaSum = min(minAreaSum, topArea + bottomLeftArea + bottomRightArea)

                topLeftArea = self.computeBoundingArea(0, rowSplit, 0, colSplit, grid)
                topRightArea = self.computeBoundingArea(0, rowSplit, colSplit, cols, grid)
                bottomArea = self.computeBoundingArea(rowSplit, rows, 0, cols, grid)
                minAreaSum = min(minAreaSum, topLeftArea + topRightArea + bottomArea)
        for rowSplit1 in range(1, rows):
            for rowSplit2 in range(rowSplit1 + 1, rows):
                topArea = self.computeBoundingArea(0, rowSplit1, 0, cols, grid)
                middleArea = self.computeBoundingArea(rowSplit1, rowSplit2, 0, cols, grid)
                bottomArea = self.computeBoundingArea(rowSplit2, rows, 0, cols, grid)
                minAreaSum = min(minAreaSum, topArea + middleArea + bottomArea)
        return minAreaSum

    def rotateClockwise(self, grid: List[List[int]]) -> List[List[int]]:
        rows, cols = len(grid), len(grid[0])
        return [[grid[r][c] for r in range(rows - 1, -1, -1)] for c in range(cols)]

    def minimumSum(self, grid: List[List[int]]) -> int:
        result = self.computeMinAreaSum(grid)
        rotatedGrid = self.rotateClockwise(grid)
        result = min(result, self.computeMinAreaSum(rotatedGrid))
        return result
