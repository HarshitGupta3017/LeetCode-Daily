// Solution for Increment Submatrices by One in JAVA

class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {

        // 🔹 2D difference matrix for efficient range updates
        int[][] diffMatrix = new int[n][n];

        // 🔹 Apply difference updates for each query
        for (int[] query : queries) {
            int rowStart = query[0];
            int colStart = query[1];
            int rowEnd   = query[2];
            int colEnd   = query[3];

            // Update each affected row
            for (int row = rowStart; row <= rowEnd; row++) {

                // Begin +1 influence
                diffMatrix[row][colStart]++;

                // End +1 influence (using -1)
                if (colEnd + 1 < n) {
                    diffMatrix[row][colEnd + 1]--;
                }
            }
        }

        // 🔹 Convert each row to prefix sums
        for (int row = 0; row < n; row++) {
            for (int col = 1; col < n; col++) {
                diffMatrix[row][col] += diffMatrix[row][col - 1];
            }
        }

        return diffMatrix;
    }
}
