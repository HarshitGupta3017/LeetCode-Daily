# Solution for Minimum Number of Flips to Make the Binary String Alternating in PY

class Solution:
    def minFlips(self, s: str) -> int:

        n = len(s)
        minimum_flips = float('inf')

        flips_pattern0 = 0
        left = 0

        for right in range(2 * n):

            expected_char = '1' if right % 2 else '0'

            if s[right % n] != expected_char:
                flips_pattern0 += 1

            if right - left + 1 > n:

                expected_left = '1' if left % 2 else '0'

                if s[left % n] != expected_left:
                    flips_pattern0 -= 1

                left += 1

            if right - left + 1 == n:

                flips_pattern1 = n - flips_pattern0
                minimum_flips = min(minimum_flips, flips_pattern0, flips_pattern1)

        return minimum_flips
