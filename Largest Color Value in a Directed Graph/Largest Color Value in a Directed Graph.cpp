// Solution for Largest Color Value in a Directed Graph in CPP

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        // Adjacency list to represent the graph
        unordered_map<int, vector<int>> adj;

        // Indegree array to track nodes with no incoming edges
        vector<int> indegree(n, 0);

        // Build the graph and fill indegree info
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Each node keeps track of the frequency of each color (26 letters)
        vector<vector<int>> colorFreq(n, vector<int>(26, 0));
        queue<int> bfsQueue;

        // Initialize nodes with indegree 0
        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                bfsQueue.push(node);
                colorFreq[node][colors[node] - 'a'] = 1;
            }
        }

        int maxColorCount = 0;
        int visitedNodes = 0;

        // Standard BFS topological sort
        while (!bfsQueue.empty()) {
            int current = bfsQueue.front();
            bfsQueue.pop();
            visitedNodes++;

            // Update the answer with the max frequency for the current node's color
            maxColorCount = max(maxColorCount, colorFreq[current][colors[current] - 'a']);

            for (int neighbor : adj[current]) {
                for (int c = 0; c < 26; c++) {
                    // Propagate max color frequencies to the neighbor
                    colorFreq[neighbor][c] = max(
                        colorFreq[neighbor][c],
                        colorFreq[current][c] + (colors[neighbor] - 'a' == c)
                    );
                }

                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    bfsQueue.push(neighbor);
                }
            }
        }

        // If not all nodes were visited, a cycle exists
        return visitedNodes == n ? maxColorCount : -1;
    }
};
