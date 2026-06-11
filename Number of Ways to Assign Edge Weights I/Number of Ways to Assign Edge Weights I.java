// Solution for Number of Ways to Assign Edge Weights I in JAVA

class Solution {
    private static final int MOD = 1_000_000_007;

    // Fast exponentiation: computes base^exp % MOD
    private long power(long base, long exp) {
        if (exp == 0) return 1;

        long half = power(base, exp / 2);
        long result = (half * half) % MOD;

        if ((exp & 1) == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    // Returns maximum depth (in edges) from current node
    private int getMaxDepth(Map<Integer, List<Integer>> adj, int node, int parent) {
        int maxChildDepth = 0;

        for (int neighbor : adj.getOrDefault(node, Collections.emptyList())) {
            if (neighbor == parent) continue;

            maxChildDepth = Math.max(
                maxChildDepth,
                getMaxDepth(adj, neighbor, node) + 1
            );
        }

        return maxChildDepth;
    }

    public int assignEdgeWeights(int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            adj.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            adj.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
        }

        int d = getMaxDepth(adj, 1, -1);

        return (int) power(2, d - 1);
    }
}
