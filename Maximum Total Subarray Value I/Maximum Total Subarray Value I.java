// Solution for Maximum Total Subarray Value I in JAVA

class Solution {
    public long maxTotalValue(int[] nums, int k) {

        int globalMax = Integer.MIN_VALUE;
        int globalMin = Integer.MAX_VALUE;

        for (int num : nums) {
            globalMax = Math.max(globalMax, num);
            globalMin = Math.min(globalMin, num);
        }

        return (long) (globalMax - globalMin) * k;
    }
}
