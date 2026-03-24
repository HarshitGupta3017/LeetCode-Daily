// Solution for Construct Product Matrix in JAVA

class Solution {
    public int[][] constructProductMatrix(int[][] grid) {

        final int MOD = 12345;

        int rows = grid.length;
        int cols = grid[0].length;

        int[][] result = new int[rows][cols];

        // STEP 1: Suffix product
        long suffixProduct = 1;

        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {

                result[r][c] = (int) suffixProduct;

                suffixProduct = (suffixProduct * grid[r][c]) % MOD;
            }
        }

        // STEP 2: Prefix product
        long prefixProduct = 1;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                result[r][c] = (int)((prefixProduct * result[r][c]) % MOD);

                prefixProduct = (prefixProduct * grid[r][c]) % MOD;
            }
        }

        return result;
    }
}
