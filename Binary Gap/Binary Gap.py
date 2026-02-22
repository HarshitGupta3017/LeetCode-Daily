# Solution for Binary Gap in PY

class Solution:
    def binaryGap(self, n: int) -> int:

        prev_position = -1
        max_distance = 0

        # A 32-bit integer has at most 32 bits
        for current_position in range(32):

            # Check if current bit is 1
            if (n >> current_position) & 1:

                if prev_position != -1:
                    distance = current_position - prev_position
                    max_distance = max(max_distance, distance)

                prev_position = current_position

        return max_distance
