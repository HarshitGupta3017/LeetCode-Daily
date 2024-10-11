class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);
        int targetArrival = times[targetFriend][0];
        sort(times.begin(), end(times));
        for (const auto& time: times) {
            int arrival = time[0];
            int leaving = time[1];
            for (int i = 0; i < n; i++) {
                if (chairs[i] <= arrival) {
                    chairs[i] = leaving;
                    if (arrival == targetArrival) return i;
                    break;
                }
            }
        }
        return -1;
    }
};
