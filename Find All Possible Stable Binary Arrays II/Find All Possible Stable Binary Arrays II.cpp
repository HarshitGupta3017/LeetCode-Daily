// Solution for Find All Possible Stable Binary Arrays II in CPP

class Solution {
public:

    const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        /*
        DP table:
        dp[z][o][last]

        z = number of zeros used
        o = number of ones used

        last = 0 → array ends with 0
        last = 1 → array ends with 1
        */

        vector<vector<vector<int>>> dp(
            zero + 1,
            vector<vector<int>>(one + 1, vector<int>(2, 0))
        );

        /*
        Base case:
        If we only use zeros (no ones),
        the array is valid only if length ≤ limit.
        */

        for (int z = 0; z <= min(zero, limit); z++) {
            dp[z][0][0] = 1;
        }

        /*
        Similarly for arrays containing only ones.
        */

        for (int o = 0; o <= min(one, limit); o++) {
            dp[0][o][1] = 1;
        }

        /*
        Fill the DP table
        */

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {

                /*
                Skip base rows because they were already initialized
                */
                if (z == 0 || o == 0)
                    continue;

                /*
                -------------------------------
                CASE 1: Array ends with 1
                -------------------------------

                We append a '1' to a smaller array.
                */

                dp[z][o][1] = (dp[z][o-1][0] + dp[z][o-1][1]) % MOD;

                /*
                If we already had 'limit' ones before,
                adding another would violate the rule.

                Remove those invalid sequences.
                */

                if (o - 1 >= limit) {
                    dp[z][o][1] = (dp[z][o][1] - dp[z][o-1-limit][0] + MOD) % MOD;
                }

                /*
                -------------------------------
                CASE 2: Array ends with 0
                -------------------------------

                Append '0' to previous arrays
                */

                dp[z][o][0] = (dp[z-1][o][0] + dp[z-1][o][1]) % MOD;

                /*
                Remove sequences that would create
                more than 'limit' consecutive zeros
                */

                if (z - 1 >= limit) {
                    dp[z][o][0] = (dp[z][o][0] - dp[z-1-limit][o][1] + MOD) % MOD;
                }
            }
        }

        /*
        Final array may end with either 0 or 1
        */

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
