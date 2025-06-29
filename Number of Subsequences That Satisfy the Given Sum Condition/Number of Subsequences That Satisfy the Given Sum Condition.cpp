// Solution for Number of Subsequences That Satisfy the Given Sum Condition in CPP

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort to easily find min & max

        // Precompute powers of 2 modulo MOD
        vector<int> powerOfTwo(n, 1);
        for (int i = 1; i < n; i++) {
            powerOfTwo[i] = (2LL * powerOfTwo[i - 1]) % MOD;
        }

        int left = 0, right = n - 1;
        int totalValid = 0;

        // Two-pointer approach to check all valid pairs (min, max)
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                // All subsequences formed between left and right are valid
                totalValid = (totalValid + powerOfTwo[right - left]) % MOD;
                left++;
            } else {
                // Reduce the max element to try to make sum smaller
                right--;
            }
        }

        return totalValid;
    }
};
