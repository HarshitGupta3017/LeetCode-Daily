class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n, 0);
        // finding difference array
        for (const auto& q: shifts) {
            int L = q[0], R = q[1];
            int x = (q[2] == 0) ? -1 : 1;
            diff[L] += x;
            if (R + 1 < n) diff[R + 1] -= x;
        }
        // cumulative sum
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        // applying shifts
        for (int i = 0; i < n; i++) {
            // checking the limit within 26 
            int shift = diff[i] % 26;
            if (shift < 0) shift += 26;
            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }
        return s;
    }
};
