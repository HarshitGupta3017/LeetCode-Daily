# Solution for Longest Subsequence Repeated k Times in PY

class Solution:
    def isSubsequence(self, s: str, sub: str, k: int) -> bool:
        i = j = 0
        n = len(s)
        length = len(sub)
        while i < n and j < length * k:
            if s[i] == sub[j % length]:
                j += 1
            i += 1
        return j == length * k

    def backtrack(self, s: str, curr: list, usable: list, remainingFreq: list, maxLen: int, k: int, result: list) -> bool:
        if len(curr) == maxLen:
            candidate = ''.join(curr)
            if self.isSubsequence(s, candidate, k):
                result[0] = candidate
                return True
            return False

        for i in range(25, -1, -1):  # from 'z' to 'a'
            if not usable[i] or remainingFreq[i] == 0:
                continue
            curr.append(chr(i + ord('a')))
            remainingFreq[i] -= 1
            if self.backtrack(s, curr, usable, remainingFreq, maxLen, k, result):
                return True
            curr.pop()
            remainingFreq[i] += 1
        return False

    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        n = len(s)
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        usable = [False] * 26
        maxAvailable = [0] * 26
        for i in range(26):
            if freq[i] >= k:
                usable[i] = True
                maxAvailable[i] = freq[i] // k

        maxPossibleLength = n // k
        result = [""]

        for maxLen in range(maxPossibleLength, 0, -1):
            remainingFreq = maxAvailable[:]
            if self.backtrack(s, [], usable, remainingFreq, maxLen, k, result):
                return result[0]

        return ""
