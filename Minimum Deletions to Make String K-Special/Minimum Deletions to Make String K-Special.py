# Solution for Minimum Deletions to Make String K-Special in PY

class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        freq = [0] * 26

        for ch in word:
            freq[ord(ch) - ord('a')] += 1

        freq.sort()
        min_deletions = float('inf')
        cumulative_deletions = 0

        for i in range(26):
            deletions_needed = cumulative_deletions

            for j in range(25, i, -1):
                if freq[j] - freq[i] <= k:
                    break
                deletions_needed += freq[j] - freq[i] - k

            min_deletions = min(min_deletions, deletions_needed)
            cumulative_deletions += freq[i]

        return min_deletions
