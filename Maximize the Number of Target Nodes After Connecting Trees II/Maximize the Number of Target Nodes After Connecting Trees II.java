// Solution for Maximize the Number of Target Nodes After Connecting Trees II in JAVA

class Solution {
    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        int N = edges1.length + 1;
        int M = edges2.length + 1;

        Map<Integer, List<Integer>> adj1 = new HashMap<>();
        Map<Integer, List<Integer>> adj2 = new HashMap<>();

        for (int[] edge : edges1) {
            int u = edge[0], v = edge[1];
            adj1.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj1.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        for (int[] edge : edges2) {
            int u = edge[0], v = edge[1];
            adj2.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj2.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        int[] mark1 = new int[N];
        Arrays.fill(mark1, -1);
        mark1[0] = 0;

        int[] count1 = new int[2];
        dfs(0, -1, adj1, mark1, count1);

        int[] mark2 = new int[M];
        Arrays.fill(mark2, -1);
        mark2[0] = 0;

        int[] count2 = new int[2];
        dfs(0, -1, adj2, mark2, count2);

        int maxFromTree2 = Math.max(count2[0], count2[1]);

        int[] result = new int[N];
        for (int i = 0; i < N; i++) {
            result[i] = count1[mark1[i]] + maxFromTree2;
        }

        return result;
    }

    private void dfs(int curr, int parent, Map<Integer, List<Integer>> adj, int[] mark, int[] count) {
        count[mark[curr]]++;

        for (int neighbor : adj.getOrDefault(curr, new ArrayList<>())) {
            if (neighbor != parent) {
                mark[neighbor] = 1 - mark[curr];
                dfs(neighbor, curr, adj, mark, count);
            }
        }
    }
}
