// Solution for Count Square Submatrices with All Ones in CPP

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int totalSquares = 0;  
        int rows = matrix.size();        // Total rows in matrix
        int cols = matrix[0].size();     // Total columns in matrix

        // DP table: dp[i][j] = size of the largest square submatrix 
        // with bottom-right corner at (i, j) or that ends at (i, j).
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));

        // Traverse through each cell of the matrix
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                // For the first row/column, the largest square ending here is 
                // just the matrix value itself (1 or 0), only 1x1 square is possible
                if (r == 0 || c == 0) {
                    dp[r][c] = matrix[r][c];
                } 
                // If current cell has value 1, then it can form squares
                else if (matrix[r][c] == 1) {
                    // The largest square ending here depends on the
                    // smallest square possible from:
                    //   - top cell     (dp[r-1][c])
                    //   - left cell    (dp[r][c-1])
                    //   - top-left     (dp[r-1][c-1])
                    dp[r][c] = 1 + min({dp[r-1][c], dp[r][c-1], dp[r-1][c-1]});
                }

                // Accumulate total squares counted till now
                totalSquares += dp[r][c];
            }
        }

        // totalSquares now contains count of all square submatrices of 1s
        return totalSquares;
    }
};
