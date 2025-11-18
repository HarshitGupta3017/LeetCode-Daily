# Solution for 1-bit and 2-bit Characters in PY

class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n, trailingOnes = len(bits), 0
        i = n - 2
        while i >= 0 and bits[i] == 1:
            trailingOnes += 1
            i -= 1
        return (trailingOnes % 2 == 0)
