// Solution for Trionic Array I in JAVA

class Solution {
    public boolean isTrionic(int[] nums) {

        int n = nums.length;
        int index = 0;

        // Phase 1: Strictly Increasing
        while (index + 1 < n && nums[index] < nums[index + 1]) {
            index++;
        }

        // No increasing part OR increasing reaches the end
        if (index == 0 || index == n - 1) {
            return false;
        }

        // Phase 2: Strictly Decreasing
        while (index + 1 < n && nums[index] > nums[index + 1]) {
            index++;
        }

        // No final increasing part
        if (index == n - 1) {
            return false;
        }

        // Phase 3: Strictly Increasing again
        while (index + 1 < n && nums[index] < nums[index + 1]) {
            index++;
        }

        // Must consume the entire array
        return index == n - 1;
    }
}
