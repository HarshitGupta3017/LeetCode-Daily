// Solution for Length of Longest Subarray With at Most K Frequency in CPP

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_map<int, int> freq;

        while (right < n) {
            freq[nums[right]]++;

            // If adding nums[right] pushed its frequency over k, shrink the window
            // from the left until the frequency is back within the allowed limit.
            // We only need to shrink when nums[right] is the violating element —
            // all other elements in the window are already within their limits.
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
