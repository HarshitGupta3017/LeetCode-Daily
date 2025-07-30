// Solution for Longest Subarray With Maximum Bitwise AND in CPP

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLength = 0;          // Stores the result: max length of subarray with max AND value
        int currentLength = 0;      // Tracks current streak of numbers equal to maxVal
        int maxVal = 0;             // The maximum value found in the array so far

        // Traverse the array to find maxVal and track longest streaks of it
        for (const auto& num : nums) {
            // If we find a number greater than current maxVal, update it
            if (num > maxVal) {
                maxVal = num;       // New maximum value
                currentLength = 1;  // Start counting new streak
                maxLength = 1;      // Reset result
            } 
            // If current number equals maxVal, increase the current streak
            else if (num == maxVal) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } 
            // If number is less than maxVal, reset current streak
            else {
                currentLength = 0;
            }
        }

        return maxLength;
    }
};
