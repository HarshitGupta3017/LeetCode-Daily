# Solution for Largest Submatrix With Rearrangements in PY

class Solution:
    def largestSubmatrix(self, matrix):
        totalRows = len(matrix)
        totalCols = len(matrix[0])

        maximumArea = 0

        # Stores (height, columnIndex)
        previousRowHeights = []

        for row in range(totalRows):

            currentRowHeights = []
            columnVisited = [False] * totalCols

            # Step 1: Extend previous heights
            for previousHeight, columnIndex in previousRowHeights:
                if matrix[row][columnIndex] == 1:
                    currentRowHeights.append((previousHeight + 1, columnIndex))
                    columnVisited[columnIndex] = True

            # Step 2: Add new columns with height = 1
            for col in range(totalCols):
                if not columnVisited[col] and matrix[row][col] == 1:
                    currentRowHeights.append((1, col))

            # Step 3: Compute max area
            for i in range(len(currentRowHeights)):
                width = i + 1
                height = currentRowHeights[i][0]
                maximumArea = max(maximumArea, width * height)

            # Step 4: Move to next row
            previousRowHeights = currentRowHeights

        return maximumArea
