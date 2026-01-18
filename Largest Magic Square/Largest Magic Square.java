// Solution for Largest Magic Square in JAVA

class Solution {
    public int largestMagicSquare(int[][] grid) {

        int rows = grid.length;
        int cols = grid[0].length;

        // Row prefix sums
        int[][] rowSum = new int[rows][cols];
        for (int r = 0; r < rows; r++) {
            rowSum[r][0] = grid[r][0];
            for (int c = 1; c < cols; c++) {
                rowSum[r][c] = rowSum[r][c - 1] + grid[r][c];
            }
        }

        // Column prefix sums
        int[][] colSum = new int[rows][cols];
        for (int c = 0; c < cols; c++) {
            colSum[0][c] = grid[0][c];
            for (int r = 1; r < rows; r++) {
                colSum[r][c] = colSum[r - 1][c] + grid[r][c];
            }
        }

        // Try square sizes from largest to smallest
        for (int side = Math.min(rows, cols); side >= 2; side--) {

            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {

                    // Expected sum from the first row
                    int expectedSum =
                        rowSum[i][j + side - 1] -
                        (j > 0 ? rowSum[i][j - 1] : 0);

                    boolean isMagic = true;

                    // Check all rows
                    for (int r = i + 1; r < i + side; r++) {
                        int currentRowSum =
                            rowSum[r][j + side - 1] -
                            (j > 0 ? rowSum[r][j - 1] : 0);

                        if (currentRowSum != expectedSum) {
                            isMagic = false;
                            break;
                        }
                    }
                    if (!isMagic) continue;

                    // Check all columns
                    for (int c = j; c < j + side; c++) {
                        int currentColSum =
                            colSum[i + side - 1][c] -
                            (i > 0 ? colSum[i - 1][c] : 0);

                        if (currentColSum != expectedSum) {
                            isMagic = false;
                            break;
                        }
                    }
                    if (!isMagic) continue;

                    // Check diagonals
                    int diagSum = 0;
                    int antiDiagSum = 0;

                    for (int d = 0; d < side; d++) {
                        diagSum     += grid[i + d][j + d];
                        antiDiagSum += grid[i + d][j + side - 1 - d];
                    }

                    if (diagSum == expectedSum &&
                        antiDiagSum == expectedSum) {
                        return side;
                    }
                }
            }
        }

        // 1x1 is always a magic square
        return 1;
    }
}
