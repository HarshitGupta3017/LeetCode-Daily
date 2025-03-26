// Solution for Minimum Operations to Make a Uni-Value Grid in CPP

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (const auto& row: grid) {
            for (const auto& col: row) {
                nums.push_back(col);
            }
        }
        int remainder = nums[0] % x;
        for (const auto& num: nums) {
            if (num % x != remainder) return -1;
        }
        sort(nums.begin(), nums.end());
        int ops = 0;
        int median = nums[nums.size() / 2];
        for (const auto& num: nums) {
            ops += abs(num - median) / x;
        }
        return ops;
    }
};
