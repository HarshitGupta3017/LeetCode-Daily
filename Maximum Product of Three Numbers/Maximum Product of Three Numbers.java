// Solution for Maximum Product of Three Numbers in JAVA

class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        // Case 1: Product of the three largest numbers
        int topThree = nums[n - 1] * nums[n - 2] * nums[n - 3];

        // Case 2: Product of the two smallest (most negative) numbers
        // and the largest number
        int twoNegOnePos = nums[0] * nums[1] * nums[n - 1];

        return Math.max(topThree, twoNegOnePos);
    }
}
