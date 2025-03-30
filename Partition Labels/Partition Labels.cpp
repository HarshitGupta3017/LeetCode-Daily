// Solution for Partition Labels in CPP

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> mp(26, -1);
        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a'] = i;
        }
        int i = 0, start = 0, end = 0;
        vector<int> result;
        while (i < n) {
            end = max(end, mp[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
            i++;
        }
        return result;
    }
};
