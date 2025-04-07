// Solution for Partition Equal Subset Sum in JAVA

class Solution {
    
    int[][] t = new int[202][20002];

    private boolean solve(int[] arr, int sum, int n) {
        if (sum == 0) return true;
        if (n == 0) return false;
        if (t[n][sum] != -1) return t[n][sum] == 1;
        boolean take = false;
        if (arr[n - 1] <= sum) {
            take = solve(arr, sum - arr[n - 1], n - 1);
        }
        boolean notTake = solve(arr, sum, n - 1);
        t[n][sum] = (take || notTake) ? 1 : 0;
        return take || notTake;
    }

    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = Arrays.stream(nums).sum();
        if (sum % 2 != 0) return false;
        for (int[] row: t) {
            Arrays.fill(row, -1);
        }
        return solve(nums, sum / 2, n);
    }
}
