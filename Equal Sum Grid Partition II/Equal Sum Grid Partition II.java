// Solution for Equal Sum Grid Partition II in JAVA

class Solution {
    boolean check(int[][] grid, long totalSum) {

        int rows = grid.length;
        int cols = grid[0].length;

        HashSet<Long> topSectionValues = new HashSet<>();
        long topSum = 0;

        for (int r = 0; r < rows - 1; r++) {

            for (int c = 0; c < cols; c++) {
                topSectionValues.add((long) grid[r][c]);
                topSum += grid[r][c];
            }

            long bottomSum = totalSum - topSum;
            long diff = topSum - bottomSum;

            if (diff == 0) return true;

            if (diff == grid[0][0]) return true;
            if (diff == grid[0][cols - 1]) return true;
            if (diff == grid[r][0]) return true;

            if (r > 0 && cols > 1 && topSectionValues.contains(diff)) {
                return true;
            }
        }

        return false;
    }

    public boolean canPartitionGrid(int[][] grid) {

        int rows = grid.length;
        int cols = grid[0].length;

        long totalSum = 0;
        for (int[] row : grid) {
            for (int val : row) {
                totalSum += val;
            }
        }

        if (check(grid, totalSum)) return true;

        // reverse rows
        reverse(grid);
        if (check(grid, totalSum)) return true;
        reverse(grid);

        // transpose
        int[][] transposed = new int[cols][rows];
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                transposed[c][r] = grid[r][c];
            }
        }

        if (check(transposed, totalSum)) return true;

        reverse(transposed);
        if (check(transposed, totalSum)) return true;

        return false;
    }

    private void reverse(int[][] grid) {
        int i = 0, j = grid.length - 1;
        while (i < j) {
            int[] temp = grid[i];
            grid[i] = grid[j];
            grid[j] = temp;
            i++;
            j--;
        }
    }
}
