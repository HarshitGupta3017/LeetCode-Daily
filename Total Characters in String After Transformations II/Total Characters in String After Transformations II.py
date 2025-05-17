# Solution for Total Characters in String After Transformations II in PY

MOD = 10**9 + 7

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        # Step 1: Initial frequency vector
        freq = [0] * 26
        for ch in s:
            freq[ord(ch) - ord('a')] += 1

        # Step 2: Build transformation matrix T
        T = [[0] * 26 for _ in range(26)]
        for i in range(26):
            for add in range(1, nums[i] + 1):
                T[(i + add) % 26][i] += 1

        # Step 3: Compute T^t
        result = self.matrix_exponentiation(T, t)

        # Step 4: Multiply result * freq
        final_freq = [0] * 26
        for i in range(26):
            for j in range(26):
                final_freq[i] = (final_freq[i] + result[i][j] * freq[j]) % MOD

        # Step 5: Sum final frequencies
        return sum(final_freq) % MOD

    def matrix_exponentiation(self, base: List[List[int]], exponent: int) -> List[List[int]]:
        identity = [[1 if i == j else 0 for j in range(26)] for i in range(26)]
        if exponent == 0:
            return identity
        if exponent == 1:
            return base

        half = self.matrix_exponentiation(base, exponent // 2)
        result = self.matrix_multiplication(half, half)

        if exponent % 2 == 1:
            result = self.matrix_multiplication(result, base)

        return result

    def matrix_multiplication(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        C = [[0] * 26 for _ in range(26)]
        for i in range(26):
            for j in range(26):
                for k in range(26):
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD
        return C
