// Solution for Equal Sum Grid Partition I in JAVA

class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        long totalSum = 0;

        long[] rowSum = new long[rows];
        long[] colSum = new long[cols];

        // Compute totalSum, rowSum, colSum
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                totalSum += grid[r][c];
                rowSum[r] += grid[r][c];
                colSum[c] += grid[r][c];
            }
        }

        // If total sum is odd → cannot partition equally
        if (totalSum % 2 != 0) return false;

        // Check horizontal cut
        long topSum = 0;
        for (int r = 0; r < rows - 1; r++) {
            topSum += rowSum[r];
            if (topSum * 2 == totalSum) return true;
        }

        // Check vertical cut
        long leftSum = 0;
        for (int c = 0; c < cols - 1; c++) {
            leftSum += colSum[c];
            if (leftSum * 2 == totalSum) return true;
        }

        return false;
    }
}
