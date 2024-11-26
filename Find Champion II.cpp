class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // simple ques - one whos indegree is 0 is the champion and if more than 1 champions return -1;
        vector<int> indegree(n, 0);
        for (const auto& edge: edges) indegree[edge[1]]++;
        int champ = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (champ != -1) return -1;
                champ = i;
            }
        }
        return champ;
    }
};
