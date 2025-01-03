class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long tsum = accumulate(nums.begin(), nums.end(), 0LL);
        long long sum = 0;
        int count = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            tsum -= nums[i + 1];
            sum += nums[i + 1];
            if (tsum >= sum) count++;
        }
        return count;
    }
};
