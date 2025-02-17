class Solution {
public:
    int count = 0;
    void solve(vector<int>& freq) {
        count++;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;
            solve(freq);
            freq[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        vector<int> freq(26, 0);
        for (const auto& ch: tiles) {
            freq[ch - 'A']++;
        }
        solve(freq);
        return count - 1;
    }
};
