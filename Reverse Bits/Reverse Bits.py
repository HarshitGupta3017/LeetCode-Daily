# Solution for Reverse Bits in PY

class Solution:
    def reverseBits(self, n: int) -> int:
        
        reversed = 0
        
        for i in range(32):
            reversed <<= 1
            reversed |= (n & 1)
            n >>= 1

        return reversed
