// Solution for Count Subarrays With Fixed Bounds in CPP

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minKidx = -1, maxKidx = -1, culpritIdx = -1;
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) 
                culpritIdx = i;
            if (nums[i] == minK)
                minKidx = i;
            if (nums[i] == maxK)
                maxKidx = i;
            long long smaller = min(maxKidx, minKidx);
            long long temp = smaller - culpritIdx;
            res += (temp <= 0) ? 0 : temp;
        }
        return res;
    }
};
