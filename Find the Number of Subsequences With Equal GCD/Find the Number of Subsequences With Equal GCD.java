// Solution for Find the Number of Subsequences With Equal GCD in JAVA

class Solution {
    private static final int MOD = 1_000_000_007;

    public int subsequencePairCount(int[] nums) {
        int n = nums.length;
        int maxVal = 0;
        for (int x : nums) {
            maxVal = Math.max(maxVal, x);
        }

        int[][] dp = new int[maxVal + 1][maxVal + 1];

        // Base case
        for (int g = 1; g <= maxVal; g++) {
            dp[g][g] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            int[][] next = new int[maxVal + 1][maxVal + 1];

            for (int g1 = 0; g1 <= maxVal; g1++) {
                for (int g2 = 0; g2 <= maxVal; g2++) {
                    int skip = dp[g1][g2];
                    int assignToSeq1 = dp[gcd(g1, nums[i])][g2];
                    int assignToSeq2 = dp[g1][gcd(g2, nums[i])];

                    next[g1][g2] = (int) (((long) skip + assignToSeq1 + assignToSeq2) % MOD);
                }
            }

            dp = next;
        }

        return dp[0][0];
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
}
