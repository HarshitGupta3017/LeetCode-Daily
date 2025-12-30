// Solution for Magic Squares In Grid in JAVA

class Solution {

    /**
     * Checks whether the 3x3 subgrid starting at (startRow, startCol)
     * forms a valid magic square.
     */
    private boolean isMagicSquare(int[][] grid, int startRow, int startCol) {

        // To ensure all numbers are distinct and in the range [1, 9]
        Set<Integer> uniqueValues = new HashSet<>();

        // Validate number range and uniqueness
        for (int rowOffset = 0; rowOffset < 3; rowOffset++) {
            for (int colOffset = 0; colOffset < 3; colOffset++) {

                int value = grid[startRow + rowOffset][startCol + colOffset];

                // Magic square must contain numbers from 1 to 9 exactly once
                if (value < 1 || value > 9 || uniqueValues.contains(value)) {
                    return false;
                }
                uniqueValues.add(value);
            }
        }

        // Target sum using the first row
        int targetSum =
            grid[startRow][startCol] +
            grid[startRow][startCol + 1] +
            grid[startRow][startCol + 2];

        // Check all rows and columns
        for (int i = 0; i < 3; i++) {

            int rowSum =
                grid[startRow + i][startCol] +
                grid[startRow + i][startCol + 1] +
                grid[startRow + i][startCol + 2];

            int colSum =
                grid[startRow][startCol + i] +
                grid[startRow + 1][startCol + i] +
                grid[startRow + 2][startCol + i];

            if (rowSum != targetSum || colSum != targetSum) {
                return false;
            }
        }

        // Check both diagonals
        int mainDiagonal =
            grid[startRow][startCol] +
            grid[startRow + 1][startCol + 1] +
            grid[startRow + 2][startCol + 2];

        int antiDiagonal =
            grid[startRow][startCol + 2] +
            grid[startRow + 1][startCol + 1] +
            grid[startRow + 2][startCol];

        return mainDiagonal == targetSum && antiDiagonal == targetSum;
    }

    /**
     * Counts the number of 3x3 magic square subgrids.
     */
    public int numMagicSquaresInside(int[][] grid) {

        int totalRows = grid.length;
        int totalCols = grid[0].length;
        int magicSquareCount = 0;

        // Slide a 3x3 window over the grid
        for (int row = 0; row <= totalRows - 3; row++) {
            for (int col = 0; col <= totalCols - 3; col++) {
                if (isMagicSquare(grid, row, col)) {
                    magicSquareCount++;
                }
            }
        }

        return magicSquareCount;
    }
}
