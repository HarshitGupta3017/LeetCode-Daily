# Solution for Matrix Similarity After Cyclic Shifts in PY

class Solution:
    def areSimilar(self, matrix, k):
        totalRows = len(matrix)
        totalCols = len(matrix[0])

        # Normalize k
        k %= totalCols

        if k == 0:
            return True

        for row in range(totalRows):
            for col in range(totalCols):

                # Odd row → shift right
                if row % 2 == 1:
                    shiftedIndex = (col - k + totalCols) % totalCols
                # Even row → shift left
                else:
                    shiftedIndex = (col + k) % totalCols

                if matrix[row][col] != matrix[row][shiftedIndex]:
                    return False

        return True
