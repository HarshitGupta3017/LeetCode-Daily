// Solution for Make Sum Divisible by P in CPP

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        // totalModSum = (sum of all numbers) % p
        // We only care about the remainder relative to p.
        int totalModSum = 0;
        for (const auto& num : nums) {
            totalModSum = (totalModSum + num) % p;
        }

        // If the whole array sum is already divisible by p,
        // no need to remove anything.
        if (totalModSum == 0) return 0;

        // We need to remove a subarray whose sum % p = totalModSum.
        // That subarray removal will fix the overall remainder.
        int requiredRemainder = totalModSum % p;

        // Map "prefix_sum_modulo" → index
        // prefixModToIndex[mod] = index of the prefix where this mod occurred.
        // Start with mod 0 at index -1 (before the array starts).
        unordered_map<int, int> prefixModToIndex;
        prefixModToIndex[0] = -1;

        int currentPrefixMod = 0;
        int minLength = n;  // store minimum removable subarray length

        for (int j = 0; j < n; j++) {

            // Update prefix modulo sum
            currentPrefixMod = (currentPrefixMod + nums[j]) % p;

            // We want:
            // (currentPrefixMod - previousPrefixMod) % p == requiredRemainder
            // → previousPrefixMod == (currentPrefixMod - requiredRemainder + p) % p
            int neededMod = (currentPrefixMod - requiredRemainder + p) % p;

            // If a prefix with neededMod exists,
            // removing the subarray between that index+1 and j will fix the remainder.
            if (prefixModToIndex.count(neededMod)) {
                minLength = min(minLength, j - prefixModToIndex[neededMod]);
            }

            // Store/update current prefix mod value at index j.
            prefixModToIndex[currentPrefixMod] = j;
        }

        // If minLength was updated, return it. Otherwise, no valid subarray was found.
        return minLength == n ? -1 : minLength;
    }
};
