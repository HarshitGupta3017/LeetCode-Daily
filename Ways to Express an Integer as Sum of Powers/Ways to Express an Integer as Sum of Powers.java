// Solution for Ways to Express an Integer as Sum of Powers in JAVA

class Solution {
    private final int MOD = 1_000_000_007;
    
    public int countWays(int remainingSum, int currentBase, int power, int[][] dp) {
        // Base case: exact sum reached
        if (remainingSum == 0) return 1;
        // Sum exceeded
        if (remainingSum < 0) return 0;

        int currentValue = (int) Math.pow(currentBase, power);

        // If currentValue exceeds remainingSum, stop
        if (currentValue > remainingSum) return 0;

        // Memoization check
        if (dp[remainingSum][currentBase] != -1) return dp[remainingSum][currentBase];

        // Include currentBase
        int takeOption = countWays(remainingSum - currentValue, currentBase + 1, power, dp);
        // Skip currentBase
        int skipOption = countWays(remainingSum, currentBase + 1, power, dp);

        dp[remainingSum][currentBase] = (int) ((takeOption + (long) skipOption) % MOD);
        return dp[remainingSum][currentBase];
    }
    
    public int numberOfWays(int n, int x) {
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return countWays(n, 1, x, dp);
    }
}
