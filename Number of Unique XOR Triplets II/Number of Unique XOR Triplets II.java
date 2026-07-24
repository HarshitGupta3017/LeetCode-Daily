// Solution for Number of Unique XOR Triplets II in JAVA

class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;

        // Find the maximum value
        int maximumValue = 0;
        for (int num : nums) {
            maximumValue = Math.max(maximumValue, num);
        }

        // Smallest power of two greater than maximumValue
        int xorRange = 1;
        while (xorRange <= maximumValue) {
            xorRange <<= 1;
        }

        boolean[] pairXorExists = new boolean[xorRange];
        boolean[] tripletXorExists = new boolean[xorRange];

        // Generate all pair XORs
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXorExists[nums[i] ^ nums[j]] = true;
            }
        }

        // Generate all triplet XORs
        for (int xor = 0; xor < xorRange; xor++) {
            if (!pairXorExists[xor]) {
                continue;
            }

            for (int value : nums) {
                tripletXorExists[xor ^ value] = true;
            }
        }

        // Count distinct triplet XOR values
        int count = 0;
        for (boolean exists : tripletXorExists) {
            if (exists) {
                count++;
            }
        }

        return count;
    }
}
