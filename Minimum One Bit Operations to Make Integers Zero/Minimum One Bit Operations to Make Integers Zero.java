// Solution for Minimum One Bit Operations to Make Integers Zero in JAVA

class Solution {
    public int minimumOneBitOperations(int n) {
        // 🧠 Base case: If n is already 0, no operations needed
        if (n == 0) return 0;

        // 🔹 Precompute minimum operations for flipping a single bit (Gray code pattern)
        long[] minOpsForBit = new long[31];
        minOpsForBit[0] = 1;

        // Each level doubles the previous level + 1 extra operation
        for (int i = 1; i < 31; i++) {
            minOpsForBit[i] = 2 * minOpsForBit[i - 1] + 1;
        }

        // 🔹 Initialize result and direction tracker
        int sign = 1;
        int totalOperations = 0;

        // 🔹 Traverse bits from most significant (30th) to least (0th)
        for (int i = 30; i >= 0; i--) {
            int currentBit = n & (1 << i);
            if (currentBit == 0) continue;

            // Add or subtract based on current sign
            totalOperations += minOpsForBit[i] * sign;

            // Flip direction
            sign *= -1;
        }

        // ✅ Return the minimum number of bit operations required to make n → 0
        return totalOperations;
    }
}
