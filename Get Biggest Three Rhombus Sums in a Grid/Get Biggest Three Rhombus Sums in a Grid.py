# Solution for Get Biggest Three Rhombus Sums in a Grid in PY

class Solution:
    def getBiggestThree(self, grid):

        rows, cols = len(grid), len(grid[0])

        largestThreeSums = set()

        diagonalPrefixRight = [[0]*cols for _ in range(rows)]
        diagonalPrefixLeft = [[0]*cols for _ in range(rows)]

        # Build diagonal prefix sums
        for r in range(rows):
            for c in range(cols):

                diagonalPrefixRight[r][c] = grid[r][c]
                if r-1 >= 0 and c-1 >= 0:
                    diagonalPrefixRight[r][c] += diagonalPrefixRight[r-1][c-1]

                diagonalPrefixLeft[r][c] = grid[r][c]
                if r-1 >= 0 and c+1 < cols:
                    diagonalPrefixLeft[r][c] += diagonalPrefixLeft[r-1][c+1]

        def insert_sum(val):
            largestThreeSums.add(val)
            if len(largestThreeSums) > 3:
                largestThreeSums.remove(min(largestThreeSums))

        for centerRow in range(rows):
            for centerCol in range(cols):

                insert_sum(grid[centerRow][centerCol])

                side = 1
                while (centerRow-side >= 0 and
                       centerRow+side < rows and
                       centerCol-side >= 0 and
                       centerCol+side < cols):

                    sum_val = 0

                    topRow, topCol = centerRow-side, centerCol
                    rightRow, rightCol = centerRow, centerCol+side
                    bottomRow, bottomCol = centerRow+side, centerCol
                    leftRow, leftCol = centerRow, centerCol-side

                    sum_val += diagonalPrefixRight[rightRow][rightCol]
                    if topRow-1 >= 0 and topCol-1 >= 0:
                        sum_val -= diagonalPrefixRight[topRow-1][topCol-1]

                    sum_val += diagonalPrefixLeft[bottomRow][bottomCol]
                    if rightRow-1 >= 0 and rightCol+1 < cols:
                        sum_val -= diagonalPrefixLeft[rightRow-1][rightCol+1]

                    sum_val += diagonalPrefixRight[bottomRow][bottomCol]
                    if leftRow-1 >= 0 and leftCol-1 >= 0:
                        sum_val -= diagonalPrefixRight[leftRow-1][leftCol-1]

                    sum_val += diagonalPrefixLeft[leftRow][leftCol]
                    if topRow-1 >= 0 and topCol+1 < cols:
                        sum_val -= diagonalPrefixLeft[topRow-1][topCol+1]

                    sum_val -= grid[topRow][topCol]
                    sum_val -= grid[rightRow][rightCol]
                    sum_val -= grid[bottomRow][bottomCol]
                    sum_val -= grid[leftRow][leftCol]

                    insert_sum(sum_val)

                    side += 1

        return sorted(largestThreeSums, reverse=True)
