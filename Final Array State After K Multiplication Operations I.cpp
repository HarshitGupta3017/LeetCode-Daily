class Solution {
public:
    using P = pair<int, int>;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // easy question right??
        // just read the question and a data structure will come in your mind
        // ya that one lol
        // priority_queue i.e. min heap 
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        while (k--) {
            // just picking top element as its min heap so it will be smallest in array
            // then performing operation as told and adding back to heap
            // also adding in nums
            auto [curr, idx] = pq.top();
            pq.pop();
            nums[idx] = curr * multiplier;
            pq.push({nums[idx], idx});
        }
        return nums;
    }
};
