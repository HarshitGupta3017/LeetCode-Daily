# Solution for Smallest Palindromic Rearrangement I in PY

class Solution:
    def smallestPalindrome(self, s: str) -> str:
        s = list(s)
        half = len(s) // 2
        s[:half] = sorted(s[:half])
        for i in range(half):
            s[-1 - i] = s[i]
        return "".join(s)
