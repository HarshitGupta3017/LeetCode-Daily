// Solution for Minimum Cost Walk in Weighted Graph in JAVA

class Solution {

    int[] parent;
    
    private int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    private void Union(int x, int y) {
        parent[y] = x;
    }

    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        parent = new int[n];
        int[] cost = new int[n];
        Arrays.fill(cost, -1);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (int[] edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int parent_u = find(u), parent_v = find(v);
            if (parent_u != parent_v) {
                Union(parent_u, parent_v);
                cost[parent_u] &= cost[parent_v];
            }
            cost[parent_u] &= w;
        }
        int q = query.length;
        int[] res = new int[q];
        for (int i = 0; i < q; i++) {
            int s = query[i][0], d = query[i][1];
            int parent_s = find(s), parent_d = find(d);
            if (s == d) res[i] = 0;
            else if (parent_s == parent_d) res[i] = cost[parent_s];
            else res[i] = -1;
        }
        return res; 
    }
}
