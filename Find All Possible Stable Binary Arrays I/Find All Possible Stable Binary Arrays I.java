// Solution for Find All Possible Stable Binary Arrays I in JAVA

class Solution {

    static final int MOD = 1_000_000_007;

    public int numberOfStableArrays(int zero, int one, int limit) {

        /*
        dp[z][o][last]
        z = zeros used
        o = ones used
        last = 0 -> last block was zeros
               1 -> last block was ones
        */

        int[][][] dp = new int[zero + 1][one + 1][2];

        // Base case
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (int zerosUsed = 0; zerosUsed <= zero; zerosUsed++) {
            for (int onesUsed = 0; onesUsed <= one; onesUsed++) {

                if (zerosUsed == 0 && onesUsed == 0)
                    continue;

                long ways = 0;

                // CASE 1: Last block = 1 → place zeros
                for (int blockSize = 1; blockSize <= Math.min(zerosUsed, limit); blockSize++) {
                    ways = (ways + dp[zerosUsed - blockSize][onesUsed][0]) % MOD;
                }

                dp[zerosUsed][onesUsed][1] = (int) ways;

                ways = 0;

                // CASE 2: Last block = 0 → place ones
                for (int blockSize = 1; blockSize <= Math.min(onesUsed, limit); blockSize++) {
                    ways = (ways + dp[zerosUsed][onesUsed - blockSize][1]) % MOD;
                }

                dp[zerosUsed][onesUsed][0] = (int) ways;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
}
