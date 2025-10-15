// Solution for Adjacent Increasing Subarrays Detection II in CPP

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        // prevLen → length of previous strictly increasing sequence
        // currLen → length of current strictly increasing sequence
        // maxK → maximum k found so far
        int prevLen = 0;
        int currLen = 1;
        int maxK = 0;

        // Traverse the array to identify increasing sequences
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                // Continue the current increasing sequence
                currLen++;
            } else {
                // Sequence breaks here — store current as previous
                prevLen = currLen;
                currLen = 1; // Reset for the next increasing sequence
            }

            // There are two possible ways to form two adjacent increasing subarrays:

            // 1️⃣ Split a single long increasing sequence into two halves
            // Example: [1,2,3,4] → two adjacent subarrays of k=2 each
            // => candidate = currLen / 2
            // 
            // 2️⃣ Combine consecutive increasing sequences
            // Example: [1,2,3 | 4,5,6] → previous = 3, current = 3 → k = min(3,3)
            // => candidate = min(prevLen, currLen)

            maxK = max({maxK, currLen / 2, min(prevLen, currLen)});
        }

        // Return the maximum possible length k
        return maxK;
    }
};
