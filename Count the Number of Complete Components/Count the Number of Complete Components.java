// Solution for Count the Number of Complete Components in JAVA

class Solution {

    private void dfs(int i, Map<Integer, List<Integer>> adj, boolean[] vis, int[] count) {
        vis[i] = true;
        count[0]++;
        count[1] += adj.getOrDefault(i, new ArrayList<>()).size();
        for (int ngbr: adj.getOrDefault(i, new ArrayList<>())) {
            if (!vis[ngbr]) {
                dfs(ngbr, adj, vis, count);
            }
        }
    }

    public int countCompleteComponents(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int res = 0;
        for (int[] edge: edges) {
            int u = edge[0], v = edge[1];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int[] count = new int[2];
            dfs(i, adj, vis, count);
            int v = count[0], e = count[1];
            if ((v * (v - 1)) == e) res++;
        }
        return res;
    }
}
