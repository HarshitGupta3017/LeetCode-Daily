// Solution for Push Dominoes in CPP

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> rightClosestL(n);
        vector<int> leftClosestR(n);
        // left to right
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                leftClosestR[i] = i;
            } else if (dominoes[i] == '.') {
                leftClosestR[i] = i > 0 ? leftClosestR[i - 1] : -1;
            } else {
                leftClosestR[i] = -1;
            }
        }
        // right to left
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                rightClosestL[i] = i;
            } else if (dominoes[i] == '.') {
                rightClosestL[i] = i < n - 1 ? rightClosestL[i + 1] : -1;
            } else {
                rightClosestL[i] = -1;
            }
        }
        string result(n, ' ');
        for (int i = 0; i < n; i++) {
            int distRightL = abs(i - rightClosestL[i]); 
            int distLeftR = abs(i - leftClosestR[i]); 
            if (leftClosestR[i] == rightClosestL[i]) {
                result[i] = '.';
            } else if (leftClosestR[i] == -1) {
                result[i] = 'L';
            } else if (rightClosestL[i] == -1) {
                result[i] = 'R';
            } else if (distRightL == distLeftR) {
                result[i] = '.';
            } else {
                result[i] = distRightL < distLeftR ? 'L' : 'R';
            }
        }
        return result;
    }
};
