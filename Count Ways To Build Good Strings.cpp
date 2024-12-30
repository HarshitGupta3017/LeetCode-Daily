class Solution {
public:
    const int M = 1e9+7;
    int solve(int len, int low, int high, int zero, int one, vector<int>& dp) {
        if (len > high) return 0;
        if (dp[len] != -1) return dp[len];
        int count = (len >= low && len <= high) ? 1 : 0;
        int count_zero = solve(len + zero, low, high, zero, one, dp) % M;
        int count_one = solve(len + one, low, high, zero, one, dp) % M;
        return dp[len] = (count + count_zero + count_one) % M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return solve(0, low, high, zero, one, dp);
    }
};
