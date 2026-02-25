// Solution for Sort Integers by The Number of 1 Bits in CPP

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [](const auto& a, const auto& b) {
            int cA = __builtin_popcount(a);
            int cB = __builtin_popcount(b);
            if (cA == cB) return a < b;
            return cA < cB;
        };
        sort(begin(arr), end(arr), lambda);
        return arr;
    }
};
