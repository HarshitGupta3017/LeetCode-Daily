class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        int res = 0;
        for (int x: arr1) {
            while (!st.count(x) && x > 0) {
                st.insert(x);
                x /= 10;
            }
        }
        for (int y: arr2) {
            while (!st.count(y) && y > 0) y /= 10;
            if (y > 0) res = max(res, (int)(log10(y) + 1));
        }
        return res;
    }
};
