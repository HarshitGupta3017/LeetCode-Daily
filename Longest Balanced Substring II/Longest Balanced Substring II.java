// Solution for Longest Balanced Substring II in JAVA

class Solution {

    // Pair class for Case-3
    static class Pair {
        int d1, d2;

        Pair(int d1, int d2) {
            this.d1 = d1;
            this.d2 = d2;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return d1 == p.d1 && d2 == p.d2;
        }

        @Override
        public int hashCode() {
            return 31 * d1 + d2;  // faster than Objects.hash()
        }
    }

    public int longestBalanced(String s) {

        char[] c = s.toCharArray();
        int n = c.length;

        int res = 0;

        /*
        -----------------
        Case 1: One char
        -----------------
        */
        int cur = 1;

        for (int i = 1; i < n; i++) {
            if (c[i] == c[i - 1]) {
                cur++;
            } else {
                res = Math.max(res, cur);
                cur = 1;
            }
        }
        res = Math.max(res, cur);

        /*
        -----------------
        Case 2: Two chars
        -----------------
        */
        res = Math.max(res, find2(c, 'a', 'b'));
        res = Math.max(res, find2(c, 'a', 'c'));
        res = Math.max(res, find2(c, 'b', 'c'));

        /*
        -----------------
        Case 3: Three chars
        -----------------
        */
        int ca = 0, cb = 0, cc = 0;

        Map<Pair, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {

            if (c[i] == 'a') ca++;
            else if (c[i] == 'b') cb++;
            else cc++;

            if (ca == cb && ca == cc)
                res = Math.max(res, ca + cb + cc);

            Pair key = new Pair(ca - cb, ca - cc);

            Integer prev = mp.get(key);
            if (prev != null) {
                res = Math.max(res, i - prev);
            } else {
                mp.put(key, i);
            }
        }

        return res;
    }

    // Optimized two-character balanced substring
    private int find2(char[] c, char x, char y) {

        int n = c.length;
        int maxLen = 0;

        int[] first = new int[2 * n + 1];
        Arrays.fill(first, -2);

        int clearIdx = -1;
        int diff = n;  // shifted index

        first[diff] = -1;

        for (int i = 0; i < n; i++) {

            if (c[i] != x && c[i] != y) {

                clearIdx = i;
                diff = n;
                first[diff] = clearIdx;

            } else {

                if (c[i] == x) diff++;
                else diff--;

                if (first[diff] < clearIdx) {
                    first[diff] = i;
                } else {
                    maxLen = Math.max(maxLen, i - first[diff]);
                }
            }
        }

        return maxLen;
    }
}
