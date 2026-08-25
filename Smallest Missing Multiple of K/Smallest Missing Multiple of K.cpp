// Solution for Smallest Missing Multiple of K in CPP

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present(nums.begin(), nums.end());

        // Scan multiples of k in ascending order (k, 2k, 3k, ...)
        // and return the first one not found in the set.
        int candidate = k;
        while (present.count(candidate))
            candidate += k;

        return candidate;
    }
};
