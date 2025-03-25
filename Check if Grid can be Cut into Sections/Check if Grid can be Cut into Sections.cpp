// Solution for Check if Grid can be Cut into Sections in CPP

class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < res.back()[1]) {
                res.back()[0] = min(intervals[i][0], res.back()[0]);
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_axis, y_axis;
        for (const auto& rec: rectangles) {
            x_axis.push_back({rec[0], rec[2]});
            y_axis.push_back({rec[1], rec[3]});
        }
        vector<vector<int>> mergedX = merge(x_axis);
        if (mergedX.size() >= 3) return true;
        vector<vector<int>> mergedY = merge(y_axis);
        return mergedY.size() >= 3;
    }
};
