# Solution for Set Matrix Zeroes in PY

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix), len(matrix[0])
        firstRowImpacted, firstColImpacted = False, False

        # Check if first row has 0
        for col in range(n):
            if matrix[0][col] == 0:
                firstRowImpacted = True
                break

        # Check if first col has 0
        for row in range(m):
            if matrix[row][0] == 0:
                firstColImpacted = True
                break

        # Mark zeros in the first row and column
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

        # Use the marks to set corresponding cells to 0
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0

        # Zero out first row if needed
        if firstRowImpacted:
            for j in range(n):
                matrix[0][j] = 0

        # Zero out first column if needed
        if firstColImpacted:
            for i in range(m):
                matrix[i][0] = 0
