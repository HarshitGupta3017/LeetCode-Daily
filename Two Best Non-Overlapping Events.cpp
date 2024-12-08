class Solution {
public:

    int solve(vector<vector<int>>& events, int i, int count, int n, vector<vector<int>>& dp) {
        if (count == 2 || i >= n) return 0;
        if (dp[i][count] != -1) return dp[i][count];
        auto it = upper_bound(events.begin() + i + 1, events.end(), events[i][1], 
            [](int endTime, const auto& event){
                return event[0] > endTime;
            }
        );
        int nextidx = (it == events.end()) ? n : it - events.begin();
        int take = events[i][2] + solve(events, nextidx, count + 1, n, dp);
        int notTake = solve(events, i + 1, count, n, dp);
        return dp[i][count] = max(take, notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(events, 0, 0, n, dp);      
    }
};
