// Solution for Find Missing Elements in CPP

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // Load all present values into a hash set for O(1) membership checks.
        unordered_set<int> present(nums.begin(), nums.end());

        // The problem guarantees the original range boundaries are still in nums,
        // so the full range we need to check is [min, max].
        int rangeMin = *min_element(nums.begin(), nums.end());
        int rangeMax = *max_element(nums.begin(), nums.end());

        vector<int> missing;

        // Only interior values can be missing — the endpoints are guaranteed present.
        for (int val = rangeMin + 1; val < rangeMax; val++) {
            if (!present.contains(val))
                missing.push_back(val);
        }

        // The loop runs in ascending order, so missing is already sorted.
        return missing;
    }
};
