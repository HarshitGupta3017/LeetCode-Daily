# Solution for Check If Digits Are Equal in String After Operations I in PY

class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)
        s = list(s)

        while n > 2:
            for i in range(n - 1):
                s[i] = str((int(s[i]) + int(s[i + 1])) % 10)
            n -= 1

        return s[0] == s[1]
