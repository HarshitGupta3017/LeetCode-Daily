// Solution for Maximize the Number of Target Nodes After Connecting Trees II in CPP

class Solution {
public:
    // DFS to mark nodes alternately with 0 and 1 and count them
    void DFS(int curr, int parent, vector<vector<int>>& adj, vector<int>& mark, int& zeroCount, int& oneCount) {
        // Count current node based on its mark
        if (mark[curr] == 0) 
            zeroCount++;
        else 
            oneCount++;

        for (const auto& ngbr : adj[curr]) {
            if (ngbr != parent) {
                // Alternate mark for child node
                mark[ngbr] = (mark[curr] == 0) ? 1 : 0;
                DFS(ngbr, curr, adj, mark, zeroCount, oneCount);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size() + 1; // Number of nodes in first tree
        int M = edges2.size() + 1; // Number of nodes in second tree

        // Build adjacency list for first tree
        vector<vector<int>> adj1(N);
        for (const auto& edge : edges1) {
            int u = edge[0], v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        // Build adjacency list for second tree
        vector<vector<int>> adj2(M);
        for (const auto& edge : edges2) {
            int u = edge[0], v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        // Mark nodes in tree1 and count parity groups
        vector<int> mark1(N, -1);
        mark1[0] = 0;
        int zeroCount1 = 0, oneCount1 = 0;
        DFS(0, -1, adj1, mark1, zeroCount1, oneCount1);

        // Mark nodes in tree2 and count parity groups
        vector<int> mark2(M, -1);
        mark2[0] = 0;
        int zeroCount2 = 0, oneCount2 = 0;
        DFS(0, -1, adj2, mark2, zeroCount2, oneCount2);

        // From second tree, choose max count of even or odd distance nodes
        int maxFromTree2 = max(zeroCount2, oneCount2);

        // Final result: for each node in tree1, sum local targets + best remote target count
        vector<int> result(N, 0);
        for (int i = 0; i < N; i++) {
            result[i] = (mark1[i] == 0 ? zeroCount1 : oneCount1) + maxFromTree2;
        }

        return result;
    }
};
