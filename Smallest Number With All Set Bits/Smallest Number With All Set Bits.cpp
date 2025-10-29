// Solution for Smallest Number With All Set Bits in CPP

class Solution {
public:
    int smallestNumber(int n) {
        // Follow the pattern - 1,3,7,15,31
        int x = 1;
        while (x < n) x = x * 2 + 1;
        return x;
    }
};
