// Solution for Zero Array Transformation I in CPP

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n, 0);
        for (const auto& q: queries) {
            int start = q[0], end = q[1];
            int x = 1;
            diff[start] += 1;
            if (end + 1 < n) 
                diff[end + 1] -= 1; 
        }
        vector<int> res(n, 0);
        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            res[i] = cumSum;
        }
        for (int i = 0; i < n; i++) {
            if (res[i] < nums[i])
                return false;
        }
        return true;
    }
};
