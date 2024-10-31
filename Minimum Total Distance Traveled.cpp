class Solution {
public:
    long long t[100][100][100];
    long long solve(vector<int>& robot, vector<vector<int>>& factory, int i, int j, int count) {
        if (i < 0) return 0;
        if (j < 0) return 1LL << 40;
        if (t[i][j][count] != -1) return t[i][j][count];
        long long skip = solve(robot, factory, i, j - 1, 0);
        long long take = (count < factory[j][1]) ? abs(robot[i] - factory[j][0]) + solve(robot, factory, i - 1, j, count + 1) : 1LL << 40;
        return t[i][j][count] = min(skip, take);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int r = robot.size(), f = factory.size();
        memset(t, -1, sizeof(t));
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        return solve(robot, factory, r - 1, f - 1, 0);
    }
};
