# Solution for Reordered Power of 2 in PY

class Solution:
    def getDigitSignature(self, num):
        sig = 0
        while num:
            sig += 10 ** (num % 10)
            num //= 10
        return sig

    def reorderedPowerOf2(self, n: int) -> bool:
        sig = self.getDigitSignature(n)
        return any(sig == self.getDigitSignature(1 << p) for p in range(30))
