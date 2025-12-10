// Solution for Count the Number of Computer Unlocking Permutations in CPP

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1e9 + 7;

        // Start with 1 as the multiplicative identity
        long long totalSequences = 1;

        // Iterate over all computers except the root (computer 0)
        for (int currentComputer = 1; currentComputer < complexity.size(); currentComputer++) {

            // If this computer's complexity is less than or equal to root's complexity,
            // there is no previously unlocked computer that can unlock it → no valid permutation
            if (complexity[currentComputer] <= complexity[0]) {
                return 0;
            }

            // Multiply the number of choices for this computer
            // i.e., all previously unlocked computers < current index
            totalSequences = (totalSequences * currentComputer) % MOD;
        }

        return totalSequences;
    }
};
