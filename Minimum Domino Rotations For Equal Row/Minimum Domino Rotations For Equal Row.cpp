// Solution for Minimum Domino Rotations For Equal Row in CPP

class Solution {
public:

    int find(vector<int>& tops, vector<int>& bottoms, int val) {
        int swapTop = 0, swapBot = 0;
        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != val && bottoms[i] != val) {
                return -1;
            } else if (tops[i] != val) {
                swapTop++;
            } else if (bottoms[i] != val) {
                swapBot++;
            }
        }
        return min(swapTop, swapBot);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX;
        for (int val = 1; val <= 6; val++) {
            int steps = find(tops, bottoms, val);
            if (steps != -1) 
                res = min(res, steps);
        }
        return res == INT_MAX ? -1 : res;
    }
};
