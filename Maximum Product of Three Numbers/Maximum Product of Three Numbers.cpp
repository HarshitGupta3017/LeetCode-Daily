// Solution for Maximum Product of Three Numbers in CPP

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // After sorting, the maximum product of three numbers comes from one of two cases:
        // Case 1: The three largest numbers (all positive, or mixed signs where positives dominate).
        int topThree = nums[n - 1] * nums[n - 2] * nums[n - 3];

        // Case 2: The two smallest numbers (most negative) multiplied by the largest.
        // Two negatives multiply to a large positive, which may outweigh taking three positives.
        int twoNegOnePos = nums[0] * nums[1] * nums[n - 1];

        return max(topThree, twoNegOnePos);
    }
};
