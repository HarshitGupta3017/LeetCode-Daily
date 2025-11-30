// Solution for Make Sum Divisible by P in JAVA

class Solution {
    public int minSubarray(int[] nums, int p) {
        int n = nums.length;

        // Compute total sum mod p
        int totalModSum = 0;
        for (int num : nums) {
            totalModSum = (totalModSum + num) % p;
        }

        if (totalModSum == 0) return 0;

        int requiredRemainder = totalModSum % p;

        // Map prefix_mod → index
        Map<Integer, Integer> prefixModToIndex = new HashMap<>();
        prefixModToIndex.put(0, -1);

        int currentPrefixMod = 0;
        int minLength = n;

        for (int j = 0; j < n; j++) {
            currentPrefixMod = (currentPrefixMod + nums[j]) % p;
            int neededMod = (currentPrefixMod - requiredRemainder + p) % p;

            if (prefixModToIndex.containsKey(neededMod)) {
                minLength = Math.min(minLength, j - prefixModToIndex.get(neededMod));
            }

            prefixModToIndex.put(currentPrefixMod, j);
        }

        return minLength == n ? -1 : minLength;
    }
}
