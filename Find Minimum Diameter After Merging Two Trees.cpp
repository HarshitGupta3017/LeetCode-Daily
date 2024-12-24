class Solution {
public:

    int dfs(int node, int parent, vector<vector<int>>& graph, int& dia) {
        int max1 = 0, max2 = 0;
        for (const int& ngb: graph[node]) {
            if (ngb == parent) continue;
            int depth = dfs(ngb, node, graph, dia);
            if (depth > max1) {
                max2 = max1;
                max1 = depth;
            } else if (depth > max2) {
                max2 = depth;
            }
        }
        dia = max(dia, max2 + max1);
        return max1 + 1;
    }

    int calcD(vector<vector<int>>& graph) {
        int dia = 0;
        dfs(0, -1, graph, dia);
        return dia;
    }

    auto build(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> tree1 = build(n, edges1);
        vector<vector<int>> tree2 = build(m, edges2);
        int diameter1 = calcD(tree1);
        int diameter2 = calcD(tree2);
        int height1 = (diameter1 + 1 ) / 2;
        int height2 = (diameter2 + 1 ) / 2;
        return max({diameter1, diameter2, height1 + height2 + 1});
    }
};
