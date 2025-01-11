class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) freq[s[i]]++;
        int oddCount = 0;
        for (const auto& it: freq) {
            if (it.second % 2 != 0) oddCount++;
        }
        return oddCount <= k;
    }
};
