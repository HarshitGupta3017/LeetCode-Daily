// Solution for Minimum Score After Removals on a Tree in CPP

class Solution {
public:

    // DFS function to compute:
    // 1. subTreeXOR[node]: XOR of the entire subtree rooted at this node.
    // 2. inTime and outTime: timestamps used to identify ancestor-descendant relationships.
    void dfs(int node, int parent, vector<int>& subTreeXOR, vector<int>& inTime,
             vector<int>& outTime, int& timer, unordered_map<int, vector<int>>& adj,
             vector<int>& nums) {

        subTreeXOR[node] = nums[node]; // Start with node’s own value
        inTime[node] = timer++;        // Mark in-time when DFS enters this node

        // Visit all neighbors (DFS traversal)
        for (auto& ngbr : adj[node]) {
            if (ngbr != parent) { // Avoid going back to parent
                dfs(ngbr, node, subTreeXOR, inTime, outTime, timer, adj, nums);

                // After visiting child, include its XOR into current node's XOR
                subTreeXOR[node] ^= subTreeXOR[ngbr];
            }
        }

        outTime[node] = timer++; // Mark out-time after fully processing subtree
    }

    // Helper function to check if u is an ancestor of v using DFS timestamps
    bool isAncestor(int u, int v, vector<int>& inTime, vector<int>& outTime) {
        // v lies inside the time range of u => u is ancestor of v
        return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
    }

    // Compute score as difference between max and min among 3 xor values
    int getScore(int a, int b, int c) {
        int maxXor = max({a, b, c});
        int minXor = min({a, b, c});
        return maxXor - minXor;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        // Build adjacency list for the tree
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Arrays to hold:
        // - XOR of subtree rooted at node
        // - In-time and out-time for each node
        vector<int> subTreeXOR(n, 0);
        vector<int> inTime(n, 0);
        vector<int> outTime(n, 0);
        int timer = 0;

        // Step 1: DFS to calculate subtree XOR and timestamps
        dfs(0, -1, subTreeXOR, inTime, outTime, timer, adj, nums);

        int result = INT_MAX;

        // Step 2: Try removing every possible pair of edges
        // u and v represent the "child" side of the edge being removed
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int xor1, xor2, xor3;

                // Case 1: u is ancestor of v
                if (isAncestor(u, v, inTime, outTime)) {
                    xor1 = subTreeXOR[v];                     // Component rooted at v
                    xor2 = subTreeXOR[u] ^ subTreeXOR[v];     // Remaining part of u’s subtree
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2;       // Everything else (outside u)
                }
                // Case 2: v is ancestor of u
                else if (isAncestor(v, u, inTime, outTime)) {
                    xor1 = subTreeXOR[u];                     // Component rooted at u
                    xor2 = subTreeXOR[v] ^ subTreeXOR[u];     // Remaining part of v’s subtree
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2;       // Everything else
                }
                // Case 3: u and v are independent subtrees
                else {
                    xor1 = subTreeXOR[u];                     // Subtree u
                    xor2 = subTreeXOR[v];                     // Subtree v
                    xor3 = subTreeXOR[0] ^ xor1 ^ xor2;       // Remaining tree
                }

                // Update result with minimum score
                result = min(result, getScore(xor1, xor2, xor3));
            }
        }

        return result;
    }
};
