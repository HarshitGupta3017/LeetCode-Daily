# Solution for Prime Number of Set Bits in Binary Representation in PY

class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        prime_set_bits = {2, 3, 5, 7, 11, 13, 17, 19}
        return sum(1 for num in range(left, right + 1) if num.bit_count() in prime_set_bits)
