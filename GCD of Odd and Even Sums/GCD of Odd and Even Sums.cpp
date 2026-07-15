// Solution for GCD of Odd and Even Sums in CPP

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // The smallest n positive odd numbers are 1, 3, 5, ..., (2n-1).
        // Their sum is n² (sum of first n odd numbers is always a perfect square).
        //
        // The smallest n positive even numbers are 2, 4, 6, ..., 2n.
        // Their sum is n(n+1) (= 2 + 4 + ... + 2n = 2 * n(n+1)/2).
        //
        // gcd(n², n(n+1)) = n * gcd(n, n+1)
        //                 = n * 1          [consecutive integers are always coprime]
        //                 = n
        return n;
    }
};
