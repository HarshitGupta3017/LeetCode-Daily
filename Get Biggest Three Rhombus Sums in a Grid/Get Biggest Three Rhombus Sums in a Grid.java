// Solution for Get Biggest Three Rhombus Sums in a Grid in JAVA

class Solution {
    public int[] getBiggestThree(int[][] grid) {

        int rows = grid.length;
        int cols = grid[0].length;

        TreeSet<Integer> largestThreeSums = new TreeSet<>();

        int[][] diagonalPrefixRight = new int[rows][cols];
        int[][] diagonalPrefixLeft = new int[rows][cols];

        // Build diagonal prefix sums
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                diagonalPrefixRight[r][c] = grid[r][c];
                if (r - 1 >= 0 && c - 1 >= 0)
                    diagonalPrefixRight[r][c] += diagonalPrefixRight[r - 1][c - 1];

                diagonalPrefixLeft[r][c] = grid[r][c];
                if (r - 1 >= 0 && c + 1 < cols)
                    diagonalPrefixLeft[r][c] += diagonalPrefixLeft[r - 1][c + 1];
            }
        }

        // helper function
        java.util.function.IntConsumer insertSum = sumValue -> {
            largestThreeSums.add(sumValue);
            if (largestThreeSums.size() > 3) {
                largestThreeSums.pollFirst();
            }
        };

        for (int centerRow = 0; centerRow < rows; centerRow++) {
            for (int centerCol = 0; centerCol < cols; centerCol++) {

                insertSum.accept(grid[centerRow][centerCol]);

                for (int side = 1;
                     centerRow - side >= 0 &&
                     centerRow + side < rows &&
                     centerCol - side >= 0 &&
                     centerCol + side < cols;
                     side++) {

                    int sum = 0;

                    int topRow = centerRow - side, topCol = centerCol;
                    int rightRow = centerRow, rightCol = centerCol + side;
                    int bottomRow = centerRow + side, bottomCol = centerCol;
                    int leftRow = centerRow, leftCol = centerCol - side;

                    sum += diagonalPrefixRight[rightRow][rightCol];
                    if (topRow - 1 >= 0 && topCol - 1 >= 0)
                        sum -= diagonalPrefixRight[topRow - 1][topCol - 1];

                    sum += diagonalPrefixLeft[bottomRow][bottomCol];
                    if (rightRow - 1 >= 0 && rightCol + 1 < cols)
                        sum -= diagonalPrefixLeft[rightRow - 1][rightCol + 1];

                    sum += diagonalPrefixRight[bottomRow][bottomCol];
                    if (leftRow - 1 >= 0 && leftCol - 1 >= 0)
                        sum -= diagonalPrefixRight[leftRow - 1][leftCol - 1];

                    sum += diagonalPrefixLeft[leftRow][leftCol];
                    if (topRow - 1 >= 0 && topCol + 1 < cols)
                        sum -= diagonalPrefixLeft[topRow - 1][topCol + 1];

                    sum -= grid[topRow][topCol];
                    sum -= grid[rightRow][rightCol];
                    sum -= grid[bottomRow][bottomCol];
                    sum -= grid[leftRow][leftCol];

                    insertSum.accept(sum);
                }
            }
        }

        int size = largestThreeSums.size();
        int[] result = new int[size];
        int idx = size - 1;

        for (int val : largestThreeSums) {
            result[idx--] = val;
        }

        return result;
    }
}
