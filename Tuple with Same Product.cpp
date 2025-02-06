class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prod = nums[i] * nums[j];
                if (mp.find(prod) != mp.end()) {
                    res += mp[prod] * 8;
                }
                mp[prod]++;
            }
        } 
        return res;
    }
};
