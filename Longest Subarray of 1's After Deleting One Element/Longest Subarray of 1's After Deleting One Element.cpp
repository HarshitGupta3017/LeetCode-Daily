// Solution for Longest Subarray of 1's After Deleting One Element in CPP

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;                  // Left pointer for the sliding window
        int maxlen = 0;             // Stores the maximum window length found
        int zerocount = 0;          // Tracks the number of zeros in the current window

        // Traverse the array using 'j' as the right pointer
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) 
                zerocount++;        // Count the zeros in the current window

            // If more than one zero, shrink the window from the left
            while (zerocount > 1) {
                if (nums[i] == 0) 
                    zerocount--;    // Reduce zero count when moving past a zero
                i++;                // Move left pointer forward
            }

            // Update maximum window size (this window has at most one zero)
            maxlen = max(maxlen, j - i + 1);
        }

        // Subtract 1 because we must delete one element (the one zero or a one if no zeros)
        return maxlen - 1;
    }
};
