// Solution for Check if Array is Good in JAVA

class Solution {
    public boolean isGood(int[] nums) {

        // Sort array
        Arrays.sort(nums);

        int expectedMax = nums.length - 1;

        // Check sequence: 1,2,3,...,n-1
        for (int i = 0; i < expectedMax; i++) {
            if (nums[i] != i + 1)
                return false;
        }

        // Last element must be n
        return nums[expectedMax] == expectedMax;
    }
}
