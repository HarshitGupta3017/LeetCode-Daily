// Solution for Count Special Triplets in JAVA

class Solution {
    public int specialTriplets(int[] nums) {

        Map<Integer, Long> freqLeft = new HashMap<>();
        Map<Integer, Long> freqRight = new HashMap<>();

        final long MOD = 1_000_000_007L;
        long totalTriplets = 0;

        // Step 1: Initially, all elements are on the RIGHT side
        for (int num : nums) {
            freqRight.put(num, freqRight.getOrDefault(num, 0L) + 1);
        }

        // Step 2: Iterate treating each index as potential j
        for (int val : nums) {

            // Move val from RIGHT to current position j
            freqRight.put(val, freqRight.get(val) - 1);

            long needed = 2L * val;

            // Count matches on left (i)
            long leftCount = freqLeft.getOrDefault((int) needed, 0L);

            // Count matches on right (k)
            long rightCount = freqRight.getOrDefault((int) needed, 0L);

            totalTriplets = (totalTriplets + (leftCount * rightCount) % MOD) % MOD;

            // Move current j value into LEFT for future iterations
            freqLeft.put(val, freqLeft.getOrDefault(val, 0L) + 1);
        }

        return (int)(totalTriplets % MOD);
    }
}
