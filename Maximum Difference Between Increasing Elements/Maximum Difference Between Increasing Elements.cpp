// Solution for Maximum Difference Between Increasing Elements in CPP

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minEle = nums[0];
        int maxDiff = -1;
        for (int j = 1; j < n; j++) {
            if (nums[j] > minEle) {
                maxDiff = max(maxDiff, nums[j] - minEle);
            } else {
                minEle = nums[j];
            }
        }
        return maxDiff;
    }
};
