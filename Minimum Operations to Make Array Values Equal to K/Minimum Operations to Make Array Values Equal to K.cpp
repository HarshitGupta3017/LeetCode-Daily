// Solution for Minimum Operations to Make Array Values Equal to K in CPP

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (const auto& num: nums) {
            if (num < k) return -1;
            else if (num > k) st.insert(num);
        }
        return st.size();
    }
};
