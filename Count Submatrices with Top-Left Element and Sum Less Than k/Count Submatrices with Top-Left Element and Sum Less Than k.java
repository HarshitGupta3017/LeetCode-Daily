// Solution for Count Submatrices with Top-Left Element and Sum Less Than k in JAVA

class Solution {
    public int countSubmatrices(int[][] grid, int k) {

        int totalRows = grid.length;
        int totalCols = grid[0].length;

        int validSubmatrixCount = 0;

        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalCols; col++) {

                // Add top
                if (row > 0)
                    grid[row][col] += grid[row - 1][col];

                // Add left
                if (col > 0)
                    grid[row][col] += grid[row][col - 1];

                // Subtract overlap
                if (row > 0 && col > 0)
                    grid[row][col] -= grid[row - 1][col - 1];

                // Check condition
                if (grid[row][col] <= k) {
                    validSubmatrixCount++;
                } else {
                    // Optimization: break since values only increase
                    break;
                }
            }
        }

        return validSubmatrixCount;
    }
}
