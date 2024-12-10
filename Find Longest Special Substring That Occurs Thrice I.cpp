class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> grid(26, vector<int>(n + 1, 0));
        int res = -1, len = 0;
        char prev_ch = s[0];
        for (int i = 0; i < n; i++) {
            if (s[i] == prev_ch) {
                len++;
            } else {
                len = 1;
                prev_ch = s[i];
            }
            grid[s[i] - 'a'][len]++;
        }
        // traversing in grid for finding longest special substring 
        for (int i = 0; i < 26; i++) {
            int freq = 0;
            for (int j = n; j >= 1; j--) {
                freq += grid[i][j];
                if (freq >= 3) {
                    res = max(res, j);
                    break;
                }
            }
        }
        return res;
    }
};
