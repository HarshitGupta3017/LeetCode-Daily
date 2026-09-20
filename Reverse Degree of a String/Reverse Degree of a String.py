# Solution for Reverse Degree of a String in PY

class Solution:
    def reverseDegree(self, s: str) -> int:
        ans = 0

        for i in range(1, len(s) + 1):
            ans += (26 - (ord(s[i - 1]) - ord('a'))) * i

        return ans
