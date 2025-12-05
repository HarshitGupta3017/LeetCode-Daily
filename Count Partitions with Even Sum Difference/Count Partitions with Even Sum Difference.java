// Solution for Count Partitions with Even Sum Difference in JAVA

class Solution {
    public int countPartitions(int[] nums) {
        // Step 1: Compute total sum
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: If total sum is even → all (n - 1) partitions are valid
        if (totalSum % 2 == 0) {
            return nums.length - 1;
        }

        // Otherwise no valid partitions
        return 0;
    }
}
