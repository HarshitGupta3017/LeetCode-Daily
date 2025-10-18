// Solution for Maximum Number of Distinct Elements After Operations in JAVA

class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        Arrays.sort(nums);
        int distinctCount = 0;
        int lastUsed = Integer.MIN_VALUE;

        for (int num : nums) {
            int minPossible = num - k;
            int maxPossible = num + k;

            if (lastUsed < minPossible) {
                lastUsed = minPossible;
                distinctCount++;
            } else if (lastUsed < maxPossible) {
                lastUsed++;
                distinctCount++;
            }
        }

        return distinctCount;
    }
}
