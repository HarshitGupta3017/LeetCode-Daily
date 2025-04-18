class Solution {
public:

    int solve(int j, int k, vector<int>& arr, unordered_map<int, int>& mp, vector<vector<int>>& t) {
        if (t[j][k] != -1) return t[j][k];
        int target = arr[k] - arr[j];
        if (mp.count(target) && mp[target] < j) {
            int i = mp[target];
            return t[j][k] = solve(i, j, arr, mp, t) + 1;
        }
        return t[j][k] = 2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        vector<vector<int>> t(n, vector<int>(n, -1));
        int mxlen = 0;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int length = solve(j, k, arr, mp, t);
                if (length >= 3) {
                    mxlen = max(mxlen, length);
                }
            }
        }
        return mxlen;
    }
};
