// Solution for Find the Maximum Length of Valid Subsequence II in JAVA

class Solution {
    public int maximumLength(int[] nums, int k) {
        int n = nums.length;
        int[][] dp = new int[k][n];

        for (int i = 0; i < k; i++)
            Arrays.fill(dp[i], 1);

        int maxLength = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int mod = (nums[i] + nums[j]) % k;
                dp[mod][i] = Math.max(dp[mod][i], 1 + dp[mod][j]);
                maxLength = Math.max(maxLength, dp[mod][i]);
            }
        }

        return maxLength;
    }
}
