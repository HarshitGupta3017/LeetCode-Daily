// Solution for Reordered Power of 2 in JAVA

class Solution {
    private int getDigitSignature(int num) {
        int sig = 0;
        while (num > 0) {
            sig += Math.pow(10, num % 10);
            num /= 10;
        }
        return sig;
    }

    public boolean reorderedPowerOf2(int n) {
        int sig = getDigitSignature(n);
        for (int p = 0; p < 30; p++) {
            if (sig == getDigitSignature(1 << p)) return true;
        }
        return false;
    }
}
