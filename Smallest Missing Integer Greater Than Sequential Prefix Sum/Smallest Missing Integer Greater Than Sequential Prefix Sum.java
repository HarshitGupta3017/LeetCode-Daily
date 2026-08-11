// Solution for Smallest Missing Integer Greater Than Sequential Prefix Sum in JAVA

class Solution {
    public int missingInteger(int[] nums) {
        // Compute the sum of the longest sequential prefix.
        int prefixSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                break;
            }
            prefixSum += nums[i];
        }

        // Store all values for O(1) average membership checks.
        HashSet<Integer> present = new HashSet<>();

        for (int num : nums) {
            present.add(num);
        }

        // Find the smallest integer >= prefixSum not present in nums.
        while (present.contains(prefixSum)) {
            prefixSum++;
        }

        return prefixSum;
    }
}
