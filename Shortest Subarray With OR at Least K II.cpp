class Solution {
public:

    void updateInWin(int num, vector<int>& vec, int sign) {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) vec[i] += sign;
        }
    }

    int getCurrOR(vector<int>& vec) {
        int currOR = 0;
        for (int i = 0; i < 32; i++) {
            if (vec[i] > 0) {
                currOR |= (1 << i);
            }
        }
        return currOR;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        // need to keep track of smallest subarray so a sliding window concept
        int i = 0, minLen = INT_MAX;
        // for keeping track of bits
        vector<int> vec(32, 0);
        for (int j = 0; j < nums.size(); j++) {
            // need to add in window here so sign will be 1
            updateInWin(nums[j], vec, 1);
            while (getCurrOR(vec) >= k && i <= j) {
                minLen = min(minLen, j - i + 1);
                // need to remove here to sign will be -1 so that no need to rewrite function
                updateInWin(nums[i], vec, -1);
                i++;
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};
