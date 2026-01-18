// Solution for Largest Magic Square in CPP

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        /*
            rowSum[r][c] = sum of elements from grid[r][0] to grid[r][c]
            This allows us to get the sum of any row segment in O(1)
            using:
                rowSum[r][right] - rowSum[r][left - 1]
        */
        vector<vector<int>> rowSum(rows, vector<int>(cols));
        for (int r = 0; r < rows; r++) {
            rowSum[r][0] = grid[r][0];
            for (int c = 1; c < cols; c++) {
                rowSum[r][c] = rowSum[r][c - 1] + grid[r][c];
            }
        }

        /*
            colSum[r][c] = sum of elements from grid[0][c] to grid[r][c]
            This allows us to get the sum of any column segment in O(1)
            using:
                colSum[bottom][c] - colSum[top - 1][c]
        */
        vector<vector<int>> colSum(rows, vector<int>(cols));
        for (int c = 0; c < cols; c++) {
            colSum[0][c] = grid[0][c];
            for (int r = 1; r < rows; r++) {
                colSum[r][c] = colSum[r - 1][c] + grid[r][c];
            }
        }

        /*
            We try square sizes from largest → smallest.
            As soon as we find one valid magic square,
            we return immediately (greedy exit).
        */
        for (int side = min(rows, cols); side >= 2; side--) {

            // Try placing a square of this size at every valid position
            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {

                    /*
                        Use the first row of the square
                        as the reference sum that all rows,
                        columns, and diagonals must match.
                    */
                    int expectedSum =
                        rowSum[i][j + side - 1] -
                        (j > 0 ? rowSum[i][j - 1] : 0);

                    bool isMagic = true;

                    /*
                        Check all rows:
                        If any row sum differs, this square
                        cannot be magic → early exit.
                    */
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

                    /*
                        Check all columns:
                        Same logic as rows, but using col prefix sums.
                    */
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

                    /*
                        Diagonal checks:
                        These cannot be optimized with prefix sums
                        easily, so we sum them manually.
                    */
                    int diagSum = 0;
                    int antiDiagSum = 0;

                    for (int d = 0; d < side; d++) {
                        diagSum     += grid[i + d][j + d];
                        antiDiagSum += grid[i + d][j + side - 1 - d];
                    }

                    /*
                        Final validation:
                        Both diagonals must match the expected sum.
                    */
                    if (diagSum == expectedSum &&
                        antiDiagSum == expectedSum) {
                        return side;
                    }
                }
            }
        }

        /*
            If no square of size >= 2 works,
            a single cell (1x1) is always a magic square.
        */
        return 1;
    }
};
