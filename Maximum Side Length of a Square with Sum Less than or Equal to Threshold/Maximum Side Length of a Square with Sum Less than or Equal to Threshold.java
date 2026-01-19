// Solution for Maximum Side Length of a Square with Sum Less than or Equal to Threshold in JAVA

class Solution {
    public int maxSideLength(int[][] mat, int threshold) {

        int rows = mat.length;
        int cols = mat[0].length;

        // Prefix sum matrix
        int[][] prefix = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] =
                    (i > 0 ? prefix[i - 1][j] : 0) +
                    (j > 0 ? prefix[i][j - 1] : 0) -
                    (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0) +
                    mat[i][j];
            }
        }

        // Helper to get sum of submatrix using prefix sums
        java.util.function.IntFunction<Boolean> isValid = (side) -> {
            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {

                    int r2 = i + side - 1;
                    int c2 = j + side - 1;

                    int sum = prefix[r2][c2];
                    if (i > 0) sum -= prefix[i - 1][c2];
                    if (j > 0) sum -= prefix[r2][j - 1];
                    if (i > 0 && j > 0) sum += prefix[i - 1][j - 1];

                    if (sum <= threshold) return true;
                }
            }
            return false;
        };

        // Binary search on square side length
        int low = 1;
        int high = Math.min(rows, cols);
        int best = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid.apply(mid)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return best;
    }
}
