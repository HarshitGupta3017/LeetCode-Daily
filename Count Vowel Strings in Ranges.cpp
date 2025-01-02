class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), q = queries.size();
        vector<int> res(q), cumSum(n);
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (st.count(words[i][0]) && st.count(words[i].back())) sum++;
            cumSum[i] = sum;
        }
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            res[i] = cumSum[r] - (l > 0 ? cumSum[l - 1] : 0);
        }
        return res;
    }
};
