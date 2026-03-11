# Solution for Complement of Base 10 Integer in PY

class Solution:
    def bitwiseComplement(self, n: int) -> int:
        return 1 if n == 0 else n ^ ((1 << (int(log2(n)) + 1)) - 1)
