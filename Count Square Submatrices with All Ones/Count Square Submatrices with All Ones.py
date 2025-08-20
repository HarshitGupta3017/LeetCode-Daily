# Solution for Count Square Submatrices with All Ones in PY

class Solution:
    def countSquares(self, matrix):
        rows, cols = len(matrix), len(matrix[0])
        dp = [[0] * (cols + 1) for _ in range(rows + 1)]
        totalSquares = 0

        for r in range(rows):
            for c in range(cols):
                if r == 0 or c == 0:
                    dp[r][c] = matrix[r][c]
                elif matrix[r][c] == 1:
                    dp[r][c] = 1 + min(dp[r-1][c], dp[r][c-1], dp[r-1][c-1])
                totalSquares += dp[r][c]

        return totalSquares
