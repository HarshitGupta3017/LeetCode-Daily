class Solution {
public:

    bool isBipartite(unordered_map<int, vector<int>>& adj, int curr, vector<int>& colors, int currColor) {
        colors[curr] = currColor;
        for (const auto& v: adj[curr]) {
            if (colors[v] == colors[curr]) return false;
            if (colors[v] == -1) {
                if (isBipartite(adj, v, colors, 1 - currColor) == false) return false;
            }
        }
        return true;
    }

    int bfs(unordered_map<int, vector<int>>& adj, int node, int n) {
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(node);
        vis[node] = true;
        int levels = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front();
                q.pop();
                for (const auto& ngbr: adj[curr]) {
                    if (!vis[ngbr]) {
                        vis[ngbr] = true;
                        q.push(ngbr);
                    }
                }
            }
            levels++;
        }
        return levels - 1;
    }

    int getMaxFromEachComp(unordered_map<int, vector<int>>& adj, int node, vector<bool>& vis, vector<int>& levels) {
        vis[node] = true;
        int maxGrp = levels[node];
        for (const auto& ngbr: adj[node]) {
            if (!vis[ngbr]) {
                maxGrp = max(maxGrp, getMaxFromEachComp(adj, ngbr, vis, levels));
            }
        }
        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (const auto& edge: edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] == -1) {
                if (isBipartite(adj, node, colors, 1) == false) return -1;
            }
        }
        vector<int> levels(n, 0);
        for (int node = 0; node < n; node++) {
            levels[node] = bfs(adj, node, n);
        }
        int res = 0;
        vector<bool> vis(n, false);
        for (int node = 0; node < n; node++) {
            if (!vis[node]) {
                res += getMaxFromEachComp(adj, node, vis, levels);
            }
        }
        return res;
    }
};
