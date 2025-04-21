// Solution for Count the Hidden Sequences in JAVA

class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        int curr = 0, mn = 0, mx = 0;
        for (int d: differences) {
            curr += d;
            mn = Math.min(mn, curr);
            mx = Math.max(mx, curr);
            if ((upper - mx) - (lower - mn) + 1 <= 0) return 0;
        }
        return (upper - mx) - (lower - mn) + 1;
    }
}
