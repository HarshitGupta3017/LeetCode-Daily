// Solution for Minimum One Bit Operations to Make Integers Zero in CPP

class Solution {
public:
    int minimumOneBitOperations(int n) {
        // 🧠 Base case: If n is already 0, no operations are needed
        if (n == 0) return 0;

        // 🔹 Precompute the minimum operations needed to flip a number
        // with only the i-th bit set (similar to Gray code pattern)
        // f[i] represents the minimum number of operations to make 2^i -> 0
        vector<long long> minOpsForBit(31, 0);
        minOpsForBit[0] = 1;

        // Each level doubles the operations of the previous level + 1 extra operation
        for (int i = 1; i < 31; i++) {
            minOpsForBit[i] = 2 * minOpsForBit[i - 1] + 1;
        }

        // 🔹 Initialize result and a sign tracker to manage flipping directions
        int sign = 1;
        int totalOperations = 0;

        // 🔹 Traverse all bits from the most significant (30th) to least significant (0th)
        for (int i = 30; i >= 0; i--) {
            int currentBit = (1 << i) & n;  // Check if the i-th bit is set in n
            if (currentBit == 0) continue;  // Skip unset bits

            // If bit is set → add or subtract its operation value based on current direction
            totalOperations += minOpsForBit[i] * sign;

            // Flip direction because toggling a bit affects lower bits inversely
            sign *= -1;
        }

        // ✅ Return the minimum number of bit operations required to make n → 0
        return totalOperations;
    }
};
