// Solution for Count Complete Subarrays in an Array in CPP

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = 0, res = 0, unique_ch = st.size();
        unordered_map<int, int> mp;
        while (j < n) {
            mp[nums[j]]++;
            while (mp.size() == unique_ch) {
                res += n - j;
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};
