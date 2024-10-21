class Solution {
public:

    int backtrack(string s, int idx, unordered_set<string>& st) {
        if (idx == s.size()) return st.size();
        int count = 0;
        for (int j = idx + 1; j <= s.size(); j++) {
            string sub = s.substr(idx, j - idx);
            if (st.find(sub) == st.end()) {
                st.insert(sub);
                count = max(count, backtrack(s, j, st));
                st.erase(sub);
            }
        }
        return count;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return backtrack(s, 0, st);
    }
};
