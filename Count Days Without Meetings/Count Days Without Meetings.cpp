// Solution for Count Days Without Meetings in CPP

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int res = 0;
        int merge_end = 0;
        for (const auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            if (start > merge_end + 1) {
                res += (start - merge_end - 1);
            }
            merge_end = max(merge_end, end);
        }
        if (merge_end < days) {
            res += days - merge_end;
        }
        return res;
    }
};
