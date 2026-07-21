# Solution for Maximize Active Section with Trade I in PY

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        n = len(s)

        # Count total active sections ('1')
        total_active = s.count('1')

        # Store lengths of contiguous 0-blocks
        zero_block_lengths = []
        i = 0
        while i < n:
            if s[i] == '0':
                start = i
                while i < n and s[i] == '0':
                    i += 1
                zero_block_lengths.append(i - start)
            else:
                i += 1

        # Find maximum sum of adjacent 0-block lengths
        max_gain = 0
        for j in range(1, len(zero_block_lengths)):
            max_gain = max(max_gain,
                           zero_block_lengths[j] + zero_block_lengths[j - 1])

        return total_active + max_gain
