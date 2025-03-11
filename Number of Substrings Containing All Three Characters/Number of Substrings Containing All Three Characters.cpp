// Solution for Number of Substrings Containing All Three Characters in CPP

class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0, res = 0;
        int n = s.length();
        unordered_map<char, int> mp;
        while (j < n) {
            mp[s[j]]++;
            while (mp.size() == 3) {
                res += n - j;
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};
