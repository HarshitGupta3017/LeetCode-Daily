// Solution for Maximum Number of Jumps to Reach the Last Index in JAVA

class Solution {
    public int maximumJumps(int[] nums, int target) {

        int totalElements = nums.length;

        // dp[i] = maximum jumps required to reach index i
        // Initialize with -1 (unreachable)
        int[] dp = new int[totalElements];

        Arrays.fill(dp, -1);

        // Starting index requires 0 jumps
        dp[0] = 0;

        // Try transitions from every reachable index
        for (int currentIndex = 0; currentIndex < totalElements; currentIndex++) {

            // Skip unreachable states
            if (dp[currentIndex] == -1)
                continue;

            // Try jumping to all forward indices
            for (int nextIndex = currentIndex + 1; nextIndex < totalElements; nextIndex++) {

                // Valid jump condition
                if (Math.abs(nums[nextIndex] - nums[currentIndex]) <= target) {
                    dp[nextIndex] = Math.max(dp[nextIndex], dp[currentIndex] + 1);
                }
            }
        }

        // Maximum jumps needed to reach last index
        return dp[totalElements - 1];
    }
}
