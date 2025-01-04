class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<char> letters(s.begin(), s.end());
        int res = 0;
        for (const char& letter: letters) {
            int leftIdx = -1, rightIdx = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (leftIdx == -1) leftIdx = i;
                    rightIdx = i;
                }
            }
            unordered_set<char> st;
            for (int i = leftIdx + 1; i <= rightIdx - 1; i++) {
                st.insert(s[i]);
            }
            res += st.size();
        }
        return res;
    }
};
