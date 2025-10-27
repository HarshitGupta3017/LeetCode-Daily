# Solution for Number of Laser Beams in a Bank in PY

class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        res, prev = 0, 0
        for row in bank:
            curr = row.count('1')
            if curr:
                res += prev * curr
                prev = curr
        return res
