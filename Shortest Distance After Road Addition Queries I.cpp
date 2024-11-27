class Solution {
public:

    int BFS(int n, unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(0);
        vis[0] = true;
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1) return level;
                for (const auto& nbr: adj[curr]) {
                    if (!vis[nbr]) {
                        q.push(nbr);
                        vis[nbr] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // simple BFS question
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i <= n - 2; i++) {
            adj[i].push_back(i + 1);
        }
        vector<int> res;
        for (const auto& query: queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back(v);
            int ans = BFS(n, adj);
            res.push_back(ans);
        }
        return res;
    }
};
