// Solution for Smallest Subarrays With Maximum Bitwise OR in CPP

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        // Result array to store length of minimum subarray for each index
        vector<int> minSubarrayLength(n);

        // Stores the latest index where each bit (0-31) was set
        vector<int> latestBitPosition(32, -1);

        // Iterate from the end of the array towards the beginning
        for (int i = n - 1; i >= 0; i--) {
            int farthestReach = i; // need to go till this idx to set all bits of nums[i]

            // Check all 32 bits for the current number
            for (int bit = 0; bit < 32; bit++) {
                // If this bit is not set in nums[i]
                if (!(nums[i] & (1 << bit))) {
                    // If any future element has this bit set, we need to include it
                    if (latestBitPosition[bit] != -1) {
                        farthestReach = max(farthestReach, latestBitPosition[bit]);
                    }
                } else {
                    // Update the latest position where this bit was seen
                    latestBitPosition[bit] = i;
                }
            }

            // Length of subarray = farthest reach - current index + 1
            minSubarrayLength[i] = farthestReach - i + 1;
        }

        return minSubarrayLength;
    }
};
