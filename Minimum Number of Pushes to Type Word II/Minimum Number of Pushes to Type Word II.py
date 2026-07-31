# Solution for Minimum Number of Pushes to Type Word II in PY

class Solution:
    def minimumPushes(self, word: str) -> int:
        # Count frequency of each letter
        freq = [0] * 26
        for ch in word:
            freq[ord(ch) - ord('a')] += 1

        # Sort frequencies in descending order
        freq.sort(reverse=True)

        total_pushes = 0
        for i in range(26):
            total_pushes += freq[i] * (i // 8 + 1)

        return total_pushes
