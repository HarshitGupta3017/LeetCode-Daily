// Solution for Minimum Absolute Difference in Sliding Submatrix in JAVA

class Solution {
    public int[][] minAbsDiff(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] result = new int[m - k + 1][n - k + 1];

        for (int rowStart = 0; rowStart <= m - k; rowStart++) {
            for (int colStart = 0; colStart <= n - k; colStart++) {

                List<Integer> submatrixElements = new ArrayList<>();

                for (int r = rowStart; r < rowStart + k; r++) {
                    for (int c = colStart; c < colStart + k; c++) {
                        submatrixElements.add(grid[r][c]);
                    }
                }

                Collections.sort(submatrixElements);

                int minDiff = Integer.MAX_VALUE;

                for (int i = 1; i < submatrixElements.size(); i++) {
                    if (!submatrixElements.get(i).equals(submatrixElements.get(i - 1))) {
                        minDiff = Math.min(minDiff,
                                submatrixElements.get(i) - submatrixElements.get(i - 1));
                    }
                }

                result[rowStart][colStart] = (minDiff == Integer.MAX_VALUE ? 0 : minDiff);
            }
        }

        return result;
    }
}
