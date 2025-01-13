class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freq;
        int res = 0;
        for (const auto& ch: s) {
            freq[ch]++;
        }
        for (const auto& it: freq) {
            res += (it.second % 2 == 0) ? 2 : 1; 
        }
        return res;
    }
};
