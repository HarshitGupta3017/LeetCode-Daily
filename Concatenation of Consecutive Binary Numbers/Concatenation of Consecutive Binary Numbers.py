# Solution for Concatenation of Consecutive Binary Numbers in PY

class Solution:
    def concatenatedBinary(self, n: int) -> int:

        finalNumber = 0
        MOD = 10**9 + 7

        for currentNumber in range(1, n + 1):
            numberOfBits = currentNumber.bit_length()
            finalNumber = ((finalNumber << numberOfBits) % MOD + currentNumber) % MOD

        return finalNumber
