// Solution for Power of Four in CPP

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        double x = log10(n) / log10(4);
        return x == (int) x;
    }
};
