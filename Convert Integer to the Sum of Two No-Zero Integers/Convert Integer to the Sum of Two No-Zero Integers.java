// Solution for Convert Integer to the Sum of Two No-Zero Integers in JAVA

class Solution {
    public int[] getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (!(String.valueOf(a) + String.valueOf(b)).contains("0")) {
                return new int[]{a, b};
            }
        }
        return new int[0];
    }
}
