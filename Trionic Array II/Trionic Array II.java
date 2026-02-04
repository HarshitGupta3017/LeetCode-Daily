// Solution for Trionic Array II in JAVA

class Solution {

    // We use a very small negative value instead of Long.MIN_VALUE
    // to avoid overflow when adding numbers.
    private static final long NEG_INF = Long.MIN_VALUE / 2;

    // Recursive DP function
    // index -> current position in nums
    // trend -> current phase of the trionic sequence
    // nums  -> input array
    // memo  -> memoization table
    private long dfsMaxSum(
        int index,
        int trend,
        int[] nums,
        long[][] memo
    ) {
        int n = nums.length;

        // Base case: reached the end of the array
        // Valid only if all 3 phases are completed (trend == 3)
        if (index == n) {
            return (trend == 3) ? 0 : NEG_INF;
        }

        // Return cached result if already computed
        if (memo[index][trend] != Long.MIN_VALUE) {
            return memo[index][trend];
        }

        // Option 1: take the current element
        long takeCurrent = NEG_INF;

        // Option 2: skip the current element
        long skipCurrent = NEG_INF;

        // Skipping is allowed only before starting the sequence
        if (trend == 0) {
            skipCurrent = dfsMaxSum(index + 1, 0, nums, memo);
        }

        // If already in the final increasing phase,
        // we can always take the current element
        if (trend == 3) {
            takeCurrent = nums[index];
        }

        // Try transitions using the next element
        if (index + 1 < n) {
            int currentValue = nums[index];
            int nextValue = nums[index + 1];

            // Phase 0 -> Phase 1 (start first increasing phase)
            if (trend == 0 && nextValue > currentValue) {
                takeCurrent = Math.max(
                    takeCurrent,
                    currentValue + dfsMaxSum(index + 1, 1, nums, memo)
                );
            }

            // Phase 1: strictly increasing
            else if (trend == 1) {
                // Continue increasing
                if (nextValue > currentValue) {
                    takeCurrent = Math.max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 1, nums, memo)
                    );
                }
                // Switch to decreasing phase
                else if (nextValue < currentValue) {
                    takeCurrent = Math.max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 2, nums, memo)
                    );
                }
            }

            // Phase 2: strictly decreasing
            else if (trend == 2) {
                // Continue decreasing
                if (nextValue < currentValue) {
                    takeCurrent = Math.max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 2, nums, memo)
                    );
                }
                // Switch to final increasing phase
                else if (nextValue > currentValue) {
                    takeCurrent = Math.max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 3, nums, memo)
                    );
                }
            }

            // Phase 3: final increasing phase
            else if (trend == 3 && nextValue > currentValue) {
                takeCurrent = Math.max(
                    takeCurrent,
                    currentValue + dfsMaxSum(index + 1, 3, nums, memo)
                );
            }
        }

        // Store and return the best result
        memo[index][trend] = Math.max(takeCurrent, skipCurrent);
        return memo[index][trend];
    }

    public long maxSumTrionic(int[] nums) {
        int n = nums.length;

        // memo[index][trend] = maximum sum starting from index with given trend
        long[][] memo = new long[n + 1][4];

        // Initialize memo table with Long.MIN_VALUE
        for (int i = 0; i <= n; i++) {
            for (int t = 0; t < 4; t++) {
                memo[i][t] = Long.MIN_VALUE;
            }
        }

        // Start from index 0 with trend 0 (not started yet)
        return dfsMaxSum(0, 0, nums, memo);
    }
}
