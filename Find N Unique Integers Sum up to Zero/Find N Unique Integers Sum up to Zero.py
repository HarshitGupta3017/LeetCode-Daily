# Solution for Find N Unique Integers Sum up to Zero in PY

class Solution:
    def sumZero(self, n: int) -> List[int]:
        return [num for num in range(-(n // 2), (n // 2) + 1) if not (num == 0 and n % 2 == 0)] 
