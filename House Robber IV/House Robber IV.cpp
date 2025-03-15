// Solution for House Robber IV in CPP

class Solution {
public:

    bool isPossible(vector<int>& nums, int mid, int k, int n) {
        int house = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                house++; // included
                i++; // moved to i + 2
            }
        }
        return house >= k; // got atleast k houses
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int res = r;
        while (l <= r) {
            int mid = l + (r - l) / 2; // capability
            if (isPossible(nums, mid, k, n)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
