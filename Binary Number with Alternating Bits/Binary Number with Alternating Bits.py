# Solution for Binary Number with Alternating Bits in PY

class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        xor_result = n ^ (n >> 1)
        return (xor_result & (xor_result + 1)) == 0
