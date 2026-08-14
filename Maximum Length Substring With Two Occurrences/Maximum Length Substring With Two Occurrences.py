# Solution for Maximum Length Substring With Two Occurrences in PY

class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        left = 0
        right = 0
        max_len = 0
        freq = [0] * 26

        while right < len(s):
            freq[ord(s[right]) - ord('a')] += 1

            while freq[ord(s[right]) - ord('a')] > 2:
                freq[ord(s[left]) - ord('a')] -= 1
                left += 1

            max_len = max(max_len, right - left + 1)
            right += 1

        return max_len
