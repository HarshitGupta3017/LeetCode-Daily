// Solution for Left and Right Sum Differences in JAVA

class Solution {
    public int[] leftRightDifference(int[] nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;
        int rightSum = totalSum;
        int[] result = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            rightSum -= nums[i];
            result[i] = Math.abs(leftSum - rightSum);
            leftSum += nums[i];
        }

        return result;
    }
}
