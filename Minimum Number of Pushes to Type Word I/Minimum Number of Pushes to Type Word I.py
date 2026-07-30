# Solution for Minimum Number of Pushes to Type Word I in PY

class Solution:
    def minimumPushes(self, word: str) -> int:
        # We have 8 keys (2–9), each of which can hold any number of letters.
        # The first 8 letters cost 1 push, the next 8 cost 2 pushes, and so on.
        total_pushes = 0

        for i in range(len(word)):
            total_pushes += (i // 8) + 1

        return total_pushes
