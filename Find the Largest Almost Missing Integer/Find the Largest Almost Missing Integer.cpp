// Solution for Find the Largest Almost Missing Integer in CPP

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Count global frequency of each value.
        vector<int> freq(51, 0);
        for (int num : nums) freq[num]++;

        // When k == n there is exactly one subarray (the whole array),
        // so every element appears in exactly one subarray — the answer is the max.
        if (k == n)
            return *max_element(nums.begin(), nums.end());

        // When k == 1 every single element is its own subarray.
        // A value is almost missing iff it appears in exactly one subarray of size 1,
        // i.e. its global frequency is exactly 1. Return the largest such value.
        if (k == 1) {
            for (int val = 50; val >= 0; val--)
                if (freq[val] == 1) return val;
            return -1;
        }

        // For 1 < k < n, the subarrays of size k are nums[0..k-1], nums[1..k], ..., nums[n-k..n-1].
        // A value x appears in exactly one such subarray iff it occurs globally exactly once
        // AND that single occurrence is at an index that belongs to only one window.
        // Indices 0 and n-1 each belong to exactly one window (the first and last respectively).
        // Every interior index i (1 <= i <= n-2) belongs to min(i+1, k, n-k) >= 2 windows
        // (at least 2 when 1 < k < n), so an element at an interior index always appears
        // in more than one subarray if k > 1 and k < n.
        // Therefore only elements at index 0 or index n-1 can qualify.
        int best = -1;
        if (freq[nums[0]]     == 1) best = max(best, nums[0]);
        if (freq[nums[n - 1]] == 1) best = max(best, nums[n - 1]);

        return best;
    }
};
