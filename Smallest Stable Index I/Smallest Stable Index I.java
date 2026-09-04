// Solution for Smallest Stable Index I in JAVA

class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;

        // suffixMinimum[i] = minimum value in nums[i..n-1]
        int[] suffixMinimum = new int[n];

        int currentMinimum = Integer.MAX_VALUE;

        // Build suffix minimum from right to left.
        for (int index = n - 1; index >= 0; --index) {
            currentMinimum = Math.min(currentMinimum, nums[index]);
            suffixMinimum[index] = currentMinimum;
        }

        // Maximum value in nums[0..index]
        int currentMaximum = Integer.MIN_VALUE;

        // Scan from left to right to find the first stable index.
        for (int index = 0; index < n; index++) {
            currentMaximum = Math.max(currentMaximum, nums[index]);

            int suffixMinValue = suffixMinimum[index];

            // Instability score:
            // max(nums[0..index]) - min(nums[index..n-1])
            if (currentMaximum - suffixMinValue <= k) {
                return index;
            }
        }

        return -1;
    }
}
