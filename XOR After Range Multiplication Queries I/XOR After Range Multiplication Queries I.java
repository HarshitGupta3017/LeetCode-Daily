// Solution for XOR After Range Multiplication Queries I in JAVA

class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        final int MOD = 1000000007;

        // STEP 1: Process each query
        for (int[] query : queries) {
            int leftIndex = query[0];
            int rightIndex = query[1];
            int stepSize = query[2];
            int multiplier = query[3];

            int currentIndex = leftIndex;

            while (currentIndex <= rightIndex) {
                nums[currentIndex] = (int)((1L * nums[currentIndex] * multiplier) % MOD);
                currentIndex += stepSize;
            }
        }

        // STEP 2: Compute XOR
        int finalXOR = 0;
        for (int value : nums) {
            finalXOR ^= value;
        }

        return finalXOR;
    }
}
