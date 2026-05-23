// Solution for Check if Array Is Sorted and Rotated in JAVA

class Solution {
    public boolean check(int[] nums) {

        int n = nums.length;
        int breaksCount = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] > nums[(i + 1) % n]) {
                breaksCount++;
            }
        }

        return breaksCount <= 1;
    }
}
