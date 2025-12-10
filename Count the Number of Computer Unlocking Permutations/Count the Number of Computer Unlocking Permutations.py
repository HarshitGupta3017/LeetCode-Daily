# Solution for Count the Number of Computer Unlocking Permutations in PY

class Solution:
    def countPermutations(self, complexity: list[int]) -> int:
        MOD = 10**9 + 7
        total_sequences = 1

        # Iterate over all computers except root (index 0)
        for i in range(1, len(complexity)):

            # If complexity is <= root's complexity, no valid permutation
            if complexity[i] <= complexity[0]:
                return 0

            # Multiply choices for this computer
            total_sequences = (total_sequences * i) % MOD

        return total_sequences
