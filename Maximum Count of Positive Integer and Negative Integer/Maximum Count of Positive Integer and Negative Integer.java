// Solution for Maximum Count of Positive Integer and Negative Integer in JAVA

class Solution {
    public int maximumCount(int[] nums) {
        int pos = nums.length - lowerBound(nums, 1);
        int neg = upperBound(nums, -1);
        return Math.max(pos, neg);
    }
    
    private int lowerBound(int[] nums, int target) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private int upperBound(int[] nums, int target) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
