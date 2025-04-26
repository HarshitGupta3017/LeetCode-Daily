// Solution for Count Subarrays With Fixed Bounds in JAVA

class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int minKidx = -1, maxKidx = -1, culpritIdx = -1;
        int n = nums.length;
        long res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) 
                culpritIdx = i;
            if (nums[i] == minK)
                minKidx = i;
            if (nums[i] == maxK)
                maxKidx = i;
            long smaller = Math.min(maxKidx, minKidx);
            long temp = smaller - culpritIdx;
            res += (temp <= 0) ? 0 : temp;
        }
        return res;
    }
}
