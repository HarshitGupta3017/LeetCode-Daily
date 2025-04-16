// Solution for Count the Number of Good Subarrays in JAVA

class Solution {
    public long countGood(int[] nums, int k) {
        int n = nums.length, i = 0, j = 0;
        long res = 0, pairs = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        while (j < n) {
            pairs += mp.getOrDefault(nums[j], 0);
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            while (pairs >= k) {
                res += n - j;
                mp.put(nums[i], mp.get(nums[i]) - 1);
                pairs -= mp.get(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
}
