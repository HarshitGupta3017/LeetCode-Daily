class Solution {
public:
    int maxScore(string s) {
        int res = 0;
        int zeroes = 0, ones = count(s.begin(), s.end(), '1');
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') ones -= 1;
            else zeroes += 1;
            res = max(res, zeroes + ones);
        }
        return res;
    }
};
