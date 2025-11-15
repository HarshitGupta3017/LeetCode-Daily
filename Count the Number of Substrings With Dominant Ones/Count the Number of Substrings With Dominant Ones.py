# Solution for Count the Number of Substrings With Dominant Ones in PY

class Solution:
    def numberOfSubstrings(self, s: str) -> int:

        n = len(s)
        result = 0

        # 🔹 Prefix sum for ones
        prefix = [0] * n
        prefix[0] = 1 if s[0] == '1' else 0

        for i in range(1, n):
            prefix[i] = prefix[i - 1] + (1 if s[i] == '1' else 0)

        # 🔹 Check all substrings
        for left in range(n):

            right = left
            while right < n:

                ones = prefix[right] - (prefix[left - 1] if left > 0 else 0)
                zeroes = (right - left + 1) - ones

                # Case A: not dominant → skip ahead
                if zeroes * zeroes > ones:
                    needed = (zeroes * zeroes) - ones
                    right += needed - 1

                # Case B: exact dominant
                elif zeroes * zeroes == ones:
                    result += 1

                # Case C: dominant → jump ahead
                else:
                    result += 1

                    jump = int(ones ** 0.5) - zeroes
                    next_r = right + jump

                    if next_r >= n:
                        result += (n - right - 1)
                        break

                    result += jump
                    right = next_r

                right += 1

        return result
