// Solution for Maximum Difference Between Adjacent Elements in a Circular Array in JAVA

class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            maxDiff = Math.max(maxDiff, Math.abs(nums[i] - nums[(i + 1) % n]));
        }
        return maxDiff;
    }
}
