// Solution for Shift 2D Grid in JAVA

class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int rows = grid.length;
        int cols = grid[0].length;
        int totalCells = rows * cols;

        k %= totalCells;
        if (k != 0) {
            reverseSegment(grid, 0, totalCells - 1, cols);
            reverseSegment(grid, 0, k - 1, cols);
            reverseSegment(grid, k, totalCells - 1, cols);
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < rows; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j < cols; j++) {
                row.add(grid[i][j]);
            }
            result.add(row);
        }

        return result;
    }

    private void reverseSegment(int[][] grid, int lo, int hi, int cols) {
        while (lo < hi) {
            int r1 = lo / cols, c1 = lo % cols;
            int r2 = hi / cols, c2 = hi % cols;

            int temp = grid[r1][c1];
            grid[r1][c1] = grid[r2][c2];
            grid[r2][c2] = temp;

            lo++;
            hi--;
        }
    }
}
