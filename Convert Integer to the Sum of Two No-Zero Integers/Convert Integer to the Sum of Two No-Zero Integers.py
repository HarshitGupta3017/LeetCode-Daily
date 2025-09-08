# Solution for Convert Integer to the Sum of Two No-Zero Integers in PY

class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        return next([a, n-a] for a in range(1, n) if "0" not in str(a) and "0" not in str(n-a))
