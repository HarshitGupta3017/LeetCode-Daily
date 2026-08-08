# Solution for Find the Lexicographically Smallest Valid Sequence in PY

class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n = len(word1)
        m = len(word2)

        # suffixMatchCount[i] = number of characters of word2
        # that can be matched by scanning word1[i..n-1] from right to left.
        suffixMatchCount = [0] * n

        suffixMatched = 0
        j = m - 1

        for i in range(n - 1, -1, -1):
            if j >= 0 and word1[i] == word2[j]:
                suffixMatched += 1
                j -= 1

            suffixMatchCount[i] = suffixMatched

        # Greedily build the index sequence from left to right.
        seq = []
        canUseMismatch = True
        j = 0

        for i in range(n):
            if j >= m:
                break

            if word1[i] == word2[j]:
                # Exact match
                seq.append(i)
                j += 1

            elif (
                canUseMismatch
                and i + 1 < n
                and suffixMatchCount[i + 1] >= m - j - 1
            ):
                # Use the one allowed substitution
                seq.append(i)
                j += 1
                canUseMismatch = False

        # If word2 cannot be matched, return an empty sequence.
        return seq if j == m else []
