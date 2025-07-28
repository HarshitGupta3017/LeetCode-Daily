// Solution for Count Number of Maximum Bitwise-OR Subsets in JAVA

class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int n = nums.length;
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }

        Integer[][] memo = new Integer[n + 1][maxOr + 1];

        return solve(0, 0, maxOr, nums, memo);
    }

    private int solve(int idx, int currOr, int maxOr, int[] nums, Integer[][] memo) {
        if (idx == nums.length) {
            return currOr == maxOr ? 1 : 0;
        }
        if (memo[idx][currOr] != null) {
            return memo[idx][currOr];
        }

        int take = solve(idx + 1, currOr | nums[idx], maxOr, nums, memo);
        int notTake = solve(idx + 1, currOr, maxOr, nums, memo);

        memo[idx][currOr] = take + notTake;
        return memo[idx][currOr];
    }
}
