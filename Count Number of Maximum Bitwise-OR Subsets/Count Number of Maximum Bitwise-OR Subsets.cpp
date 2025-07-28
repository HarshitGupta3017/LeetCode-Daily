// Solution for Count Number of Maximum Bitwise-OR Subsets in CPP

class Solution {
public:
    // Recursive function to count subsets achieving max OR
    int solve(int idx, int currOr, int& maxOr, vector<int>& nums, vector<vector<int>>& memo) {
        // Base case: if we’ve considered all elements
        if (idx == nums.size()) {
            // If the OR of the current subset equals the max OR, count it
            return currOr == maxOr ? 1 : 0;
        }

        // If this state has already been computed, return the stored result
        if (memo[idx][currOr] != -1) return memo[idx][currOr];

        // ----------------------------
        // Choice 1: Include nums[idx] in the subset
        // Do bitwise OR with current value
        int take = solve(idx + 1, currOr | nums[idx], maxOr, nums, memo);

        // Choice 2: Exclude nums[idx] from the subset
        int notTake = solve(idx + 1, currOr, maxOr, nums, memo);

        // Store result in memoization table and return
        return memo[idx][currOr] = take + notTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;

        // Step 1: Find the maximum OR value possible across *any* subset
        for (const auto& num : nums) {
            maxOr |= num;  // Bitwise OR with all elements
        }

        // Step 2: Initialize memoization table with -1
        // memo[i][j] represents number of subsets from index i with OR value j
        vector<vector<int>> memo(n + 1, vector<int>(maxOr + 1, -1));

        // Step 3: Start recursion from index 0 and OR = 0
        return solve(0, 0, maxOr, nums, memo);
    }
};
