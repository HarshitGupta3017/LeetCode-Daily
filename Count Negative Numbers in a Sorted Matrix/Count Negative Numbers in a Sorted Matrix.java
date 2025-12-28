// Solution for Count Negative Numbers in a Sorted Matrix in JAVA

class Solution {
    public int countNegatives(int[][] grid) {

        int totalRows = grid.length;
        int totalCols = grid[0].length;

        int negativeCount = 0;

        // Start from bottom-left corner
        int row = totalRows - 1;
        int col = 0;

        // Traverse until out of bounds
        while (row >= 0 && col < totalCols) {

            // If current value is negative,
            // all elements to the right in this row are negative
            if (grid[row][col] < 0) {
                negativeCount += (totalCols - col);
                row--;  // move up
            }
            // If current value is non-negative,
            // move right to find first negative
            else {
                col++;
            }
        }

        return negativeCount;
    }
}
