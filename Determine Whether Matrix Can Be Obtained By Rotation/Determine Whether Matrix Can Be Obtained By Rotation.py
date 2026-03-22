# Solution for Determine Whether Matrix Can Be Obtained By Rotation in PY

class Solution:
    
    # Function to rotate matrix by 90° clockwise
    def rotate90Clockwise(self, matrix, size):
        
        # STEP 1: Transpose
        for row in range(size):
            for col in range(row, size):
                matrix[row][col], matrix[col][row] = matrix[col][row], matrix[row][col]

        # STEP 2: Reverse each row
        for row in matrix:
            row.reverse()

    def findRotation(self, mat, target):
        n = len(mat)

        # Try all 4 rotations
        for _ in range(4):

            isSame = True

            # Check if matrices match
            for row in range(n):
                for col in range(n):
                    if mat[row][col] != target[row][col]:
                        isSame = False
                        break
                if not isSame:
                    break

            if isSame:
                return True

            # Rotate and try again
            self.rotate90Clockwise(mat, n)

        return False
