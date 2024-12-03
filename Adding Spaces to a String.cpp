class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // simple question
        // we can iterate in string s and if at a point index equals to spaces index we can add space to it
        string res;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            // take care of out of bound too
            if (j < spaces.size() && i == spaces[j]) {
                res += " ";
                j++;
            }
            res += s[i];
        }
        return res;
    }
};
