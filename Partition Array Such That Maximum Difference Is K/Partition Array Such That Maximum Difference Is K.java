// Solution for Partition Array Such That Maximum Difference Is K in JAVA

class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);

        int n = nums.length;
        int minSubsequences = 1;           // At least one subsequence is needed
        int minInSubsequence = nums[0];    // Minimum element of the current subsequence

        for (int i = 0; i < n; i++) {
            // If the current number cannot fit in the current subsequence
            if (nums[i] - minInSubsequence > k) {
                minSubsequences++;         // Start a new subsequence
                minInSubsequence = nums[i]; // Update minimum of the new subsequence
            }
        }

        return minSubsequences;
    }
}
