# Solution for Count Odd Numbers in an Interval Range in PY

class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high + 1) // 2 - low // 2
