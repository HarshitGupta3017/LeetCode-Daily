// Solution for Find the Maximum Length of Valid Subsequence II in CPP

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        // Create a 2D dp table with k rows (for each possible modulo from 0 to k-1)
        // and n columns (for each element in the array).
        // dp[mod][i] stores the length of the longest valid subsequence ending at index i
        // where the sum of any two consecutive elements in the subsequence gives remainder = mod when divided by k.
        vector<vector<int>> dp(k, vector<int>(n, 1));

        int maxLength = 1;  // Result stores the maximum length found

        // Loop through all elements from second to last
        for (int i = 1; i < n; i++) {

            // For every i, check all previous elements j < i
            for (int j = 0; j < i; j++) {

                // Calculate the modulo of the sum of nums[i] and nums[j]
                int mod = (nums[i] + nums[j]) % k;

                // If we choose to continue the subsequence from index j to i,
                // then we can try extending dp[mod][j] to dp[mod][i]
                // But only if the modulo matches!
                // Try extending the subsequence ending at j with nums[i] only if the modulo remains same
                // dp[mod][j] means we had a valid subsequence ending at j with that modulo
                // If we append nums[i], the subsequence length becomes dp[mod][j] + 1
                // Update the best possible length ending at i for that mod
                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);

                // Update the maximum length seen so far
                maxLength = max(maxLength, dp[mod][i]);
            }
        }

        return maxLength;
    }
};
