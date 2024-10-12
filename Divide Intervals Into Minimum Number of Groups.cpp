class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& inte: intervals) {
            int arr = inte[0];
            int lea = inte[1];
            if (!pq.empty() && pq.top() < arr) pq.pop();
            pq.push(lea);
        }
        return pq.size();
    }
};
