# Solution for Power of Two in PY

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        return n.bit_count() == 1
