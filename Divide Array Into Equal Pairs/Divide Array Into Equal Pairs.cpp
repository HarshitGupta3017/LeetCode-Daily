// Solution for Divide Array Into Equal Pairs in CPP

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (const auto& num: nums) mp[num]++;
        for (const auto& it: mp) {
            if (it.second % 2 != 0) return false;
        }
        return true;
    }
};
