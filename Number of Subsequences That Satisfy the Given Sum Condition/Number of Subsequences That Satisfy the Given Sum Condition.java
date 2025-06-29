// Solution for Number of Subsequences That Satisfy the Given Sum Condition in JAVA

class Solution {
    final int MOD = 1_000_000_007;

    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;

        int[] powerOfTwo = new int[n];
        powerOfTwo[0] = 1;
        for (int i = 1; i < n; i++) {
            powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;
        }

        int left = 0, right = n - 1;
        int totalValid = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                totalValid = (totalValid + powerOfTwo[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return totalValid;
    }
}
