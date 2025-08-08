// Solution for Soup Servings in JAVA

class Solution {
    // Memoization table
    private Double[][] dp;

    public double soupServings(int n) {
        // For large n, result converges to 1.0
        if (n >= 5000) return 1.0;

        dp = new Double[n + 1][n + 1];
        return getProbability(n, n);
    }

    private double getProbability(int a, int b) {
        // Both soups run out
        if (a <= 0 && b <= 0) return 0.5;
        // Soup A runs out
        if (a <= 0) return 1.0;
        // Soup B runs out
        if (b <= 0) return 0.0;

        if (dp[a][b] != null) return dp[a][b];

        dp[a][b] = 0.25 * (
            getProbability(a - 100, b) +
            getProbability(a - 75, b - 25) +
            getProbability(a - 50, b - 50) +
            getProbability(a - 25, b - 75)
        );

        return dp[a][b];
    }
}
