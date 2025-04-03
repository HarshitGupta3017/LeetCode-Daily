// Solution for Maximum Value of an Ordered Triplet II in JAVA

class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long maxPrefix = nums[0];
        long[] maxSuffix = new long[n];
        maxSuffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxSuffix[i] = Math.max(maxSuffix[i + 1], (long)nums[i]);
        }
        long maxVal = 0;
        for (int j = 1; j < n - 1; j++) {
            maxVal = Math.max(maxVal, (maxPrefix - nums[j]) * maxSuffix[j + 1]);
            maxPrefix = Math.max(maxPrefix, (long)nums[j]);
        }
        return maxVal;
    }
}
