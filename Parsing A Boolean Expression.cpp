class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (const char& ch: expression) {
            if (ch == ')') {
                bool hast = false, hasf = false;
                while (st.top() != '(') {
                    char val = st.top();
                    st.pop();
                    if (val == 'f') hasf = true;
                    if (val == 't') hast = true;
                }
                st.pop();
                char op = st.top();
                st.pop();
                if (op == '&') {
                    st.push(hasf ? 'f' : 't');
                } else if (op == '|') {
                    st.push(hast ? 't' : 'f');
                } else {
                    st.push(hasf ? 't' : 'f');
                }
            } else if (ch != ',') {
                st.push(ch);
            }
        }
        return st.top() == 't';
    }
};
