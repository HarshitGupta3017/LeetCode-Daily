// Solution for Count Square Submatrices with All Ones in JAVA

class Solution {
    public int countSquares(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] dp = new int[rows + 1][cols + 1];
        int totalSquares = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (r == 0 || c == 0) {
                    dp[r][c] = matrix[r][c];
                } else if (matrix[r][c] == 1) {
                    dp[r][c] = 1 + Math.min(dp[r-1][c], Math.min(dp[r][c-1], dp[r-1][c-1]));
                }
                totalSquares += dp[r][c];
            }
        }

        return totalSquares;
    }
}
