// Solution for Longest Nice Subarray in CPP

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, mask = 0, res = 1;
        while (j < n) {
            while ((mask & nums[j]) != 0){
                mask ^= nums[i++];
            }
            res = max(res, j - i + 1);
            mask |= nums[j++];
        }
        return res;
    }
};
