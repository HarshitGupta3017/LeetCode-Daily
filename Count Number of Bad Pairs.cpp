class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result = 0;
        unordered_map<int, int> mp;
        mp[nums[0]] = 1;
        for (int i = 1; i < nums.size(); i++) {
            result += i - mp[nums[i] - i]++;
        }
        return result;
    }
};
