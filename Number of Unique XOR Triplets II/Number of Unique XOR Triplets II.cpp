// Solution for Number of Unique XOR Triplets II in CPP

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
    
        // Number of elements in the array
        int n = nums.size();

        // Find the maximum value present in the array
        int maximumValue = *max_element(nums.begin(), nums.end());

        // Compute the smallest power of two greater than the maximum value.
        // This represents the maximum possible XOR state we need to track.
        int xorRange = 1;
        while (xorRange <= maximumValue) {
            xorRange <<= 1;
        }

        // pairXorExists[x] = true if there exists a pair (i, j) with i <= j
        // such that nums[i] XOR nums[j] == x.
        vector<bool> pairXorExists(xorRange, false);

        // tripletXorExists[x] = true if there exists a triplet (i, j, k)
        // with i <= j <= k whose XOR value equals x.
        vector<bool> tripletXorExists(xorRange, false);

        // Generate all possible XOR values obtained from valid pairs.
        for (int firstIndex = 0; firstIndex < n; firstIndex++) {
            for (int secondIndex = firstIndex; secondIndex < n; secondIndex++) {
                int pairXor = nums[firstIndex] ^ nums[secondIndex];
                pairXorExists[pairXor] = true;
            }
        }

        // Extend every achievable pair XOR by XOR-ing it with each array element
        // to generate all possible triplet XOR values.
        for (int currentXor = 0; currentXor < xorRange; currentXor++) {
            if (!pairXorExists[currentXor]) {
                continue;
            }

            for (int value : nums) {
                int tripletXor = currentXor ^ value;
                tripletXorExists[tripletXor] = true;
            }
        }

        // Count the number of distinct triplet XOR values.
        return count(tripletXorExists.begin(), tripletXorExists.end(), true);
    }
};
