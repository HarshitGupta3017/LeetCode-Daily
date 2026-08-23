// Solution for Sum Game in JAVA

class Solution {
    public boolean sumGame(String num) {
        int n = num.length(), h = n / 2;
        int ls = 0, rs = 0, lw = 0, rw = 0;

        for (int i = 0; i < n; i++) {
            if (num.charAt(i) == '?') {
                if (i < h) lw++; else rw++;
            } else {
                if (i < h) ls += num.charAt(i) - '0';
                else rs += num.charAt(i) - '0';
            }
        }

        if ((lw + rw) % 2 != 0) return true;
        return 2 * (ls - rs) + 9 * (lw - rw) != 0;
    }
};
