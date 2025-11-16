# Solution for Number of Substrings With Only 1s in PY

class Solution:
    def numSub(self, s: str) -> int:
        
        MOD = 10**9 + 7
        total = 0
        streak = 0

        for ch in s:
            if ch == '1':
                streak += 1
                total = (total + streak) % MOD
            else:
                streak = 0

        return total
