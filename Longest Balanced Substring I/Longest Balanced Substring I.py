# Solution for Longest Balanced Substring I in PY

class Solution:
    def longestBalanced(self, s: str) -> int:

        n = len(s)
        max_length = 0

        for start in range(n):

            frequency = [0] * 26

            for end in range(start, n):

                frequency[ord(s[end]) - ord('a')] += 1

                if self.is_balanced(frequency):
                    max_length = max(max_length, end - start + 1)

        return max_length

    def is_balanced(self, freq):

        required_frequency = 0

        for count in freq:

            if count == 0:
                continue

            if required_frequency == 0:
                required_frequency = count
            elif count != required_frequency:
                return False

        return True
