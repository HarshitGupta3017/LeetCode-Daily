# Solution for Maximum Number of Operations to Move Ones to the End in PY

class Solution:
    def maxOperations(self, s: str) -> int:
        n = len(s)           # Total length of the binary string
        index = 0            # Pointer to traverse the string
        count_ones = 0       # Tracks number of '1's encountered so far
        total_ops = 0        # Stores total number of possible operations

        # 🧩 Traverse through the string character by character
        while index < n:
            if s[index] == '0':
                # 💡 Every '0' can be paired with all previous '1's
                total_ops += count_ones

                # ⏩ Skip over all consecutive zeros
                while index < n and s[index] == '0':
                    index += 1
            else:
                # 🔸 Increment '1' count
                count_ones += 1
                index += 1

        # ✅ Return total number of operations possible
        return total_ops
