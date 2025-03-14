// Solution for Maximum Candies Allocated to K Children in CPP

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = *max_element(candies.begin(), candies.end());
        int res = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long count = 0;
            for (int c: candies) {
                count += (c / mid);
                if (count >= k) break;
            }
            if (count >= k) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
