// Solution for Alice and Bob Playing Flower Game in CPP

class Solution {
public:
    long long flowerGame(int n, int m) {
        // Alice wins iff x + y is odd.
        // Exactly half of all (x, y) pairs satisfy this.
        return 1LL * n * m / 2;
    }
};
