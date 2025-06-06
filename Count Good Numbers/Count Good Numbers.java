// Solution for Count Good Numbers in JAVA

class Solution {

    private static final int M = 1_000_000_007;
    private long findPower(long a, long b) {
        if (b == 0) return 1;
        long half = findPower(a, b / 2);
        long result = (half * half) % M;
        if (b % 2 == 1) {
            result = (result * a) % M;
        }
        return result;
    }

    public int countGoodNumbers(long n) {
        return (int)((findPower(5, (n + 1) / 2) * findPower(4, n / 2)) % M);
    }
}
