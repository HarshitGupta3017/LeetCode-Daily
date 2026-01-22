// Solution for Minimum Pair Removal to Sort Array I in CPP

class Solution {
public:

    // This function finds the index of the adjacent pair
    // with the minimum sum.
    // If multiple pairs have the same minimum sum,
    // the leftmost one is chosen.
    int minIdx(vector<int> nums) {
        int minIndex = -1;          // stores index of pair with minimum sum
        int minimumSum = INT_MAX;   // stores the minimum adjacent pair sum

        // iterate over adjacent pairs
        for (int i = 0; i < nums.size() - 1; i++) {
            int currentPairSum = nums[i] + nums[i + 1];

            // update if a smaller sum is found
            if (currentPairSum < minimumSum) {
                minimumSum = currentPairSum;
                minIndex = i;
            }
        }

        return minIndex;
    }

    // This function performs the minimum number of operations
    // to make the array non-decreasing.
    // In each operation:
    // 1. Find the adjacent pair with minimum sum
    // 2. Replace the pair with their sum
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;  // count of operations performed

        // Continue until the array becomes non-decreasing
        while (!is_sorted(nums.begin(), nums.end())) {

            // Find index of the adjacent pair with minimum sum
            int pairIndex = minIdx(nums);

            // Merge the pair by replacing nums[pairIndex]
            // with the sum of nums[pairIndex] and nums[pairIndex + 1]
            nums[pairIndex] = nums[pairIndex] + nums[pairIndex + 1];

            // Remove the second element of the merged pair
            nums.erase(nums.begin() + pairIndex + 1);

            // Increment operation count
            operations++;
        }

        return operations;
    }
};
