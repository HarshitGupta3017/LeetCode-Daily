// Solution for Minimum Equal Sum of Two Arrays After Replacing Zeros in JAVA

class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
        for (int num: nums1) {
            sum1 += num == 0 ? 1 : num;
            zero1 += num == 0 ? 1 : 0;
        }
        for (int num: nums2) {
            sum2 += num == 0 ? 1 : num;
            zero2 += num == 0 ? 1 : 0;
        }
        return ((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0)) ? -1 : Math.max(sum1, sum2);
    }
}
