// Solution for Maximum Average Pass Ratio in CPP

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        
        // Lambda function to calculate gain (delta)
        auto delta = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max-heap based on delta
        priority_queue<pair<double, int>> pq;
        
        // Push all classes with their delta
        for (int i = 0; i < n; i++) {
            pq.push({delta(classes[i][0], classes[i][1]), i});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [gain, idx] = pq.top(); pq.pop();
            
            classes[idx][0]++;  // one more student passes
            classes[idx][1]++;  // total increases
            
            // Push updated delta for that class
            pq.push({delta(classes[idx][0], classes[idx][1]), idx});
        }

        // Calculate final average pass ratio
        double result = 0.0;
        for (auto &c : classes) {
            result += (double)c[0] / c[1];
        }

        return result / n;
    }
};
