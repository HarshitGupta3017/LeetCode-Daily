// Solution for Count the Number of Powerful Integers in CPP

class Solution {
public:

    long long solve(string& str, string& suff, int limit) {
        if (str.length() < suff.length()) return 0;
        long long count = 0;
        string trailStr = str.substr(str.length() - suff.length());
        int remL = str.length() - suff.length();
        for (int i = 0; i < remL; i++) {
            int digit = str[i] - '0';
            if (digit <= limit) {
                count += digit * pow(limit + 1, remL - i - 1);
            } else {
                count += pow(limit + 1, remL - i);
                return count;
            }
        }
        if (trailStr >= suff) count += 1;
        return count;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string startStr = to_string(start - 1);
        string finishStr = to_string(finish);
        return solve(finishStr, s, limit) - solve(startStr, s, limit);
    }
};
