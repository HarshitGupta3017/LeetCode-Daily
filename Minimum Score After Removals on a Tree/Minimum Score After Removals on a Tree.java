// Solution for Minimum Score After Removals on a Tree in JAVA

class Solution {
    int timer;

    void dfs(int node, int parent, int[] subTreeXOR, int[] inTime, int[] outTime, Map<Integer, List<Integer>> adj, int[] nums) {
        subTreeXOR[node] = nums[node];
        inTime[node] = timer++;

        for (int ngbr : adj.getOrDefault(node, new ArrayList<>())) {
            if (ngbr != parent) {
                dfs(ngbr, node, subTreeXOR, inTime, outTime, adj, nums);
                subTreeXOR[node] ^= subTreeXOR[ngbr];
            }
        }

        outTime[node] = timer++;
    }

    boolean isAncestor(int u, int v, int[] inTime, int[] outTime) {
        return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
    }

    int getScore(int a, int b, int c) {
        int maxXor = Math.max(a, Math.max(b, c));
        int minXor = Math.min(a, Math.min(b, c));
        return maxXor - minXor;
    }

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj.computeIfAbsent(u, x -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, x -> new ArrayList<>()).add(u);
        }

        int[] subTreeXOR = new int[n];
        int[] inTime = new int[n];
        int[] outTime = new int[n];
        timer = 0;

        dfs(0, -1, subTreeXOR, inTime, outTime, adj, nums);

        int result = Integer.MAX_VALUE;

        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int xor1, xor2, xor3;

                if (isAncestor(u, v, inTime, outTime)) {
                    xor1 = subTreeXOR[v];
                    xor2 = subTreeXOR[u] ^ subTreeXOR[v];
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2;
                } else if (isAncestor(v, u, inTime, outTime)) {
                    xor1 = subTreeXOR[u];
                    xor2 = subTreeXOR[v] ^ subTreeXOR[u];
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2;
                } else {
                    xor1 = subTreeXOR[u];
                    xor2 = subTreeXOR[v];
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2;
                }

                result = Math.min(result, getScore(xor1, xor2, xor3));
            }
        }

        return result;
    }
}
