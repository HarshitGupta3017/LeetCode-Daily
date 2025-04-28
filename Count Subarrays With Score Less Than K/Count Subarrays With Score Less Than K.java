// Solution for Count Subarrays With Score Less Than K in JAVA

class Solution {
    public long countSubarrays(int[] nums, long k) {
        int n = nums.length;
        int i = 0, j = 0;
        long res = 0, sum = 0;
        while (j < n) {
            sum += nums[j];
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            res += (j - i + 1);
            j++;
        }
        return res;
    }
}
