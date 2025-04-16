// Solution for Count the Number of Good Subarrays in CPP

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        long long res = 0, pairs = 0;
        unordered_map<int, int> mp;
        while (j < n) {
            pairs += mp[nums[j]];
            mp[nums[j]]++;
            while (pairs >= k) {
                res += n - j;
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }
        return res;
    }
};
