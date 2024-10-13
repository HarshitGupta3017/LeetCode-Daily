class Solution {
public:
    using T = tuple<int, int, int>;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res(2);
        int left = nums[0][0], right = nums[0][0];
        int n = nums.size();
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < n; i++) {
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
            pq.push({nums[i][0], i, 0});
        }
        res = {left, right};
        while (true) {
            auto [num, i, idx] = pq.top();
            pq.pop();
            left = num;
            if (right - left < res[1] - res[0] || (right - left == res[1] - res[0] && left < res[0])) {
                res[0] = left;
                res[1] = right;
            }
            idx++;
            if (idx == nums[i].size()) break;
            pq.push({nums[i][idx], i, idx});
            right = max(right, nums[i][idx]);
        }
        return res;
    }
};
