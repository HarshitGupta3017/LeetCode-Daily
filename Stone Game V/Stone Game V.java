// Solution for Stone Game V in JAVA

class Solution {
    // Returns the maximum score Alice can achieve from stoneValue[left..right].
    public int solve(int left, int right, int[] prefix, int[][] memo) {
        if (left >= right) {
            return 0;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        int bestScore = 0;

        for (int mid = left; mid < right; mid++) {
            int leftSum = prefix[mid] - (left > 0 ? prefix[left - 1] : 0);
            int rightSum = prefix[right] - prefix[mid];

            if (leftSum < rightSum) {
                // Keep left half.
                bestScore = Math.max(
                    bestScore,
                    leftSum + solve(left, mid, prefix, memo)
                );
            } else if (rightSum < leftSum) {
                // Keep right half.
                bestScore = Math.max(
                    bestScore,
                    rightSum + solve(mid + 1, right, prefix, memo)
                );
            } else {
                // Equal sums: choose the better continuation.
                int keepLeft =
                    leftSum + solve(left, mid, prefix, memo);

                int keepRight =
                    rightSum + solve(mid + 1, right, prefix, memo);

                bestScore = Math.max(
                    bestScore,
                    Math.max(keepLeft, keepRight)
                );
            }
        }

        return memo[left][right] = bestScore;
    }

    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;

        int[] prefix = new int[n];
        prefix[0] = stoneValue[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i];
        }

        int[][] memo = new int[n][n];

        // Java initializes int arrays to 0, so use -1 explicitly.
        for (int i = 0; i < n; i++) {
            java.util.Arrays.fill(memo[i], -1);
        }

        return solve(0, n - 1, prefix, memo);
    }
}
