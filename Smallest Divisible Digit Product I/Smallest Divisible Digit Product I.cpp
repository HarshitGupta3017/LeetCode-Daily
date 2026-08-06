// Solution for Smallest Divisible Digit Product I in CPP

class Solution {
public:
    int digitProduct(int n) {
        int product = 1;
        while (n > 0) {
            product *= n % 10;
            n /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        // Scan upward from n until we find a number whose digit product is
        // divisible by t. The answer is guaranteed to exist within a small
        // window — at most 50 steps — because we can always append a digit
        // that supplies the missing factor.
        for (int candidate = n; ; candidate++) {
            if (digitProduct(candidate) % t == 0)
                return candidate;
        }
    }
};
