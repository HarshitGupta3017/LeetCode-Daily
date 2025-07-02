// Solution for Find the Original Typed String II in CPP

class Solution {
public:
    const int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        int n = word.length();
        if (k > n) return 0;

        // Step 1: Count consecutive character groups (repeats)
        vector<int> groupFreq;
        int freq = 1;

        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                freq++;
            } else {
                groupFreq.push_back(freq);
                freq = 1;
            }
        }
        groupFreq.push_back(freq); // Add the last group

        int groupCount = groupFreq.size();

        // Step 2: Calculate total valid possibilities (product of each group freq)
        long long totalWays = 1;
        for (int f : groupFreq) {
            totalWays = (totalWays * f) % MOD;
        }

        // If the number of groups is already >= k, all ways are valid
        if (groupCount >= k) return totalWays;

        // Step 3: Use DP to subtract invalid combinations where length < k
        vector<vector<int>> dp(groupCount + 1, vector<int>(k + 1, 0));

        // Base case: Any count < k from the last group is valid to subtract
        for (int len = k - 1; len >= 0; len--) {
            dp[groupCount][len] = 1;
        }

        // Bottom-up DP from groupCount - 1 to 0
        for (int i = groupCount - 1; i >= 0; i--) {
            // Compute prefix sum for optimized range query
            vector<int> prefix(k + 2, 0);
            for (int j = 1; j <= k; j++) {
                prefix[j] = (prefix[j - 1] + dp[i + 1][j - 1]) % MOD;
            }

            // Try all valid lengths using groupFreq[i]
            for (int len = k - 1; len >= 0; len--) {
                int minLen = len + 1;
                int maxLen = len + groupFreq[i];
                if (maxLen >= k) maxLen = k - 1;

                if (minLen <= maxLen) {
                    dp[i][len] = (prefix[maxLen + 1] - prefix[minLen] + MOD) % MOD;
                }
            }
        }

        long long invalidWays = dp[0][0];

        // Step 4: Valid = total - invalid (with modulo adjustment)
        return (totalWays - invalidWays + MOD) % MOD;
    }
};
