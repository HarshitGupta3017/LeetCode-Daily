# Solution for Minimum One Bit Operations to Make Integers Zero in PY

class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        # 🧠 Base case: If n is already 0, no operations are needed
        if n == 0:
            return 0

        # 🔹 Precompute the minimum operations needed to flip a number
        # with only the i-th bit set (similar to Gray code pattern)
        # f[i] represents minimum operations to make 2^i -> 0
        minOpsForBit = [0] * 31
        minOpsForBit[0] = 1

        # Each level doubles the previous one and adds +1 operation
        for i in range(1, 31):
            minOpsForBit[i] = 2 * minOpsForBit[i - 1] + 1

        # 🔹 Initialize result and sign tracker
        sign = 1
        totalOperations = 0

        # 🔹 Traverse bits from most significant (30th) to least (0th)
        for i in range(30, -1, -1):
            currentBit = n & (1 << i)
            if currentBit == 0:
                continue

            # Add or subtract operations depending on current direction
            totalOperations += minOpsForBit[i] * sign

            # Flip direction after toggling a bit
            sign *= -1

        # ✅ Return total minimum operations
        return totalOperations
