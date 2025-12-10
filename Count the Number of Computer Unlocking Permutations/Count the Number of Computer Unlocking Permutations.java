// Solution for Count the Number of Computer Unlocking Permutations in JAVA

class Solution {
    public int countPermutations(int[] complexity) {
        final int MOD = 1_000_000_007;

        long totalSequences = 1;

        // Iterate over all computers except root (index 0)
        for (int i = 1; i < complexity.length; i++) {

            // If complexity is <= root's complexity, no valid permutation
            if (complexity[i] <= complexity[0]) {
                return 0;
            }

            // Multiply choices for this computer
            totalSequences = (totalSequences * i) % MOD;
        }

        return (int) totalSequences;
    }
}
