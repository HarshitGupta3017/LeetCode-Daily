// Solution for Maximize the Number of Target Nodes After Connecting Trees I in CPP

class Solution {
public:

    // Perform BFS from a given node to count all nodes within distance `maxDist`
    int BFS(int startNode, unordered_map<int, vector<int>>& adj, int maxDist, int totalNodes) {
        queue<pair<int, int>> q;  // Pair of (currentNode, currentDistance)
        q.push({startNode, 0});

        vector<bool> visited(totalNodes, false);
        visited[startNode] = true;

        int reachableNodesCount = 0;

        while (!q.empty()) {
            auto [currNode, dist] = q.front();
            q.pop();

            // If the distance exceeds max allowed, skip further processing
            if (dist > maxDist) continue;

            reachableNodesCount++;

            for (const auto& neighbor : adj[currNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1});
                }
            }
        }

        return reachableNodesCount;
    }

    // For each node in the tree, calculate how many nodes are within `maxDist`
    vector<int> computeTargetNodesPerNode(vector<vector<int>>& edges, int maxDist) {
        int totalNodes = edges.size() + 1;
        unordered_map<int, vector<int>> adj;

        // Construct the adjacency list
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> nodeTargetCounts(totalNodes);

        // For every node, compute how many nodes are reachable within maxDist
        for (int i = 0; i < totalNodes; i++) {
            nodeTargetCounts[i] = BFS(i, adj, maxDist, totalNodes);
        }

        return nodeTargetCounts;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // For each node in Tree1, count target nodes within distance k
        vector<int> targetsFromTree1 = computeTargetNodesPerNode(edges1, k);

        // For each node in Tree2, count target nodes within distance k - 1
        vector<int> targetsFromTree2 = computeTargetNodesPerNode(edges2, k - 1);

        // Find the max target count from any node in Tree2
        int maxTargetsInTree2 = *max_element(targetsFromTree2.begin(), targetsFromTree2.end());

        // Combine results: for each node in Tree1, add the max reachable nodes from Tree2
        for (int i = 0; i < targetsFromTree1.size(); i++) {
            targetsFromTree1[i] += maxTargetsInTree2;
        }

        return targetsFromTree1;
    }
};
