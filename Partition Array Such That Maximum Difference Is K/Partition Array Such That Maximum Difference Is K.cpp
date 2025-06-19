// Solution for Partition Array Such That Maximum Difference Is K in CPP

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // Sort the array to group close elements together
        sort(nums.begin(), nums.end());

        int minSubsequences = 1;           // At least one subsequence is needed
        int minInSubsequence = nums[0];    // Minimum element of the current subsequence

        for (const int& ele: nums) {
            // If the current number cannot fit in the current subsequence
            if (ele - minInSubsequence > k) {
                minSubsequences++;         // Start a new subsequence
                minInSubsequence = ele; // Update minimum of the new subsequence
            }
        }

        return minSubsequences;
    }
};
