// Solution for Count the Hidden Sequences in CPP

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0, mn = 0, mx = 0;
        for (int d: differences) {
            curr += d;
            mn = min(mn, curr);
            mx = max(mx, curr);
            if ((upper - mx) - (lower - mn) + 1 <= 0) return 0;
        }
        return (upper - mx) - (lower - mn) + 1;
    }
};
