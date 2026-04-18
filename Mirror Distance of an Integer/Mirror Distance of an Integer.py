# Solution for Mirror Distance of an Integer in PY

class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(n - self.getReverse(n))
        
    def getReverse(self, x: int) -> int:
        rev = 0
        while (x > 0):
            rev = (rev * 10) + (x % 10)
            x //= 10
        return rev
