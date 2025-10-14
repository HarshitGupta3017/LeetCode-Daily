// Solution for Adjacent Increasing Subarrays Detection I in JAVA

class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();

        // freq[i] represents the length of the longest strictly increasing
        // subarray starting at index i.
        int[] increasingLength = new int[n];
        Arrays.fill(increasingLength, 1);

        // Traverse backward to fill increasingLength[]
        // If nums[i+1] > nums[i], it means we can extend the increasing sequence.
        for (int i = n - 2; i >= 0; i--) {
            if (nums.get(i + 1) > nums.get(i)) 
                increasingLength[i] = increasingLength[i + 1] + 1;
        }

        // Now, check for two *adjacent* subarrays of length k each
        // Subarray 1: starts at index a → nums[a ... a + k - 1]
        // Subarray 2: starts right after it → nums[a + k ... a + 2k - 1]
        for (int a = 0; a <= n - 2 * k; a++) {
            // If both subarrays starting at a and a + k are strictly increasing
            if (increasingLength[a] >= k && increasingLength[a + k] >= k)
                return true;
        }

        // If no such pair of adjacent increasing subarrays found
        return false;
    }
}
