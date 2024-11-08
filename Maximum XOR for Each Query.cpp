class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> res(n);
        int totalXor = 0;
        for (const int& num: nums) {
            totalXor ^= num;
        }
        int mask = (1 << maximumBit) - 1;
        for (int i = 0; i < n; i++) {
            res[i] = totalXor ^ mask;
            totalXor ^= nums[n - i - 1];
        }
        return res;
    }
};
