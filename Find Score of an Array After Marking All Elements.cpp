class Solution {
public:
    using P = pair<int, int>;
    long long findScore(vector<int>& nums) {
        // simple question 
        // need to store elements in ascending order with idx 
        // min heap right??
        int n = nums.size();
        long long score = 0;
        vector<bool> marked(n, false);
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            // if that index is marked continue
            if (marked[idx]) continue;
            // if not then mark it and add to score
            score += val;
            marked[idx] = true;
            // check for adjacent elements
            if (idx > 0) marked[idx - 1] = true;
            if (idx < n - 1) marked[idx + 1] = true;
        }
        // sorry lol returned true instead of score
        return score;
    }
};
