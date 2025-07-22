// Solution for Maximum Erasure Value in CPP

class Solution {
public:
    // Function to find the maximum score by erasing a subarray with all unique elements
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build a cumulative sum array where cumSum[i] = sum of nums[0..i]
        vector<int> cumSum(n, 0);       // Stores prefix sums to quickly calculate subarray sums
        cumSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            cumSum[i] = cumSum[i - 1] + nums[i];
        }

        // Step 2: Use two pointers (sliding window) to track the subarray
        int left = 0;                   // Left pointer of the current window
        int right = 0;                  // Right pointer of the current window
        int maxScore = 0;              // Stores the maximum score (max sum of unique subarray)

        // mp[num] stores the last index at which 'num' appeared in the array
        vector<int> lastSeen(10001, -1); // Initialize with -1 meaning not seen yet

        // Step 3: Traverse the array using right pointer
        while (right < n) {
            /*
             * If nums[right] was seen before, move the left pointer to the right of its last occurrence.
             * This ensures all elements in the current window [left, right] are unique.
             */
            left = max(left, lastSeen[nums[right]] + 1);

            // Calculate the sum of the current subarray [left, right] using prefix sums
            int currentSum = cumSum[right] - (left > 0 ? cumSum[left - 1] : 0);

            // Update the maximum score if needed
            maxScore = max(maxScore, currentSum);

            // Record the current index of nums[right] for future reference
            lastSeen[nums[right]] = right;

            // Move the right pointer to expand the window
            right++;
        }

        // Return the best score (max sum of a subarray with all unique elements)
        return maxScore;
    }
};
