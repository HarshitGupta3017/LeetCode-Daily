// Solution for Maximum Count of Positive Integer and Negative Integer in CPP

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = nums.end() - lower_bound(nums.begin(), nums.end(), 1);
        int neg = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
        return max(pos, neg);
    }
};
