class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        // for getting a number through which if we do binary AND operation we get x
        // we need to do binary OR of a number with x to get that unique number
        for (int i = 1; i < n; i++) {
            res = (res + 1) | x;
        }
        return res;
    }
};
