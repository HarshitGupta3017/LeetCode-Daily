class Solution {
public:

    bool check(stack<char>& st, string& part, int n) {
        stack<char> tempSt = st;
        for (int i = n - 1; i >= 0; i--) {
            if (tempSt.top() != part[i]) return false;
            tempSt.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        stack<char> st;
        int m = s.size(), n = part.size();
        for (int i = 0; i < m; i++) {
            st.push(s[i]);
            if (st.size() >= n && check(st, part, n) == true) {
                for (int j = 0; j < n; j++) st.pop();
            }
        } 
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
