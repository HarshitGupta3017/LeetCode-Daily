# Solution for Minimum Absolute Difference in Sliding Submatrix in PY

class Solution:
    def minAbsDiff(self, grid, k):
        m, n = len(grid), len(grid[0])

        result = [[0] * (n - k + 1) for _ in range(m - k + 1)]

        for rowStart in range(m - k + 1):
            for colStart in range(n - k + 1):

                submatrix_elements = []

                for r in range(rowStart, rowStart + k):
                    for c in range(colStart, colStart + k):
                        submatrix_elements.append(grid[r][c])

                submatrix_elements.sort()

                min_diff = float('inf')

                for i in range(1, len(submatrix_elements)):
                    if submatrix_elements[i] != submatrix_elements[i - 1]:
                        min_diff = min(min_diff,
                                       submatrix_elements[i] - submatrix_elements[i - 1])

                result[rowStart][colStart] = 0 if min_diff == float('inf') else min_diff

        return result
