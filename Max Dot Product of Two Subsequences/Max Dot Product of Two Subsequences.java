// Solution for Max Dot Product of Two Subsequences in JAVA

import java.util.Arrays;

class Solution {

    // Very small value to represent an invalid state
    private static final int NEG_INF = -1_000_000_000;

    private int dfs(
            int[] nums1,
            int[] nums2,
            int index1,
            int index2,
            int size1,
            int size2,
            int[][] dp
    ) {
        // If either array is exhausted, no valid non-empty subsequence possible
        if (index1 == size1 || index2 == size2) {
            return NEG_INF;
        }

        // Return memoized result
        if (dp[index1][index2] != Integer.MIN_VALUE) {
            return dp[index1][index2];
        }

        // Dot product of current pair
        int currentProduct = nums1[index1] * nums2[index2];

        // Option 1: Take both elements
        int takeBoth =
                currentProduct +
                dfs(nums1, nums2, index1 + 1, index2 + 1, size1, size2, dp);

        // Option 2: Skip element in nums1
        int skipFirst =
                dfs(nums1, nums2, index1 + 1, index2, size1, size2, dp);

        // Option 3: Skip element in nums2
        int skipSecond =
                dfs(nums1, nums2, index1, index2 + 1, size1, size2, dp);

        // Best possible choice
        dp[index1][index2] = Math.max(
                currentProduct,
                Math.max(takeBoth, Math.max(skipFirst, skipSecond))
        );

        return dp[index1][index2];
    }

    public int maxDotProduct(int[] nums1, int[] nums2) {

        int size1 = nums1.length;
        int size2 = nums2.length;

        // DP table initialized with Integer.MIN_VALUE
        int[][] dp = new int[size1][size2];
        for (int i = 0; i < size1; i++) {
            Arrays.fill(dp[i], Integer.MIN_VALUE);
        }

        return dfs(nums1, nums2, 0, 0, size1, size2, dp);
    }
}
