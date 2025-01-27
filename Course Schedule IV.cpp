class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (const auto& edge: prerequisites) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        unordered_map<int, unordered_set<int>> mp;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& adjNode: adj[node]) {    
                mp[adjNode].insert(node);
                for (auto& m: mp[node]) mp[adjNode].insert(m);
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        vector<bool> res;
        for (const auto& q: queries) {
            int u = q[0], v = q[1];
            res.push_back(mp[v].contains(u));
        }
        return res;
    }
};
