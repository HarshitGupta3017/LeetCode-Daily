class Solution {
public:

    bool solve(vector<int>& nums, int maxOperations, int penalty) {
        int ops = 0;
        for (const int& balls: nums) {
            ops += (balls - 1) / penalty;
            if (ops > maxOperations) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int res = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (solve(nums, maxOperations, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
