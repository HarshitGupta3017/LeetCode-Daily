class Solution {
public:

    int solve (int idx, int curror, vector<int>& nums, int& maxor, vector<vector<int>>& t) {
        if (idx == nums.size()) return (curror == maxor) ? 1 : 0;
        if (t[curror][idx] != -1) return t[curror][idx];
        int pick = solve(idx + 1, curror | nums[idx], nums, maxor, t);
        int notpick = solve(idx + 1, curror, nums, maxor, t);
        return t[curror][idx] = pick + notpick;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        for (const int& num: nums) maxor |= num;
        vector<vector<int>> t(maxor + 1, vector<int>(nums.size() + 1, -1));
        return solve(0, 0, nums, maxor, t);
    }
};
