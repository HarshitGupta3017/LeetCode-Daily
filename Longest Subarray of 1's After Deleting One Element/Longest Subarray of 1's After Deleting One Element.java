// Solution for Longest Subarray of 1's After Deleting One Element in JAVA

class Solution {
    public int longestSubarray(int[] nums) {
        int left = 0;          // Left pointer for the sliding window
        int maxLen = 0;        // Stores the maximum window length found
        int zeroCount = 0;     // Tracks the number of zeros in the current window

        // Traverse the array using 'right' as the right pointer
        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == 0) {
                zeroCount++;   // Count the zeros in the current window
            }

            // If more than one zero, shrink the window from the left
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--; // Reduce zero count when moving past a zero
                }
                left++; // Move left pointer forward
            }

            // Update maximum window size (this window has at most one zero)
            maxLen = Math.max(maxLen, right - left + 1);
        }

        // Subtract 1 because we must delete one element (the one zero or a one if no zeros)
        return maxLen - 1;
    }
}
