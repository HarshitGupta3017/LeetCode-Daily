// Solution for Furthest Point From Origin in CPP

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, blank = 0;
        for (char ch : moves) {
            if (ch == 'L') L++;
            else if (ch == 'R') R++;
            else blank++;
        }
        return abs(L - R) + blank;
    }
};
