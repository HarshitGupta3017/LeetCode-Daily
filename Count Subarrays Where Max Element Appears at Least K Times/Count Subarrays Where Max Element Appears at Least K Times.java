// Solution for Count Subarrays Where Max Element Appears at Least K Times in JAVA

class Solution {
    public long countSubarrays(int[] nums, int k) {
        int i = 0, j = 0, n = nums.length;
        long res = 0;
        int mx = Arrays.stream(nums).max().getAsInt();
        int count = 0;
        while (j < n) {
            if (nums[j] == mx) count++;
            while (count >= k) {
                res += (n - j);
                if (nums[i] == mx) count--;
                i++;
            }
            j++;
        }
        return res;
    }
}
