// Solution for Maximum Number of Jumps to Reach the Last Index in CPP

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {

        int totalElements = nums.size();

        // dp[i] = maximum jumps required to reach index i
        // Initialize with -1 (unreachable)
        vector<int> dp(totalElements, -1);

        // Starting index requires 0 jumps
        dp[0] = 0;

        // Try transitions from every reachable index
        for (int currentIndex = 0; currentIndex < totalElements; currentIndex++) {

            // Skip unreachable states
            if (dp[currentIndex] == -1)
                continue;

            // Try jumping to all forward indices
            for (int nextIndex = currentIndex + 1; nextIndex < totalElements; nextIndex++) {

                // Valid jump condition
                if (abs(nums[nextIndex] - nums[currentIndex]) <= target) {
                    dp[nextIndex] = max(dp[nextIndex], dp[currentIndex] + 1);
                }
            }
        }

        // Maximum jumps needed to reach last index
        return dp[totalElements - 1];
    }
};
