# Solution for Count the Number of Special Characters I in PY

class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lower = set(filter(str.islower, word))
        upper = set(filter(str.isupper, word))
        return sum(c.upper() in upper for c in lower)
