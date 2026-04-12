# Solution for Minimum Distance to Type a Word Using Two Fingers in PY

class Solution:
    def minimumDistance(self, word: str) -> int:
        from functools import lru_cache

        def getDistance(a, b):
            x1, y1 = divmod(a, 6)
            x2, y2 = divmod(b, 6)
            return abs(x1 - x2) + abs(y1 - y2)

        @lru_cache(None)
        def solve(index, f1, f2):
            if index >= len(word):
                return 0

            curr = ord(word[index]) - ord('A')

            # Case 1: both unused
            if f1 == 26 and f2 == 26:
                return solve(index + 1, curr, f2)

            # Case 2: finger2 unused
            if f2 == 26:
                use_f2 = solve(index + 1, f1, curr)
                use_f1 = getDistance(f1, curr) + solve(index + 1, curr, f2)
                return min(use_f2, use_f1)

            # Case 3: both used
            move_f1 = getDistance(f1, curr) + solve(index + 1, curr, f2)
            move_f2 = getDistance(f2, curr) + solve(index + 1, f1, curr)

            return min(move_f1, move_f2)

        return solve(0, 26, 26)
