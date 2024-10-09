class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0, res = 0;
        for (char c: s) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) {
                res++;
                balance = 0;
            }
        }
        return res + balance;
    }
};
