# Solution for Longest Binary Subsequence Less Than or Equal to K in PY

class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        n = len(s)
        powerOfTwo = 1
        maxLength = 0

        for i in range(n - 1, -1, -1):
            if s[i] == '0':
                maxLength += 1
            elif powerOfTwo <= k:
                k -= powerOfTwo
                maxLength += 1
            if powerOfTwo <= k:
                powerOfTwo <<= 1

        return maxLength
