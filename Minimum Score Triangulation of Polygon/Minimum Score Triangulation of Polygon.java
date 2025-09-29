// Solution for Minimum Score Triangulation of Polygon in JAVA

class Solution {
    // Recursive DP function to find minimum triangulation score
    private int solve(int[] polygon, int left, int right, int[][] dp) {
        // Base case: less than 3 vertices means no triangle can be formed
        if (right - left + 1 < 3) {
            return 0;
        }

        // Return memoized result if already computed
        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int minScore = Integer.MAX_VALUE;

        // Try all possible "middle" points to form a triangle (left, k, right)
        for (int k = left + 1; k < right; k++) {
            int triangleScore = polygon[left] * polygon[right] * polygon[k];

            int totalScore = solve(polygon, left, k, dp)
                           + triangleScore
                           + solve(polygon, k, right, dp);

            minScore = Math.min(minScore, totalScore);
        }

        // Store result in memo table
        dp[left][right] = minScore;
        return minScore;
    }

    public int minScoreTriangulation(int[] values) {
        int n = values.length;

        // Memoization table initialized with -1
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        // Compute result for the full polygon (0 to n-1)
        return solve(values, 0, n - 1, dp);
    }
}
