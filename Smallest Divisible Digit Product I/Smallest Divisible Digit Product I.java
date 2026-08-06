// Solution for Smallest Divisible Digit Product I in JAVA

class Solution {
    public int digitProduct(int n) {
        int product = 1;
        while (n > 0) {
            product *= (n % 10);
            n /= 10;
        }
        return product;
    }

    public int smallestNumber(int n, int t) {
        for (int candidate = n; ; candidate++) {
            if (digitProduct(candidate) % t == 0) {
                return candidate;
            }
        }
    }
}
