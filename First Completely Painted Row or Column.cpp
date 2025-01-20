class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) mp[arr[i]] = i;
        int minIdx = INT_MAX;
        for (int i = 0; i < m; i++) {
            int lastIdx = INT_MIN;
            for (int j = 0; j < n; j++) {
                int idx = mp[mat[i][j]];
                lastIdx = max(lastIdx, idx);
            }
            minIdx = min(minIdx, lastIdx);
        }
        for (int j = 0; j < n; j++) {
            int lastIdx = INT_MIN;
            for (int i = 0; i < m; i++) {
                int idx = mp[mat[i][j]];
                lastIdx = max(lastIdx, idx);
            }
            minIdx = min(minIdx, lastIdx);
        }
        return minIdx;
    }
};
