// Solution for Find the Minimum Area to Cover All Ones II in JAVA

class Solution {
    private int computeBoundingArea(int rowStart, int rowEnd, int colStart, int colEnd, int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int minRow = rows, maxRow = -1, minCol = cols, maxCol = -1;
        for (int r = rowStart; r < rowEnd; r++) {
            for (int c = colStart; c < colEnd; c++) {
                if (grid[r][c] == 1) {
                    minRow = Math.min(minRow, r);
                    maxRow = Math.max(maxRow, r);
                    minCol = Math.min(minCol, c);
                    maxCol = Math.max(maxCol, c);
                }
            }
        }
        if (maxRow == -1) return 0;
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    private int computeMinAreaSum(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int minAreaSum = Integer.MAX_VALUE;
        for (int rowSplit = 1; rowSplit < rows; rowSplit++) {
            for (int colSplit = 1; colSplit < cols; colSplit++) {
                int topArea = computeBoundingArea(0, rowSplit, 0, cols, grid);
                int bottomLeftArea = computeBoundingArea(rowSplit, rows, 0, colSplit, grid);
                int bottomRightArea = computeBoundingArea(rowSplit, rows, colSplit, cols, grid);
                minAreaSum = Math.min(minAreaSum, topArea + bottomLeftArea + bottomRightArea);

                int topLeftArea = computeBoundingArea(0, rowSplit, 0, colSplit, grid);
                int topRightArea = computeBoundingArea(0, rowSplit, colSplit, cols, grid);
                int bottomArea = computeBoundingArea(rowSplit, rows, 0, cols, grid);
                minAreaSum = Math.min(minAreaSum, topLeftArea + topRightArea + bottomArea);
            }
        }
        for (int rowSplit1 = 1; rowSplit1 < rows; rowSplit1++) {
            for (int rowSplit2 = rowSplit1 + 1; rowSplit2 < rows; rowSplit2++) {
                int topArea = computeBoundingArea(0, rowSplit1, 0, cols, grid);
                int middleArea = computeBoundingArea(rowSplit1, rowSplit2, 0, cols, grid);
                int bottomArea = computeBoundingArea(rowSplit2, rows, 0, cols, grid);
                minAreaSum = Math.min(minAreaSum, topArea + middleArea + bottomArea);
            }
        }
        return minAreaSum;
    }

    private int[][] rotateClockwise(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int[][] rotated = new int[cols][rows];
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                rotated[c][rows - r - 1] = grid[r][c];
            }
        }
        return rotated;
    }

    public int minimumSum(int[][] grid) {
        int result = computeMinAreaSum(grid);
        int[][] rotatedGrid = rotateClockwise(grid);
        result = Math.min(result, computeMinAreaSum(rotatedGrid));
        return result;
    }
}
