// Solution for Transformed Array in JAVA

class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] transformedResult = new int[n];

        for (int index = 0; index < n; index++) {
            int steps = nums[index] % n;
            int targetIndex = (index + steps) % n;

            // Normalize negative index
            if (targetIndex < 0) {
                targetIndex += n;
            }

            transformedResult[index] = nums[targetIndex];
        }

        return transformedResult;
    }
}
