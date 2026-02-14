// Solution for Champagne Tower in JAVA

class Solution {

    private double computeAmount(int poured, int row, int col, double[][] memo) {

        // Invalid positions
        if (row < 0 || col < 0 || col > row)
            return 0.0;

        // Base case
        if (row == 0 && col == 0)
            return poured;

        // Already computed
        if (memo[row][col] != -1.0)
            return memo[row][col];

        double leftParent = Math.max(0.0,
                (computeAmount(poured, row - 1, col - 1, memo) - 1.0) / 2.0);

        double rightParent = Math.max(0.0,
                (computeAmount(poured, row - 1, col, memo) - 1.0) / 2.0);

        memo[row][col] = leftParent + rightParent;
        return memo[row][col];
    }

    public double champagneTower(int poured, int query_row, int query_glass) {

        double[][] memo = new double[101][101];

        // Initialize with -1.0
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                memo[i][j] = -1.0;
            }
        }

        return Math.min(1.0,
                computeAmount(poured, query_row, query_glass, memo));
    }
}
