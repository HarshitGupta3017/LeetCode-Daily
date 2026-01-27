// Solution for Minimum Cost Path with Edge Reversals in CPP

class Solution {
public:

    using pii = pair<int, int>; // pair<distance, node>

    int minCost(int n, vector<vector<int>>& edges) {

        // Build adjacency list
        // Key insight:
        // - For normal edges u -> v with weight w, we just add as usual.
        // - For the "switch reversal" option, for each u -> v edge, 
        //   we can use a switch at node v to go v -> u with cost 2*w. 
        //   So we simulate that by also adding v -> u with 2*w.
        unordered_map<int, vector<pii>> adj;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Normal forward edge
            adj[u].push_back({v, w});

            // Potential "switch-reversed" edge from v -> u with double cost
            adj[v].push_back({u, 2 * w});
        }

        // Dijkstra's algorithm setup
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        vector<int> minDist(n, INT_MAX);  // Stores minimum cost to reach each node

        // Start at node 0
        minHeap.push({0, 0});
        minDist[0] = 0;

        while (!minHeap.empty()) {

            auto [currCost, currNode] = minHeap.top();
            minHeap.pop();

            // Early stopping: if we reached the target node n-1, return cost
            if (currNode == n - 1) return currCost;

            // Explore all neighbors
            for (const auto& [neighbor, edgeCost] : adj[currNode]) {

                int newCost = currCost + edgeCost;

                // If taking this edge improves the distance to neighbor, update
                if (newCost < minDist[neighbor]) {
                    minDist[neighbor] = newCost;
                    minHeap.push({newCost, neighbor});
                }
            }
        }

        // If n-1 is unreachable
        return -1;
    }
};
