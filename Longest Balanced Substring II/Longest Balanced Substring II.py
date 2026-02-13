# Solution for Longest Balanced Substring II in PY

class Solution:

    def longestTwoCharBalanced(self, s: str, ch1: str, ch2: str) -> int:

        count1 = count2 = 0
        max_length = 0
        first_seen_diff = {}

        for i, c in enumerate(s):

            if c != ch1 and c != ch2:
                first_seen_diff.clear()
                count1 = count2 = 0
                continue

            if c == ch1:
                count1 += 1
            else:
                count2 += 1

            if count1 == count2:
                max_length = max(max_length, count1 + count2)

            diff = count1 - count2

            if diff in first_seen_diff:
                max_length = max(max_length, i - first_seen_diff[diff])
            else:
                first_seen_diff[diff] = i

        return max_length

    def longestBalanced(self, s: str) -> int:

        n = len(s)
        max_length = 0

        # -------------------------
        # Case 1: single character
        # -------------------------
        streak = 1

        for i in range(1, n):
            if s[i] == s[i - 1]:
                streak += 1
            else:
                max_length = max(max_length, streak)
                streak = 1

        max_length = max(max_length, streak)

        # -------------------------
        # Case 2: two characters
        # -------------------------
        max_length = max(max_length,
                         self.longestTwoCharBalanced(s, 'a', 'b'))
        max_length = max(max_length,
                         self.longestTwoCharBalanced(s, 'a', 'c'))
        max_length = max(max_length,
                         self.longestTwoCharBalanced(s, 'b', 'c'))

        # -------------------------
        # Case 3: all three chars
        # -------------------------
        countA = countB = countC = 0
        first_seen_state = {}

        for i, c in enumerate(s):

            if c == 'a':
                countA += 1
            elif c == 'b':
                countB += 1
            else:
                countC += 1

            if countA == countB == countC:
                max_length = max(max_length,
                                 countA + countB + countC)

            diffAB = countA - countB
            diffAC = countA - countC

            key = (diffAB, diffAC)

            if key in first_seen_state:
                max_length = max(max_length,
                                 i - first_seen_state[key])
            else:
                first_seen_state[key] = i

        return max_length
