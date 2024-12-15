class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < n; i++) {
            double curr_pr = (double) classes[i][0] / classes[i][1];
            double new_pr = (double) (classes[i][0] + 1) / (classes[i][1] + 1);
            double change = new_pr - curr_pr;
            pq.push({change, i});
        }
        while (extraStudents--) {
            auto [change, idx] = pq.top();
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            double curr_pr = (double) classes[idx][0] / classes[idx][1];
            double new_pr = (double) (classes[idx][0] + 1) / (classes[idx][1] + 1);
            change = new_pr - curr_pr;
            pq.push({change, idx});
        }
        double res = 0.0;
        for (int i = 0; i < n; i++) {
            res += (double) classes[i][0] / classes[i][1];
        }
        return res / n;
    }
};
