// Solution for Find the Number of Subsequences With Equal GCD in CPP

class Solution {
public:
    int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        // dp[g1][g2] = number of ways to assign elements from index i..n-1
        // such that seq1 has running gcd g1 and seq2 has running gcd g2.
        // We use 0 as a sentinel meaning "this subsequence is still empty".
        // gcd(0, x) = x, so the sentinel correctly initialises to the first element added.
        vector<vector<int>> dp(maxVal + 1, vector<int>(maxVal + 1, 0));

        // Base case (i == n): a valid pair exists only when both subsequences
        // are non-empty and have equal gcds.
        for (int g = 1; g <= maxVal; g++)
            dp[g][g] = 1;

        // Process elements right to left, filling in the dp table for each prefix i..n-1.
        // We roll the table forward using only two layers (curr and prev) to stay O(maxVal²) space.
        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> next(maxVal + 1, vector<int>(maxVal + 1, 0));

            for (int g1 = 0; g1 <= maxVal; g1++) {
                for (int g2 = 0; g2 <= maxVal; g2++) {
                    // Option 1: skip nums[i] — neither subsequence claims this index.
                    int skip = dp[g1][g2];

                    // Option 2: add nums[i] to seq1, updating its running gcd.
                    int assignToSeq1 = dp[__gcd(g1, nums[i])][g2];

                    // Option 3: add nums[i] to seq2, updating its running gcd.
                    // Disjointness is guaranteed: each index feeds into at most one branch.
                    int assignToSeq2 = dp[g1][__gcd(g2, nums[i])];

                    // Sum all three choices, guarding against int overflow before the modulo.
                    next[g1][g2] = (0LL + skip + assignToSeq1 + assignToSeq2) % MOD;
                }
            }

            dp = move(next);
        }

        // dp[0][0] is the answer for the full array with both subsequences starting empty.
        return dp[0][0];
    }
};
