// Solution for Solving Questions With Brainpower in JAVA

class Solution {

    private long solve(int i, int[][] q, long[] t, int n) {
        if (i >= n) return 0;
        if (t[i] != -1) return t[i];
        long taken = q[i][0] + solve(i + q[i][1] + 1, q, t, n);
        long not_taken = solve(i + 1, q, t, n);
        return t[i] = Math.max(taken, not_taken);
    }

    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] t = new long[n + 1];
        Arrays.fill(t, -1);
        return solve(0, questions, t, n);
    }
}
