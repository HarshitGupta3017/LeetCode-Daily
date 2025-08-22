// Solution for Find the Minimum Area to Cover All Ones I in JAVA

class Solution {
    public int minimumArea(int[][] grid) {
        int totalRows = grid.length;
        int totalCols = grid[0].length;
        int minRow = totalRows, maxRow = -1, minCol = totalCols, maxCol = -1;
        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalCols; col++) {
                if (grid[row][col] == 1) {
                    minRow = Math.min(minRow, row);
                    maxRow = Math.max(maxRow, row);
                    minCol = Math.min(minCol, col);
                    maxCol = Math.max(maxCol, col);
                }
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
}
