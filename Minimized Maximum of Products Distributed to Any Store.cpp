class Solution {
public:

    bool solve(int val, int n, vector<int>& quantities) {
        int stores = 0;
        for (const auto& q: quantities) {
            stores += (q + val - 1) / val;
        }
        return stores <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end());
        int res = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (solve(mid, n, quantities)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
