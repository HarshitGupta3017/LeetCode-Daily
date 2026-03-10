// Solution for Find All Possible Stable Binary Arrays II in JAVA

class Solution {

    static final int MOD = 1000000007;

    public int numberOfStableArrays(int zero, int one, int limit) {

        int[][][] dp = new int[zero + 1][one + 1][2];

        // Arrays with only zeros
        for (int z = 0; z <= Math.min(zero, limit); z++) {
            dp[z][0][0] = 1;
        }

        // Arrays with only ones
        for (int o = 0; o <= Math.min(one, limit); o++) {
            dp[0][o][1] = 1;
        }

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {

                if (z == 0 || o == 0) continue;

                // End with 1
                dp[z][o][1] = (dp[z][o - 1][0] + dp[z][o - 1][1]) % MOD;

                if (o - 1 >= limit) {
                    dp[z][o][1] =
                        (dp[z][o][1] - dp[z][o - 1 - limit][0] + MOD) % MOD;
                }

                // End with 0
                dp[z][o][0] = (dp[z - 1][o][0] + dp[z - 1][o][1]) % MOD;

                if (z - 1 >= limit) {
                    dp[z][o][0] =
                        (dp[z][o][0] - dp[z - 1 - limit][o][1] + MOD) % MOD;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
}
