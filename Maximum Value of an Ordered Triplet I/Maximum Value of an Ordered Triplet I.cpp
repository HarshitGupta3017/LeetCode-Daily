// Solution for Maximum Value of an Ordered Triplet I in CPP

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxPrefix = nums[0];
        vector<long long> maxSuffix(n, 0);
        maxSuffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxSuffix[i] = max(maxSuffix[i + 1], (long long)nums[i]);
        }
        long long maxVal = 0;
        for (int j = 1; j < n - 1; j++) {
            maxVal = max(maxVal, (maxPrefix - nums[j]) * maxSuffix[j + 1]);
            maxPrefix = max(maxPrefix, (long long)nums[j]);
        }
        return maxVal;
    }
};
