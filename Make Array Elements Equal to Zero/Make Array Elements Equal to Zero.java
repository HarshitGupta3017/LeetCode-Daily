// Solution for Make Array Elements Equal to Zero in JAVA

class Solution {

    private boolean simulateProcess(int[] nums, int curr, int dir) {
        int n = nums.length;
        int[] copy = nums.clone(); // Copy to avoid modifying original

        while (curr >= 0 && curr < n) {
            if (copy[curr] == 0) {
                curr += dir;
            } else {
                copy[curr]--;
                dir = -dir; // reverse direction
                curr += dir;
            }
        }

        for (int val : copy)
            if (val != 0)
                return false;

        return true;
    }

    public int countValidSelections(int[] nums) {
        int n = nums.length;
        int validSelections = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (simulateProcess(nums, i, 1)) validSelections++;  // move right
                if (simulateProcess(nums, i, -1)) validSelections++; // move left
            }
        }

        return validSelections;
    }
}
