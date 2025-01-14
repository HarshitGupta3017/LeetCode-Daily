class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq;
        vector<int> res;
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) count++;
            freq[B[i]]++;
            if (freq[B[i]] == 2) count++;
            res.push_back(count);
        }
        return res;
    }
};
