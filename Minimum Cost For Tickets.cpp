class Solution {
public:

    int solve (vector<int>& days, vector<int>& costs, int i, unordered_map<int, int>& dp) {
        if (i == days.size()) return 0;
        if (dp.find(i) != dp.end()) return dp[i];
        int cost1 = costs[0] + solve(days, costs, i + 1, dp);
        int idx = i;
        while (idx < days.size() && days[idx] < days[i] + 7) idx++;
        int cost2 = costs[1] + solve(days, costs, idx, dp);
        idx = i;
        while (idx < days.size() && days[idx] < days[i] + 30) idx++;
        int cost3 = costs[2] + solve(days, costs, idx, dp);
        return dp[i] = min({cost1, cost2, cost3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int, int> dp;
        return solve(days, costs, 0, dp);
    }
};
