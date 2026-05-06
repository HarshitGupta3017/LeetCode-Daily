# Solution for Rotating the Box in PY

class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        
        originalRows = len(boxGrid)
        originalCols = len(boxGrid[0])

        # Create rotated matrix
        rotatedBox = [[None] * originalRows for _ in range(originalCols)]

        # STEP 1: Rotate the matrix
        for row in range(originalRows):
            for col in range(originalCols):
                rotatedBox[col][originalRows - row - 1] = boxGrid[row][col]

        # STEP 2: Apply gravity
        for col in range(originalRows):

            emptyRowPointer = originalCols - 1

            for row in range(originalCols - 1, -1, -1):

                if rotatedBox[row][col] == '*':
                    emptyRowPointer = row - 1
                elif rotatedBox[row][col] == '#':
                    rotatedBox[row][col] = '.'
                    rotatedBox[emptyRowPointer][col] = '#'
                    emptyRowPointer -= 1

        return rotatedBox
