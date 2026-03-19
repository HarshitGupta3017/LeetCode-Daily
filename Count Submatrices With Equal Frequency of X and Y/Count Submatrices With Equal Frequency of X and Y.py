# Solution for Count Submatrices With Equal Frequency of X and Y in PY

class Solution:
    def numberOfSubmatrices(self, grid):
        totalRows = len(grid)
        totalCols = len(grid[0])

        # prefixSum[r][c] = [countX, countY]
        prefixSum = [[[0, 0] for _ in range(totalCols)] for _ in range(totalRows)]

        validSubmatrixCount = 0

        for row in range(totalRows):
            for col in range(totalCols):

                # Step 1: Current cell
                if grid[row][col] == 'X':
                    prefixSum[row][col][0] += 1
                elif grid[row][col] == 'Y':
                    prefixSum[row][col][1] += 1

                # Step 2: From top
                if row > 0:
                    prefixSum[row][col][0] += prefixSum[row - 1][col][0]
                    prefixSum[row][col][1] += prefixSum[row - 1][col][1]

                # Step 3: From left
                if col > 0:
                    prefixSum[row][col][0] += prefixSum[row][col - 1][0]
                    prefixSum[row][col][1] += prefixSum[row][col - 1][1]

                # Step 4: Remove overlap
                if row > 0 and col > 0:
                    prefixSum[row][col][0] -= prefixSum[row - 1][col - 1][0]
                    prefixSum[row][col][1] -= prefixSum[row - 1][col - 1][1]

                countX = prefixSum[row][col][0]
                countY = prefixSum[row][col][1]

                if countX == countY and countX > 0:
                    validSubmatrixCount += 1

        return validSubmatrixCount
