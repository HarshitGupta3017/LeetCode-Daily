// Solution for Maximum Subarray Sum With Length Divisible by K in JAVA

class Solution {
    public long maxSubarraySum(int[] nums, int k) {

        int n = nums.length;

        // Prefix sum array
        long[] prefixSum = new long[n];
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        long bestResult = Long.MIN_VALUE;

        // Try every possible starting index modulo k
        for (int startIndex = 0; startIndex < k; startIndex++) {

            long bestEndingHere = 0;   // Kadane-style rolling sum
            int i = startIndex;

            while (i < n && (i + k - 1) < n) {

                int endIndex = i + k - 1;

                long blockSum = prefixSum[endIndex] -
                                (i > 0 ? prefixSum[i - 1] : 0);

                bestEndingHere = Math.max(blockSum, bestEndingHere + blockSum);
                bestResult = Math.max(bestResult, bestEndingHere);

                i += k; // jump to next block
            }
        }

        return bestResult;
    }
}
