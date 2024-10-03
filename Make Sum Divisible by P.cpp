class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int tsum = 0;
        for (int& num: nums) tsum = (tsum + num) % p;
        int rem = tsum % p;
        if (rem == 0) return 0;
        unordered_map<int, int> mp;
        int curr = 0;
        mp[0] = -1;
        int res = n;
        for (int i = 0; i < n; i++) {
            curr = (curr + nums[i]) % p;
            int pre = (curr - rem + p) % p;
            if (mp.find(pre) != mp.end()) {
                res = min(res, i - mp[pre]);
            }
            mp[curr] = i;
        }
        return res == n ? -1 : res; 
    }
};
