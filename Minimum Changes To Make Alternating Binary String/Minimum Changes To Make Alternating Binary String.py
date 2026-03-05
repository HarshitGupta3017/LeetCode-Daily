# Solution for Minimum Changes To Make Alternating Binary String in PY

class Solution:
    def minOperations(self, s: str) -> int:

        # Length of binary string
        stringLength = len(s)

        # Count flips if pattern starts with '0'
        flipsStartingWithZero = 0

        for index in range(stringLength):

            # Even index -> expected '0'
            # Odd index  -> expected '1'
            if (index % 2 == 0 and s[index] == '1') or \
               (index % 2 == 1 and s[index] == '0'):

                flipsStartingWithZero += 1

        # Pattern starting with '1'
        flipsStartingWithOne = stringLength - flipsStartingWithZero

        return min(flipsStartingWithZero, flipsStartingWithOne)
