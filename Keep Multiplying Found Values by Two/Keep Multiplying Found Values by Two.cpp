// Solution for Keep Multiplying Found Values by Two in CPP

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for (const int& num: nums) {
            if (num == original)
                original *= 2;
        }
        return original;
    }
};
