# Solution for Find the String with LCP in PY

class Solution:
    # Helper function to rebuild LCP matrix
    def buildLCP(self, word: str):
        n = len(word)
        computedLCP = [[0] * n for _ in range(n)]

        # Base case
        for i in range(n):
            computedLCP[i][n - 1] = 1 if word[i] == word[n - 1] else 0
        for j in range(n):
            computedLCP[n - 1][j] = 1 if word[n - 1] == word[j] else 0

        # Fill bottom-up
        for i in range(n - 2, -1, -1):
            for j in range(n - 2, -1, -1):
                if word[i] == word[j]:
                    computedLCP[i][j] = 1 + computedLCP[i + 1][j + 1]
                else:
                    computedLCP[i][j] = 0

        return computedLCP

    def findTheString(self, lcp):
        n = len(lcp)

        # Step 1: initialize
        word = ['$'] * n

        # Step 2: construct string
        for i in range(n):

            # Try reuse
            for j in range(n):
                if lcp[i][j] != 0:
                    word[i] = word[j]
                    break

            # Assign new character if needed
            if word[i] == '$':
                forbidden = [False] * 26

                for j in range(i):
                    if lcp[i][j] == 0:
                        forbidden[ord(word[j]) - ord('a')] = True

                for ch in range(26):
                    if not forbidden[ch]:
                        word[i] = chr(ord('a') + ch)
                        break

                if word[i] == '$':
                    return ""

        word_str = "".join(word)

        # Step 3: validate
        return word_str if self.buildLCP(word_str) == lcp else ""
