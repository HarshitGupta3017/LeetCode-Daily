// Solution for Minimum ASCII Delete Sum for Two Strings in JAVA

class Solution {

    /*
        Returns the minimum ASCII delete sum required to make
        s1[i ... end] and s2[j ... end] equal.
    */
    private int solve(
            int i,
            int j,
            String s1,
            String s2,
            int m,
            int n,
            int[][] dp
    ) {

        // If both strings are fully processed
        if (i >= m && j >= n) {
            return 0;
        }

        // If s1 is exhausted, delete remaining characters of s2
        if (i >= m) {
            return s2.charAt(j) +
                   solve(i, j + 1, s1, s2, m, n, dp);
        }

        // If s2 is exhausted, delete remaining characters of s1
        if (j >= n) {
            return s1.charAt(i) +
                   solve(i + 1, j, s1, s2, m, n, dp);
        }

        // Return memoized result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // If characters match, move both pointers
        if (s1.charAt(i) == s2.charAt(j)) {
            return dp[i][j] =
                   solve(i + 1, j + 1, s1, s2, m, n, dp);
        }

        // Option 1: delete from s1
        int deleteFromS1 =
                s1.charAt(i) +
                solve(i + 1, j, s1, s2, m, n, dp);

        // Option 2: delete from s2
        int deleteFromS2 =
                s2.charAt(j) +
                solve(i, j + 1, s1, s2, m, n, dp);

        // Choose minimum cost
        dp[i][j] = Math.min(deleteFromS1, deleteFromS2);
        return dp[i][j];
    }

    public int minimumDeleteSum(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        // dp[i][j] = min delete sum for s1[i:] and s2[j:]
        int[][] dp = new int[m][n];

        // Initialize with -1
        for (int i = 0; i < m; i++) {
            Arrays.fill(dp[i], -1);
        }

        return solve(0, 0, s1, s2, m, n, dp);
    }
}
