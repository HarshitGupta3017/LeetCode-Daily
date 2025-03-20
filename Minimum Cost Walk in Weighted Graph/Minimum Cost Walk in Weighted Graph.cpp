// Solution for Minimum Cost Walk in Weighted Graph in CPP

class Solution {
public:
    vector<int> parent;

    int find(int x) {
        return (parent[x] == x) ? x : parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        parent[y] = x;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n, -1);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (const auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int parent_u = find(u), parent_v = find(v);
            if (parent_u != parent_v) {
                Union(parent_u, parent_v);
                cost[parent_u] &= cost[parent_v];
            }
            cost[parent_u] &= w;
        }
        vector<int> res;
        for (const auto& q: query) {
            int s = q[0], d = q[1];
            int parent_s = find(s), parent_d = find(d);
            if (s == d) res.push_back(0);
            else if (parent_s == parent_d) res.push_back(cost[parent_s]);
            else res.push_back(-1);
        }
        return res; 
    }   
};
