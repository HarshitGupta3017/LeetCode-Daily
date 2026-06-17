// Solution for Process String with Special Operations II in JAVA

class Solution {
    public char processStr(String s, long k) {
        long len = 0;

        for (char c : s.toCharArray()) {
            if (c == '*') {
                if (len > 0) len--;
            } else if (c == '#') {
                len *= 2;
            } else if (c != '%') {
                len++;
            }
        }

        if (k >= len) return '.';

        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);

            if (c == '*') len++;
            else if (c == '%') k = len - k - 1;
            else if (c == '#') {
                len /= 2;
                if (k >= len) k -= len;
            } else {
                len--;
                if (k == len) return c;
            }
        }
        return '.';
    }
}
