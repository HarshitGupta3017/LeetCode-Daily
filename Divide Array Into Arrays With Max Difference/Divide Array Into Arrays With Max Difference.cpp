// Solution for Divide Array Into Arrays With Max Difference in CPP

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;

        // Sort the array to group closer numbers together
        sort(nums.begin(), nums.end());

        // Process the array in chunks of 3 elements
        for (int i = 0; i < nums.size(); i += 3) {
            // Ensure current chunk of 3 elements has max diff <= k
            if (nums[i + 2] - nums[i] > k) {
                return {}; // Not possible to group this triplet
            }

            // Valid triplet, add to result
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return result;
    }
};
