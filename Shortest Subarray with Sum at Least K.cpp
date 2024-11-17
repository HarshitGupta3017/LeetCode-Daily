class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MAX;
        vector<long long> cs(n, 0);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cs[i] = nums[i];
            } else {
                cs[i] = cs[i - 1] + nums[i];
            }
            if (cs[i] >= k) {
                res = min(res, i + 1);
            }
            while (!dq.empty() && cs[i] - cs[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && cs[i] <= cs[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};
