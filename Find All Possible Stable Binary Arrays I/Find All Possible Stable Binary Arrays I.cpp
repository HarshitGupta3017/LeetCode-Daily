// Solution for Find All Possible Stable Binary Arrays I in CPP

class Solution {
public:

    const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        /*
        dp[z][o][last]

        z = number of zeros used
        o = number of ones used
        last =
            0 → last placed block was zeros
            1 → last placed block was ones
        */

        vector<vector<vector<int>>> dp(
            zero + 1,
            vector<vector<int>>(one + 1, vector<int>(2, 0))
        );

        /*
        Base case:
        With 0 zeros and 0 ones there is exactly 1 empty array.

        We allow both states so that the first block
        can be either zeros or ones.
        */
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for (int zerosUsed = 0; zerosUsed <= zero; zerosUsed++) {
            for (int onesUsed = 0; onesUsed <= one; onesUsed++) {

                if (zerosUsed == 0 && onesUsed == 0)
                    continue;

                /*
                CASE 1:
                Last block placed is 1
                → now we must place a block of 0s
                */

                long long ways = 0;

                for (int blockSize = 1; blockSize <= min(zerosUsed, limit); blockSize++) {
                    ways = (ways + dp[zerosUsed - blockSize][onesUsed][0]) % MOD;
                }

                dp[zerosUsed][onesUsed][1] = ways;


                /*
                CASE 2:
                Last block placed is 0
                → now we must place a block of 1s
                */

                ways = 0;

                for (int blockSize = 1; blockSize <= min(onesUsed, limit); blockSize++) {
                    ways = (ways + dp[zerosUsed][onesUsed - blockSize][1]) % MOD;
                }

                dp[zerosUsed][onesUsed][0] = ways;
            }
        }

        /*
        Final answer:
        array may end with either 0 block or 1 block
        */

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
