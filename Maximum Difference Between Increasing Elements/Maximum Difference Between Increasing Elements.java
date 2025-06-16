// Solution for Maximum Difference Between Increasing Elements in JAVA

class Solution {
    public int maximumDifference(int[] nums) {
        int n = nums.length;
        int minEle = nums[0];
        int maxDiff = -1;
        for (int j = 1; j < n; j++) {
            if (nums[j] > minEle) {
                maxDiff = Math.max(maxDiff, nums[j] - minEle);
            } else {
                minEle = nums[j];
            }
        }
        return maxDiff;
    }
}
