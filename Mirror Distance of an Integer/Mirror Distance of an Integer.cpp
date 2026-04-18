// Solution for Mirror Distance of an Integer in CPP

class Solution {
public:
    int mirrorDistance(int n) {
        auto getReverse = [](int x){
            int rev = 0;
            while (x > 0) {
                rev = (rev * 10) + (x % 10);
                x /= 10;
            };
            return rev;
        };
        
        return abs(n - getReverse(n));
    }
};
