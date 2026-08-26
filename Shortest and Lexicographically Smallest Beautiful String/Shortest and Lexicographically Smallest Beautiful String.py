# Solution for Shortest and Lexicographically Smallest Beautiful String in PY

class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        left = 0
        ones_count = 0
        best = ""

        for right in range(len(s)):
            if s[right] == '1':
                ones_count += 1

            # Remove extra 1s
            while ones_count > k:
                if s[left] == '1':
                    ones_count -= 1
                left += 1

            # Remove leading zeros
            while left <= right and s[left] == '0':
                left += 1

            # Exactly k ones
            if ones_count == k:
                candidate = s[left:right + 1]

                if (
                    not best
                    or len(candidate) < len(best)
                    or (len(candidate) == len(best) and candidate < best)
                ):
                    best = candidate

        return best
