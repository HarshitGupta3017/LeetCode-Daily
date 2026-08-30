// Solution for Removing Minimum and Maximum From Array in CPP

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxIdx = (int)(max_element(nums.begin(), nums.end()) - nums.begin());
        int minIdx = (int)(min_element(nums.begin(), nums.end()) - nums.begin());

        // Normalise so leftIdx always refers to the element closer to the front.
        int leftIdx  = min(minIdx, maxIdx);
        int rightIdx = max(minIdx, maxIdx);

        // Three strategies to remove both elements:
        // 1. Take both from the left:  delete everything up to and including rightIdx.
        // 2. Take both from the right: delete everything from leftIdx to the end.
        // 3. Take one from each end:   delete leftIdx+1 from the front (covers leftIdx)
        //                              and n-rightIdx from the back (covers rightIdx).
        int bothFromLeft  = rightIdx + 1;
        int bothFromRight = n - leftIdx;
        int oneEachSide   = (leftIdx + 1) + (n - rightIdx);

        return min({bothFromLeft, bothFromRight, oneEachSide});
    }
};
