// Solution for Left and Right Sum Differences in CPP

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int leftSum = 0, rightSum = totalSum;
        vector<int> result;

        for (const auto& num: nums) {
            rightSum -= num;
            result.push_back(abs(leftSum - rightSum));
            leftSum += num;
        }

        return result;
    }
};
