// Solution for Smallest Stable Index I in CPP

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // suffixMinimum[i] stores the minimum value in the range [i, n - 1].
        // In other words:
        // suffixMinimum[i] = min(nums[i], nums[i + 1], ..., nums[n - 1])
        vector<int> suffixMinimum(n);

        // Initialize with the largest possible integer so that the first
        // element we process always becomes the initial minimum.
        int currentMinimum = INT_MAX;

        // Build the suffix minimum array from right to left.
        // We move backwards because suffixMinimum[i] depends on
        // suffixMinimum[i + 1].
        for (int index = n - 1; index >= 0; --index) {

            // Keep track of the smallest value seen from the right so far.
            currentMinimum = min(currentMinimum, nums[index]);

            // Store the minimum value of the entire suffix starting at 'index'.
            suffixMinimum[index] = currentMinimum;
        }

        // Stores the maximum value in the prefix [0, index].
        int currentMaximum = INT_MIN;

        // Scan from left to right because we need to return the
        // SMALLEST index that satisfies the stability condition.
        for (int index = 0; index < n; index++) {

            // Update the maximum value seen in nums[0..index].
            currentMaximum = max(currentMaximum, nums[index]);

            // The minimum value in nums[index..n-1] is already precomputed.
            int suffixMinValue = suffixMinimum[index];

            // Instability score =
            //     max(nums[0..index]) - min(nums[index..n-1])
            //
            // If this score is <= k, then the current index is stable.
            // Since we are scanning from left to right, this is
            // automatically the first stable index.
            if (currentMaximum - suffixMinValue <= k) {
                return index;
            }
        }

        // No index satisfied the stability condition.
        return -1;
    }
};
