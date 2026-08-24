// Solution for Stone Game VIII in JAVA

class Solution {
    public int stoneGameVIII(int[] stones) {
        int n = stones.length;

        // prefix[i] = sum of stones[0..i]
        int[] prefix = new int[n];
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // dp[i] = best score difference from position i onward
        int[] dp = new int[n];

        // Base case
        dp[n - 1] = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            // Pick up to index i
            int pickHere = prefix[i] - dp[i + 1];

            // Skip index i
            int skipHere = dp[i + 1];

            dp[i] = Math.max(pickHere, skipHere);
        }

        // First move must take at least 2 stones
        return dp[1];
    }
}
