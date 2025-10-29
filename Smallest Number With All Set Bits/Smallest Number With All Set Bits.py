# Solution for Smallest Number With All Set Bits in PY

class Solution:
    def smallestNumber(self, n: int) -> int:
        x = 1
        while x < n: 
            x = x * 2 + 1
        return x
