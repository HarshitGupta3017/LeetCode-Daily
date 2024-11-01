class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        for (const char& ch: s) {
            int n = res.size();
            if (n < 2 || !(res[n-1] == ch && res[n-2] == ch)) res += ch;
        }
        return res;
    }
};
