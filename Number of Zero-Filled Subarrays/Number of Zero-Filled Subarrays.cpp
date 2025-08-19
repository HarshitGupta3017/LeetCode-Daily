// Solution for Number of Zero-Filled Subarrays in CPP

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0; // Final answer: total subarrays filled with 0
        int count = 0;        // Tracks continuous zeros count

        for (int i = 0; i < nums.size(); i++) {
            // If nums[i] == 0, increase count, otherwise reset to 0
            count = (nums[i] == 0) ? count + 1 : 0;

            // Add current count to result (each new zero forms new subarrays)
            result += count;
        }   
        return result;
    }
};
