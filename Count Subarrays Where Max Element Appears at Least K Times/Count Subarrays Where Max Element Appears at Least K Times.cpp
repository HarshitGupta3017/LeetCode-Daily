// Solution for Count Subarrays Where Max Element Appears at Least K Times in CPP

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        long long res = 0;
        int mx = *max_element(nums.begin(), nums.end());
        int count = 0;
        while (j < n) {
            if (nums[j] == mx) count++;
            while (count >= k) {
                res += (n - j);
                if (nums[i] == mx) count--;
                i++;
            }
            j++;
        }
        return res;
    }
};
