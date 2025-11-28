class Solution {
public:

    // DFS function to compute subtree sums modulo k and count divisible components
    int dfs(int node, 
            int parent, 
            unordered_map<int, vector<int>>& graph, 
            vector<int>& values, 
            int k, 
            int& componentCount) 
    {
        // Start with the current node's value
        int subtreeSumModK = values[node] % k;

        // Explore all neighbors (children in the DFS tree)
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;   // Avoid revisiting the parent

            // Recursively compute child's subtree sum
            int childSumModK = dfs(neighbor, node, graph, values, k, componentCount);

            // Add child subtree sum to current subtree sum
            subtreeSumModK = (subtreeSumModK + childSumModK) % k;
        }

        // If the current subtree sum is divisible by k, it forms a valid component
        if (subtreeSumModK == 0) {
            componentCount++;
        }

        // Return subtree sum modulo k to parent
        return subtreeSumModK;
    }

    // Main function required by the problem
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        // Build adjacency list for the tree
        unordered_map<int, vector<int>> graph;
        graph.reserve(n); // Optimization: reduce rehashing

        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int componentCount = 0;

        // Run DFS from node 0 (tree root)
        dfs(0, -1, graph, values, k, componentCount);

        return componentCount;
    }
};
