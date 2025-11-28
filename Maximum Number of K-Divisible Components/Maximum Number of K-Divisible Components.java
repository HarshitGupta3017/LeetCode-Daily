// Solution for Maximum Number of K-Divisible Components in JAVA

class Solution {

    // DFS function to compute subtree sums modulo k and count divisible components
    private int dfs(
        int node,
        int parent,
        Map<Integer, List<Integer>> graph,
        int[] values,
        int k,
        int[] componentCount
    ) {
        // Start with the current node's value
        int subtreeSumModK = values[node] % k;

        // Explore all neighbors (children in the DFS tree)
        for (int neighbor : graph.get(node)) {
            if (neighbor == parent) continue;  // Skip the parent

            // Recursively compute child subtree sum
            int childSumModK = dfs(neighbor, node, graph, values, k, componentCount);

            // Add child's sum to current subtree sum
            subtreeSumModK = (subtreeSumModK + childSumModK) % k;
        }

        // If subtree sum is divisible by k, it forms a valid component
        if (subtreeSumModK == 0) {
            componentCount[0]++;
        }

        // Return subtree sum modulo k
        return subtreeSumModK;
    }

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {

        // Build adjacency list
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.put(i, new ArrayList<>());
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        // Use array for componentCount so it can be mutable inside DFS
        int[] componentCount = new int[1];

        // Start DFS from root node 0
        dfs(0, -1, graph, values, k, componentCount);

        return componentCount[0];
    }
}
