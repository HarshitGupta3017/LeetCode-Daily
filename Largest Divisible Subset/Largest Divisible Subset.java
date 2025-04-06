// Solution for Largest Divisible Subset in JAVA

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int[] prev_idx = new int[n];
        Arrays.fill(prev_idx, -1);
        int last_idx = 0;
        int maxL = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j;
                    }
                    if (dp[i] > maxL) {
                        maxL = dp[i];
                        last_idx = i;
                    }
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        while (last_idx != -1) {
            res.add(nums[last_idx]);
            last_idx = prev_idx[last_idx];
        }
        return res;
    }
}
