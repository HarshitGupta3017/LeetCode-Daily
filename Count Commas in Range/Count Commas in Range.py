# Solution for Count Commas in Range in PY

class Solution:
    def countCommas(self, n: int) -> int:
        return max(n - 999, 0)
