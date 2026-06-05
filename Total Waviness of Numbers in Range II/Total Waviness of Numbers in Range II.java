// Solution for Total Waviness of Numbers in Range II in JAVA

class Solution {
    String s;
    long[][][] cnt = new long[16][10][10];
    long[][][] wav = new long[16][10][10];

    long[] dfs(int i, int pp, int p, boolean lim, boolean lead) {
        if (i == s.length()) return new long[]{1, 0};

        if (!lim && !lead && pp >= 0 && p >= 0 && cnt[i][pp][p] != -1)
            return new long[]{cnt[i][pp][p], wav[i][pp][p]};

        long c = 0, w = 0;
        int up = lim ? s.charAt(i) - '0' : 9;

        for (int d = 0; d <= up; d++) {
            boolean nl = lead && d == 0;
            long[] r = dfs(i + 1, p, nl ? -1 : d, lim && d == up, nl);

            if (!nl && pp >= 0 && p >= 0 &&
                ((pp < p && p > d) || (pp > p && p < d)))
                w += r[0];

            c += r[0];
            w += r[1];
        }

        if (!lim && !lead && pp >= 0 && p >= 0) {
            cnt[i][pp][p] = c;
            wav[i][pp][p] = w;
        }
        return new long[]{c, w};
    }

    long f(long x) {
        if (x < 100) return 0;
        for (long[][] a : cnt) for (long[] b : a) java.util.Arrays.fill(b, -1);
        for (long[][] a : wav) for (long[] b : a) java.util.Arrays.fill(b, -1);
        s = String.valueOf(x);
        return dfs(0, -1, -1, true, true)[1];
    }

    public long totalWaviness(long num1, long num2) {
        return f(num2) - f(num1 - 1);
    }
}
