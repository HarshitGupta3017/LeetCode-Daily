# Solution for Vowels Game in a String in PY

class Solution:
    def doesAliceWin(self, s: str) -> bool:
        return any(ch in "aeiou" for ch in s)
