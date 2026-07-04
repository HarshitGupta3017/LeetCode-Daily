// Solution for Minimum Score of a Path Between Two Cities in CPP

class Solution {
public:
    // DFS through the entire connected component reachable from node u,
    // tracking the minimum edge weight seen across all traversed edges.
    // Since the path can reuse edges and revisit nodes freely, every edge
    // in the connected component containing node 1 is a candidate —
    // we just need the smallest one anywhere in that component.
    void dfs(int u, unordered_map<int, vector<pair<int,int>>>& adj,
             int& minEdge, vector<bool>& visited) {

        visited[u] = true;

        for (auto [neighbor, dist] : adj[u]) {
            // Every edge incident to u is reachable (the path can traverse it),
            // so we consider it as a candidate for the minimum regardless of
            // whether the neighbor has been visited before.
            minEdge = min(minEdge, dist);

            if (!visited[neighbor])
                dfs(neighbor, adj, minEdge, visited);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (const auto& road : roads) {
            int u = road[0], v = road[1], dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        int minEdge = INT_MAX;

        // visited is sized n+1 (1-indexed cities) to avoid off-by-one issues.
        vector<bool> visited(n + 1, false);

        // Start DFS from city 1. The problem guarantees a path from 1 to n exists,
        // so they share a connected component — the answer is the minimum edge
        // weight anywhere in that component.
        dfs(1, adj, minEdge, visited);

        return minEdge;
    }
};
