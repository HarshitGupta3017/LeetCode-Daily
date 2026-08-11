// Solution for Smallest Missing Integer Greater Than Sequential Prefix Sum in CPP

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Compute the sum of the longest sequential prefix.
        // We stop extending as soon as the consecutive-increment property breaks.
        int prefixSum = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) break;
            prefixSum += nums[i];
        }

        // Load all values into a set for O(1) membership checks.
        // Then scan upward from prefixSum until we find a value not in nums.
        unordered_set<int> present(nums.begin(), nums.end());
        while (present.count(prefixSum))
            prefixSum++;

        return prefixSum;
    }
};
