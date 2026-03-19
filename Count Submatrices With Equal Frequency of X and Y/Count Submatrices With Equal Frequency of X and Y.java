// Solution for Count Submatrices With Equal Frequency of X and Y in JAVA

class Solution {

    public int numberOfSubmatrices(char[][] grid) {

        int totalRows = grid.length;
        int totalCols = grid[0].length;

        // prefixSum[r][c][0] -> count of 'X'
        // prefixSum[r][c][1] -> count of 'Y'
        int[][][] prefixSum = new int[totalRows][totalCols][2];

        int validSubmatrixCount = 0;

        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalCols; col++) {

                // Step 1: Current cell contribution
                if (grid[row][col] == 'X') {
                    prefixSum[row][col][0] += 1;
                } else if (grid[row][col] == 'Y') {
                    prefixSum[row][col][1] += 1;
                }

                // Step 2: Add from top
                if (row > 0) {
                    prefixSum[row][col][0] += prefixSum[row - 1][col][0];
                    prefixSum[row][col][1] += prefixSum[row - 1][col][1];
                }

                // Step 3: Add from left
                if (col > 0) {
                    prefixSum[row][col][0] += prefixSum[row][col - 1][0];
                    prefixSum[row][col][1] += prefixSum[row][col - 1][1];
                }

                // Step 4: Remove overlap
                if (row > 0 && col > 0) {
                    prefixSum[row][col][0] -= prefixSum[row - 1][col - 1][0];
                    prefixSum[row][col][1] -= prefixSum[row - 1][col - 1][1];
                }

                int countX = prefixSum[row][col][0];
                int countY = prefixSum[row][col][1];

                if (countX == countY && countX > 0) {
                    validSubmatrixCount++;
                }
            }
        }

        return validSubmatrixCount;
    }
}
