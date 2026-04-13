// Solution for Minimum Distance to the Target Element in CPP

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                result = min(result, abs(i - start));
            }
        }
        return result;
    }
};
