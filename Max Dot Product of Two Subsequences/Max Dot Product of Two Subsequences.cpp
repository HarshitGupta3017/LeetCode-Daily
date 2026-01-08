// Solution for Max Dot Product of Two Subsequences in CPP

class Solution {
public:
    // A very small value to represent an invalid state
    static constexpr int NEG_INF = -1e9;

    int dfs(
        vector<int>& nums1,
        vector<int>& nums2,
        int index1,
        int index2,
        int size1,
        int size2,
        vector<vector<int>>& dp
    ) {
        // If either array is exhausted, no valid non-empty subsequence possible
        if (index1 == size1 || index2 == size2) {
            return NEG_INF;
        }

        // Return memoized result if already computed
        if (dp[index1][index2] != INT_MIN) {
            return dp[index1][index2];
        }

        // Dot product of current pair
        int currentProduct = nums1[index1] * nums2[index2];

        // Option 1: Take both elements and move diagonally
        int takeBoth =
            currentProduct +
            dfs(nums1, nums2, index1 + 1, index2 + 1, size1, size2, dp);

        // Option 2: Skip current element of nums1
        int skipFirst =
            dfs(nums1, nums2, index1 + 1, index2, size1, size2, dp);

        // Option 3: Skip current element of nums2
        int skipSecond =
            dfs(nums1, nums2, index1, index2 + 1, size1, size2, dp);

        // Best among:
        // - starting a new subsequence with current pair
        // - extending a subsequence
        // - skipping elements
        return dp[index1][index2] =
            max({currentProduct, takeBoth, skipFirst, skipSecond});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        // DP table initialized with INT_MIN to denote uncomputed states
        vector<vector<int>> dp(size1, vector<int>(size2, INT_MIN));

        return dfs(nums1, nums2, 0, 0, size1, size2, dp);
    }
};
