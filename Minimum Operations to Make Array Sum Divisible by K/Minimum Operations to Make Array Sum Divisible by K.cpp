// Solution for Minimum Operations to Make Array Sum Divisible by K in CPP

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};
