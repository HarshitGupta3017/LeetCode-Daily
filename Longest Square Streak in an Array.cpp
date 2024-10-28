class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = -1;
        for (int num: nums) {
            int len = 0;
            long long curr = num;
            while (st.count(curr) > 0) {
                len++;
                if (curr*curr > 1e5) break;
                curr *= curr;
            }
            res = max(res, len);
        }
        return res < 2 ? -1 : res;
    }
};
