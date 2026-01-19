# Solution for Maximum Side Length of a Square with Sum Less than or Equal to Threshold in PY

class Solution:
    def maxSideLength(self, mat, threshold):

        rows = len(mat)
        cols = len(mat[0])

        # Prefix sum matrix
        prefix = [[0] * cols for _ in range(rows)]

        for i in range(rows):
            for j in range(cols):
                prefix[i][j] = (
                    (prefix[i - 1][j] if i > 0 else 0) +
                    (prefix[i][j - 1] if j > 0 else 0) -
                    (prefix[i - 1][j - 1] if i > 0 and j > 0 else 0) +
                    mat[i][j]
                )

        # Check if any square of given side length is valid
        def is_valid(side):
            for i in range(rows - side + 1):
                for j in range(cols - side + 1):

                    r2 = i + side - 1
                    c2 = j + side - 1

                    total = prefix[r2][c2]
                    if i > 0:
                        total -= prefix[i - 1][c2]
                    if j > 0:
                        total -= prefix[r2][j - 1]
                    if i > 0 and j > 0:
                        total += prefix[i - 1][j - 1]

                    if total <= threshold:
                        return True
            return False

        # Binary search on side length
        low, high = 1, min(rows, cols)
        best = 0

        while low <= high:
            mid = (low + high) // 2
            if is_valid(mid):
                best = mid
                low = mid + 1
            else:
                high = mid - 1

        return best
