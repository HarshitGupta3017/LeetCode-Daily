// Solution for Maximum Unique Subarray Sum After Deletion in JAVA

class Solution {
    public int maxSum(int[] nums) {
        int[] seen = new int[101];
        Arrays.fill(seen, -1);
        int maxSum = 0;
        int maxNegative = Integer.MIN_VALUE;

        for (int num : nums) {
            if (num <= 0) {
                maxNegative = Math.max(maxNegative, num);
            } else if (seen[num] == -1) {
                maxSum += num;
                seen[num] = 1;
            }
        }

        return maxSum == 0 ? maxNegative : maxSum;
    }
}
