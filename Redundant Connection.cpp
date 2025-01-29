class Solution {
public:

    bool bfs(unordered_map<int, vector<int>>& adj, int u, int v, int n) {
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = true;
            if (node == v) return true;
            for(const auto& ngr: adj[node]) {
                if (!vis[ngr]) q.push(ngr);
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            if (adj.find(u) != adj.end() && adj.find(v) != adj.end() && bfs(adj, u, v, n)) {
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
