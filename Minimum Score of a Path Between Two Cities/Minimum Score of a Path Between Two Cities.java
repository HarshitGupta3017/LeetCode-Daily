// Solution for Minimum Score of a Path Between Two Cities in JAVA

class Solution {
    int ans = Integer.MAX_VALUE;

    void dfs(int u, List<int[]>[] g, boolean[] vis) {
        vis[u] = true;
        for (int[] e : g[u]) {
            ans = Math.min(ans, e[1]);
            if (!vis[e[0]]) dfs(e[0], g, vis);
        }
    }

    public int minScore(int n, int[][] roads) {
        List<int[]>[] g = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) g[i] = new ArrayList<>();
        for (int[] r : roads) {
            g[r[0]].add(new int[]{r[1], r[2]});
            g[r[1]].add(new int[]{r[0], r[2]});
        }
        dfs(1, g, new boolean[n + 1]);
        return ans;
    }
}
