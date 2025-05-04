// Solution for Number of Equivalent Domino Pairs in CPP

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mp;
        int res = 0;
        for (const auto& d: dominoes) {
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            res += mp[key];
            mp[key]++;
        }
        return res;
    }
};
