// Solution for Count the Number of Fair Pairs in JAVA

class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long res = 0;
        for (int i = 0; i < nums.length; i++) {
            int x = lowerBound(nums, i + 1, nums.length, lower - nums[i]);
            int y = upperBound(nums, i + 1, nums.length, upper - nums[i]);
            res += (y - x);
        }
        return res;
    }

    private int lowerBound(int[] arr, int start, int end, int target) {
        int low = start, high = end;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    
    private int upperBound(int[] arr, int start, int end, int target) {
        int low = start, high = end;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
