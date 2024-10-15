class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        int ones = 0;
        for (char c: s) {
            if (c == '1') ones++;
            else count += ones;
        }
        return count;
    }
};
