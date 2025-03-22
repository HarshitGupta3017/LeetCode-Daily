// Solution for Count the Number of Complete Components in CPP

class Solution {
public:

    void dfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& vis, int& v, int& e) {
        vis[i] = true;
        v++;
        e += adj[i].size();
        for (const int& ngbr: adj[i]) {
            if (!vis[ngbr]) {
                dfs(ngbr, adj, vis, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int res = 0;
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            int v = 0, e = 0;
            dfs(i, adj, vis, v, e);
            if ((v * (v - 1)) == e) res++;
        }
        return res;
    }
};
