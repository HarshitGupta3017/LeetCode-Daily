// Solution for Longest Nice Subarray in JAVA

class Solution {
    public int longestNiceSubarray(int[] nums) {
        int n = nums.length;
        int i = 0, j = 0, mask = 0, res = 1;
        while (j < n) {
            while ((mask & nums[j]) != 0){
                mask ^= nums[i++];
            }
            res = Math.max(res, j - i + 1);
            mask |= nums[j++];
        }
        return res;
    }
}
