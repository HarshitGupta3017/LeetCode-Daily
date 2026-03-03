# Solution for Find Kth Bit in Nth Binary String in PY

class Solution:
    def findKthBit(self, n: int, k: int) -> str:

        # Base case
        if n == 1:
            return '0'

        length_of_current = (1 << n) - 1
        middle_index = 1 << (n - 1)

        # Case 1: Middle
        if k == middle_index:
            return '1'

        # Case 2: Left half
        if k < middle_index:
            return self.findKthBit(n - 1, k)

        # Case 3: Right half
        mirror_index = length_of_current - k + 1

        mirrored_bit = self.findKthBit(n - 1, mirror_index)

        # Invert bit
        return '1' if mirrored_bit == '0' else '0'
