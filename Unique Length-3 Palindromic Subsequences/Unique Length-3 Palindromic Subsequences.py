# Solution for Unique Length-3 Palindromic Subsequences in PY

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)

        # (first, last) for each char
        charBounds = [[-1, -1] for _ in range(26)]

        # record first & last appearance
        for i, ch in enumerate(s):
            idx = ord(ch) - ord('a')
            if charBounds[idx][0] == -1:
                charBounds[idx][0] = i
            charBounds[idx][1] = i

        result = 0

        # count distinct middle chars
        for c in range(26):
            leftIndex, rightIndex = charBounds[c]
            if leftIndex == -1:
                continue

            middleChars = set()
            for mid in range(leftIndex + 1, rightIndex):
                middleChars.add(s[mid])

            result += len(middleChars)

        return result
