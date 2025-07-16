// Solution for Find the Maximum Length of Valid Subsequence I in CPP

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // Counters for number of even and odd elements in the array
        int evenCount = 0;
        int oddCount = 0;

        // Tracks the maximum length of an alternating parity subsequence
        int maxAlternatingLength = 1;

        // First element's parity: 0 for even, 1 for odd
        int previousParity = nums[0] % 2;

        // Count the first element
        (previousParity == 0) ? evenCount++ : oddCount++;

        for (int i = 1; i < nums.size(); i++) {
            int currentParity = nums[i] % 2;

            // Update alternating subsequence length only when parity changes
            if (currentParity != previousParity) {
                maxAlternatingLength++;
                previousParity = currentParity;
            }

            // Count even and odd numbers
            (currentParity == 0) ? evenCount++ : oddCount++;
        }

        // Return the longest valid subsequence length
        return max({evenCount, oddCount, maxAlternatingLength});
    }
};
