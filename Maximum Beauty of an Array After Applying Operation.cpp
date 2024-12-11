class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // simple sliding window concept here
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int j = 0, res = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] <= nums[i] + 2 * k) j++;
            res = max(res, j - i);
        }
        return res;
    }
};
