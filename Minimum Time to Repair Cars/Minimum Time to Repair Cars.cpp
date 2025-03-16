// Solution for Minimum Time to Repair Cars in CPP

class Solution {
public:

    using ll = long long;
    bool isPossible(vector<int>& ranks, int cars, ll mid) {
        ll carsFixed = 0;
        for (int i = 0; i < ranks.size(); i++) {
            carsFixed += sqrt(mid / ranks[i]);
        }
        return carsFixed >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int maxR = *max_element(ranks.begin(), ranks.end());
        ll l = 1, r = 1LL * maxR * cars * cars;
        ll res = -1;
        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if (isPossible(ranks, cars, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
