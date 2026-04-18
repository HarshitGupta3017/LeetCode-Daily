// Solution for Mirror Distance of an Integer in JAVA

class Solution {
    public int mirrorDistance(int n) {
        return Math.abs(n - getReverse(n));
    }
    
    private int getReverse(int x) {
        int rev = 0;
        while (x > 0) {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        };
        return rev;
    };
}
