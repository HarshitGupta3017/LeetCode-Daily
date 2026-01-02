// Solution for N-Repeated Element in Size 2N Array in CPP

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        for (const auto& num: nums) {
            if (st.count(num)) return num;
            st.insert(num);
        }
        return 0;
    }
};
